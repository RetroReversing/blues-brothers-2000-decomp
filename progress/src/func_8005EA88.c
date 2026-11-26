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

void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_800B9510;
extern M2C_UNK D_8014AA55;
extern M2C_UNK func_8005E744;

void *func_8005EA88(void *arg0) {
    void *temp_v0;

    func_80050460(&func_8005E744, &D_8014AA55);
    temp_v0 = func_80042F00(0x26, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x100D;
    actorSetAnim(temp_v0, 0xDE, 0x100);
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    M2C_FIELD(temp_v0, M2C_UNK **, 0xC8) = &D_800B9510;
    return temp_v0;
}
