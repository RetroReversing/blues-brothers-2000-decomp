#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void updateCameraView(void *);
f32 approachF32(f32, f32, f32);
void func_80034FEC(void *, s32 *);
void func_80036FB8(void *, s32);
extern s32 gCamSpeedScale;
extern void *gCameraTarget;

void func_80064730(void *arg0) {
    s32 sp10[3];

    F(arg0, f32 *, 0xC) = approachF32(F(gCameraTarget, f32 *, 0xC) - 1250.0f, F(arg0, f32 *, 0xC), gCamSpeedScale * 50);
    F(arg0, f32 *, 4) = F(arg0, f32 *, 0x40);
    F(arg0, f32 *, 8) = F(arg0, f32 *, 0x44) - 200.0f;
    sp10[0] = F(F(arg0, void **, 0xA8), f32 *, 4);
    sp10[1] = F(F(arg0, void **, 0xA8), f32 *, 8);
    sp10[2] = F(F(arg0, void **, 0xA8), f32 *, 0xC);
    func_80034FEC(arg0, sp10);
    updateCameraView(arg0);
    func_80036FB8(arg0, 0xF);
}
