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

s16 coss(s32);                                      /* extern */
s32 func_800134F0(void *);                      /* extern */
s32 func_80013550(void *);                      /* extern */
s32 syncActorPrevPos(void *);                      /* extern */
s32 initSpline(s32, s32);       /* extern */
s32 func_80081990(void *, s32, f32);                /* extern */
s32 func_80081AC0(s32 *, s32, f32);         /* extern */
extern s32 D_800B4D2C;
extern s32 gTextWaveTime;
extern s32 *gCameraTarget;
extern s32 func_800768E8;

void func_8007B330(void *arg0) {
    char sp10[0x20];
    s32 *temp_v1;
    f32 temp_fv0;
    s32 temp;

    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        M2C_FIELD(arg0, s32 *, 0) = 0x142;
        M2C_FIELD(arg0, s32 *, 0x80) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = M2C_FIELD(arg0, s32 *, 0x70) * 200;
        initSpline(M2C_FIELD(arg0, s32 *, 0x70), 0);
        M2C_FIELD(arg0, f32 *, 0xAC) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0xB4) = 0.05f;
    }
    temp = *gCameraTarget;
    if ((temp != 3) || (D_800B4D2C != 0)) {
        M2C_FIELD(arg0, f32 *, 0xAC) = 0.0f;
        M2C_FIELD(arg0, s32 *, 0xA8) = 0;
        M2C_FIELD(arg0, f32 *, 0xDC) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0xB4) = 0.05f;
    }
    if (M2C_FIELD(arg0, s32 *, 0xA8) != 0) {
        M2C_FIELD(arg0, f32 *, 0xAC) = M2C_FIELD(arg0, f32 *, 0xB4);
    } else {
        M2C_FIELD(arg0, f32 *, 0xAC) = M2C_FIELD(arg0, f32 *, 0xAC) * 0.95;
    }
    M2C_FIELD(arg0, f32 *, 0xDC) += M2C_FIELD(arg0, f32 *, 0xAC);
    if (func_80081990((char *)arg0 + 4, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xDC)) != 0) {
        if (M2C_FIELD(arg0, f32 *, 0xDC) <= 0.0) {
            M2C_FIELD(arg0, f32 *, 0xB4) = 0.05f;
        } else {
            M2C_FIELD(arg0, f32 *, 0xB4) = -0.05f;
        }
        M2C_FIELD(arg0, s32 *, 0x64) = 0x12C;
        temp_v1 = M2C_FIELD(arg0, s32 **, 0x9C);
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_800768E8;
        M2C_FIELD(arg0, s32 **, 0xD8) = temp_v1;
    }
    if (M2C_FIELD(arg0, s32 *, 0xA8) != 0) {
        temp = (coss((gTextWaveTime * 0x320) & 0xFFE0) * 5) >> 0xE;
    } else {
        temp = (coss((gTextWaveTime * 0x320) & 0xFFE0) * 5) >> 0xD;
    }
    do { temp += 0x140; M2C_FIELD(arg0, f32 *, 8) -= temp; } while (0);
    func_80081AC0((s32 *)sp10, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xDC));
    M2C_FIELD(arg0, f32 *, 0x4C) = M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(arg0, f32 *, 0x40);
    M2C_FIELD(arg0, f32 *, 0x54) = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(arg0, f32 *, 0x48);
    syncActorPrevPos(arg0);
    func_800134F0(arg0);
    func_80013550(arg0);
}
