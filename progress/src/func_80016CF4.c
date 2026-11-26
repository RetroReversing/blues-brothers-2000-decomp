typedef struct {
    /* 0x000 */ s32 f0;
    /* 0x004 */ f32 x;
    /* 0x008 */ f32 y;
    /* 0x00C */ f32 z;
    /* 0x010 */ u8 pad10[0x34];
    /* 0x044 */ f32 baseY;
    /* 0x048 */ u8 pad48[0x34];
    /* 0x07C */ s32 state;
    /* 0x080 */ u8 pad80[0x38];
    /* 0x0B8 */ s32 kind;
    /* 0x0BC */ u8 padBC[0x44];
    /* 0x100 */ f32 goalY;
} Obj;
typedef struct {
    s32 a;
    s32 h;
    s32 c;
} HRow;
void func_800134F0(Obj *);
void func_80013550(Obj *);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(Obj *);
Obj *func_8003B980(Obj *);
f32 sqrtf(f32);
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;
extern HRow D_800F4A00[];

void func_80016CF4(Obj *arg0) {
    f32 dx;
    f32 dz;
    f32 dy;
    f32 vy;
    f32 d;

    if (arg0->state == 0) {
        arg0->state = 1;
        D_800F4A00[arg0->kind].h = -15;
        arg0->f0 = 0x10E;
        syncActorPrevPos(arg0);
        arg0->goalY = arg0->baseY + 2400.0f;
    }
    D_800F4A00[arg0->kind].h = -15;
    vy = -arg0->y;
    arg0->y = approachF32(arg0->goalY, arg0->y, gCamSpeedScale * 10.0);
    vy += arg0->y;
    if (arg0->y <= arg0->baseY - 2400.0f) {
        arg0->y = arg0->baseY - 2400.0f;
        arg0->goalY = arg0->baseY + 2400.0f;
    }
    if (arg0->baseY + 2400.0f <= arg0->y) {
        arg0->y = arg0->baseY + 2400.0f;
        arg0->goalY = arg0->baseY - 2400.0f;
    }
    func_800134F0(arg0);
    func_80013550(arg0);
    dx = arg0->x - gCameraTarget->x;
    dz = arg0->z - gCameraTarget->z;
    dy = arg0->y - gCameraTarget->y;
    d = sqrtf(dx * dx + dz * dz);
    if (d < 200.0f && vy < 0.0f && dy < 300.0f && 50.0f < dy) {
        func_8003B980(gCameraTarget);
        arg0->goalY = arg0->baseY + 2400.0f;
    }
}
