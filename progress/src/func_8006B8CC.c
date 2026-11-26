typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x5C];
    s32 f70;
} Obj;
s32 func_80081990(f32 *, s32, f32);
s32 func_80081AC0(f32 *, s32, f32);
f32 approachF32(f32, f32, f32);
s32 func_8002492C(f32, f32);
Obj *func_80043248(Obj *);
Obj *func_80080594(Obj *, s32);
extern s32 gCamSpeedScale;

Obj *func_8006B8CC(Obj *o) {
    f32 v[3];
    Obj *r;

    func_80081990(v, o->f70, 0.0f);
    o->x = approachF32(v[0], o->x, gCamSpeedScale * 50);
    o->y = approachF32(v[1], o->y, gCamSpeedScale * 50);
    o->z = approachF32(v[2], o->z, gCamSpeedScale * 50);
    func_80081AC0(v, o->f70, 0.0f);
    o->f10 = func_8002492C(v[0], v[2]);
    r = func_80043248(o);
    if (r != NULL) {
        func_80080594(o, 1)->y += 200.0f;
    }
    return r;
}
