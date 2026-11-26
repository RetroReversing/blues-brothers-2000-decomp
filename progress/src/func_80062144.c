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

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK animSampleKeys(s32, f32);                    /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, s32);        /* extern */
M2C_UNK func_80050460(M2C_UNK *, void *);           /* extern */
extern M2C_UNK D_8014AA38;
extern M2C_UNK func_80061F78;
extern M2C_UNK func_80061FA8;
extern M2C_UNK func_80062110;

void *func_80062144(void *arg0) {
    s32 temp_lo;
    s32 temp_s0;
    void *temp_s1;

    func_80050460(&func_80061F78, (char *)&D_8014AA38 + 2);
    temp_s1 = func_80042F00(0x1C, 0, 0, 0);
    actorSetAnim(temp_s1, 0xA1, randomRange(0x80, 0x140));
    temp_s0 = M2C_FIELD(temp_s1, s32 *, 0xE0);
    animSampleKeys(temp_s0, (f32) randomRange(0, 0xA));
    M2C_FIELD(temp_s1, s32 *, 0) = 0x101B;
    M2C_FIELD(temp_s1, M2C_UNK **, 0x9C) = &func_80061FA8;
    M2C_FIELD(temp_s1, s32 *, 0x10) = (s32) (randomRange(1, 8) << 0xD);
    if (M2C_FIELD(temp_s1, s32 *, 0x7C) == 0) {
        do {
            M2C_FIELD(temp_s1, s32 *, 0x7C) = randomRange(-1, 1);
            temp_lo = M2C_FIELD(temp_s1, s32 *, 0x7C) * randomRange(5, 0x64);
            M2C_FIELD(temp_s1, s32 *, 0x7C) = temp_lo;
        } while (temp_lo == 0);
    }
    if (arg0 != NULL) {
        M2C_FIELD(temp_s1, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_s1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_s1, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        if (M2C_FIELD(arg0, s32 *, 0) == 1) {
            M2C_FIELD(temp_s1, M2C_UNK **, 0x9C) = &func_80062110;
        }
    }
    return temp_s1;
}
