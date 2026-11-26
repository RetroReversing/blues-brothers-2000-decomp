typedef struct G {
    u8 p0[0xC]; f32 fC; s32 f10; u8 p1[0x34]; f32 f48; u8 p2[0x18]; s32 f64; u8 p3[0x14]; s32 f7C; s32 f80;
} G;
extern void syncActorPrevPos();
extern s32 func_8006DA0C(G *);
extern void animStepKeys(G *);
extern s32 tickActorTimer(G *);
extern f32 approachF32(f32, f32, f32);
extern void actorSetAnim(G *, s32, s32);
extern s32 func_80043248(G *);

void func_8006E0A0(G *arg0) {
    f32 temp_fv0;

    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        arg0->f10 = 0;
        arg0->f80 = 0;
        arg0->f64 = 0xA;
        syncActorPrevPos();
    }
    if (func_8006DA0C(arg0) == 0) {
        switch (arg0->f80) {
        case 0:
            animStepKeys(arg0);
            if (tickActorTimer(arg0) != 0) {
                arg0->f64 = 0xA;
                temp_fv0 = approachF32(arg0->f48 + 500.0f, arg0->fC, 20.0f);
                arg0->fC = temp_fv0;
                if (temp_fv0 == (arg0->f48 + 500.0f)) {
                    arg0->f80 = 1;
                    actorSetAnim(arg0, 0x51, 0x100);
                }
            }
            break;
        case 1:
            if (func_80043248(arg0) != 0) {
                arg0->f10 = 0x8000;
                arg0->f80 = 2;
                actorSetAnim(arg0, 0x4F, 0x100);
            }
            break;
        case 2:
            animStepKeys(arg0);
            if (tickActorTimer(arg0) != 0) {
                arg0->f64 = 0xA;
                temp_fv0 = approachF32(arg0->f48, arg0->fC, 20.0f);
                arg0->fC = temp_fv0;
                if (temp_fv0 == arg0->f48) {
                    arg0->f80 = 3;
                    actorSetAnim(arg0, 0x51, 0x100);
                }
            }
            break;
        case 3:
            if (func_80043248(arg0) != 0) {
                arg0->f10 = 0;
                arg0->f80 = 0;
                actorSetAnim(arg0, 0x4F, 0x100);
            }
            break;
        }
    }
}
