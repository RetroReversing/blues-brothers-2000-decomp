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
M2C_UNK func_80085244(void *, s32);                 /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B81D0;
extern M2C_UNK D_8014AA4A;
extern M2C_UNK func_80041D18;
extern M2C_UNK updateSpiderAi;
extern M2C_UNK func_80061C40;
extern M2C_UNK func_8006E250;

void *func_80061D40(s32 arg0) {
    void *temp_v0;

    func_80050460(&func_80061C40, &D_8014AA4A);
    temp_v0 = func_80042F00(0x14, 0, 0, 0);
    actorSetAnim(temp_v0, 0x98, 0x100);
    func_800852CC(temp_v0, arg0);
    if (D_800B81D0 != 0) {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80041D18;
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006E250;
        M2C_FIELD(temp_v0, s32 *, 0xBC) = 4;
    } else {
        func_80085244(temp_v0, arg0);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &updateSpiderAi;
        M2C_FIELD(temp_v0, s32 *, 0) = 0x101A;
        M2C_FIELD(temp_v0, s32 *, 0x74) = 0x97;
    }
    return temp_v0;
}
