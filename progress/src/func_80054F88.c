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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8001B990();
s32 func_8001C6D8();
s32 func_80023DBC();
s32 func_8004303C();
s32 func_80043328();
s32 func_80052B24();
s32 func_80054F38();
extern char D_800082D8[];
extern s32 D_800B9ECC;

void func_80054F88(void *arg0) {
    s32 temp_a1;
    s32 temp_a2;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        func_80043328(arg0, 0x46, 0x100);
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        return;
    }
    func_8004303C(arg0);
    temp_a2 = D_800B9ECC * 2;
    temp_a1 = D_800B9ECC << 8;
    M2C_FIELD(arg0, s32 *, 0x5C) -= temp_a2;
    M2C_FIELD(arg0, s32 *, 0x10) += M2C_FIELD(arg0, s32 *, 0x70);
    M2C_FIELD(arg0, s32 *, 0x70) += temp_a1;
    M2C_FIELD(arg0, f32 *, 8) += (f32) (D_800B9ECC * 4);
    if (M2C_FIELD(arg0, s32 *, 0x5C) <= 0) {
        func_80054F38(func_8001C6D8(arg0, temp_a1, temp_a2));
        func_8001B990(0x200, 0x42);
        func_80052B24(func_80023DBC(0xEA5), D_800082D8, arg0);
        M2C_FIELD(arg0, s32 (**)(void *), 0xA0)(arg0);
    }
}
