typedef struct Obj58 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    u8 pad14[0x48];
    s32 x5C;
    u8 pad60[0x20];
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    u32 x90;
    u8 pad94[0xC];
    void (*xA0)(struct Obj58 *);
    u8 padA4[0x14];
    s32 xB8;
    u8 padBC[4];
    s32 xC0;
} Obj58;
typedef struct Ent58 {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0xB0];
    s32 xC0;
    u8 padC4[0x44];
} Ent58;
typedef struct Row58 {
    s32 x0;
    s32 x4;
    s32 x8;
} Row58;
typedef struct Cam58 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
} Cam58;
extern Cam58 *gCameraTarget;
extern Ent58 *D_800AB9BC;
extern Ent58 *D_800AB9C0;
extern Ent58 *D_8014AAC0;
extern Row58 gPlatformMaxOffsets[];
extern s32 D_800F7910[];
s32 animStepKeys(void);
s32 atan2S16(s32, s32);
s32 func_8002D260(s32);
s32 approachAngle(s32, s32, s32);
s32 isqrtS32(s32);
void sendCommand(s32, s32);
void actorSetAnim(Obj58 *, s32, s32);
void func_80043328(Obj58 *, s32, s32);
f32 func_8002DD60(f32);
float sqrtf(float);

/* Updates a logic bomb: tracks the player, arms and detonates when a nearby bomb is close, and pushes the player out of its radius. */ void updateLogicBomb(Obj58 *bomb) {
    s32 tick;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dxSq;
    s32 dzSq;
    Ent58 *other;
    Row58 *row;
    f32 fx;
    f32 fz;
    f32 lim;
    f32 d;
    f32 k;

    tick = animStepKeys();
    switch (bomb->x90) {
    case 0:
        bomb->x84 = 0;
        bomb->x80 = 0;
        bomb->xC0 = 0;
        bomb->x90 = 1;
        bomb->x8C = 0;
        actorSetAnim(bomb, 0x77, 0x100);
        break;
    case 1:
        dx = bomb->x4 - gCameraTarget->x4;
        dz = bomb->xC - gCameraTarget->xC;
        bomb->x88 = func_8002D260(atan2S16(-dx, -dz));
        bomb->x10 = approachAngle(bomb->x88, bomb->x10, 0x1000);
        for (other = D_800AB9BC; other <= D_800AB9C0; other++) {
            if (other->x0 != 0x1008) {
                continue;
            }
            dx = bomb->x4 - other->x4;
            dxSq = dx * dx;
            dy = bomb->x8 - other->x8;
            dz = bomb->xC - other->xC;
            dzSq = dz * dz;
            if (isqrtS32(dxSq + dy * dy + dzSq) < 0xC8) {
                if (bomb->x84 == 0) {
                    bomb->x90 = 2;
                    bomb->x8C = 0;
                    D_8014AAC0 = other;
                    break;
                }
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x15);
            }
            if (isqrtS32(dxSq + dzSq) < 0x190) {
                if (other->x8 < bomb->x8 && !(other->xC0 & 4)) {
                    other->x8 = bomb->x8;
                    other->xC0 |= 2;
                }
            }
        }
        if (bomb->xC0 & 8) {
            bomb->x90 = 3;
            bomb->x8C = 0;
        }
        break;
    case 2:
        switch (bomb->x8C) {
        case 0:
            bomb->x8C = 1;
            bomb->x10 = bomb->x88 = func_8002D260(atan2S16(-dx, -dz));
            actorSetAnim(bomb, 0x7B, 0x600);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x3A);
            D_8014AAC0->xC0 |= 1;
            bomb->x84 = 1;
            break;
        case 1:
            if (tick != 0) {
                func_80043328(bomb, 0x7E, 0x100);
                bomb->x8C = 2;
            }
            break;
        case 2:
            if (tick != 0) {
                bomb->x90 = 1;
                bomb->x8C = 0;
                func_80043328(bomb, 0x77, 0x100);
            }
            break;
        }
        break;
    case 3:
        switch (bomb->x8C) {
        case 0:
            func_80043328(bomb, 0x7E, 0x100);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x3A);
            bomb->x8C = 1;
            break;
        case 1:
            if (tick != 0) {
                func_80043328(bomb, 0x7E, 0x100);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x3A);
            }
            break;
        case 2:
            bomb->x5C -= 0x18;
            if (bomb->x5C < 0) {
                bomb->x5C = 0;
                bomb->x90 = 4;
            }
            break;
        }
        break;
    case 4:
        bomb->xA0(bomb);
        break;
    }
    row = &gPlatformMaxOffsets[bomb->xB8];
    if (!(bomb->x8 + (f32) row->x4 + 300.0f < gCameraTarget->x8)) {
        fx = bomb->x4 - gCameraTarget->x4;
        fz = bomb->xC - gCameraTarget->xC;
        lim = (f32) D_800F7910[bomb->xB8] / 3.0f;
        if (!(lim < func_8002DD60((f32) dx)) && !(lim < func_8002DD60((f32) dz))) {
            d = sqrtf(fx * fx + fz * fz);
            if (!(lim < d)) {
                k = lim - d;
                gCameraTarget->x4 -= fx * k / d;
                gCameraTarget->xC -= fz * k / d;
            }
        }
    }
}
