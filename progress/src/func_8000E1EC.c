typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0xA8];
    s32 fB8;
} Obj;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Rec;
extern Obj *gCameraTarget;
extern Rec gPlatformMaxOffsets[];
extern Rec gPlatformMinOffsets[];
f32 func_8000E1EC(Obj *o) {
    f32 f;
    f32 t;
    s32 d;
    s32 c;

    t = o->x;
    f = gCameraTarget->x - t;
    d = f;
    if (d > 0) {
        c = gPlatformMaxOffsets[o->fB8].a < d;
    } else {
        c = d < gPlatformMinOffsets[o->fB8].a;
    }
    if (c) {
        return f;
    }
    t = o->z;
    f = gCameraTarget->z - t;
    d = f;
    if (d > 0) {
        if (gPlatformMaxOffsets[o->fB8].c < d) return f;
    } else {
        if (d < gPlatformMinOffsets[o->fB8].c) return f;
    }
}
