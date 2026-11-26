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

s32 func_80013784(void *);                          /* extern */
s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D124();                            /* extern */
f32 func_8002DD60(f32);                             /* extern */
s32 func_80069050();                                /* extern */
M2C_UNK func_800692C0(void *);                      /* extern */
extern f32 D_80008E04;
extern f32 D_80008E08;
extern void *D_800B3964;
extern void *gCameraTarget;

void func_800690B0(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fv0;
    s32 var_s2;

    var_s2 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        M2C_FIELD(arg0, s32 *, 0x90) = func_80069050();
        M2C_FIELD(arg0, s32 *, 0x58) = packDrawFlags(1, 1, 0, 2, 0, 1, 1, 0);
    }
    if ((M2C_FIELD(arg0, s32 *, 0x90) == M2C_FIELD(D_800B3964, s32 *, 0x90)) && (M2C_FIELD(arg0, s32 *, 0x8C) == 0) && (func_80013784(arg0) != 0)) {
        temp_fs0 = func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4));
        temp_fs1 = func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 8) - M2C_FIELD(arg0, f32 *, 8));
        temp_fv0 = func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0xC));
        if ((temp_fs0 < 180.0f) && (temp_fv0 < 180.0f) && (temp_fs1 < 100.0f)) {
            if (M2C_FIELD(D_800B3964, void **, 0x84) == NULL) {
                M2C_FIELD(D_800B3964, void **, 0x84) = arg0;
                var_s2 = 1;
            }
            if (M2C_FIELD(D_800B3964, void **, 0x88) == NULL) {
                if (var_s2 == 0) {
                    M2C_FIELD(D_800B3964, void **, 0x88) = arg0;
                    var_s2 = 1;
                    goto block_13;
                }
                goto block_15;
            }
block_13:
            if (var_s2 != 0) {
block_15:
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 7);
                func_8002D124();
                func_800692C0(arg0);
                M2C_FIELD(arg0, s32 *, 0x8C) = 1;
            }
        }
    }
}

