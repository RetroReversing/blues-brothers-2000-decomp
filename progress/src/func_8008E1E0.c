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

void func_8008E1E0(Chan1E0 *cp, s32 x) {
    u8 *ptr;
    s32 note;
    s32 w;
    u8 v;
    s32 m;
    s32 t;
    u8 c;
    Wave1E0 *wt;
    u16 *map;
    f32 f;

    ptr = cp->pdata;
    if (ptr != NULL) {
    loop:
        v = *ptr;
        if (v > 127) {
            ptr = D_800BA650[v & 0x7F](cp, ptr + 1);
            if (ptr != NULL) {
                goto loop;
            }
        }
    }
    cp->pdata = ptr;
    if (ptr != NULL) {
        cp->oldf = cp->basef;
        note = *cp->pdata++;
        if (cp->velon) {
            cp->vel = *cp->pdata++;
            if (cp->vel > 127) {
                cp->vel &= 0x7F;
                cp->velon = 0;
                cp->defvel = cp->vel;
            }
        } else {
            cp->vel = cp->defvel;
        }
        if (cp->fixlen) {
            if (cp->cB7) {
                cp->cB7 = 0;
                v = *cp->pdata++;
                if (v < 128) {
                    cp->length = v;
                } else {
                    cp->length = ((v & 0x7F) << 8) + *cp->pdata++;
                }
            } else {
                cp->length = cp->fixlen;
            }
        } else {
            v = *cp->pdata++;
            if (v < 128) {
                cp->length = v;
            } else {
                cp->length = ((v & 0x7F) << 8) + *cp->pdata++;
            }
        }
        cp->last = cp->end;
        cp->cAA = 0;
        cp->cD1 = 0;
        cp->end += cp->length << 8;
        cp->cD0 = cp->cCF;
        if (cp->bank != NULL && cp->drums == NULL && cp->bank->wmap[cp->wnum] == 0xFFFF) {
            note = 0x60;
        }
        if (note != 0x60) {
        wt = cp->wtab;
        if (cp->drums != NULL) {
            cp->wnum = cp->drums[note].wave;
            cp->cBD = cp->drums[note].pan >> 1;
            func_8008C3FC(cp, cp->bank->env + cp->drums[note].env * 7);
            note = cp->drums[note].note;
        }
        if (!cp->cD6) {
            func_8008E93C(cp);
        }
        if (cp->cD4) {
            func_8008EB8C(cp);
        }
        w = cp->wnum;
        if (cp->bank != NULL) {
            w = cp->bank->wmap[w];
        } else {
            w = cp->b78->wmap[w];
        }
        if (!cp->cD7) {
            cp->wave = wt->waves[w];
            if (cp->playing && cp->cA0) {
                cp->cA0 = 0;
                alSynSetVol(D_8017B4A0, D_8017B208 + x * 28, 0, D_8017B218);
            } else {
                func_8008E644(cp, x);
            }
        }
        f = (f32) note + wt->detune[w];
        cp->freq = f;
        v = cp->cB9 * (1 - cp->cBA);
        cp->freq = f + ((v & 0x80) ? v - 0x100 : v);
        c = cp->cCA;
        if (c != cp->cCC) {
            cp->cCC = c;
            alSynSetFXMix(D_8017B4A0, D_8017B208 + x * 28, cp->cCB + (((0x80 - cp->cCB) * c) >> 7));
        }
        } else {
            if (cp->cC3 < 4) {
                cp->cC3 = 4;
                cp->cC5 = 1;
                cp->c54 = cp->c0C;
                cp->cCD = cp->cC4;
            }
        }

    } else {
        if (cp->playing) {
            cp->playing = 0;
            alSynSetVol(D_8017B4A0, D_8017B208 + x * 28, 0, D_8017B218);
            alSynStopVoice(D_8017B4A0, D_8017B208 + x * 28);
        }
    }
}
