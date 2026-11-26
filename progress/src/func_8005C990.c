/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_80013654(s32);                             /* extern */
s32 func_80013784(s32);                             /* extern */
s32 func_800137E0(s32, s32);                        /* extern */
s32 func_800137F8(s32);                             /* extern */
s32 func_80083920(void *, s32);                     /* extern */
extern s32 D_800BD06C;
extern s32 D_8014AB00;

s32 func_8005C990(void *arg0) {
    
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a1;

    M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD_PTR(arg0, const s32 *, 0xC0) & 0x41);
    if (D_8014AB00 < 0xD2) {
        temp_v0_2 = func_80013654(D_800BD06C);
        if (temp_v0_2 != 0) {
            temp_v1 = M2C_FIELD(arg0, const s32 *, 0xC0);
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (temp_v1 | 2);
            if (temp_v0_2 == 2) {
                M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (temp_v1 | 0x82);
            }
        }
        if (func_800137E0(D_800BD06C, temp_v0_2) != 0) {
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD(arg0, const s32 *, 0xC0) | 8);
        }
        if (func_80013784(D_800BD06C) != 0) {
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD(arg0, const s32 *, 0xC0) | 4);
        }
        if (func_800137F8(D_800BD06C) != 0) {
            M2C_FIELD(arg0, s32 *, 0xC0) = (s32) (M2C_FIELD(arg0, const s32 *, 0xC0) | 0x12);
        }
    }
    var_a1 = 0;
    if (M2C_FIELD(arg0, const s32 *, 0x90) == 3) {
        var_a1 = M2C_FIELD(arg0, const s32 *, 0x8C) == 4;
    }
    temp_v0_2 = func_80083920(arg0, var_a1);
    if (temp_v0_2 != 0) {
        M2C_FIELD(arg0, s32 *, 0xF0) = 0xC0;
    }
    return temp_v0_2;
}
