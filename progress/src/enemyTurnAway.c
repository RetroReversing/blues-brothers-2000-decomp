typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x40 - 0x14];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x64 - 0x4C];
    s32 unk64;
    u8 pad68[0x74 - 0x68];
    s32 unk74;
    u8 pad78[0xD8 - 0x78];
    void *unkD8;
} Obj;

s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
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
void enemyIdle(void);
void enemyLeashWander(void);

s32 enemyTurnAway(Obj *arg0) {
    f32 range;
    f32 dist;
    f32 dx, dz;
    f32 dy;
    s32 angle;

    range = arg0->unk74;
    range += range;
    dx = arg0->x - arg0->unk40;
    dz = arg0->z - arg0->unk48;
    angle = func_8002492C(-dx, -dz);
    func_80043328(arg0, 0xC1, 0x100);
    arg0->unk10 = approachAngle(angle, arg0->unk10, gCamSpeedScale << 8);
    func_8002D3E4(arg0, 100);
    func_8002DA80(arg0);
    if (tickActorTimer(arg0) != 0) {
        arg0->unkD8 = enemyIdle;
        arg0->unk64 = randomRange(180, 400);
        func_80080594(arg0, 2);
        return 0;
    }
    dx = gCameraTarget->x - arg0->unk40;
    dz = gCameraTarget->z - arg0->unk48;
    dist = sqrtf(dx * dx + dz * dz);
    dy = func_8002DD60(gCameraTarget->y - arg0->y);
    if (dist < range && dy < 400.0f) {
        func_80080594(arg0, 0);
        arg0->unkD8 = enemyLeashWander;
    }
    return 0;
}
