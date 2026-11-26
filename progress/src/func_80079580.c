typedef struct Obj {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    char pad14[0x44];
    s32 f58;
    char pad5C[8];
    s32 f64;
    char pad68[8];
    s32 f70;
    char pad74[4];
    s32 f78;
    char pad7C[8];
    s32 f84;
    char pad88[4];
    s32 f8C;
    char pad90[0xC];
    void *f9C;
    void (*fA0)(struct Obj *);
    char padA4[0x2C];
    s32 fD0;
    char padD4[4];
    s32 fD8;
    f32 fDC;
} Obj;
s32 cameraGetMode();
s32 func_8000DF10();
s32 randomRange();
s32 approachAngle(s32, s32, s32);
s32 tickActorTimer();
f32 func_8002DD60(f32);
s32 func_8003BF98();
s32 func_8003C9AC();
Obj *func_80042F00();
s32 animStepKeys();
s32 func_80043328();
s32 actorSetAnim();
s32 func_80076080();
s32 func_80083920();
s32 func_800853E8();
extern f32 D_801700D0;
extern s32 D_801700D4;
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;
extern s32 func_8007631C;

void func_80079580(Obj *self) {
    f32 v[4];
    char big[0xF8];
    f32 near;
    f32 dy;
    s32 mode;
    s32 id;
    Obj *o;
    s32 n;

    if (func_80076080() != 0) {
        return;
    }
    near = D_801700D0;
    id = D_801700D4;
    dy = self->y - gCameraTarget->y;
    tickActorTimer(self);
    switch (func_80083920(self, self->f64 > 0)) {
    case 1:
        actorSetAnim(o, 0x96, 0x100);
        self->f64 = 0x64;
        break;
    case 2:
        o = func_80042F00(0x21, 0, 0, 0);
        actorSetAnim(o, 0x95, 0x100);
        o->f58 = self->f58;
        o->f9C = &func_8007631C;
        o->fD8 = 0;
        o->x = self->x;
        o->y = self->y;
        o->z = self->z;
        o->f10 = self->f10;
        self->fA0(self);
        return;
    }
    func_800853E8(self);
    self->f70 = animStepKeys(self);
    if (self->f70 != 0) {
        self->f8C = self->f8C - 1;
    }
    if (self->f8C == 0) {
        self->f84 = 0;
        if (self->fD0 == 0x92) {
            func_80043328(self, 0x93, 0x100);
        } else {
            func_80043328(self, 0x92, 0x100);
        }
        self->f8C = randomRange(1, 4);
    }
    self->f10 = approachAngle(id, self->f10, gCamSpeedScale << 9);
    if (near < 885.0f) {
        if (func_8002DD60(dy) < 250.0f) {
            if (self->f64 <= 0) {
                if (func_8003C9AC(self, 0, 1, 1) != 0) {
                    func_80043328(self, 0x94, 0x100);
                    self->f8C = 1;
                    if (350.0f < near) {
                        if (10.0f < self->fDC) {
                            if (self->f84 == 0) {
                                func_8003BF98(self);
                                self->f84 = self->f84 + 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (cameraGetMode() == 0x30) {
        if (self->fD0 == 0x93) {
            n = (s32) self->fDC;
            if (n >= 0x29) {
                n -= 0x14;
            }
            if ((u32) (n - 0x13) < 4) {
                if (self->f78 == 0) {
                    v[1] = self->x;
                    v[2] = self->y;
                    v[3] = self->z;
                    func_8000DF10(v);
                    self->f78 = 1;
                }
            } else {
                self->f78 = 0;
            }
        }
    }
}
