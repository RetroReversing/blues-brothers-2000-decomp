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

void *func_800232B4(s32, s32, s32, s32);
void func_80072CA8(void);
extern s32 D_8014A928[];
extern s32 *D_8014A9A8[];
extern s32 func_80073224;

void func_800723EC(void) {
    s32 i;
    s32 found;
    void *o;
    s32 *p;

    found = 0;
    for (i = 20; i < 30; i++) {
        if (D_8014A928[i] != 0) {
            found = 1;
            o = func_800232B4(1, 0, 0, 0);
            *(s32 **)((s8 *)o + 0x9C) = &func_80073224;
            *(s32 *)((s8 *)o + 0x70) = i;
            p = D_8014A9A8[i];
            if (p != NULL) {
                *(f32 *)((s8 *)o + 4) = p[0];
                *(f32 *)((s8 *)o + 8) = p[1];
                *(f32 *)((s8 *)o + 0xC) = p[2];
            }
        }
    }
    if (found != 0) {
        func_80072CA8();
    }
}
