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

s32 func_800263F4();
s32 func_8002642C();
s32 func_80026A6C();
s32 func_80026D28();
s32 func_80032980();
s32 osPfsDeleteFile();
s32 osPfsFileState();
extern char D_80001120[];
extern char D_801071B0[];
extern char D_80107210[];
extern char D_801073DE[];

s32 func_800265C0(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s3;

    func_800263F4();
    temp_s1 = arg0 << 5;
    temp_s3 = temp_s1 + D_801073DE;
    if (func_80026D28(func_80026A6C(temp_s3, 0x10), D_80001120, 5) == 0) {
        func_80032980();
    }
    temp_s0 = temp_s1 + (D_801073DE - 0xE);
    if (osPfsDeleteFile(D_80107210, M2C_FIELD(temp_s0, u16 *, 8), M2C_FIELD(temp_s0, s32 *, 4), temp_s3, temp_s1 + (D_801073DE - 4)) != 0) {
        return 0;
    }
    M2C_FIELD(temp_s0, s8 *, 0xE) = 0xF;
    *((s32 *) ((arg0 * 4) + D_801071B0)) = osPfsFileState(D_80107210, arg0, temp_s0);
    func_8002642C(D_801071B0);
    return 1;
}

