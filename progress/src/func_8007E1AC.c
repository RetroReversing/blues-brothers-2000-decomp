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

s32 func_80023874(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80023DBC(M2C_UNK);                         /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002ABC0(M2C_UNK);                     /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
s32 func_80052B24(s32, M2C_UNK *, void *);          /* extern */
extern M2C_UNK D_80009604;
extern void *D_800B3964;
extern s32 D_800B4988;

s32 func_8007E1AC(void *arg0) {

    D_800B4988 = 0x1E;
    if (M2C_FIELD(arg0, s32 *, 0x88) == 0) {
        func_80052A5C(0x56F);
        if (func_80052B24(func_80023DBC(0xE45), &D_80009604, arg0) != 0) {
            M2C_FIELD(arg0, s32 *, 0x88) = (s32) (M2C_FIELD(arg0, s32 *, 0x88) + 1);
        }
        func_8002ABC0(0x60);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xCA);
        func_8002ABC0(0x40);
    }
    func_8004303C(arg0);
    func_8004303C(M2C_FIELD(arg0, void **, 0xA8));
    if (func_80023874(0x801, 0) == 0) {
        M2C_FIELD(D_800B3964, s32 *, 0x7C) = (s32) (M2C_FIELD(D_800B3964, s32 *, 0x7C) + 1);
        return 0xDE;
    }
    return 0;
}
