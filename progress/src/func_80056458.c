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

s32 cameraGetMode();                                /* extern */
s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
void *func_8005639C(s32);                           /* extern */
void *func_80056BB0(s32);                           /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B7B0C;
extern M2C_UNK D_8014AA59;
extern M2C_UNK func_80055E70;
extern M2C_UNK func_80056140;
extern M2C_UNK func_8005634C;

void *func_80056458(s32 arg0) {
    void *temp_v0;

    if ((cameraGetMode() == 0x24) || (cameraGetMode() == 0x20)) {
        return func_8005639C(arg0);
    }
    if (cameraGetMode() == 0x3D) {
        return func_80056BB0(arg0);
    }
    func_80050460(&func_8005634C, &D_8014AA59);
    temp_v0 = func_80042F00(0x31, 0, 0, 0);
    func_80043328(temp_v0, 0xBD, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80055E70;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1009;
    M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    func_800852CC(temp_v0, arg0);
    if (cameraGetMode() == 0x1C) {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80056140;
        M2C_FIELD(temp_v0, s32 *, 0x7C) = 0;
    }
    return temp_v0;
}
