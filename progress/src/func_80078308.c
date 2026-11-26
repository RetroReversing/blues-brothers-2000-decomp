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

void *func_80042F00();
s32 actorSetAnim();
s32 func_80050460();
s32 func_800852CC();
extern char D_800F4A00[];
extern char D_800F6188[];
extern char D_8014AA68[];
extern s32 func_80078008;
extern s32 func_80078048;

void *func_80078308(s32 arg0) {
    void *temp_v0;
    u8 *base;
    u8 *base2;
    s32 *t;
    s32 *t2;

    func_80050460(&func_80078008, (char *)D_8014AA68 + 2);
    temp_v0 = func_80042F00(0x58, 0, 0, 0);
    actorSetAnim(temp_v0, 0x11A, 0xC0);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_80078048;
    base = D_800F4A00;
    t = (s32 *)(base + M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC);
    t[2] = 0x6E;
    t[1] = 0x6E;
    t[0] = 0x6E;
    base2 = D_800F6188;
    t2 = (s32 *)(base2 + M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC);
    t2[2] = -0x6E;
    t2[1] = -0x6E;
    t2[0] = -0x6E;
    return temp_v0;
}
