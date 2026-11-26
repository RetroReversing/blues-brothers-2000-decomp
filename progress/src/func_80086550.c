/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_80023DBC();
s32 sendCommand();
s32 tickActorTimer();
s32 actorSetAnim();
s32 startStoryDialog();
s32 func_80082400();
s32 sprintf();
extern char D_80009B4C[];
extern char D_800B8720[];
extern s32 gComboActorA;
extern void *D_80171A30;
extern s32 func_800864B8;

void func_80086550(void *arg0) {
    u8 *__base_D_800B8720;
    s32 __index_D_800B8720;
    char sp10[0x20];
    s32 temp_s0;
    s32 temp_s1;

    __base_D_800B8720 = 0;

    temp_s0 = func_80082400();
    temp_s1 = func_80023DBC(0xE33);
    if (tickActorTimer(arg0) != 0) {
        loop_goto_1:
        {
 __base_D_800B8720 = D_800B8720;
 __index_D_800B8720 = temp_s0 * 0x14;
 sprintf(sp10, D_80009B4C, M2C_FIELD((__base_D_800B8720 + __index_D_800B8720), s32 *, 8));
        }
        if (0)
        {
            goto loop_goto_1;
        }
        startStoryDialog(temp_s1, sp10, arg0);
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_800864B8;
        actorSetAnim(gComboActorA, 0x178, 0x100);
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x78);
        M2C_FIELD_PTR(arg0, s32 *, 0x64) = 0x12C;
        M2C_FIELD(D_80171A30, s32 *, 0x68) = -1;
    }
}
