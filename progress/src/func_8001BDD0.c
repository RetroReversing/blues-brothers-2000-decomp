/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
extern f32 D_80000C70;
extern f32 D_80000C74;

void func_8001BDD0(void *arg0) {
    f32 temp_ft0;
    f32 temp_fv1;

    if (func_8001B990(0x100, 0xB) != 0) {
        temp_fv1 = M2C_FIELD(arg0, f32 *, 8) - D_80000C70;
        temp_ft0 = M2C_FIELD(arg0, f32 *, 0x44) - D_80000C74;
        M2C_FIELD(arg0, f32 *, 8) = temp_fv1;
        if (temp_fv1 < temp_ft0) {
            M2C_FIELD(arg0, f32 *, 8) = temp_ft0;
        }
    }
}
