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

M2C_UNK syncActorPrevPos(void *);                      /* extern */
M2C_UNK func_80043328(void *, s32, M2C_UNK);        /* extern */
s32 func_8006A758(void *);                          /* extern */
s32 func_8006A7A0(void *);                          /* extern */
s32 func_8006A914(void *);                          /* extern */
s32 func_80080DE0(s32);                             /* extern */
M2C_UNK initSpline(s32, M2C_UNK);                /* extern */
M2C_UNK func_80083A28(void *);                      /* extern */
extern f32 D_80008EA0;
extern f32 D_80008EA4;

void func_8006A978(void *arg0) {
    s32 (*temp_v0)(void *);
    s32 (*temp_v0_2)(void *);
    s32 (*var_v0)(void *);
    s32 temp_v1;
    s32 var_s2;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        if (func_80080DE0(M2C_FIELD(arg0, s32 *, 0x70)) == 0) {
            initSpline(M2C_FIELD(arg0, s32 *, 0x70), 1);
        }
        M2C_FIELD(arg0, s32 *, 0xBC) = 1;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x78) = 0;
        syncActorPrevPos(arg0);
        M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = NULL;
        if (M2C_FIELD(arg0, f32 *, 0xAC) == 0.0f) {
            M2C_FIELD(arg0, f32 *, 0xAC) = (f32) D_80008EA0;
        }
        if (M2C_FIELD(arg0, f32 *, 0x104) == 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x104) = (f32) D_80008EA4;
        }
        M2C_FIELD(arg0, f32 *, 0xB4) = 0.0f;
        M2C_FIELD(arg0, s32 *, 0xBC) = 1;
        M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = func_8006A914;
        M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    }
    temp_v0 = M2C_FIELD(arg0, s32 (**)(void *), 0xD8);
    if (temp_v0 != NULL) {
        var_s2 = temp_v0(arg0);
    }
    if (var_s2 != 0) {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x78);
        if (temp_v1 < 5) {
            if (temp_v1 < 3) {
                if (temp_v1 != 0) {
                    M2C_FIELD(arg0, s32 *, 0x78) = 4;
                    goto block_21;
                }
                goto block_16;
            }
            goto block_17;
        }
        if (temp_v1 == 8) {
block_16:
block_17:
            if (var_s2 != 3) {
                M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = func_8006A914;
                M2C_FIELD(arg0, s32 *, 0x78) = 1;
            } else {
                var_v0 = func_8006A758;
                M2C_FIELD(arg0, s32 *, 0x78) = var_s2;
                goto block_22;
            }
        } else {
            M2C_FIELD(arg0, s32 *, 0x78) = 4;
block_21:
            var_v0 = func_8006A7A0;
block_22:
            M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = var_v0;
        }
        func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x74) + M2C_FIELD(arg0, s32 *, 0x78), 0x100);
        temp_v0_2 = M2C_FIELD(arg0, s32 (**)(void *), 0xD8);
        if (temp_v0_2 != NULL) {
            temp_v0_2(arg0);
        }
    }
    func_80083A28(arg0);
}
