typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u8 pad10[0x60];
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    u8 pad80[0x1C];
    void *f9C;
} Obj;
Obj *func_8007B880(void);
Obj *func_80056F04(Obj *);
Obj *spawnEffectObj(s32, s32, s32, s32);
void func_8003BB90(Obj *);
void func_8007BC24(void);
extern Obj *gCameraTarget;

void func_8007BD08(Obj *arg0) {
    Obj *p;

    if (arg0->f7C == 0) {
        arg0->f70 = 0;
        arg0->f74 = 0;
        arg0->f78 = 0;
        p = func_8007B880();
        p->x = 160684.0f;
        p->y = -24986.0f;
        p->z = 58640.0f;
        p = func_80056F04(arg0);
        p->x = 161868.0f;
        p->y = -24000.0f;
        p->z = 53933.0f;
        p = spawnEffectObj(1, 0, 0, 0);
        p->f9C = func_8007BC24;
        p->f70 = 1;
        p = spawnEffectObj(1, 0, 0, 0);
        p->f9C = func_8007BC24;
        p->f70 = 2;
        p = spawnEffectObj(1, 0, 0, 0);
        p->f9C = func_8007BC24;
        p->f70 = 3;
        p->f74 = 1;
        p = spawnEffectObj(1, 0, 0, 0);
        p->f9C = func_8007BC24;
        p->f70 = 4;
        p->f74 = 1;
        arg0->f7C = 1;
    }
    if (gCameraTarget->y < -25355.0f && gCameraTarget->f0 == 3) {
        func_8003BB90(gCameraTarget);
    }
}
