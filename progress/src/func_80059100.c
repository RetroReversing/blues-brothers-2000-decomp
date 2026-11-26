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
s32 func_8002492C(f32, f32);
f32 getCameraTargetDist(void *, f32, s32);
void animStepKeys(void *);
void func_80043328(void *, s32, s32);
void func_80058F74(void *, void *);
void func_80081990(void *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
extern s32 gSplinePointCount[];
extern s32 func_80058FA8;
extern s32 func_80059058;

void func_80059100(void *arg0) {
    f32 v[4];
    f32 t;
    f32 lim;

    if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
        func_80043328(arg0, 0x40, 0x180);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) & ~1) {
        func_80058F74(arg0, &func_80059058);
        return;
    }
    if (getCameraTargetDist(arg0, 400.0f, 0) < 400.0f) {
        func_80058F74(arg0, &func_80058FA8);
        return;
    }
    animStepKeys(arg0);
    t = M2C_FIELD(arg0, f32 *, 0xB4) + 0.05;
    M2C_FIELD(arg0, f32 *, 0xB4) = t;
    lim = (f32) gSplinePointCount[M2C_FIELD(arg0, s32 *, 0x70)] - 1.0f;
    if (lim <= t) {
        M2C_FIELD(arg0, f32 *, 0xB4) = t - lim;
    }
    func_80081990((s8 *)arg0 + 4, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xB4));
    func_80081AC0(v, M2C_FIELD(arg0, s32 *, 0x70), M2C_FIELD(arg0, f32 *, 0xB4));
    M2C_FIELD(arg0, s32 *, 0x10) = func_8002492C(v[0], v[2]);
}
