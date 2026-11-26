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

extern s32 D_8017B204;
extern void *D_8017B20C;

typedef struct { int field_0; unsigned char pad_4[64]; int field_44; } __repair_record_var_v1;
void func_8008F944(s32 arg0, s32 arg1, s32 arg2) {
    u8 __repair_frame[8];
    s32 var_a3;
    void *var_v1;

    var_v1 = D_8017B20C;
    var_a3 = 0;
    if (D_8017B204 > 0) {
        do {
            var_a3 += 1;
            if (((__repair_record_var_v1*)var_v1)->field_44 == arg0) {
                ((__repair_record_var_v1*)var_v1)->field_0 = (s32) ((((__repair_record_var_v1*)var_v1)->field_0 & arg1) | arg2);
            }
            var_v1 += 0x13C;
        } while (var_a3 < D_8017B204);
    }
}
