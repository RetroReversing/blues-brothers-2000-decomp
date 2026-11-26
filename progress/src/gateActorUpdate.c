typedef struct ObjY {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x44 - 0x14];
    f32 f44;
    u8 pad48[0x50 - 0x48];
    f32 f50;
    u8 pad54[0x64 - 0x54];
    s32 f64;
    u8 pad68[0x7C - 0x68];
    s32 f7C;
    u8 pad80[0x88 - 0x80];
    s32 f88;
    u8 pad8C[0x90 - 0x8C];
    s32 f90;
    u8 pad94[0xB0 - 0x94];
    f32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s32 fB8;
    u8 padBC[0xC0 - 0xBC];
    s32 fC0;
} ObjY;

typedef struct { s32 x; s32 pad; s32 z; } Bound;

ObjY *func_80012718(ObjY *);
void func_80013384(ObjY *);
s32 func_8001B990(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_8002D4E0(ObjY *, s32);
s32 tickActorTimer(ObjY *);
void syncActorPrevPos(ObjY *);
void func_8002DA80(ObjY *);
f32 func_8002DD60(f32);
extern f32 D_800B9EC4;
extern ObjY *gCameraTarget;
extern Bound gPlatformMaxOffsets[];
extern Bound gPlatformMinOffsets[];

/* Gate actor update: while both switch bits (0x15, 0x16) are set and the gate is at rest with its trigger armed, it fires four spawned shots and resets; otherwise it falls. Also clamps it to its floor and stops falling when the camera is inside its bounds. */
void gateActorUpdate(ObjY *gate) {
    s32 switchMask;
    f32 dx;
    f32 dz;
    f32 dy;
    ObjY *shot;
    Bound *maxBound;
    Bound *minBound;
    s32 boundOff;

    switchMask = func_8001B990(0x100, 0x15) & func_8001B990(0x100, 0x16);
    if (gate->f7C == 0) {
        gate->f7C = 1;
        gate->fC0 = 3;
        gate->f0 = 0x10E;
        gate->fB0 = gate->f50 = 0.0f;
        syncActorPrevPos(gate);
        gate->f64 = 0x64;
    }
    if (gate->f90 != 0 && gate->y == gate->f44 && switchMask != 0) {
        if (gate->f88 == 0) {
            gate->f88 = 1;
            func_8002A360(0x1A, 0);
        }
        if (tickActorTimer(gate) != 0) {
            gate->f50 = 3100.0f;
            shot = func_80012718(gate);
            shot->x = gate->x + 300.0f;
            shot->y = gate->y;
            shot->z = gate->z;
            shot->f10 = 0x4000;
            func_8002D4E0(shot, 0x3E8);
            shot = func_80012718(gate);
            shot->x = gate->x - 300.0f;
            shot->y = gate->y;
            shot->z = gate->z;
            shot->f10 = -0x4000;
            func_8002D4E0(shot, 0x3E8);
            shot = func_80012718(gate);
            shot->x = gate->z + 300.0f;
            shot->y = gate->y;
            shot->z = gate->x;
            shot->f10 = 0;
            func_8002D4E0(shot, 0x3E8);
            shot = func_80012718(gate);
            shot->x = gate->z - 300.0f;
            shot->y = gate->y;
            shot->z = gate->x;
            shot->f10 = 0x8000;
            func_8002D4E0(shot, 0x3E8);
            gate->f64 = 0x64;
            gate->f88 = 0;
            func_8002D124();
        }
    } else {
        gate->f64 = 0x64;
        gate->fB0 = -1600.0f;
        gate->f50 += D_800B9EC4 * -1600.0f;
        if (gate->f88 != 0) {
            func_8002A360(0x1B, 0);
            gate->f88 = 0;
        }
    }
    dx = gCameraTarget->x - gate->x;
    dz = gCameraTarget->z - gate->z;
    dy = gCameraTarget->y - gate->y;
    if (!(8000.0f < func_8002DD60(dx)) && !(8000.0f < func_8002DD60(dz))) {
        {
        char *base = (char *)gPlatformMaxOffsets;
        boundOff = gate->fB8 * sizeof(Bound);
        maxBound = (Bound *)(base + boundOff);
        }
        if (!(maxBound->x < dx)) {
            minBound = (Bound *)((char *)gPlatformMinOffsets + boundOff);
            if (!(dx < minBound->x) && !(maxBound->z < dz) && !(dz < minBound->z) && dy < -600.0f) {
                gate->f50 = 0.0f;
            }
        }
    }
    func_8002DA80(gate);
    if (gate->y <= gate->f44) {
        gate->y = gate->f44;
        gate->f50 = 0.0f;
        gate->fB0 = 0.0f;
    }
    func_80013384(gate);
}
