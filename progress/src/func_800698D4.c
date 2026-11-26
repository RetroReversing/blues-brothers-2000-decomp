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

extern void *gCameraRig;
extern M2C_UNK D_800BD0E0;
extern M2C_UNK func_80064808;

void func_800698D4(void *arg0) {
    M2C_UNK *__base_D_800BD0E0;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x5C) - 6;
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
    if (temp_v0 < 6) {
        M2C_FIELD(arg0, M2C_UNK (**)(), 0xA0)();
        M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C) = &func_80064808;
        __base_D_800BD0E0 = &D_800BD0E0;
        M2C_FIELD(__base_D_800BD0E0, s32 *, 0x14) = (s32) (M2C_FIELD(__base_D_800BD0E0, s32 *, 0x14) + 5);
    }
}
