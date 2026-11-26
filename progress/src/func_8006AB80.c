f32 approachF32(f32, f32, f32);
extern s32 gCamSpeedScale;

void func_8006AB80(void *arg0) {
    *(f32 *)((s8 *)arg0 + 8) = approachF32(150.0f, *(f32 *)((s8 *)arg0 + 8), (f32) (gCamSpeedScale * 10));
}
