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

s32 debugPrintf();
extern char D_80007BE4[];
extern s32 D_800B7690;
extern char D_801407C8[];

typedef struct { int field_0; signed char field_4; } __repair_record_temp_v1;
void func_80048534(s32 arg0) {
    void *temp_v1;

    if (D_800B7690 >= 0x100) {
        debugPrintf(D_80007BE4);
    }
    temp_v1 = (D_800B7690 * 8) + D_801407C8;
    ((__repair_record_temp_v1*)temp_v1)->field_4 = 1;
    ((__repair_record_temp_v1*)temp_v1)->field_0 = arg0;
    D_800B7690 += 1;
}
