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

M2C_UNK func_80017F78(M2C_UNK);                     /* extern */
s32 func_80043248(void *);                          /* extern */
M2C_UNK func_80043328(void *, s32, M2C_UNK);        /* extern */
s32 func_8007DDB8(void *, M2C_UNK *, M2C_UNK *);    /* extern */
extern void *gCameraRig;
extern void *D_800B3964;
extern M2C_UNK D_800B86C0;
extern M2C_UNK D_800B86D8;
extern M2C_UNK D_800B86F0;
extern M2C_UNK D_800B86FC;
extern M2C_UNK func_80017E34;
extern M2C_UNK func_8007E0B4;

s32 func_8007E674(void *arg0) {
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_v0;
    void *temp_s0_2;

    func_80043248(M2C_FIELD(arg0, void **, 0xA8));
    temp_s4 = func_80043248(arg0);
    func_8007DDB8(arg0, &D_800B86D8, &D_800B86C0);
    func_8007DDB8(M2C_FIELD(arg0, void **, 0xA8), &D_800B86FC, &D_800B86F0);
    func_8007DDB8(arg0, &D_800B86D8, &D_800B86C0);
    func_8007DDB8(M2C_FIELD(arg0, void **, 0xA8), &D_800B86FC, &D_800B86F0);
    temp_s0 = func_8007DDB8(arg0, &D_800B86D8, &D_800B86C0);
    temp_v0 = func_8007DDB8(M2C_FIELD(arg0, void **, 0xA8), &D_800B86FC, &D_800B86F0);
    if ((temp_s4 != 0) && (temp_s0 != 0) && (temp_v0 != 0)) {
        if (M2C_FIELD(D_800B3964, s32 *, 0x74) == 0) {
            M2C_FIELD(D_800B3964, s32 *, 0x74) = 1;
            func_80017F78(1);
        }
        if (M2C_FIELD(gCameraRig, s32 *, 0x9C) != &func_80017E34) {
            M2C_FIELD(D_800B3964, s32 *, 0x8C) = 0;
            M2C_FIELD(D_800B3964, s32 *, 0x74) = 0;
            if (M2C_FIELD(arg0, s32 *, 0xFC) <= 0) {
                temp_s0_2 = M2C_FIELD(arg0, void **, 0xA8);
                M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007E0B4;
                M2C_FIELD(arg0, s32 *, 0x78) = 5;
                func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x74) + 5, 0x100);
                func_80043328(temp_s0_2, M2C_FIELD(temp_s0_2, s32 *, 0x74) + M2C_FIELD(arg0, s32 *, 0x78), 0x100);
                return 0;
            }
            return 1;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

