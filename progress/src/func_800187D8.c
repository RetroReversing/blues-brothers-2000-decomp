typedef struct O187D8 {
    s32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x9C - 0x1C];
    void (*f9C)(void);
    void (*fA0)(struct O187D8 *);
} O187D8;
O187D8 *func_80017DEC(s32);
O187D8 *findActor(s32, s32);
f32 getCameraTargetDist(O187D8 *, f32, s32);
extern O187D8 *D_800B3960;
extern O187D8 *gCameraTarget;
void updateCameraView(void);
void func_80036DB4(void);

void func_800187D8(O187D8 *arg0) {
    O187D8 *q;
    O187D8 *o;
    f32 d;

    d = getCameraTargetDist(arg0, 300.0f, 0);
    arg0->f0 = 0x10D;
    if (d < 300.0f) {
        if (gCameraTarget->f8 < arg0->f8 - 100.0f) {
            q = findActor(0x11E, 0);
            if (q != NULL) {
                gCameraTarget->f4 = q->f4;
                gCameraTarget->f8 = q->f8;
                gCameraTarget->fC = q->fC;
            }
            q = func_80017DEC(1);
            if (q != NULL) {
                o = D_800B3960;
                o->f4 = q->f4;
                o->f8 = q->f8;

                o->fC = q->fC;
                o->f9C = func_80036DB4;

                o->f10 = q->f10;
                o->f14 = q->f14;
                o->f18 = q->f18;
                o->f9C = updateCameraView;

            }
            arg0->fA0(arg0);
        }
    }
}
