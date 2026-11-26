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

M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
void func_8002AD4C(void);                     /* extern */
M2C_UNK func_8002D124();                            /* extern */
M2C_UNK actorSetAnim(M2C_UNK, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80107040;
extern M2C_UNK gPadPressed;
extern s32 D_8014023C;

s32 func_8003AB30(void *arg0) {

    if (((u32 *) &gPadPressed)[M2C_FIELD(arg0, s32 *, 0xBC)] & 0x4000) {
        if (((u32 *) &D_80107040)[M2C_FIELD(arg0, s32 *, 0xBC)] & 0x2000) {
            actorSetAnim(arg0, 0x1E, 0x100);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x82);
            func_8002D124();
            return 1;
        }
        D_8014023C = 0;
        func_8002AD4C();
        if (M2C_FIELD(arg0, s32 *, 0x78) != 0) {
            actorSetAnim(arg0, 0xD, 0x100);
        } else {
            actorSetAnim(arg0, 0x13, 0x100);
        }
        M2C_FIELD(arg0, s32 *, 0x88) = 0;
        M2C_FIELD(arg0, s32 *, 0x74) = 0;
        M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) ^ 1);
        return 1;
    }
    return 0;
}
