s32 cameraGetMode(void *);
void func_8003C140(void *);
extern void *D_800B3960;
extern void *gCameraTarget;
extern s32 func_80036DB4;

typedef struct {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x8C];
    s32 *unk9C;
} Obj;

void func_8007591C(s32 arg0, s32 arg1) {
    s32 r;

    if (((Obj *)gCameraTarget)->y < arg1 && ((Obj *)D_800B3960)->unk9C != &func_80036DB4) {
        ((Obj *)D_800B3960)->x = ((Obj *)gCameraTarget)->x;
        ((Obj *)D_800B3960)->z = ((Obj *)gCameraTarget)->z;
        r = cameraGetMode(D_800B3960);
        if (r == 9 || r == 0x11) {
            ((Obj *)D_800B3960)->y = 1000.0f;
        } else {
            ((Obj *)D_800B3960)->y = -1000.0f;
        }
        ((Obj *)D_800B3960)->unk9C = &func_80036DB4;
    }
    if (((Obj *)gCameraTarget)->y < arg0 && ((Obj *)gCameraTarget)->unk0 == 3) {
        func_8003C140(gCameraTarget);
    }
}
