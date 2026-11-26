typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x3C];
    f32 f4C;
    f32 f50;
    f32 f54;
    u8 pad58[0x20];
    s32 f78;
    s32 f7C;
    u8 pad80[0x50];
    s32 fD0;
} Obj;
f32 getCameraTargetDist(Obj *, f32, s32 *);
void actorSetAnim(Obj *, s32, s32);
void func_8002ACAC(void);
s32 animStepKeys(Obj *);
s32 func_80043248(Obj *);
extern Obj *gCameraTarget;
extern s32 D_80140240;
extern f32 D_800B9EC4;
extern s32 D_800BD100;
extern s32 D_80107040;

void func_80078B00(Obj *o) {
    Obj *p;
    f32 f;
    f32 k;
    f32 g;
    f32 c;

    if (o->f7C == 0) {
        if (getCameraTargetDist(o, 300.0f, NULL) < 300.0f) {
            actorSetAnim(gCameraTarget, 5, 0x100);
            func_8002ACAC();
            f = D_80140240 * 1.5f;
            c = 7000.0f;
            g = D_800B9EC4 * c;
            gCameraTarget->f4C *= 3.0f;
            gCameraTarget->f54 *= 3.0f;
            gCameraTarget->y += 1.0f;
            gCameraTarget->f50 = f + g;
            o->f7C = 1;
            o->f78 = 1;
            animStepKeys(o);
        }
    } else if (func_80043248(o) != 0) {
        o->f7C = 0;
    }
    if (o->f78 != 0) {
        p = gCameraTarget;
        if (p->fD0 == 5 && !(D_80107040 & 0x8000)) {
            k = 3500.0f;
            if (D_800BD100 == 1) {
                k = 1750.0f;
            }
            p->f50 += D_800B9EC4 * k;
        } else {
            o->f78 = 0;
        }
    }
}
