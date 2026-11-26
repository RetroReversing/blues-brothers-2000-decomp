typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x2C];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[0x28];
    s32 f74;
    u8 pad78[0x18];
    s32 f90;
} Obj;
s32 approachAngle(s32, s32, s32);
void func_8002D3E4(Obj *, s32);
s32 tickActorTimer(Obj *);
void func_8002DA80(Obj *);
f32 func_8002DD60(f32);
void func_80043328(Obj *, s32, s32);
void func_80080594(Obj *, s32);
float sqrtf(float);
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;

s32 func_800574D8(Obj *o) {
    f32 range;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 dy;

    range = o->f74;
    range *= 50.0f;
    o->f10 = approachAngle(o->f90, o->f10, gCamSpeedScale << 9);
    func_80043328(o, 0xC1, 0x100);
    func_8002D3E4(o, 100);
    func_8002DA80(o);
    dx = o->x - o->f40;
    dz = o->z - o->f48;
    dy = func_8002DD60(gCameraTarget->y - o->y);
    dist = sqrtf(dx * dx + dz * dz);
    if (range < dist) {
        o->x = o->f40 + dx * range / dist;
        o->z = o->f48 + dz * range / dist;
        return 1;
    }
    if (tickActorTimer(o) != 0) {
        return 1;
    }
    if (dist < range && dy < 400.0f) {
        func_80080594(o, 0);
        return 2;
    }
    return 0;
}
