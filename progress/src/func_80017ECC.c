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

void *func_8002E374(M2C_UNK);                       /* extern */
extern M2C_UNK func_80023078;

void func_80017ECC(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *temp_v0;
    void *temp_v1;

    temp_v0 = func_8002E374(0x82);
    M2C_FIELD(temp_v0, s32 *, 0x68) = -1;
    temp_v1 = (char *) &func_80023078 + 8;
    M2C_FIELD(temp_v0, void **, 0x9C) = temp_v1;
    M2C_FIELD(temp_v0, void **, 0x98) = temp_v1;
    M2C_FIELD(temp_v0, s32 *, 0x70) = arg0;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x131;
    M2C_FIELD(temp_v0, f32 *, 4) = arg1;
    M2C_FIELD(temp_v0, f32 *, 8) = arg2;
    M2C_FIELD(temp_v0, f32 *, 0xC) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg4;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg5;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg6;
}
