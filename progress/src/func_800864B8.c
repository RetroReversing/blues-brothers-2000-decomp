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

s32 findActor(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
M2C_UNK func_80026C04(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80087160(s32);                         /* extern */
extern M2C_UNK D_801719E0;
extern void *D_80171A30;
extern s32 D_80171A34;
extern s32 D_80171A54;
extern M2C_UNK func_8008626C;

void func_800864B8(void *arg0) {
    if (findActor(0x800, 0) == 0) {
        func_80087160(func_80023D58(0x21C));
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8008626C;
        func_80026C04(&D_801719E0, 0, 0x50);
        M2C_FIELD(&D_801719E0, s32 *, 8) = 5;
        D_80171A34 = 0;
        D_80171A54 = 0;
        M2C_FIELD(D_80171A30, s32 *, 0x68) = 0xE;
    }
}
