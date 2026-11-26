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

s32 approachS32(M2C_UNK, s32, s32);               /* extern */
extern s32 gCamSpeedScale;
void func_80067FF4(void *);

void func_8006808C(void *arg0) {
    void *p;

    p = M2C_FIELD(arg0, void **, 0xA4);
    if (p == NULL) {
        M2C_FIELD(arg0, void (**)(void *), 0xA0)(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0xFF;
        M2C_FIELD(arg0, void **, 0x98) = func_80067FF4;
        M2C_FIELD(arg0, s32 *, 0x68) = 0xD;
        M2C_FIELD(arg0, s32 *, 0xF4) = 0;
    }
    if (M2C_FIELD(p, s32 *, 0x78) < M2C_FIELD(arg0, s32 *, 0x90)) {
        M2C_FIELD(arg0, s32 *, 0x8C) = approachS32(0, M2C_FIELD(arg0, s32 *, 0x8C), gCamSpeedScale * 4);
        if (M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
            M2C_FIELD(arg0, void (**)(void *), 0xA0)(arg0);
        }
    }
}
