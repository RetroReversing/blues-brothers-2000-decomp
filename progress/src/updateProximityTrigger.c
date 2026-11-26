s16 coss(u16);
s16 sins(u16);
void *func_8001B91C(void);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80023E3C(s32);
void func_8002ADFC(s32, s32, void *);
void *func_8002B240(s32, s32, s32, s32, s32, s32);
void func_8002D604(void *);
f32 func_8002DD60(f32);
void actorSetAnim(void *, s32, s32);
void func_8003BC40();
typedef struct Obj Obj;
typedef void (*Fn)(Obj *);
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 ang;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ u8 pad40[0x18];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[0x10];
    /* 0x6C */ s32 f6C;
    /* 0x70 */ s32 f70;
    /* 0x74 */ s32 f74;
    /* 0x78 */ s32 f78;
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x10];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[8];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ Fn fA0;
    /* 0xA4 */ s32 fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0xC];
    /* 0xB8 */ s32 fB8;
    /* 0xBC */ u8 padBC[0x28];
    /* 0xE4 */ s32 fE4;
    /* 0xE8 */ u8 padE8[8];
    /* 0xF0 */ s32 fF0;
};
extern f32 gTargetOffset[3];
extern Obj *gCameraRig;
extern s32 gTextWaveTime;
extern Obj *gCameraTarget;
extern s32 D_800BD100;
extern u8 D_800BD1F0[];

/* Proximity trigger: once the camera target is within range, runs the trigger
   behaviour and marks it used for this stage; otherwise it updates the idle wave
   animation. */
void updateProximityTrigger(Obj *self) {
    f32 offZ;
    f32 offY;
    f32 range;

    if (self->f7C == 0) {
        if (D_800BD1F0[D_800BD100 * 10 + self->f70] == 1) {
            self->fA0(self);
            return;
        }
        self->f58 = packDrawFlags(1, 1, 0, 2, 0, 1, 1, 0);
        self->f0 = 0x101;
        self->f7C = 1;
        self->fB8 = 0x98;
        self->fE4 = func_80023E3C(0x98);
        if (self->f74 == 0) {
            self->fA8 = func_8002B240(self->x, self->y, self->z, 0xBF, 3000, 0);
        }
    }
    gTargetOffset[0] = self->x - gCameraTarget->x;
    gTargetOffset[1] = offZ = self->z - gCameraTarget->z;
    gTargetOffset[2] = offY = self->y - gCameraTarget->y;
    range = 180.0f;
    if (func_8002DD60(gTargetOffset[0]) < range && func_8002DD60(offY) < 360.0f && func_8002DD60(offZ) < range) {
        func_8002ADFC(6, 1000, self);
        if (gCameraTarget->f90 == 1) {
            gCameraTarget->fF0 = 0xFF;
            gCameraTarget->ang = gCameraRig->ang + 0x8000;
            actorSetAnim(gCameraTarget, 0x1A, 0x100);
            gCameraTarget->f9C = func_8003BC40;
            gCameraTarget->fF0 = 0xFF;
            gCameraTarget->f0 = 0x101;
        } else {
            gCameraTarget->f6C = 2;
        }
        D_800BD1F0[D_800BD100 * 10 + self->f70] = 1;
        func_8001B91C();
        if (self->fA8 != 0) {
            self->fA8->fA0(self->fA8);
        }
        self->fA0(self);
        return;
    }
    func_8002D604(self);
    self->f38 = (coss((gTextWaveTime * 2000) & 0xFFF0) >> 11) + 0x100;
    self->f3C = (sins((gTextWaveTime * 2000) & 0xFFF0) >> 11) + 0x100;
    self->f34 = (sins((gTextWaveTime * 2000) & 0xFFF0) >> 11) + 0x100;
}
