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

M2C_UNK func_8008DE38(s32);                         /* extern */
extern s32 D_8017B244;
extern s32 D_8017B248;
extern s32 D_8017B24C;
extern s32 D_8017B250;

void func_8008DDAC(void) {
    s32 temp_v0;

    if (D_8017B244 != D_8017B248) {
        do {
            func_8008DE38(D_8017B250 + (D_8017B244 * 8));
            temp_v0 = D_8017B244 + 1;
            D_8017B244 = temp_v0;
            if (temp_v0 == D_8017B24C) {
                D_8017B244 = 0;
            }
        } while (D_8017B244 != D_8017B248);
    }
}
