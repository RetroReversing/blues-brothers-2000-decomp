typedef struct Hdr43248 {
    u16 f0;
    u16 f2;
} Hdr43248;
typedef struct Anim43248 {
    Hdr43248 *f0;
    u8 pad4[0x1C - 4];
    f32 f1C;
} Anim43248;
typedef struct O43248 {
    u8 pad0[0xD4];
    s32 fD4;
    u8 padD8[4];
    f32 fDC;
    Anim43248 *fE0;
} O43248;
void animSampleKeys(Anim43248 *, f32);
extern f32 D_800B9EC4;
extern s32 D_801402F8;

s32 func_80043248(O43248 *arg0) {
    Anim43248 *a;
    f32 frame;
    f32 last;
    f32 rate;
    s32 r;

    a = arg0->fE0;
    rate = arg0->fD4;
    if (a == NULL) {
        return 0;
    }
    frame = a->f1C;
    frame += (f32)((f32)(rate * 0.00390625) * D_800B9EC4 / 0.03);
    D_801402F8++;
    last = a->f0->f2 - 1;
    if (last < frame) {
        animSampleKeys(a, last);
        arg0->fDC = a->f1C;
        return 1;
    } else {
        animSampleKeys(a, frame);
        arg0->fDC = a->f1C;
        return 0;
    }
}
