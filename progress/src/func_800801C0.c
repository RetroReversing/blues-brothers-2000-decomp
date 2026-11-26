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

M2C_UNK func_8002D604(void *);                      /* extern */
M2C_UNK func_8007FE5C();                            /* extern */
extern void *D_800B3960;
extern void *D_800B3964;
extern void *gCameraTarget;
extern s32 D_80107040;
extern M2C_UNK func_8007E0B4;
extern M2C_UNK func_8007FE90;
extern M2C_UNK func_800800A8;

void func_800801C0(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(D_800B3964, void **, 0xA8);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, s32 *, 0x9C) == &func_8007E0B4)) {
        func_8007FE5C();
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        return;
    }
    func_8002D604(arg0);
    if (M2C_FIELD(D_800B3964, s32 *, 0x90) != 0) {
        if ((M2C_FIELD(D_800B3964, s32 *, 0x8C) != 0) && (M2C_FIELD(D_800B3960, s32 *, 0xC0) != 0) && (D_80107040 & 0x2000)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007FE90;
            D_80107040 = *(volatile s32 *)&D_80107040 & ~0x2000;
            M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        }
    }
    if (M2C_FIELD(gCameraTarget, s32 *, 0xF0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800800A8;
    }
}

