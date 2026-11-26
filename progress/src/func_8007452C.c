typedef struct G G;
struct G {
    u8 p0[8]; f32 f8; u8 p1[0x58]; s32 f64; s32 f68; s32 f6C; u8 p2[0x2C]; void *f9C; u8 p3[0x20]; s32 fC0;
};
typedef struct H { u8 p0[0x88]; s32 f88; } H;
extern void func_8002A360(s32, s32);
extern void func_80074490(void);
extern H *D_800B3964;

void func_8007452C(G *arg0) {
    if (arg0->fC0 == 0) {
        arg0->f8 = arg0->f8 - 150.0f;
        if (arg0->f8 < 900.0f) {
            if (arg0->f6C == 0) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0xAE);
                D_800B3964->f88 = 1;
                arg0->f6C = 1;
            }
        }
        if (arg0->f8 < 700.0f) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xB9);
            arg0->f64 = 0x96;
            arg0->f9C = func_80074490;
            arg0->f68 = -1;
        }
    }
}
