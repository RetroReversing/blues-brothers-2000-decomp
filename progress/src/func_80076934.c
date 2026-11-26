#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 randomRange(s32, s32);
s32 sendCommand(s32, s32);
s32 func_8002D124();
s32 func_8002D260(s32);
s32 tickActorTimer(void *);
f32 func_8002DD60(f32);
s32 func_8003BF98(void *);
s32 isTargetVulnerable(void *, s32, s32, s32);
s32 animStepKeys(void *);
s32 func_80043328(void *, s32, s32);
s32 updateDistanceCull(void *);
extern void *gCameraTarget;
extern f32 D_801700D0;
extern s32 D_801700D4;
extern s32 func_8007631C;
extern s32 func_800768E8;
void func_80076934(void *arg0) {
    s32 buf[4];
    f32 f;
    f32 d;
    void *old;
    s32 v;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x74) = 0;
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
        M2C_FIELD(arg0, s32 *, 0x64) = randomRange(-200, 200) + 500;
    } else {
        if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x14C) {
            func_80043328(arg0, 0x14E, 0x100);
        }
        if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x14D) {
            func_80043328(arg0, 0x14F, 0x100);
        }
    }
    if (updateDistanceCull(arg0) == 0) {
        d = func_8002DD60(M2C_FIELD(gCameraTarget, f32 *, 8) - M2C_FIELD(arg0, f32 *, 8));
        f = D_801700D0;
        if (f < 525.0f && d < 500.0f && isTargetVulnerable(arg0, 1, 0, 0) != 0) {
            M2C_FIELD(arg0, s32 *, 0x74) = 1;
        }
        if (M2C_FIELD(arg0, s32 *, 0x74) == 0 && tickActorTimer(arg0) != 0) {
            if (M2C_FIELD(arg0, s32 *, 0xB8) == 0x4A) {
                func_80043328(arg0, 0x14D, 0x100);
            } else {
                func_80043328(arg0, 0x14C, 0x100);
            }
            old = M2C_FIELD(arg0, void **, 0x9C);
            M2C_FIELD(arg0, void **, 0x9C) = &func_8007631C;
            M2C_FIELD(arg0, s32 *, 0x64) = 500;
            M2C_FIELD(arg0, void **, 0xD8) = old;
            return;
        }
        if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
            if (animStepKeys(arg0) != 0) {
                old = M2C_FIELD(arg0, void **, 0x9C);
                M2C_FIELD(arg0, void **, 0x9C) = &func_800768E8;
                M2C_FIELD(arg0, s32 *, 0x80) = 0;
                M2C_FIELD(arg0, s32 *, 0x74) = 0;
                M2C_FIELD(arg0, s32 *, 0xCC) = 0;
                M2C_FIELD(arg0, s32 *, 0x64) = 100;
                M2C_FIELD(arg0, void **, 0xD8) = old;
                return;
            }
            if ((f32)(M2C_FIELD(arg0, s32 *, 0x84) - 7) < M2C_FIELD(arg0, f32 *, 0xDC) && M2C_FIELD(arg0, s32 *, 0xCC) == 0) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x16);
                M2C_FIELD(arg0, s32 *, 0xCC) = 1;
            }
            if (M2C_FIELD(arg0, s32 *, 0x80) == 0 && f < 475.0f) {
                if ((f32)M2C_FIELD(arg0, s32 *, 0x84) < M2C_FIELD(arg0, f32 *, 0xDC) && M2C_FIELD(arg0, f32 *, 0xDC) <= (f32)M2C_FIELD(arg0, s32 *, 0x88)) {
                    v = func_8002D260(D_801700D4 - M2C_FIELD(arg0, s32 *, 0x10));
                    if (v < 0) {
                        v = -v;
                    }
                    if (v < 0x800) {
                        if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x14E) {
                            sendCommand(0xC, 0x80);
                            sendCommand(8, 0xB6);
                        } else {
                            sendCommand(0xC, 0x80);
                            sendCommand(8, 0xB7);
                        }
                        func_8002D124();
                        func_8003BF98(arg0);
                        M2C_FIELD(arg0, s32 *, 0x80) = 1;
                    }
                }
            }
        }
    }
}
