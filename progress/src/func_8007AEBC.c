#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 randomRange(s32, s32);
void func_8002D3E4(void *, s32);
s32 tickActorTimer();
f32 getCameraTargetDist(void *, f32, s32 *);
void func_8002DA80(void *);
void func_8003C140(void *);
void animStepKeys(void *);
extern s32 gCamSpeedScale;
extern void *gCameraTarget;

void func_8007AEBC(void *arg0) {
    s32 sp10;
    f32 dist;
    f32 dz;
    s32 k;

    if (tickActorTimer() != 0) {
        F(arg0, void (**)(void *), 0xA0)(arg0);
        return;
    }
    F(arg0, s32 *, 0x5C) += gCamSpeedScale * 8;
    if (F(arg0, s32 *, 0x5C) >= 0x100) {
        F(arg0, s32 *, 0x5C) = 0xFF;
    }
    animStepKeys(arg0);
    dist = getCameraTargetDist(arg0, 500.0f, &sp10);
    F(arg0, s32 *, 0x10) = sp10 + randomRange(-300, 300);
    k = 0x8A;
    if (dist < 140.0f) {
        k = 0;
    }
    dz = F(gCameraTarget, f32 *, 8) - F(arg0, f32 *, 8);
    func_8002D3E4(arg0, k);
    func_8002DA80(arg0);
    if (dist < 150.0f && dz < 150.0f) {
        F(gCameraTarget, s32 *, 0xF0) = randomRange(0x80, 0xFF);
        func_8003C140(gCameraTarget);
    }
}
