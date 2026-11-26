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

void *func_80023874(M2C_UNK, void *);               /* extern */
s32 func_80023D58();                  /* extern */
f32 func_8002DD60(f32);                             /* extern */
extern s32 D_8014AB34;
extern s32 D_8014AB40;
extern M2C_UNK D_8014AB58;
extern M2C_UNK func_80064F08;

void func_80064D94(void *arg0) {
f32 __repair_cmp_l; f32 __repair_cmp_r;

    s32 *__base_D_8014AB40;
    f32 temp_fs0;
    f32 temp_fv1;
    s32 temp_v1;
    void *var_s0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x7C);
    if (temp_v1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 4;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        __base_D_8014AB40 = &D_8014AB40;
        if ((*(&D_8014AB40)) == 0) {
            (*__base_D_8014AB40) = 1;
            D_8014AB34 = func_80023D58(0x19E);
            M2C_FIELD(&D_8014AB58, s32 *, 0) = func_80023D58(0x19D);
            M2C_FIELD(&D_8014AB58, s32 *, 4) = func_80023D58(0x19A);
            M2C_FIELD(&D_8014AB58, s32 *, 8) = func_80023D58(0x19B);
            M2C_FIELD(&D_8014AB58, s32 *, 0xC) = func_80023D58(0x19C);
        }
    } else if ((temp_v1 & 3) != 3) {
        var_s0 = func_80023874(0x11E, NULL);
        if (var_s0 != NULL) {
            temp_fs0 = 300.0f;
loop_6:
            if (func_8002DD60(M2C_FIELD(var_s0, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4)) < temp_fs0) {
                do { do { temp_fv1 = M2C_FIELD(var_s0, f32 *, 8); } while (0); } while (0);
                if (temp_fv1 < M2C_FIELD(arg0, f32 *, 8)) {
                    M2C_FIELD(arg0, s32 *, 0x8C) = (s32) temp_fv1;
                    M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) | 1);
                }
                __repair_cmp_r = M2C_FIELD(var_s0, f32 *, 8);
__repair_cmp_l = M2C_FIELD(arg0, f32 *, 8);
if (__repair_cmp_l < __repair_cmp_r) {
                    M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(var_s0, f32 *, 8);
                    M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) | 2);
                }
            }
            var_s0 = func_80023874(0x11E, var_s0);
            if (var_s0 != NULL) {
                goto loop_6;
            }
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80064F08;
    }
}

