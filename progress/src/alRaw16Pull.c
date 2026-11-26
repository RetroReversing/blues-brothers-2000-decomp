typedef union {
    struct { unsigned int w0; unsigned int w1; } words;
    long long int force_structure_alignment;
} Acmd;

typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);

typedef struct {
    u32         start;
    u32         end;
    u32         count;
} ALRawLoop;

typedef struct ALWaveTable_s {
    u8          *base;
    s32         len;
    u8          type;
    u8          flags;
} ALWaveTable;

typedef struct ALFilter_s {
    struct ALFilter_s   *source;
    void                *handler;
    void                *setParam;
    s16                 inp;
    s16                 outp;
    s32                 type;
} ALFilter;

typedef struct {
    ALFilter                    filter;
    s16                         *state;
    s16                         *lstate;
    ALRawLoop                   loop;
    struct ALWaveTable_s        *table;
    s32                         bookSize;
    ALDMAproc                   dma;
    void                        *dmaState;
    s32                         sample;
    s32                         lastsam;
    s32                         first;
    s32                         memin;
} ALLoadFilter;

/* Queues DMA and copy commands that stream 16-bit PCM from a raw ALLoadFilter into DMEM, wrapping at the loop end and zero-filling any overflow past the table; returns the advanced command pointer. */
Acmd *alRaw16Pull(void *filter, s16 *outDmem, s32 sampleCount, s32 sampleOffset, Acmd *cmdList)
{
    Acmd        *cmd = cmdList;
    s32         nBytes;
    s32         dramAddr;
    s32         dramMisalign;
    s32         dmemPad;
    s32         overflow;
    s32         zeroBytes;
    s32         loopSamples;
    s32         dmemPos;

    ALLoadFilter *loadFilter = (ALLoadFilter *)filter;
    ALFilter *baseFilter = (ALFilter *) filter;

    if (sampleCount == 0)
        return cmd;

    if ((sampleCount + loadFilter->sample > loadFilter->loop.end) && (loadFilter->loop.count != 0)){

        loopSamples = loadFilter->loop.end - loadFilter->sample;
        nBytes = loopSamples<<1;
        if (loopSamples > 0){
            dramAddr = (loadFilter->dma)(loadFilter->memin, nBytes, loadFilter->dmaState);

            dramMisalign = dramAddr & 0x7;
            nBytes += dramMisalign;
            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = (((unsigned int) (((unsigned int)( 8  ) & ((0x01 << (  8 )) - 1)) << (  24 )))  | ((unsigned int) (((unsigned int)(   0  ) & ((0x01 << (  8 )) - 1)) << (  16 )))  | ((unsigned int) (((unsigned int)(   *outDmem  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ); _a->words.w1 = ((unsigned int) (((unsigned int)(   0  ) & ((0x01 << (  16 )) - 1)) << (  16 )))  | ((unsigned int) (((unsigned int)(   nBytes + 8 - (nBytes & 0x7)  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ; } ;
            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = ((unsigned int) (((unsigned int)( 4  ) & ((0x01 << (  8 )) - 1)) << (  24 ))) ; _a->words.w1 = (unsigned int)(  dramAddr - dramMisalign ); } ;
        } else
            dramMisalign = 0;

        *outDmem += dramMisalign;

        #ifdef PORT
        loadFilter->memin = (uintptr_t) loadFilter->table->base + (loadFilter->loop.start<<1);
#else
        loadFilter->memin = (s32) loadFilter->table->base + (loadFilter->loop.start<<1);
#endif
        loadFilter->sample = loadFilter->loop.start;
        dmemPos = *outDmem;

        while (sampleCount > loopSamples){

            dmemPos += (loopSamples<<1);
            sampleCount -= loopSamples;

            if ((loadFilter->loop.count != -1) && (loadFilter->loop.count != 0))
                loadFilter->loop.count--;

            loopSamples = (( sampleCount ) < (  loadFilter->loop.end - loadFilter->loop.start ) ? ( sampleCount ) : (  loadFilter->loop.end - loadFilter->loop.start )) ;
            nBytes = loopSamples<<1;

            dramAddr = (loadFilter->dma)(loadFilter->memin, nBytes, loadFilter->dmaState);

            dramMisalign = dramAddr & 0x7;
            nBytes += dramMisalign;
            if (dmemPos & 0x7)
                dmemPad = 8 - (dmemPos & 0x7);
            else
                dmemPad = 0;

            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = (((unsigned int) (((unsigned int)( 8  ) & ((0x01 << (  8 )) - 1)) << (  24 )))  | ((unsigned int) (((unsigned int)(   dmemPos + dmemPad  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ); _a->words.w1 = ((unsigned int) (((unsigned int)(   0  ) & ((0x01 << (  16 )) - 1)) << (  16 )))  | ((unsigned int) (((unsigned int)(   nBytes + 8 - (nBytes & 0x7)  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ; } ;
            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = ((unsigned int) (((unsigned int)( 4  ) & ((0x01 << (  8 )) - 1)) << (  24 ))) ; _a->words.w1 = (unsigned int)(  dramAddr - dramMisalign ); } ;

            if (dramMisalign || dmemPad)
                { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = ((unsigned int) (((unsigned int)( 10  ) & ((0x01 << (  8 )) - 1)) << (  24 )))  | ((unsigned int) (((unsigned int)(   dmemPos+dramMisalign+dmemPad  ) & ((0x01 << (  24 )) - 1)) << (  0 ))) ; _a->words.w1 = ((unsigned int) (((unsigned int)(   dmemPos  ) & ((0x01 << (  16 )) - 1)) << (  16 )))  | ((unsigned int) (((unsigned int)(   loopSamples<<1  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ; } ;

        }

        loadFilter->sample += sampleCount;
        loadFilter->memin += (sampleCount<<1);

        return cmd;
    }

    nBytes = sampleCount<<1;
    #ifdef PORT
    overflow = loadFilter->memin + nBytes - ((uintptr_t) loadFilter->table->base + loadFilter->table->len);
#else
    overflow = loadFilter->memin + nBytes - ((s32) loadFilter->table->base + loadFilter->table->len);
#endif
    if (overflow < 0)
        overflow = 0;
    if (overflow > nBytes)
        overflow = nBytes;

    if (overflow < nBytes){
        if (sampleCount > 0){
            nBytes -= overflow;
            dramAddr = (loadFilter->dma)(loadFilter->memin, nBytes, loadFilter->dmaState);

            dramMisalign = dramAddr & 0x7;
            nBytes += dramMisalign;
            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = (((unsigned int) (((unsigned int)( 8  ) & ((0x01 << (  8 )) - 1)) << (  24 )))  | ((unsigned int) (((unsigned int)(   *outDmem  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ); _a->words.w1 = ((unsigned int) (((unsigned int)(   0  ) & ((0x01 << (  16 )) - 1)) << (  16 )))  | ((unsigned int) (((unsigned int)(   nBytes + 8 - (nBytes & 0x7)  ) & ((0x01 << (  16 )) - 1)) << (  0 ))) ; } ;
            { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = ((unsigned int) (((unsigned int)( 4  ) & ((0x01 << (  8 )) - 1)) << (  24 ))) ; _a->words.w1 = (unsigned int)(  dramAddr - dramMisalign ); } ;
        } else
            dramMisalign = 0;
        *outDmem += dramMisalign;

        loadFilter->sample += sampleCount;
        loadFilter->memin += sampleCount<<1;
    } else {
        loadFilter->memin += sampleCount<<1;
    }

    if (overflow){
        zeroBytes = (sampleCount<<1) - overflow;
        if (zeroBytes < 0)
            zeroBytes = 0;
        { Acmd *_a = (Acmd *) cmd++ ; _a->words.w0 = ((unsigned int) (((unsigned int)( 2  ) & ((0x01 << (  8 )) - 1)) << (  24 )))  | ((unsigned int) (((unsigned int)(   zeroBytes + *outDmem  ) & ((0x01 << (  24 )) - 1)) << (  0 ))) ; _a->words.w1 = (unsigned int)(  overflow ); } ;
    }
    return cmd;
}
