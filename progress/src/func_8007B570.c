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

s32 func_80023874(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D260(s32);                             /* extern */
s32 func_8003C140(D_800BD06C);                      /* extern */
extern void *D_800B3960;
extern void *D_800BD06C;
extern M2C_UNK func_8006495C;

void func_8007B570(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x7C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        break;
    case 1:
        if (func_80023874(0x11E, 0) != 0) {
            if (M2C_FIELD(D_800BD06C, s32 *, 0) == 3) {
                M2C_FIELD(D_800B3960, M2C_UNK **, 0x9C) = &func_8006495C;
                M2C_FIELD(D_800B3960, s32 *, 0xA8) = 0;
                M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
            }
        }
        break;
    case 3:
        if (M2C_FIELD(D_800BD06C, s32 *, 0) == temp_v1) {
            M2C_FIELD(arg0, s32 *, 0x7C) = 2;
        }
        M2C_FIELD(D_800B3960, f32 *, 8) = (f32) (M2C_FIELD(D_800BD06C, f32 *, 8) + 250.0f);
        break;
    }
    if ((M2C_FIELD(D_800BD06C, f32 *, 4) < 150000.0f) && (M2C_FIELD(D_800BD06C, f32 *, 8) < -13000.0f) && (M2C_FIELD(D_800BD06C, s32 *, 0) == 3)) {
        func_8003C140(D_800BD06C);
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
    }
    if (((M2C_FIELD(D_800BD06C, f32 *, 8) < -35000.0f) || (func_8002D260(M2C_FIELD(D_800B3960, s32 *, 0x14)) < -0x2CEC)) && (M2C_FIELD(D_800BD06C, s32 *, 0) == 3)) {
        func_8003C140(D_800BD06C);
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
    }
}
