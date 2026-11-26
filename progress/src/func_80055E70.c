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

s32 cameraGetMode();                                /* extern */
s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80023DBC(M2C_UNK);                         /* extern */
f32 func_8002DD60(f32);                             /* extern */
M2C_UNK animStepKeys(void *);                      /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
M2C_UNK startStoryDialog(s32, M2C_UNK *, void *);      /* extern */
s32 func_80076080();                                /* extern */
extern M2C_UNK D_80008338;
extern M2C_UNK D_80008340;
extern void *gCameraTarget;
extern f32 D_801700D0;
extern s32 D_801700D4;

void func_80055E70(void *arg0) {
    f32 temp_fs0;
    s32 temp_s1;

    if (func_80076080() == 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) D_801700D4;
        temp_fs0 = D_801700D0;
        do { animStepKeys(arg0); } while (0);
        if (cameraGetMode() == 3) {
            if (temp_fs0 <= 500.0f) {
                M2C_FIELD(arg0, s32 *, 0x80) = 0;
                if (M2C_FIELD(arg0, s32 *, 0xD0) == 0xBF) {
                    func_80043328(arg0, 0xBE, 0x100);
                }
            } else {
                M2C_FIELD(arg0, s32 *, 0x80) = 1;
                M2C_FIELD(arg0, s32 *, 0x84) = 0;
            }
            if ((M2C_FIELD(arg0, s32 *, 0x80) == 0) && (func_8002DD60(M2C_FIELD(arg0, f32 *, 8) - M2C_FIELD(gCameraTarget, f32 *, 8)) < 500.0f) && (M2C_FIELD(arg0, s32 *, 0x84) == 0)) {
                temp_s1 = func_80023DBC(0xE1B);
                func_80052A5C(0x561);
                if (func_8001B990(0x100, 0x1C) != 0) {
                    startStoryDialog(temp_s1, &D_80008338, arg0);
                    func_8001B990(0x200, 0x1B);
                } else {
                    startStoryDialog(temp_s1, &D_80008340, arg0);
                }
                func_80043328(arg0, 0xBF, 0x100);
                M2C_FIELD(arg0, s32 *, 0x84) = 1;
            }
        }
    }
}

