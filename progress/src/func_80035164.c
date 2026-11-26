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

s32 func_8001E994();                                /* extern */
M2C_UNK func_800340B4(void *);                      /* extern */
M2C_UNK func_80036FB8(void *, M2C_UNK);             /* extern */
extern s32 cameraDistTable;
extern s32 D_80107040;
extern s32 gPadPressed;

void func_80035164(void *arg0) {
    if (func_8001E994() != 0) {
        M2C_FIELD(arg0, s32 *, 0x6C) = 0;
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) cameraDistTable;
        func_80036FB8(arg0, 2);
        D_80107040 &= ~4;
        gPadPressed &= ~4;
    }
    func_800340B4(arg0);
}
