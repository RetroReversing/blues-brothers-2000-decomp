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
void *findActor(M2C_UNK, M2C_UNK);              /* extern */
f32 func_8002D858(void *, M2C_UNK);                 /* extern */
f32 func_8002DD60(f32);                             /* extern */
s32 func_8003C9AC(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 animStepKeys();                                /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80052A30();                            /* extern */
s16 sins(u16);                                      /* extern */
extern void *gCameraTarget;

void func_800506D0(void *arg0) {
    f32 temp_fs0;
    s32 temp_s1;
    s32 temp_v1;
    void *temp_v0;

    temp_s1 = animStepKeys();
    if ((M2C_FIELD(findActor(0x102D, 0), s32 *, 0xFC) <= 0) && (temp_fs0 = func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 8) - M2C_FIELD(arg0, f32 *, 8)), !(800.0f < func_8002D858(arg0, 0))) && !(800.0f < temp_fs0)) {
        if ((func_8003C9AC(arg0, 0, 1, 0) != 0) && (M2C_FIELD(arg0, s32 *, 0x80) == 0)) {
            func_80052A30();
            func_80043328(gCameraTarget, 1, 0x100);
            M2C_FIELD(arg0, s32 *, 0x80) = 1;
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x7C);
        switch (temp_v1) {                          /* irregular */
        case 0:
            if (temp_s1 != 0) {
                func_80043328(arg0, 0x83, 0x100);
                func_80043328(M2C_FIELD(arg0, void **, 0xA8), 0x86, 0x100);
                M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
                return;
            }
            break;
        case 1:
            if (temp_s1 != 0) {
                func_80043328(arg0, 0x80, 0x100);
                func_80043328(M2C_FIELD(arg0, void **, 0xA8), 0x84, 0x100);
                M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
                M2C_FIELD(arg0, f32 *, 8) = (f32) (-54.0f);
                M2C_FIELD(arg0, f32 *, 0xC) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + (f32) ((s32) (coss(M2C_FIELD(arg0, u16 *, 0x12)) * 0xAF) >> 0xE));
                M2C_FIELD(arg0, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + (f32) ((s32) (sins(M2C_FIELD(arg0, u16 *, 0x12)) * 0xAF) >> 0xE));
                return;
            }
            break;
        case 2:
            temp_v0 = findActor(0x13C, 0);
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(gCameraTarget, f32 *, 4);
                M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(gCameraTarget, f32 *, 8);
                M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(gCameraTarget, f32 *, 0xC);
            }
            break;
        }
    }
}

