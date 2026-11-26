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

extern s32 gCamSpeedScale;

void func_80017160(void *arg0) {
    s32 temp_v1;
    s32 temp_v0;
    (*(s32 *)((s8 *)arg0 + 0x18)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x18)) + 0x4B4);
    (*(s32 *)((s8 *)arg0 + 0x80)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x80)) + 0xA);
    (*(s32 *)((s8 *)arg0 + 0x10)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x10)) + 0x1000);
    temp_v1 = (*(s32 *)((s8 *)arg0 + 0x5C)) - (gCamSpeedScale * 4);
    (*(s32 *)((s8 *)arg0 + 0x5C)) = temp_v1;
    if (temp_v1 <= 0) {
        (*(s32 (**)())((s8 *)arg0 + 0xA0))();
    }
}
