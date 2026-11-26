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

s32 func_80023B2C(s32);                             /* extern */
s32 func_8003EAB4(void *, s32);                 /* extern */
s32 animSampleKeys(void *, f32);                 /* extern */

void func_80043418(void *arg0, s32 arg1, s32 arg2) {
    f32 temp_fs0;
    f32 temp_fs1;
    s32 temp_a1;
    void *temp_s0;

    temp_a1 = func_80023B2C(arg1);
    temp_s0 = (*(void **)((s8 *)arg0 + 0xE0));
    if (temp_s0 == NULL) {
        (*(s32 *)((s8 *)arg0 + 0xD0)) = arg1;
        return;
    }
    if (arg1 != (*(s32 *)((s8 *)arg0 + 0xD0))) {
        (*(s32 *)((s8 *)arg0 + 0xD4)) = arg2;
        temp_fs0 = (*(f32 *)((s8 *)temp_s0 + 0x1C));
        func_8003EAB4(temp_s0, temp_a1);
        animSampleKeys(temp_s0, temp_fs0);
        temp_fs1 = (*(f32 *)((s8 *)temp_s0 + 0x1C));
        (*(s32 *)((s8 *)arg0 + 0xD0)) = arg1;
        (*(f32 *)((s8 *)arg0 + 0xDC)) = temp_fs1;
    }
}
