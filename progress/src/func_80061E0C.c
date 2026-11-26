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

M2C_UNK syncActorPrevPos(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
extern f32 D_800089B0;
extern M2C_UNK D_8014AA53;
extern M2C_UNK func_80060E44;
extern M2C_UNK func_80061CD0;

void *func_80061E0C(void *arg0) {
    void *temp_v0;

    func_80050460(&func_80061CD0, &D_8014AA53);
    temp_v0 = func_80042F00(0x53, 0, 0, 0);
    actorSetAnim(temp_v0, 0x9C, 0x100);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1025;
    M2C_FIELD(temp_v0, void **, 0x9C) = (void *) ((char *)&func_80060E44 + 0xC);
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + D_800089B0);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    syncActorPrevPos(temp_v0);
    return temp_v0;
}
