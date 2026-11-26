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

s32 randomRange(M2C_UNK, s32);                    /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_800730E0(void *);                      /* extern */
extern s32 D_800AB9C8;
extern void *D_800B3964;
extern s32 D_800BD0FC;

void func_80073224(void *arg0) {
    s32 var_v0;

    if ((D_800AB9C8 == 0) && (M2C_FIELD(D_800B3964, s32 *, 0x8C) == 0)) {
        if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
            if (M2C_FIELD(arg0, s32 *, 0x78) == 0) {
                if (D_800BD0FC == 5) {
                    M2C_FIELD(arg0, s32 *, 0x78) = 0x12C;
                } else {
                    M2C_FIELD(arg0, s32 *, 0x78) = 0xB4;
                }
            }
            if (M2C_FIELD(arg0, s32 *, 0x74) == 0) {
                M2C_FIELD(arg0, s32 *, 0x74) = 0x2D;
            }
            if (M2C_FIELD(arg0, s32 *, 0x74) >= 0x65) {
                M2C_FIELD(arg0, s32 *, 0x74) = 0x64;
            }
            M2C_FIELD(arg0, s32 *, 0x7C) = 1;
            M2C_FIELD(arg0, s32 *, 0x80) = 0;
            M2C_FIELD(arg0, s32 *, 0x64) = randomRange(0, M2C_FIELD(arg0, s32 *, 0x78));
        }
        if (tickActorTimer(arg0) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0x80) < M2C_FIELD(arg0, s32 *, 0x74)) {
                func_800730E0(arg0);
                M2C_FIELD(arg0, s32 *, 0x80) = (s32) (M2C_FIELD(arg0, s32 *, 0x80) + 1);
            }
            M2C_FIELD(arg0, s32 *, 0x64) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) + randomRange(-0x14, 0x14));
        }
    }
}
