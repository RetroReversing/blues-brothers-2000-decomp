/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
void *func_80050964(s32);                           /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern f32 D_80008040;
extern M2C_UNK D_8014AA41;
extern M2C_UNK func_800509EC;

void *func_80050A3C(s32 arg0) {
    void *temp_v0;
    void *temp_v0_2;

    func_80050460(&func_800509EC, &D_8014AA41);
    temp_v0 = func_80042F00(0x78, 0, 0, 0);
    actorSetAnim(temp_v0, 0x85, 0x100);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, 1, 0, 1, 0);
    temp_v0_2 = func_80050964(arg0);
    M2C_FIELD(temp_v0_2, void **, 0xA8) = temp_v0;
    M2C_FIELD(temp_v0_2, f32 *, 8) = (f32) (M2C_FIELD(temp_v0_2, f32 *, 8) + D_80008040);
    actorSetAnim(temp_v0_2, 0x82, 0x100);
    return temp_v0;
}
