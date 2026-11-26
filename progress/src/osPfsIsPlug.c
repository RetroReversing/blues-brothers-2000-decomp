/* identical to osPfsIsPlug in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct { u16 type; u8 status; u8 errno; } CS;
extern u8 D_8017DBBC;
extern char D_80175D8E[];
s32 __osPfsRequestData(s32);
void func_800A0E30();
void func_8009DBF4();
void func_8009DC60();
s32 func_8009DB00();
s32 osRecvMesg(s32, s32 *, s32);

/* Polls the controller pak status for every channel until all of them report
 * ready, then stores a bitmask of the channels with a pak plugged in. */
s32 osPfsIsPlug(s32 queue, u8 *pattern) {
    s32 ret;
    s32 dummy;
    s32 channel;
    s32 cntrlrs = 0;
    u8 bitpattern;
    CS data[4];
    s32 crap = 3;
    u8 *pif;
    func_8009DBF4();
    pif = (u8*)(D_80175D8E + 0x7E82);
    do {
        __osPfsRequestData(0);
        func_8009DB00(1, pif);
        osRecvMesg(queue, &dummy, 1);
        ret = func_8009DB00(0, pif);
        osRecvMesg(queue, &dummy, 1);
        func_800A0E30(&bitpattern, data);
        for (channel = 0; channel < D_8017DBBC; channel++) {
            if (!(data[channel].status & 4)) { crap--; break; }
        }
        if (channel != D_8017DBBC) continue;
        crap = 0;
    } while (crap > 0);
    for (channel = 0; channel < D_8017DBBC; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1)) cntrlrs |= 1 << channel;
    }
    func_8009DC60();
    *pattern = cntrlrs;
    return ret;
}
