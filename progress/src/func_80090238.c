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

s32 setDelayFxParams();
s32 func_8009B074();
extern s32 D_800BA900;
extern char D_800BA904[];
extern void *gFxSynth;

s32 func_80090238(s32 arg0) {
    s32 temp_a2;

    if (arg0 >= D_800BA900) {
        return 1;
    }
    setDelayFxParams(*(s32 *)(D_800BA904 + (arg0 * 4)));
    temp_a2 = M2C_FIELD(gFxSynth, s32 *, 0x34);
    func_8009B074(temp_a2 + 0x20, 1, temp_a2);
    return 0;
}
