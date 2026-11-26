#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8002ADFC();
s32 func_8002D3E4();
s32 func_8002D5CC();
s32 func_8002D620();
f32 func_8002D858();
s32 func_8002DA80();
s32 func_8004303C();
s32 func_8007DFAC();
extern f32 D_80009610;
extern f32 D_80009614;
extern f32 D_80009618;
extern f32 D_8000961C;
extern f32 D_80009620;

s32 func_8007E3A0(void *arg0) {
    f32 x;

    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        M2C_FIELD(arg0, s32 *, 0x88) = 1;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x3E8;
    }
    func_8004303C(arg0);
    func_8004303C(M2C_FIELD(arg0, void **, 0xA8));
    func_8002D620(arg0);
    func_8002D3E4(arg0, 0x2EE);
    func_8002DA80(arg0);
    func_8007DFAC(arg0);
    x = M2C_FIELD(arg0, f32 *, 0xDC);
    if (((2.0f <= x) && (x < 4.0f)) || ((18.0f <= x) && (x < 20.0f))) {
        func_8002ADFC(0xD9, 0x1770, arg0);
    }
    if (func_8002D5CC(arg0) != 0) {
        return 1;
    }
    if (func_8002D858(arg0, 0) < 1500.0f) {
        return 2;
    }
    return 0;
}
