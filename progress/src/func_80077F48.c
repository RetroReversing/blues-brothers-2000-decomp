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

s32 randomRange(s32, s32);                /* extern */
s32 animSampleKeys(s32, f32);                    /* extern */
void *func_80042F00(s32, s32, s32, s32); /* extern */
s32 actorSetAnim(void *, s32, s32);        /* extern */
s32 func_80050460(s32 *, void *);           /* extern */
s32 func_800852CC(void *, s32);                 /* extern */
extern s32 D_8014AA38;
extern s32 func_80077E50;
extern s32 func_80077E80;

s32 func_80077F48(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;

    func_80050460(&func_80077E50, (char *)&D_8014AA38 + 2);
    temp_s0 = func_80042F00(0x1C, 0, 0, 0);
    actorSetAnim(temp_s0, 0xA1, randomRange(0xE0, 0x120));
    temp_s1 = (*(s32 *)((s8 *)temp_s0 + 0xE0));
    animSampleKeys(temp_s1, (f32) randomRange(0, 0xA));
    (*(s32 *)((s8 *)temp_s0 + 0)) = 0x101B;
    func_800852CC(temp_s0, arg0);
    (*(s32 **)((s8 *)temp_s0 + 0x9C)) = &func_80077E80;

return (s32) temp_s0;
}
