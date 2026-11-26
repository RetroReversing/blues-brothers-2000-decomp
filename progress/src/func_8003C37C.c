typedef struct Obj Obj;
void func_8000DC80(Obj *);
Obj *func_800232B4(s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_8002A360(s32, s32);
s32 tickActorTimer(Obj *);
void func_80035238(void);
void func_8003BCC4(Obj *);
void func_800414D0(Obj *);
s32 func_80043248(Obj *);
void actorSetAnim(Obj *, s32, s32);
void updateModelBoneActors(Obj *);
void updateCameraView();
extern char func_80023078[];
void func_8003BE2C();
void func_8003BF4C();
void func_8003C37C(Obj *arg0);
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ u8 pad4[0x10];
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ u8 pad1C[0x18];
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ u8 pad40[0x1C];
    /* 0x5C */ s32 f5C;
    /* 0x60 */ u8 pad60[4];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ s32 f6C;
    /* 0x70 */ u8 pad70[0x28];
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[0x20];
    /* 0xC0 */ u32 fC0;
};
extern s32 D_800A9540;
extern Obj *gCameraRig;
extern s32 D_800B4D2C;
extern s32 D_800B5DD4;
extern s32 D_800B764C;
typedef struct { s32 f0; s32 pad[4]; s32 f14; } S0E0;
extern S0E0 D_800BD0E0;
extern s32 D_80140228;
extern s32 D_80140244;

void func_8003C37C(Obj *arg0) {
    Obj *o;

    switch (arg0->fC0) {
    case 0:
        actorSetAnim(arg0, 0x16, 0x100);
        arg0->f9C = func_8003C37C;
        arg0->f0 = 0x101;
        arg0->fC0++;
        break;
    case 1:
        if (func_80043248(arg0) != 0) {
            arg0->fC0++;
        }
        break;
    case 2:
        D_80140228 = 0;
        arg0->f98 = updateModelBoneActors;
        arg0->f64 = 150;
        arg0->fC0++;
        break;
    case 3:
        arg0->f68 = -1;
        arg0->f98 = func_800414D0;
        if (tickActorTimer(arg0) != 0) {
            arg0->fC0++;
            if (D_800BD0E0.f0 == 0) {
                arg0->fC0++;
            }
        }
        break;
    case 4:
        D_800B764C = 1;
        func_8000DC80(arg0);
        func_80035238();
        arg0->f5C = 0xFF;
        arg0->f18 = 0;
        arg0->f14 = 0;
        arg0->f68 = 3;
        arg0->f6C = 0;
        func_8003BCC4(arg0);
        D_800B5DD4 = 1;
        D_800B4D2C = 0;
        D_800BD0E0.f14 = D_800A9540;
        arg0->f3C = 0x100;
        arg0->f38 = 0x100;
        arg0->f34 = 0x100;
        break;
    case 5:
        arg0->f64 = 200;
        arg0->f9C = func_80023078 + 8;
        arg0->f98 = func_80023078 + 8;
        arg0->f68 = -1;
        o = func_800232B4(0x13F, 0, 0, 0);
        o->f9C = func_8003BF4C;
        o->f98 = func_8003BE2C;
        o->f68 = 0xE;
        o->f64 = 300;
        D_800A9540 = 2;
        gCameraRig->f9C = updateCameraView;
        D_80140244 = func_80023D58(0xD9E);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x13);
        func_8002A360(4, 0);
        D_800B5DD4 = 0;
        break;
    }
}
