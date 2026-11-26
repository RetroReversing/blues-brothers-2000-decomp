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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_800232B4(s32, s32, s32, s32);
void func_80026C04(void *, s32, s32);
void actorSetAnim(s32, s32, s32);
extern s32 D_800B87EC;
extern s32 gComboBeat;
extern s32 D_801719A8;
extern s32 D_801719AC;
extern s32 gComboSlots[];
extern s32 func_80081CF8;
extern s32 func_800820E8;
extern s32 func_80082990;

void func_80082BE0(void *arg0) {
    void *t;

    if (D_800B87EC != 0) {
        gComboBeat = 0x24;
        actorSetAnim(D_801719A8, 0x17B, 0x100);
        actorSetAnim(D_801719AC, 0x18B, 0x100);
        *(s32 **)((s8 *)arg0 + 0x9C) = &func_80082990;
        func_80026C04(gComboSlots, 0, 0x50);
        t = func_800232B4(0x141, 0xA, 0x28, 0);
        *(s32 **)((s8 *)t + 0x98) = &func_800820E8;
        *(s32 *)((s8 *)t + 0x70) = 0;
        *(s32 *)((s8 *)t + 0x68) = 0xD;
        t = func_800232B4(0x141, 0x8C, 0x28, 0);
        *(s32 **)((s8 *)t + 0x98) = &func_800820E8;
        *(s32 *)((s8 *)t + 0x70) = 1;
        *(s32 *)((s8 *)t + 0x68) = 0xD;
        t = func_800232B4(0x141, 0, 0, 0);
        *(s32 **)((s8 *)t + 0x98) = &func_80081CF8;
        *(s32 *)((s8 *)t + 0x68) = 0xD;
        gComboSlots[2] = 5;
        gComboSlots[12] = 5;
    }
}
