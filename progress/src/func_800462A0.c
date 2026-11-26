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

extern M2C_UNK func_80045E34;

void func_800462A0(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0xBC);
    if (temp_v1 <= 0xE75975) {
        M2C_FIELD(arg0, s32 *, 0xBC) = 0xE75976;
        M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_80045E34;
        return;
    }
    if (temp_v1 == 0xE75976) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        M2C_FIELD(arg0, s32 *, 0xBC) = (s32) (M2C_FIELD(arg0, s32 *, 0xBC) + 1);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0xA0)();
}
