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

M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D124();                            /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern void *gCameraRig;
extern M2C_UNK func_800340B4;
extern M2C_UNK func_8003B670;
extern M2C_UNK func_8003C264;

void func_8003BB90(void *arg0) {
    M2C_UNK *temp_a0;

    if (M2C_FIELD(arg0, s32 *, 0xD0) != 0x17) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x19);
        func_8002D124();
        if (M2C_FIELD(gCameraRig, M2C_UNK **, 0xD8) == NULL) {
            temp_a0 = M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C);
            if (temp_a0 == &func_800340B4) {
                M2C_FIELD(gCameraRig, M2C_UNK **, 0xD8) = temp_a0;
                M2C_FIELD(gCameraRig, M2C_UNK **, 0x9C) = &func_8003B670;
            }
        }
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 0x9C);
        actorSetAnim(arg0, 0x17, 0x100);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003C264;
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
    }
}
