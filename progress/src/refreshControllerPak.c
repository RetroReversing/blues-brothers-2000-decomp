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

M2C_UNK func_800261A0(s32);                         /* extern */
M2C_UNK func_800263F4();                            /* extern */
M2C_UNK func_8002642C();                            /* extern */
M2C_UNK osPfsIsPlug(M2C_UNK *, M2C_UNK *);          /* extern */
extern M2C_UNK D_80107050;
extern M2C_UNK D_80107058;

void refreshControllerPak(s32 arg0) {
    func_800263F4();
    osPfsIsPlug(&D_80107058, &D_80107050);
    func_8002642C();
    func_800261A0(arg0);
}
