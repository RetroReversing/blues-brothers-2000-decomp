typedef struct {
    u8 pad_0[8];
    f32 f8;
    u8 pad_C[4];
    s32 f10;
    u8 pad_14[0x30];
    f32 f44;
    u8 pad_48[0x14];
    s32 f5C;
    u8 pad_60[4];
    s32 f64;
    u8 pad_68[0xC];
    s32 f74;
    s32 f78;
    s32 f7C;
} Obj800548C0;

s32 approachAngle();
s32 approachS32();
f32 approachF32(f32, f32, f32);
s32 tickActorTimer();
s32 func_8002D858();
void animStepKeys();
void func_80043328();
void func_80058F74();
extern void *gCameraTarget;
extern s32 gCamSpeedScale;
void func_800549F8();
void func_80054BF0();
void func_80054F88();
void func_80055068();

void func_800548C0(Obj800548C0 *arg0) {
    s32 sp10;
    f32 temp_fa0;
    f32 temp_fs0;

    if (arg0->f7C != 0) {
        arg0->f7C = 0;
        func_80043328(arg0, 0x46, 0x100);
        arg0->f64 = 0x64;
        return;
    }
    temp_fa0 = ((f32 *)gCameraTarget)[2];
    arg0->f44 = temp_fa0;
    arg0->f8 = approachF32(temp_fa0, arg0->f8, 20.0f);
    temp_fs0 = (f32) func_8002D858(arg0, &sp10);
    arg0->f10 = approachAngle(sp10, arg0->f10, gCamSpeedScale << 8);
    arg0->f5C = approachS32(0x80, arg0->f5C, gCamSpeedScale * 2);
    animStepKeys(arg0);
    if (arg0->f78 <= 0) {
        func_80058F74(arg0, func_80054F88);
    } else if (arg0->f74 >= 0x190) {
        func_80058F74(arg0, func_80055068);
    } else if (tickActorTimer(arg0) != 0) {
        if (500.0f < temp_fs0) {
            func_80058F74(arg0, func_80054BF0);
        } else {
            func_80058F74(arg0, func_800549F8);
        }
    }
}
