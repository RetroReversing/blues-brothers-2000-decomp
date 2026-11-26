typedef struct Obj {
    s32 f0;
    f32 x;
    s32 f8;
    f32 z;
    s32 pad10[0x13];
    s32 f5C;
    s32 pad60;
    s32 f64;
    s32 f68;
    s32 pad6C[4];
    s32 f7C;
    s32 pad80;
    s32 f84;
    s32 pad88;
    s32 f8C;
    s32 f90;
    s32 f94;
    void *f98;
    void *f9C;
    void (*fA0)(struct Obj *);
    s32 padA4;
    struct Obj *fA8;
    s32 padAC[5];
    s32 fC0;
} Obj;
Obj *findActor();
s32 func_80023C64();
s32 sendCommand();
s32 tickActorTimer();
s32 func_8007C310();
s32 func_8007C54C();
s32 func_8007C780();
extern Obj *gCameraRig;
extern Obj *gCameraTarget;
extern s32 D_800BD0E0[];
extern s32 gPadPressed;
extern s32 D_8014002C;
extern Obj *D_801700E8;
extern s32 func_80023078;
extern s32 func_8007BE88;
extern s32 drawMeterPips;

void func_8007CB84(Obj *self) {
    s32 n;
    Obj *p;
    s32 *e;

    n = 0;
    if (self->f7C == 0) {
        func_8007C780();
        self->f98 = &drawMeterPips;
        self->f68 = 0xD;
        self->f7C = 1;
        self->f90 = 0x1D;
        self->f94 = 0x1E;
        self->f64 = 0x64;
        self->f8C = 0;
        D_801700E8 = self;
        p = findActor(0x100B, 0);
        while (p != 0) {
            p->f90 = 0;
            p = findActor(0x100B, p);
        }
        gCameraTarget->x = self->fA8->x;
        gCameraTarget->z = self->fA8->z;
        gCameraRig->fC0 = 1;
        gCameraTarget->f68 = -1;
        e = &D_800BD0E0[D_800BD0E0[8]];
        D_8014002C = 1;
        if (e[1] >= 10) {
            e[1] -= 10;
        }
        p = findActor(6, 0);
        if (p != 0) {
            p->f68 = -1;
        }
        func_8007C54C();
        return;
    }
    if (gPadPressed & 0x2000) {
        if (self->f90 >= 0 && self->f94 > 0) {
            self->f90 = self->f90 - 1;
            func_8007C310();
            sendCommand(0x15, 0);
        }
    }
    if (tickActorTimer(self) != 0) {
        self->f64 = 0x64;
        if (self->f94 > 0 && self->f90 > 0) {
            self->f94 = self->f94 - 1;
            return;
        }
        p = findActor(0x100B, 0);
        while (p != 0) {
            if (p->f84 != 0) {
                n++;
                p->fC0 |= 8;
            }
            p = findActor(0x100B, p);
        }
        D_8014002C = 0;
        gCameraRig->fC0 = 0;
        gCameraTarget->f68 = 4;
        self->f9C = (char *)&func_8007BE88 + 8;
        self->f98 = (char *)&func_80023078 + 8;
        if (n >= 8) {
            self->f7C = 8;
            self->fA8->f90 = 1;
        } else {
            self->f7C = 6;
            self->fA8->f90 = 0;
        }
        p = findActor(0x1008, 0);
        while (p != 0) {
            p->f9C = (char *)&func_80023078 + 8;
            p->fA0(p);
            p = findActor(0x1008, p);
        }
        func_80023C64(0x122);
        p = findActor(6, 0);
        if (p != 0) {
            p->f68 = 0xF;
        }
    }
}
