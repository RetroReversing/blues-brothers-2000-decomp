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

void *func_80023874(M2C_UNK, void *);               /* extern */
extern void *D_800BD06C;
extern M2C_UNK func_8000F670;

void func_8001B588(void) {
    s32 temp_v1;
    s32 var_s1;
    s32 var_s1_1;
    void *temp_s0;
    void *var_a1;

    temp_s0 = D_800BD06C;
    var_a1 = NULL;
    var_s1 = -1;
loop_1:
    var_a1 = func_80023874(0x816, var_a1);
    if (var_a1 != NULL) {
        temp_v1 = M2C_FIELD(var_a1, s32 *, 0x78);
        if (temp_v1 >= var_s1) {
            M2C_FIELD(temp_s0, f32 *, 4) = (f32) M2C_FIELD(var_a1, f32 *, 4);
            M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(var_a1, f32 *, 8);
            var_s1 = temp_v1;
            M2C_FIELD(temp_s0, f32 *, 0xC) = (f32) M2C_FIELD(var_a1, f32 *, 0xC);
        }
        goto loop_1;
    }
    for (;;) {
        var_a1 = func_80023874(0x13C, var_a1);
        if (var_a1 == NULL) {
            break;
        }
        if (M2C_FIELD(var_a1, s32 *, 0x78) >= var_s1) {
            M2C_FIELD(var_a1, M2C_UNK **, 0x9C) = &func_8000F670;
            var_s1 = M2C_FIELD(var_a1, s32 *, 0x78);
            M2C_FIELD(temp_s0, f32 *, 4) = (f32) M2C_FIELD(var_a1, f32 *, 4);
            M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(var_a1, f32 *, 8);
            M2C_FIELD(temp_s0, f32 *, 12) = (f32) M2C_FIELD(var_a1, f32 *, 12);
        }
    }
}
