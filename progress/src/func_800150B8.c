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

s32 coss(s32);                                      /* extern */
M2C_UNK func_80014EF8(void *);                      /* extern */
M2C_UNK func_80014FDC(void *);                      /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
s32 tickActorTimer(void *);                          /* extern */
s32 sins(s32);                                      /* extern */
extern s32 gTextWaveTime;

void func_800150B8(void *arg0) {
    s32 temp_s0;

    temp_s0 = ((gTextWaveTime + M2C_FIELD(arg0, s32 *, 0x8C)) * 0x320) & 0xFFFF;
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (((s32) (coss(temp_s0) << 0x10) >> 0x1B) + 0x100);
    M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (((s32) (sins(temp_s0) << 0x10) >> 0x1B) + 0x100);
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (((s32) (sins(temp_s0) << 0x10) >> 0x1B) + 0x100);
    if (tickActorTimer(arg0) != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x39);
        func_80014FDC(arg0);
        func_80014EF8(arg0);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
