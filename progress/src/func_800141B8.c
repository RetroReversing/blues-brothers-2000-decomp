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

void *func_800140D0();                              /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D4E0(void *, s32);                 /* extern */
extern f32 D_80000824;

typedef struct { unsigned char pad_0[8]; float field_8; unsigned char pad_C[4]; int field_10; int field_14; } __repair_record_temp_s0;
s32 func_800141B8(void) {
    void *temp_s0;

    temp_s0 = func_800140D0();
    ((__repair_record_temp_s0*)temp_s0)->field_14 = func_80024394(0x2EE0, 0x3FFC);
    ((__repair_record_temp_s0*)temp_s0)->field_10 = (s32) (func_80024394(1, 8) << 0xD);
    func_8002D4E0(temp_s0, func_80024394(0x3E8, 0x3EA));
    ((__repair_record_temp_s0*)temp_s0)->field_14 = 0;
    ((__repair_record_temp_s0*)temp_s0)->field_8 = (f32) (((__repair_record_temp_s0*)temp_s0)->field_8 + D_80000824);
    return (s32) temp_s0;
}
