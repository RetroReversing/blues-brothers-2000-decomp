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

M2C_UNK func_80025D00(s32);                         /* extern */
M2C_UNK func_800261B8(s32);                         /* extern */
M2C_UNK func_800263F4();                            /* extern */
M2C_UNK func_8002642C();                            /* extern */
s32 osMotorInit(M2C_UNK *, void *, s32);            /* extern */
M2C_UNK osPfsIsPlug(M2C_UNK *, u8 *);               /* extern */
extern M2C_UNK D_800AE154;
extern s32 D_800AE174;
extern u8 D_80107050;
extern M2C_UNK D_80107058;
extern u8 D_80107210[];

void func_8002621C(s32 arg0) {
    func_800263F4();
    osPfsIsPlug(&D_80107058, &D_80107050);
    func_8002642C();
    if (osMotorInit(&D_80107058, (arg0 * 0x68) + D_80107210, arg0) == 0) {
        func_80025D00(arg0);
        (&D_800AE154)[arg0] = 1;
        D_800AE174 = 0;
        D_80107050 &= ~(1 << arg0);
    } else {
        (&D_800AE154)[arg0] = 0;
    }
    func_800261B8(arg0);
}
