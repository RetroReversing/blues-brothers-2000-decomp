typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x2C];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[0x18];
    s32 f64;
    u8 pad68[0xC];
    s32 f74;
    u8 pad78[8];
    s32 f80;
} Obj;
void func_8002D3E4(Obj *, s32);
s32 tickActorTimer(Obj *);
void func_8002DA80(Obj *);
f32 func_8002DD60(f32);
void func_80043328(Obj *, s32, s32);
void func_80080594(Obj *, s32);
s32 func_8002444C(void);
s32 randomRange(s32, s32);
float sqrtf(float);
extern Obj *gCameraTarget;

s32 func_8005738C(Obj *o) {
    f32 range;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 dy;

    range = o->f74 - 2;
    range *= 50.0f;
    func_80043328(o, 0xC0, 0x100);
    func_8002D3E4(o, 0);
    func_8002DA80(o);
    dy = func_8002DD60(gCameraTarget->y - o->y);
    dx = gCameraTarget->x - o->f40;
    dz = gCameraTarget->z - o->f48;
    dist = sqrtf(dx * dx + dz * dz);
    if (dist < range && dy < 400.0f) {
        func_80080594(o, 0);
        return 2;
    }
    if (tickActorTimer(o) == 0) {
        return 0;
    }
    if ((func_8002444C() & 3) != 3) {
        return 1;
    }
    o->f80 = 1;
    o->f64 = randomRange(0x50, 0x140);
    return 0;
}
