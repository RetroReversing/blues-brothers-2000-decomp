/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8002A360(s32, s32);            /* extern */
s32 func_80030C40(void *, s32);             /* extern */
extern s32 D_800B3968;
extern s32 D_800B9EA0;
extern u32 D_801070A0;
extern s32 func_80023078;
extern s32 func_80031DF4;

void func_80030D6C(void *arg0) {
    s32 var_a0;
    s32 temp_v1;
    u32 temp2;

    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
        M2C_FIELD(arg0, s32 *, 0xBC) = 1;
    }
    M2C_FIELD(arg0, s32 **, 0x98) = &func_80031DF4;
    if (D_800B3968 != 0) {
        var_a0 = (u32) D_801070A0 >> 0xC;
        var_a0 &= 1;
    } else if (M2C_FIELD(arg0, s32 *, 0xBC) == 0) {
        temp2 = D_801070A0 & 0x1000;
        var_a0 = temp2 != 0;
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x64) + D_800B9EA0;
    M2C_FIELD(arg0, s32 *, 0x64) = temp_v1;
    if ((temp_v1 >= 0xBB9) || (var_a0 != 0)) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x9F);
        M2C_FIELD(arg0, s32 **, 0x98) = (s32 *) ((s8 *) &func_80023078 + 8);
        D_801070A0 = 0;
        func_80030C40(arg0, 1);
    }
}
