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
void func_80023C58(s32);
void func_80023C64(s32);
s32 func_8002D298(s32, s32, s32);
void func_80030C40(void *, s32);
extern s32 D_800AE010;
extern s32 D_800B3968;
extern s32 D_800B9C70;
extern s32 D_801070A0;
extern char func_80023078[];
extern s32 func_800318BC;

void func_80032ADC(void *arg0) {
    if (D_800B3968 != 0) {
        func_80030C40(arg0, 1);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x94) = 1;
        M2C_FIELD(arg0, s32 **, 0x98) = &func_800318BC;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0x6C) = 0;
        D_801070A0 = 0;
        M2C_FIELD(arg0, s32 *, 0x90) = D_800AE010;
        M2C_FIELD(arg0, s32 *, 0x64) = 0x2BC;
        func_80023C58(0xB9458F);
        M2C_FIELD(arg0, f32 *, 8) = 240.0f;
    }
    if (M2C_FIELD(arg0, s32 *, 0x94) != 0) {
        M2C_FIELD(arg0, s32 *, 0x6C) = func_8002D298(0xFF, M2C_FIELD(arg0, s32 *, 0x6C), 5);
    } else {
        M2C_FIELD(arg0, s32 *, 0x6C) = func_8002D298(0, M2C_FIELD(arg0, s32 *, 0x6C), 5);
    }
    if (M2C_FIELD(arg0, s32 *, 0x94) != 0 && M2C_FIELD(arg0, f32 *, 8) < -350.0f) {
        M2C_FIELD(arg0, void **, 0x98) = func_80023078 + 8;
        func_80030C40(arg0, 1);
        func_80023C58(M2C_FIELD(arg0, s32 *, 0x90));
        func_80023C64(0xB9458F);
        D_800B9C70 = 1;
    }
}
