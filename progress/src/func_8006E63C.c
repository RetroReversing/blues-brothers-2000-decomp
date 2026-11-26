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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK setSlotAsset(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
void *func_80042F00(M2C_UNK, s32, s32, s32);        /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern void *gCameraTarget;
extern M2C_UNK func_8006E3F8;

s32 func_8006E63C(void *arg0) {
    void *temp_v0;

    func_80023A74(1, 0x675);
    setSlotAsset(1, 0x6AA, 0);
    setSlotAsset(0x22, 0x66F, 0);
    setSlotAsset(0x18, 0x66A, 0);
    do { setSlotAsset(0x1A, 0x667, 0); } while (0);
    temp_v0 = func_80042F00(1, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    actorSetAnim(temp_v0, 1, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006E3F8;
    M2C_FIELD(temp_v0, s32 *, 0x68) = 3;
    gCameraTarget = temp_v0;
    return gCameraTarget;
}
