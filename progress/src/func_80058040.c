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

M2C_UNK syncActorPrevPos(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_800852CC(void *, void *);              /* extern */
extern M2C_UNK D_8014AA5B;
extern M2C_UNK func_800579E0;
extern M2C_UNK func_80057CCC;
extern M2C_UNK func_80057FC0;

void *func_80058040(void *arg0) {
    s32 temp_v0_2;
    void *temp_v0;

    func_80050460(&func_80057FC0, &D_8014AA5B);
    temp_v0 = func_80042F00(0x33, 0, 0, 0);
    func_80043328(temp_v0, 0xC0, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800579E0;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x100A;
    if (arg0 != NULL) {
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x70);
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_v0, s32 *, 0x70) = temp_v0_2;
            M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80057CCC;
        }
    }
    func_800852CC(temp_v0, arg0);
    syncActorPrevPos(temp_v0);
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
    }
    M2C_FIELD(temp_v0, s32 *, 0x6C) = 0;
    return temp_v0;
}
