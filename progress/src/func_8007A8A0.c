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

s32 func_80023DBC(s32);                             /* extern */
s32 func_80052A68(s32, s32 *);                  /* extern */
s32 func_80052B24(s32, s32 *, void *);      /* extern */
extern s32 D_80009468;
extern s32 D_80009478;
extern s32 D_800B83C4;

void func_8007A8A0(void *arg0) {
    s32 t;
    s32 *a;
    s32 *b;

    t = func_80023DBC(D_800B83C4);
    a = &D_80009468;
    b = &D_80009478;
    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        if (func_80052A68(t, a) == 0) {
            func_80052B24(t, a, arg0);
        } else {
            func_80052B24(t, b, arg0);
        }
        M2C_FIELD(arg0, s32 *, 0x88)++;
    }
}
