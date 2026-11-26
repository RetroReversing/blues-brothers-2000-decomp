typedef struct { s32 pad0; s32 pad1; s32 pad2[2]; s32 pad3; s16 pad4; s16 pad5; s32 s0; } ALResamplerX;
typedef struct {
    s32 input;       /* 0x00 */
    s32 output;      /* 0x04 */
    s16 ffcoef;      /* 0x08 */
    s16 fbcoef;      /* 0x0A */
    s16 gain;        /* 0x0C */
    s16 pad0E;
    f32 rsinc;       /* 0x10 */
    f32 rsval;       /* 0x14 */
    s32 rsdelta;     /* 0x18 */
    f32 rsgain;      /* 0x1C */
    void *lp;        /* 0x20 */
    void *rs;        /* 0x24 */
} ALDelayX;
typedef struct {
    u8 pad[0x34];
    s16 *base;       /* 0x34 */
    s16 *input;      /* 0x38 */
    u32 length;      /* 0x3C */
    ALDelayX *delay; /* 0x40 */
    u8 section_count;/* 0x44 */
} ALFxX;
typedef struct {
    u8 pad[0x34];
    ALFxX *fx;       /* 0x34 */
    u8 pad2[0x44 - 0x38];
    s32 outputRate;  /* 0x44 */
} ALSynX;
typedef struct {
    u8 pad[0x14];
    s16 *base;
    s16 *input;
    u32 length;
    ALDelayX *delay;
    u8 section_count;
} ALFxIn;
typedef struct { s32 pad[5]; s32 state; s32 pad2[2]; s32 delta; s32 first; } ALResX;
typedef struct { s16 fc; s16 pad; s32 pad1[9]; s32 fstate; } ALLpX;
extern f32 D_80009DA0;
extern f64 D_80009DA8;
extern f64 D_80009DB0;
extern f32 D_80009DB8;
extern ALSynX *D_8017B260;
extern ALDelayX *D_8017B270[];
extern s16 *D_8017B274[];
extern s32 D_8017B278[];
void alFxFillDecay(void *);
void func_8008FEBC(s32 *param) {
    ALFxX *r;
    u16 i, k;
    ALDelayX *d;
    ALFxIn *q;

    r = D_8017B260->fx;
    r->section_count = param[0];
    r->length = param[1];
    r->delay = D_8017B270[0];
    r->input = r->base = D_8017B274[0];
    q = (ALFxIn *)((u8 *)r + 0x20);
    k = 2;
    for (i = 0; i < q->length; i++) {
        q->base[i] = 0;
    }
    for (i = 0; i < q->section_count; i++) {
        d = &q->delay[i];
        d->input = param[k++];
        d->output = param[k++];
        d->fbcoef = param[k++];
        d->ffcoef = param[k++];
        d->gain = param[k++];
        if (param[k]) {
            d->rsinc = ((f32)param[k++] / D_80009DA0) * 2.0 / D_8017B260->outputRate;
            d->rsgain = ((f32)param[k++] / D_80009DA8) * (u32)(d->output - d->input);
            d->rsval = D_80009DB8;
            d->rsdelta = 0;
            d->rs = (void *)D_8017B278[0];
            ((ALResX *)d->rs)->state = D_8017B278[1];
            ((ALResX *)d->rs)->delta = 0;
            ((ALResX *)d->rs)->first = 1;
        } else {
            d->rs = 0;
            k += 2;
        }
        if (param[k]) {
            d->lp = (void *)D_8017B278[2];
            ((ALLpX *)d->lp)->fstate = D_8017B278[3];
            ((ALLpX *)d->lp)->fc = param[k++];
            alFxFillDecay(d->lp);
        } else {
            d->lp = 0;
            k++;
        }
    }
}
