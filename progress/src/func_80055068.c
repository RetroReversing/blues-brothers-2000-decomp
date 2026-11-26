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

s32 approachAngle(s32, s32, s32);                   /* extern */
s32 approachS32(M2C_UNK, s32, s32);               /* extern */
M2C_UNK func_8002D4E0(void *, M2C_UNK);             /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002D858(void *, s32 *);               /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
M2C_UNK func_80058F74(void *, M2C_UNK *);           /* extern */
extern s32 gCamSpeedScale;
extern M2C_UNK func_800548C0;

void func_80055068(void *arg0) {
    s32 sp10;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0xC8;
        M2C_FIELD(arg0, s32 *, 0x74) = 0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = -0xFA0;
        return;
    }
    func_8002D858(arg0, &sp10);
    M2C_FIELD(arg0, s32 *, 0x10) = approachAngle(sp10, M2C_FIELD(arg0, s32 *, 0x10), gCamSpeedScale << 8);
    func_8002D4E0(arg0, -0x3E8);
    func_8002DA80(arg0);
    animStepKeys(arg0);
    M2C_FIELD(arg0, s32 *, 0x5C) = approachS32(0x80, M2C_FIELD(arg0, s32 *, 0x5C), gCamSpeedScale * 2);
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
        func_80058F74(arg0, &func_800548C0);
    }
}
