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

s32 func_8002492C(f32, f32);                        /* extern */
M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
s32 func_8002D260(s32);                             /* extern */
s32 tickActorTimer(void *);                          /* extern */
f32 getCameraTargetDist(void *, M2C_UNK, s32 *);          /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_8005FD88(s32, void *);                     /* extern */
M2C_UNK func_80060214(void *);                      /* extern */
void func_8007631C(void *arg0);                     /* extern */
s32 func_80080DE0(s32);                             /* extern */
M2C_UNK initSpline(s32, M2C_UNK);                /* extern */
s32 func_80081990(void *, s32, f32);                /* extern */
M2C_UNK func_80081AC0(f32 *, s32, f32);             /* extern */
extern f32 D_80008900;
extern f32 D_80008904;
extern s32 gCameraTarget;

#define sp10 (*(f32 *)(sp + 0x0))
#define sp18 (*(f32 *)(sp + 0x8))
#define sp20 (*(s32 *)(sp + 0x10))
void func_800607B0(void *arg0) {
    u8 sp[24];
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv1;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_v0;
    void (*temp_v1)(void *);
    void *temp_s3;

    temp_s2 = M2C_FIELD(arg0, s32 *, 0x70);
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, f32 *, 0xB4) = 0.0f;
        M2C_FIELD(arg0, s32 *, 0xBC) = 1;
        M2C_FIELD(arg0, f32 *, 0xAC) = 0.015f;
        if (func_80080DE0(temp_s2) == 0) {
            initSpline(M2C_FIELD(arg0, s32 *, 0x70), 0);
        }
    }
    func_80060214(arg0);
    if (M2C_FIELD(arg0, s32 *, 0x80) == 0) {
        temp_fs0 = getCameraTargetDist(arg0, 0x43C80000, &sp20);
        if ((tickActorTimer(arg0) != 0) && (temp_fs0 < 200.0f)) {
            var_v0 = func_8002D260(sp20 - M2C_FIELD(arg0, s32 *, 0x10));
            if (var_v0 < 0) {
                var_v0 = -var_v0;
            }
            if ((var_v0 < 0x1000) && (func_8005FD88(gCameraTarget, arg0) != 0)) {
                func_8002ADFC(0x25, 0x1F4, arg0);
                M2C_FIELD(arg0, void (**)(void *), 0xD8) = func_800607B0;
                M2C_FIELD(arg0, void (**)(void *), 0x9C) = func_8007631C;
                actorSetAnim(arg0, 0x56, 0x100);
                M2C_FIELD(arg0, s32 *, 0x74) = 1;
                M2C_FIELD(arg0, s32 *, 0x64) = 0x96;
                return;
            }
            goto block_11;
        }
block_11:
        if (M2C_FIELD(arg0, s32 *, 0x64) < 0) {
            M2C_FIELD(arg0, s32 *, 0x64) = 0;
        }
        if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
            func_80043328(arg0, 0x55, 0x100);
            M2C_FIELD(arg0, s32 *, 0x74) = 0;
        }
        temp_fv0 = M2C_FIELD(arg0, f32 *, 0xB4) + M2C_FIELD(arg0, f32 *, 0xAC);
        temp_s3 = arg0 + 4;
        M2C_FIELD(arg0, f32 *, 0xB4) = temp_fv0;
        temp_s1 = func_80081990(temp_s3, temp_s2, temp_fv0);
        func_80081AC0(&sp10, temp_s2, M2C_FIELD(arg0, f32 *, 0xB4));
        temp_v0 = func_8002492C(sp10, sp18);
        M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
        if (M2C_FIELD(arg0, s32 *, 0xBC) <= 0) {
            M2C_FIELD(arg0, s32 *, 0x10) = func_8002D260(temp_v0 + 0x8000);
        }
        if (temp_s1 != 0) {
            temp_v1 = M2C_FIELD(arg0, void (**)(void *), 0x9C);
            M2C_FIELD(arg0, void (**)(void *), 0x9C) = func_8007631C;
            { { M2C_FIELD(arg0, f32 *, 0xAC) = (f32) -M2C_FIELD(arg0, f32 *, 0xAC); } }
            { { M2C_FIELD(arg0, s32 *, 0xBC) = (s32) -M2C_FIELD(arg0, s32 *, 0xBC); } }
            M2C_FIELD(arg0, void (**)(void *), 0xD8) = temp_v1;
            func_80043328(arg0, 0x58, 0x100);
            temp_fv1 = M2C_FIELD(arg0, f32 *, 0xB4) + (2.0f * M2C_FIELD(arg0, f32 *, 0xAC));
            M2C_FIELD(arg0, s32 *, 0x74) = 1;
            M2C_FIELD(arg0, f32 *, 0xB4) = temp_fv1;
            func_80081990(temp_s3, temp_s2, temp_fv1);
        }
    }
}


