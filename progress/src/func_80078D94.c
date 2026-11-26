/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s16 coss(u16);                                      /* extern */
s32 func_8002444C();                                /* extern */
M2C_UNK func_8002D260(s32);                         /* extern */
f32 func_8002D340(f32, f32, f32);                   /* extern */
s32 func_8002D5CC(void *);                          /* extern */
s32 func_8004303C(void *);                          /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80076080();                                /* extern */
s16 sins(u16);                                      /* extern */
extern s32 D_800B9ECC;
extern f32 D_801700D0;
extern M2C_UNK func_8007631C;
extern M2C_UNK func_80079038;
extern M2C_UNK func_800790B4;

void func_80078D94(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fv1;
    s32 temp_a0;
    s32 temp_v0;

    if ((func_80076080() == 0) && (temp_fs0 = D_801700D0, (func_8002D5CC(arg0) != 0))) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
        if (func_8004303C(arg0) != 0) {
            M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) - 1);
        }
        if ((M2C_FIELD(arg0, s32 *, 0xD0) == 0x104) && (M2C_FIELD(arg0, f32 *, 4) == M2C_FIELD(arg0, f32 *, 0x40)) && (M2C_FIELD(arg0, f32 *, 0xC) == M2C_FIELD(arg0, f32 *, 0x48))) {
            M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        }
        if (M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
            if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x104) {
                func_80043328(arg0, 0x106, 0x100);
                M2C_FIELD(arg0, s32 *, 0x7C) = 0;
                M2C_FIELD(arg0, s32 *, 0x8C) = 1;
                if ((func_8002444C() & 7) == 6) {
                    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80079038;
                    return;
                }
                goto block_13;
            }
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x10) + 0x8000;
            M2C_FIELD(arg0, s32 *, 0x10) = temp_a0;
            func_8002D260(temp_a0);
            func_80043328(arg0, 0x104, 0x100);
            M2C_FIELD(arg0, f32 *, 0x40) = (f32) (M2C_FIELD(arg0, f32 *, 0x40) + (f32) ((s32) (sins(M2C_FIELD(arg0, u16 *, 0x12)) * 0x271) >> 0xE));
            temp_fv1 = M2C_FIELD(arg0, f32 *, 0x48) + (f32) ((s32) (coss(M2C_FIELD(arg0, u16 *, 0x12)) * 0x271) >> 0xE);
            M2C_FIELD(arg0, s32 *, 0x8C) = 0xA;
            M2C_FIELD(arg0, f32 *, 0x48) = temp_fv1;
            goto block_13;
        }
block_13:
        if ((M2C_FIELD(arg0, s32 *, 0xC0) & ~1) && (M2C_FIELD(arg0, s32 *, 0xD0) != 0x109)) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0xFC) - 1;
            M2C_FIELD(arg0, s32 *, 0xFC) = temp_v0;
            if (temp_v0 <= 0) {
                func_800433A8(arg0, 0x108, 0x100);
                M2C_FIELD(arg0, s32 *, 0) = 0x101;
                M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007631C;
                M2C_FIELD(arg0, s32 *, 0xD8) = 0;
                return;
            }
            func_800433A8(arg0, 0x109, 0xE0);
            M2C_FIELD(arg0, s32 *, 0x7C) = 1;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80079038;
            goto block_18;
        }
block_18:
        if ((temp_fs0 < 300.0f) && (M2C_FIELD(arg0, s32 *, 0x7C) == 0)) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800790B4;
            M2C_FIELD(arg0, s32 *, 0x7C) = 0;
            return;
        }
        temp_fs0 = (f32) ((f64) D_800B9ECC * 3.0);
        M2C_FIELD(arg0, f32 *, 4) = func_8002D340(M2C_FIELD(arg0, f32 *, 0x40), M2C_FIELD(arg0, f32 *, 4), temp_fs0);
        M2C_FIELD(arg0, f32 *, 0xC) = func_8002D340(M2C_FIELD(arg0, f32 *, 0x48), M2C_FIELD(arg0, f32 *, 0xC), temp_fs0);
    }
}

