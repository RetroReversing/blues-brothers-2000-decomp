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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
f32 func_8002D340(f32, f32, f32);                   /* extern */
extern f32 D_8000949C;
extern s32 D_800B9ECC[2];

void func_8007AAE0(void *arg0) {
    f32 a1;
    f32 a2;
    f32 a3;
    s32 n;

    if (func_8001B990(0x100, 0x1F) != 0) {
                n = D_800B9ECC[0];
        a1 = M2C_FIELD(arg0, f32 *, 0x44) + D_8000949C;
        a2 = M2C_FIELD(arg0, f32 *, 8);
        a3 = (f32) (n * 0xA);

        M2C_FIELD(arg0, f32 *, 8) = func_8002D340(a1, a2, a3);
    }
}
