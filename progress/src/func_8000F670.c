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

s32 cameraGetMode(void);                          /* extern */
s32 func_8000F5E4();                            /* extern */
s32 sendCommand(s32, s32);            /* extern */
s32 tickActorTimer(arg0);                            /* extern */
f32 func_8002DD60(f32);                             /* extern */
extern f32 D_80000608;
extern f32 D_8000060C;
extern s32 D_800B3838;
extern void *D_800B3964;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 D_800BD274;
extern s32 func_8000F310;
extern s32 func_80023078;

typedef struct { unsigned char pad[100]; int value; } __repair_field_64;
void func_8000F670(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fs2;

    tickActorTimer();
    if (((__repair_field_64 *)arg0)->value <= 0) {
        ((__repair_field_64 *)arg0)->value = 0;
        temp_fs0 = (*(f32 *)((s8 *)arg0 + 0xC)) - (*(f32 *)((s8 *)gCameraTarget + 0xC));
        temp_fs1 = 250.0f;
        temp_fs2 = (*(f32 *)((s8 *)arg0 + 8)) - (*(f32 *)((s8 *)gCameraTarget + 8));
        if ((func_8002DD60((*(f32 *)((s8 *)arg0 + 4)) - (*(f32 *)((s8 *)gCameraTarget + 4))) < temp_fs1) && (func_8002DD60(temp_fs0) < temp_fs1) && (func_8002DD60(temp_fs2) < 400.0f)) {
            func_8000F5E4();
            (*(s32 *)((s8 *)arg0 + 0)) = 0x101;
            (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_8000F310;
            D_800BD274 = (*(s32 *)((s8 *)arg0 + 0xBC));
            if (D_800B3964 != NULL) {
                (*(void **)((s8 *)D_800B3964 + 0x9C)) = (void *) ((&func_80023078) + 0x2);
            }
            D_800B3838 = 0;
            D_800B5DD4 = 0;
            if (cameraGetMode() == 1) {
                sendCommand(0x19, 0);
            }
        }
    }
}
