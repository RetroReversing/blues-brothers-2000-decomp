typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x54];
    s32 f64;
    u8 pad68[8];
    s32 f70;
    u8 pad74[0x28];
    void *f9C;
} Obj;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Pt;
void func_80015C30(Obj *);
s32 spawnEffectObj(s32, s32, s32, s32);
f32 getCameraTargetDist(Obj *, f32, s32 *);
void actorSetAnim(Obj *, s32, s32);
void animStepKeys(void);
void func_80072310(void);
float sqrtf(float);
extern Obj *D_800B3964;
extern Obj *gCameraTarget;
extern Pt *gSplineSrcPoints[];

void func_800721A8(Obj *o) {
    s32 i;
    Pt *pt;
    Obj *n;
    f32 dx;
    f32 dz;

    if (getCameraTargetDist(o, 450.0f, NULL) < 450.0f) {
        i = o->f70;
        pt = gSplineSrcPoints[i];
        dx = pt->x - o->x;
        dz = pt->z - o->z;
        if (sqrtf(dx * dx + dz * dz) < 3000.0f) {
            n = (Obj *)spawnEffectObj(1, 0, 0, 0);
            n->f9C = func_80072310;
            n->f70 = i;
            D_800B3964->f64 = 300;
            actorSetAnim(gCameraTarget, 0x20, 0xF0);
            gCameraTarget->x = n->x;
            gCameraTarget->y = n->y;
            gCameraTarget->z = n->z;
            gCameraTarget->f9C = animStepKeys;
            for (i = 0; i < 4; i++) {
                func_80015C30(o);
            }
        }
    }
}
