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

M2C_UNK func_8002DCB4(void *);                      /* extern */

void func_8002DE20(void *arg0, void *arg1, void *arg2) {
    func_8002DCB4(arg1);
    func_8002DCB4(arg2);
    M2C_FIELD(arg0, f32 *, 0) = (f32) ((M2C_FIELD(arg1, f32 *, 0) * M2C_FIELD(arg2, f32 *, 0)) + (M2C_FIELD(arg1, f32 *, 4) * M2C_FIELD(arg2, f32 *, 0xC)) + (M2C_FIELD(arg1, f32 *, 8) * M2C_FIELD(arg2, f32 *, 0x18)));
    M2C_FIELD(arg0, f32 *, 4) = (f32) ((M2C_FIELD(arg1, f32 *, 0) * M2C_FIELD(arg2, f32 *, 4)) + (M2C_FIELD(arg1, f32 *, 4) * M2C_FIELD(arg2, f32 *, 0x10)) + (M2C_FIELD(arg1, f32 *, 8) * M2C_FIELD(arg2, f32 *, 0x1C)));
    M2C_FIELD(arg0, f32 *, 8) = (f32) ((M2C_FIELD(arg1, f32 *, 0) * M2C_FIELD(arg2, f32 *, 8)) + (M2C_FIELD(arg1, f32 *, 4) * M2C_FIELD(arg2, f32 *, 0x14)) + (M2C_FIELD(arg1, f32 *, 8) * M2C_FIELD(arg2, f32 *, 0x20)));
    M2C_FIELD(arg0, f32 *, 0xC) = (f32) ((M2C_FIELD(arg1, f32 *, 0xC) * M2C_FIELD(arg2, f32 *, 0)) + (M2C_FIELD(arg1, f32 *, 0x10) * M2C_FIELD(arg2, f32 *, 0xC)) + (M2C_FIELD(arg1, f32 *, 0x14) * M2C_FIELD(arg2, f32 *, 0x18)));
    M2C_FIELD(arg0, f32 *, 0x10) = (f32) ((M2C_FIELD(arg1, f32 *, 0xC) * M2C_FIELD(arg2, f32 *, 4)) + (M2C_FIELD(arg1, f32 *, 0x10) * M2C_FIELD(arg2, f32 *, 0x10)) + (M2C_FIELD(arg1, f32 *, 0x14) * M2C_FIELD(arg2, f32 *, 0x1C)));
    M2C_FIELD(arg0, f32 *, 0x14) = (f32) ((M2C_FIELD(arg1, f32 *, 0xC) * M2C_FIELD(arg2, f32 *, 8)) + (M2C_FIELD(arg1, f32 *, 0x10) * M2C_FIELD(arg2, f32 *, 0x14)) + (M2C_FIELD(arg1, f32 *, 0x14) * M2C_FIELD(arg2, f32 *, 0x20)));
    M2C_FIELD(arg0, f32 *, 0x18) = (f32) ((M2C_FIELD(arg1, f32 *, 0x18) * M2C_FIELD(arg2, f32 *, 0)) + (M2C_FIELD(arg1, f32 *, 0x1C) * M2C_FIELD(arg2, f32 *, 0xC)) + (M2C_FIELD(arg1, f32 *, 0x20) * M2C_FIELD(arg2, f32 *, 0x18)));
    M2C_FIELD(arg0, f32 *, 0x1C) = (f32) ((M2C_FIELD(arg1, f32 *, 0x18) * M2C_FIELD(arg2, f32 *, 4)) + (M2C_FIELD(arg1, f32 *, 0x1C) * M2C_FIELD(arg2, f32 *, 0x10)) + (M2C_FIELD(arg1, f32 *, 0x20) * M2C_FIELD(arg2, f32 *, 0x1C)));
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) ((M2C_FIELD(arg1, f32 *, 0x18) * M2C_FIELD(arg2, f32 *, 8)) + (M2C_FIELD(arg1, f32 *, 0x1C) * M2C_FIELD(arg2, f32 *, 0x14)) + (M2C_FIELD(arg1, f32 *, 0x20) * M2C_FIELD(arg2, f32 *, 0x20)));
}
