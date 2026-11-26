typedef struct Src { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; } Src;
typedef struct Dst { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; } Dst;
typedef struct Hdr { u8 p0[0x14]; Src *f14; u8 p1[0xC]; f32 f24; } Hdr;
typedef struct Obj {
    u8 p0[0xC]; s32 fC; Hdr *f10; u8 p1[4]; s32 f18; u8 p2[0x14]; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; u8 p3[4]; Dst *f48;
} Obj;

void func_8003F2A4(Obj *arg0) {
    s32 i;

    arg0->f40 = 0;
    arg0->f30 = arg0->f38;
    arg0->f34 = arg0->f3C;
    for (i = 0; i < arg0->f18; i++) {
        arg0->f48[i].f18 = (s32) (arg0->f10->f14[i].f10 * arg0->f10->f24);
        arg0->f48[i].f1C = (s32) (arg0->f10->f14[i].f14 * arg0->f10->f24);
        arg0->f48[i].f20 = (s32) (arg0->f10->f14[i].f18 * arg0->f10->f24);
        arg0->f48[i].fC = (s32) ((f64) (arg0->f10->f14[i].f1C * (f32) (1 << arg0->fC)) / 6.283185307179586);
        arg0->f48[i].f10 = (s32) ((f64) (arg0->f10->f14[i].f20 * (f32) (1 << arg0->fC)) / 6.283185307179586);
        arg0->f48[i].f14 = (s32) ((f64) (arg0->f10->f14[i].f24 * (f32) (1 << arg0->fC)) / 6.283185307179586);
        arg0->f48[i].f0 = 0;
        arg0->f48[i].f4 = 0;
        arg0->f48[i].f8 = 0;
    }
}
