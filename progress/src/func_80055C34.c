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
M2C_UNK syncActorPrevPos(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK initSpline(s32, M2C_UNK);                /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern M2C_UNK D_8014AA3D;
extern M2C_UNK updateChaserActor;
extern M2C_UNK func_80055A34;
extern M2C_UNK func_80055AD4;

void *func_80055C34(s32 arg0) {
    s32 temp_a0;
    void *temp_v0;

    func_80050460(&func_80055A34, &D_8014AA3D);
    temp_v0 = func_80042F00(0xB, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1001;
    actorSetAnim(temp_v0, 0x4A, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &updateChaserActor;
    func_800852CC(temp_v0, arg0);
    temp_a0 = M2C_FIELD(temp_v0, s32 *, 0x70);
    if (temp_a0 != 0) {
        initSpline(temp_a0, 1);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80055AD4;
        actorSetAnim(temp_v0, 0x4B, 0x100);
        M2C_FIELD(temp_v0, s32 *, 0x64) = randomRange(0, 0x1F4);
    }
    syncActorPrevPos(temp_v0);
    return temp_v0;
}
