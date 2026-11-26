typedef struct Bank1E0 {
    u8 pad0[0x18];
    u8 *env;
    u8 pad1C[4];
    u16 *wmap;
} Bank1E0;

typedef struct Bank78 {
    u8 pad0[0x14];
    u16 *wmap;
} Bank78;

typedef struct Wave1E0 {
    u8 pad0[0x28];
    f32 *detune;
    void **waves;
} Wave1E0;

typedef struct Drum1E0 {
    u16 wave;
    u16 env;
    u8 pan;
    u8 note;
} Drum1E0;

typedef struct Chan1E0 {
    u8 pad0[0x4];
    u8 * pdata;
    void * wave;
    s32 c0C;
    u8 pad10[0x1C];
    f32 freq;
    u8 pad30[0xC];
    s32 end;
    s32 last;
    u8 pad44[0x8];
    f32 oldf;
    f32 basef;
    s32 c54;
    u8 pad58[0x1C];
    Bank1E0 * bank;
    Bank78 * b78;
    Wave1E0 * wtab;
    u8 pad80[0x4];
    Drum1E0 * drums;
    u8 pad88[0x12];
    u16 length;
    u8 pad9C[0x4];
    u16 cA0;
    u8 padA2[0x8];
    u16 cAA;
    u16 fixlen;
    u16 wnum;
    u8 padB0[0x7];
    u8 cB7;
    u8 padB8[0x1];
    u8 cB9;
    u8 cBA;
    u8 vel;
    u8 padBC[0x1];
    u8 cBD;
    u8 padBE[0x5];
    u8 cC3;
    u8 cC4;
    u8 cC5;
    u8 padC6[0x3];
    u8 playing;
    u8 cCA;
    u8 cCB;
    u8 cCC;
    u8 cCD;
    u8 padCE[0x1];
    u8 cCF;
    u8 cD0;
    u8 cD1;
    u8 velon;
    u8 defvel;
    u8 cD4;
    u8 padD5[0x1];
    u8 cD6;
    u8 cD7;
} Chan1E0;

typedef u8 *(*Cmd1E0)(Chan1E0 *, u8 *);

extern Cmd1E0 D_800BA650[];
extern u8 D_8017B4A0[];
extern u8 *D_8017B208;
extern s32 D_8017B218;
extern void alSynSetVol(void *, void *, s16, s32);
extern void alSynSetFXMix(void *, void *, u8);
extern void alSynStopVoice(void *, void *);
extern void func_8008C3FC(Chan1E0 *, u8 *);
extern void func_8008E93C(Chan1E0 *);
extern void func_8008EB8C(Chan1E0 *);
extern void func_8008E644(Chan1E0 *, s32);

/* Sound driver: runs the sequence commands for one channel, then starts its next note on the given voice. If the sequence has ended, the voice is stopped. */
void playSeqChannelNote(Chan1E0 *chan, s32 voice) {
    u8 *seq;
    s32 noteNum;
    s32 waveIdx;
    u8 byte;
    s32 m;
    s32 t;
    u8 fxLevel;
    Wave1E0 *waveTab;
    u16 *map;
    f32 pitch;

    seq = chan->pdata;
    if (seq != NULL) {
    loop:
        byte = *seq;
        if (byte > 127) {
            seq = D_800BA650[byte & 0x7F](chan, seq + 1);
            if (seq != NULL) {
                goto loop;
            }
        }
    }
    chan->pdata = seq;
    if (seq != NULL) {
        chan->oldf = chan->basef;
        noteNum = *chan->pdata++;
        if (chan->velon) {
            chan->vel = *chan->pdata++;
            if (chan->vel > 127) {
                chan->vel &= 0x7F;
                chan->velon = 0;
                chan->defvel = chan->vel;
            }
        } else {
            chan->vel = chan->defvel;
        }
        if (chan->fixlen) {
            if (chan->cB7) {
                chan->cB7 = 0;
                byte = *chan->pdata++;
                if (byte < 128) {
                    chan->length = byte;
                } else {
                    chan->length = ((byte & 0x7F) << 8) + *chan->pdata++;
                }
            } else {
                chan->length = chan->fixlen;
            }
        } else {
            byte = *chan->pdata++;
            if (byte < 128) {
                chan->length = byte;
            } else {
                chan->length = ((byte & 0x7F) << 8) + *chan->pdata++;
            }
        }
        chan->last = chan->end;
        chan->cAA = 0;
        chan->cD1 = 0;
        chan->end += chan->length << 8;
        chan->cD0 = chan->cCF;
        if (chan->bank != NULL && chan->drums == NULL && chan->bank->wmap[chan->wnum] == 0xFFFF) {
            noteNum = 0x60;
        }
        if (noteNum != 0x60) {
        waveTab = chan->wtab;
        if (chan->drums != NULL) {
            chan->wnum = chan->drums[noteNum].wave;
            chan->cBD = chan->drums[noteNum].pan >> 1;
            func_8008C3FC(chan, chan->bank->env + chan->drums[noteNum].env * 7);
            noteNum = chan->drums[noteNum].note;
        }
        if (!chan->cD6) {
            func_8008E93C(chan);
        }
        if (chan->cD4) {
            func_8008EB8C(chan);
        }
        waveIdx = chan->wnum;
        if (chan->bank != NULL) {
            waveIdx = chan->bank->wmap[waveIdx];
        } else {
            waveIdx = chan->b78->wmap[waveIdx];
        }
        if (!chan->cD7) {
            chan->wave = waveTab->waves[waveIdx];
            if (chan->playing && chan->cA0) {
                chan->cA0 = 0;
                alSynSetVol(D_8017B4A0, D_8017B208 + voice * 28, 0, D_8017B218);
            } else {
                func_8008E644(chan, voice);
            }
        }
        pitch = (f32) noteNum + waveTab->detune[waveIdx];
        chan->freq = pitch;
        byte = chan->cB9 * (1 - chan->cBA);
        chan->freq = pitch + ((byte & 0x80) ? byte - 0x100 : byte);
        fxLevel = chan->cCA;
        if (fxLevel != chan->cCC) {
            chan->cCC = fxLevel;
            alSynSetFXMix(D_8017B4A0, D_8017B208 + voice * 28, chan->cCB + (((0x80 - chan->cCB) * fxLevel) >> 7));
        }
        } else {
            if (chan->cC3 < 4) {
                chan->cC3 = 4;
                chan->cC5 = 1;
                chan->c54 = chan->c0C;
                chan->cCD = chan->cC4;
            }
        }

    } else {
        if (chan->playing) {
            chan->playing = 0;
            alSynSetVol(D_8017B4A0, D_8017B208 + voice * 28, 0, D_8017B218);
            alSynStopVoice(D_8017B4A0, D_8017B208 + voice * 28);
        }
    }
}
