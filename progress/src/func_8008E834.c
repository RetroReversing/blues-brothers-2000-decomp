typedef struct Snd8E834 {
    u8 pad0[0x24];
    f32 f24;
    f32 f28;
    f32 f2C;
    u8 pad30[0x4C - 0x30];
    f32 f4C;
    f32 f50;
    u8 pad54[0xAA - 0x54];
    u16 fAA;
    u8 padAC[0xB8 - 0xAC];
    u8 fB8;
    u8 padB9[2];
    u8 fBB;
} Snd8E834;
typedef struct Voice8E834 {
    u8 pad[0x1C];
} Voice8E834;
f32 func_8008EEF0(f32);
void alSynSetPitch(void *, void *, f32);
extern f64 D_80009CE8;
extern f64 D_80009CF0;
extern f32 D_80009CF8;
extern Voice8E834 *D_8017B208;
extern char D_8017B4A0[];

void func_8008E834(Snd8E834 *p, s32 idx, f32 arg2) {
    f32 v;
    f32 r;
    u8 n;

    v = p->f2C;
    n = p->fB8;
    if (n != 0) {
        if (p->fB8 >= p->fAA) {
            v = p->f4C + (v - p->f4C) / (s32)n * (s32)p->fAA;
        }
        p->f50 = v;
    }
    v += arg2 + p->f24;
    if (v != p->f28) {
        p->f28 = v;
        v = func_8008EEF0(v * D_80009CE8);
        if (v > D_80009CF0) {
            v = D_80009CF8;
            p->fBB = 0;
        }
        alSynSetPitch(D_8017B4A0, &D_8017B208[idx], v);
    }
}
