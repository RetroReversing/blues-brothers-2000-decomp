typedef struct Obj {
    u8 pad0[8];
    f32 f8;
    u8 padC[0x60];
    s32 f6C;
    s32 f70;
    u8 pad74[8];
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x14];
    s32 fA4;
} Obj;
typedef struct Info {
    u8 pad0[0x58];
    s32 f58;
    s32 f5C;
} Info;
s32 randomRange(s32, s32);
void func_80034F1C(Obj *);
void func_800723EC(void);
Obj *func_800730E0(Obj *);
extern Obj *gCameraRig;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern Obj *gCameraTarget;
extern Info gSplinePointCount;

void func_80072B58(Obj *o) {
    s32 i;
    s32 n;
    Obj *c;

    if (o->f7C == 0) {
        o->f7C = 1;
        D_800B3970 = 0x96;
        D_800B3974 = 0xB6;
        D_800B3978 = 0xC6;
        o->f6C = 0;
        func_800723EC();
        o->f8C = 0;
        n = gSplinePointCount.f5C;
        if (gSplinePointCount.f58 < n) {
            n = gSplinePointCount.f58;
        }
        for (i = 0; i < n; i += randomRange(1, 2)) {
            o->f70 = 0x17;
            c = func_800730E0(o);
            c->fA4 = 0;
            c->f88 = i;
            c->f84 = 0x80;
            o->f70 = 0x16;
            c = func_800730E0(o);
            c->fA4 = 0;
            c->f88 = i;
            c->f84 = 0x80;
        }
    }
    if (1000.0f < gCameraTarget->f8) {
        if (o->f6C == 0) {
            o->f6C = 1;
            gCameraRig->f6C = 2;
            func_80034F1C(gCameraRig);
        }
    } else {
        o->f6C = 0;
    }
}
