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
extern ALSynX *gFxSynth;
extern ALDelayX *gFxDelayLines[];
extern s16 *gFxSampleBuffers[];
extern s32 D_8017B278[];
void alFxFillDecay(void *);
/* Loads the delay-line FX parameter block into the synth's FX state, clears the sample buffer and sets up each section's resampler and lowpass filter. */
void setDelayFxParams(s32 *params) {
    ALFxX *fx;
    u16 i, pi;
    ALDelayX *line;
    ALFxIn *fxIn;

    fx = gFxSynth->fx;
    fx->section_count = params[0];
    fx->length = params[1];
    fx->delay = gFxDelayLines[0];
    fx->input = fx->base = gFxSampleBuffers[0];
    fxIn = (ALFxIn *)((u8 *)fx + 0x20);
    pi = 2;
    for (i = 0; i < fxIn->length; i++) {
        fxIn->base[i] = 0;
    }
    for (i = 0; i < fxIn->section_count; i++) {
        line = &fxIn->delay[i];
        line->input = params[pi++];
        line->output = params[pi++];
        line->fbcoef = params[pi++];
        line->ffcoef = params[pi++];
        line->gain = params[pi++];
        if (params[pi]) {
            line->rsinc = ((f32)params[pi++] / D_80009DA0) * 2.0 / gFxSynth->outputRate;
            line->rsgain = ((f32)params[pi++] / D_80009DA8) * (u32)(line->output - line->input);
            line->rsval = D_80009DB8;
            line->rsdelta = 0;
            line->rs = (void *)D_8017B278[0];
            ((ALResX *)line->rs)->state = D_8017B278[1];
            ((ALResX *)line->rs)->delta = 0;
            ((ALResX *)line->rs)->first = 1;
        } else {
            line->rs = 0;
            pi += 2;
        }
        if (params[pi]) {
            line->lp = (void *)D_8017B278[2];
            ((ALLpX *)line->lp)->fstate = D_8017B278[3];
            ((ALLpX *)line->lp)->fc = params[pi++];
            alFxFillDecay(line->lp);
        } else {
            line->lp = 0;
            pi++;
        }
    }
}
