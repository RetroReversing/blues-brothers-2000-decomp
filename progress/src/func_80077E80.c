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

s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8003BF98(void *);                      /* extern */
s32 func_8003C9AC(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
s32 func_80076080();                                /* extern */
s16 sins(s32);                                      /* extern */
extern f32 D_8000930C;
extern s32 D_800B9EA4;
extern f32 D_801700D0;

void func_80077E80(void *arg0) {
    f32 temp_fs0;

    if (func_80076080() == 0) {
        temp_fs0 = D_801700D0;
        M2C_FIELD(arg0, s32 *, 0x18) = (s32) ((s32) (sins((D_800B9EA4 * 0xFA) & 0xFFFE) * 7) >> 3);
        func_8004303C(arg0);
        if ((temp_fs0 < 500.0f) && (func_8003C9AC(arg0, 1, 0, 0) != 0) && (func_8002D5CC(arg0) != 0)) {
            M2C_FIELD(arg0, s32 *, 0x64) = 0x64;
            func_8003BF98(arg0);
        }
    }
}
