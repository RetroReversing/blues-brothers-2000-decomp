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

s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
s32 func_8002D298(M2C_UNK, s32, M2C_UNK);           /* extern */
extern f32 D_80008E68;
extern s32 D_800B3964[];

void func_8006A024(void *arg0) {
    f32 temp_fv1;
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        do { M2C_FIELD(arg0, s32 *, 0x88) = func_80024394(0x2D, 0x41); } while (0);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0x127;
        M2C_FIELD(arg0, s32 *, 0x78) = 1;
        M2C_FIELD(arg0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    }
    if (M2C_FIELD(D_800B3964[0], s32 *, 0x84) != 0) {
        if (M2C_FIELD(D_800B3964[0], s32 *, 0x88) != 0) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x70) + func_80024394(-0x400, 0x400);
            M2C_FIELD(arg0, s32 *, 0x70) = temp_v1;
            M2C_FIELD(arg0, s32 *, 0x18) = temp_v1;
            if (temp_v1 >= 0x4001) {
                M2C_FIELD(arg0, s32 *, 0x18) = 0x4000;
            }
            if (M2C_FIELD(arg0, s32 *, 0x18) < -0x4000) {
                M2C_FIELD(arg0, s32 *, 0x18) = -0x4000;
            }
        } else {
            goto block_9;
        }
    } else {
block_9:
        M2C_FIELD(arg0, s32 *, 0x18) = func_8002D298(0, M2C_FIELD(arg0, s32 *, 0x18), 0x200);
    }
    if (M2C_FIELD(arg0, s32 *, 0x8C) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x78) != 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0xB5);
            M2C_FIELD(arg0, s32 *, 0x78) = 0;
        }
        temp_fv1 = M2C_FIELD(arg0, f32 *, 8) - (f32) M2C_FIELD(arg0, s32 *, 0x88);
        M2C_FIELD(arg0, f32 *, 8) = temp_fv1;
        if (temp_fv1 < (M2C_FIELD(arg0, f32 *, 0x44) - D_80008E68)) {
            M2C_FIELD(D_800B3964[0], s32 *, 0x6C) = 0x10;
            do { M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0); } while (0);
        }
    }
}

