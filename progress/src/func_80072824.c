typedef struct Vec { f32 x; f32 y; f32 z; } Vec;
typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    s32 f0; Vec pos; s32 f10; u8 p0[0x2C]; f32 f40; u8 p1[4]; f32 f48; f32 f4C; u8 p2[4]; f32 f54; u8 p3[0xC]; s32 f64;
    u8 p4[8]; s32 f70; u8 p5[8]; s32 f7C; u8 p6[0x1C]; Fn f9C; u8 p7[0xC]; f32 fAC; u8 p8[4]; s32 fB4; u8 p9[0x20]; Fn fD8;
    f32 fDC; u8 pa[0x18]; s32 fF8; u8 pb[0xD0];
};
extern s32 func_80080DE0(s32);
extern void func_80081588(s32, s32);
extern s32 func_80081990(Vec *, s32, f32);
extern void func_80081AC0(Vec *, s32, s32);
extern s32 func_8002492C(f32, f32);
extern void func_8002D620(G *);
extern void func_800768E8(G *);
extern void func_800134F0(G *);
extern void func_80013550(G *);
typedef struct D6 { u8 p0[0xD0]; s32 fD0; } D6;
extern D6 *D_800BD06C;

void func_80072824(G *arg0) {
    Vec sp;
    Fn temp_v1;
    f32 temp_fv0;

    if (arg0->f7C == 0) {
        if (arg0->f0 == 0x102) {
            arg0->f0 = 0x10E;
        }
        arg0->f7C = 1;
        arg0->fF8 = arg0->fF8 | 8;
        if (func_80080DE0(arg0->f70) == 0) {
            func_80081588(arg0->f70, 0);
        }
        arg0->fDC = 0.0f;
        arg0->fAC = 0.05f;
    }
    temp_fv0 = arg0->fDC + arg0->fAC;
    arg0->fDC = temp_fv0;
    if (func_80081990(&arg0->pos, arg0->f70, temp_fv0) != 0) {
        if (arg0->fDC <= 0.0f) {
            arg0->fAC = 0.05f;
        } else {
            arg0->fAC = -0.05f;
        }
        temp_v1 = arg0->f9C;
        arg0->f9C = func_800768E8;
        arg0->f64 = 0x12C;
        arg0->fD8 = temp_v1;
        if (arg0->f0 == 0x10E) {
            arg0->f4C = 0.0f;
            arg0->f54 = 0.0f;
            func_8002D620(arg0);
            func_800134F0(arg0);
            func_80013550(arg0);
        }
    } else {
        func_80081AC0(&sp, arg0->f70, arg0->fB4);
        arg0->f10 = func_8002492C(sp.x, sp.z);
        if (arg0->f0 == 0x10E) {
            arg0->f4C = arg0->pos.x - arg0->f40;
            arg0->f54 = arg0->pos.z - arg0->f48;
            func_8002D620(arg0);
            if (D_800BD06C->fD0 != 5) {
                func_800134F0(arg0);
            }
            func_80013550(arg0);
        }
    }
}
