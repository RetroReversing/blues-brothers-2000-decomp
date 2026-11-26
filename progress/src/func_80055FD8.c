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

s32 func_800113D8(M2C_UNK);                         /* extern */
s32 func_80023874(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80023DBC(M2C_UNK);                         /* extern */
f32 func_8002D858(void *, void *);                  /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
M2C_UNK func_80052B24(s32, M2C_UNK *, void *);      /* extern */
s32 func_80076080();                                /* extern */
extern M2C_UNK D_80008354;
extern M2C_UNK D_80008360;
extern M2C_UNK D_8000836C;
extern f32 D_80008378;
extern M2C_UNK func_8003D558;

void func_80055FD8(void *arg0) {
    f32 temp_fs0;
    s32 temp_s1;
    s32 var_v0;

    if (func_80076080() == 0) {
        func_8004303C(arg0);
        temp_fs0 = func_8002D858(arg0, arg0 + 0x10);
        temp_s1 = func_80023DBC(0xE87);
        if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
            if (temp_fs0 < D_80008378) {
                func_80052A5C(0x56D);
                func_80052B24(temp_s1, &D_80008354, arg0);
                M2C_FIELD(arg0, s32 *, 0x7C) = 1;
            }
        }
        if ((M2C_FIELD(arg0, s32 *, 0x7C) == 1) && (func_80023874(0x801, 0) == 0)) {
            if (func_800113D8(2) != 0) {
                func_80052B24(temp_s1, &D_80008360, arg0);
                var_v0 = 2;
            } else {
                func_80052B24(temp_s1, &D_8000836C, arg0);
                var_v0 = 3;
            }
            M2C_FIELD(arg0, s32 *, 0x7C) = var_v0;
        }
        if (M2C_FIELD(arg0, s32 *, 0x7C) == 2) {
            if (func_80023874(0x801, 0) == 0) {
                M2C_FIELD(arg0, s32 *, 0x7C) = 4;
            }
        }
        if ((M2C_FIELD(arg0, s32 *, 0x7C) == 3) && (func_80023874(0x801, 0) == 0)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003D558;
            func_8002E7B8(1, 0);
            M2C_FIELD(arg0, s32 *, 0x70) = 2;
        }
    }
}
