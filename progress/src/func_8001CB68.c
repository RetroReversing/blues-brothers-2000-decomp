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

s32 func_800171C0(void *);                      /* extern */
s32 func_8001B990(s32, s32);            /* extern */
void *func_800232B4(s32, s32, s32, s32); /* extern */
extern f32 D_80000CB4;
extern s32 gCamSpeedScale;
extern s32 func_8001C964;
extern s32 func_80023078;

void func_8001CB68(void *arg0) {
    s32 *__base_func_80023078;
    f32 temp_fv1;
    void *temp_v0;

    temp_fv1 = M2C_FIELD(arg0, f32 *, 0xC) - (f32) (gCamSpeedScale * 2);
    M2C_FIELD(arg0, f32 *, 0xC) = temp_fv1;
    if (temp_fv1 <= (M2C_FIELD(arg0, f32 *, 0x48) - D_80000CB4)) {
        if (M2C_FIELD(arg0, s32 *, 0x70) == 1) {
            func_8001B990(0x200, 0x15);
        } else {
            func_8001B990(0x200, 0x16);
        }
        __base_func_80023078 = &func_80023078;
        M2C_FIELD(arg0, void **, 0x9C) = (void *) (__base_func_80023078 + 0x2);
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        func_800171C0(arg0);
        temp_v0 = func_800232B4(1, 0, 0, 0);
        M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_8001C964;
        M2C_FIELD(temp_v0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x70);
    }
}
