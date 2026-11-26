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

void *func_80042F00();
s32 actorSetAnim();
s32 func_80050460();
s32 func_80076BF0(s32);
s32 func_80085244();
s32 func_800852CC();
extern s32 D_800BD0E0;
extern s32 D_8014AA38;
extern s32 func_80056C30;

void *func_80056CC0(s32 arg0) {
    void *temp_v0;
    void *base;

    base = &D_800BD0E0;
    if (((*(s32 *)((s8 *)base + 0x20)) == 0) && ((*(s32 *)((s8 *)base + 0x1C)) >= 6)) {
        func_80076BF0(arg0);
        return;
    }
    func_80050460(&func_80056C30, &D_8014AA38);
    temp_v0 = func_80042F00(0x24, 0, 0, 0);
    actorSetAnim(temp_v0, 0xD1, 0x100);
    func_800852CC(temp_v0, arg0);
    func_80085244(temp_v0, arg0);
    (*(s32 *)((s8 *)temp_v0 + 0)) = 0x1007;
    (*(s32 *)((s8 *)temp_v0 + 0x74)) = 0xD0;
    return temp_v0;
}



