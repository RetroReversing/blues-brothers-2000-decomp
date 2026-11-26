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

M2C_UNK func_80015C30(void *);                      /* extern */
M2C_UNK func_8004EB60(void *);                      /* extern */
void *func_800511B4(void *);                        /* extern */
void func_8000EA34(void *);

void func_8000EA6C(void *arg0) {
    s32 var_s0;
    s32 var_v1;
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x94);
        M2C_FIELD(arg0, s32 *, 0) = 0x129;
        if (var_v1 < 0) {
            var_v1 += 3;
        }
        M2C_FIELD(arg0, s32 *, 0x94) = (s32) (var_v1 >> 2);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) & 2) {
        temp_v0 = func_800511B4(arg0);
        M2C_FIELD(temp_v0, f32 *, 4) = M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8000EA34;
        M2C_FIELD(temp_v0, s32 *, 0) = 0x101;
        func_8004EB60(arg0);
        var_s0 = 0;
        do {
            do { func_80015C30(arg0); } while (0);
            do { var_s0 += 1; } while (0);
        } while (var_s0 < 4);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}

