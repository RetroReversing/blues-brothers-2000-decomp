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

s32 func_80043328();
s32 debugPrintf();
extern char D_800081C0[];
extern s32 D_8014AA94;

s32 func_800537E8(s32 arg0, void *arg1) {
    if (D_8014AA94 == 0) {
        debugPrintf(D_800081C0);
    }
    func_80043328(D_8014AA94, M2C_FIELD(arg1, s32 *, 4), 0x100);
    return 0;
}
