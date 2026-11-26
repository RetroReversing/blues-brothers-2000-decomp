/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s16 sins(s32);                                      /* extern */
extern s32 D_800B9EA4;

typedef struct { unsigned char pad_0[16]; int field_10; unsigned char pad_14[4]; int field_18; unsigned char pad_1C[96]; int field_7C; } __repair_record_arg0;
void func_8006D950(void *arg0) {
    ((__repair_record_arg0*)arg0)->field_10 = (s32) ((s32) (sins((D_800B9EA4 * 0xC8) & 0xFFF8) * 0x1F) >> 7);
    ((__repair_record_arg0*)arg0)->field_18 = (s32) ((s32) (sins((D_800B9EA4 * 0x190) & 0xFFF0) * 0x1FC1) >> 0xF);
    if (((__repair_record_arg0*)arg0)->field_7C == 0) {
        ((__repair_record_arg0*)arg0)->field_10 = (s32) (((__repair_record_arg0*)arg0)->field_10 + 0x8000);
    }
}
