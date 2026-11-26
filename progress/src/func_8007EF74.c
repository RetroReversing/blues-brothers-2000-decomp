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

M2C_UNK func_800414D0();                            /* extern */
M2C_UNK guMtxL2F(s32, M2C_UNK *);                   /* extern */
extern s32 D_800B74E4;
extern s32 D_80140260;
extern M2C_UNK *D_80140310;

void func_8007EF74(void *arg0) {
    M2C_UNK sp10[32];

    D_80140260 = 0xC;
    D_80140310 = &sp10;
    D_800B74E4 = 1;
    func_800414D0();
    guMtxL2F(M2C_FIELD(arg0, s32 *, 0x8C), &sp10);
}
