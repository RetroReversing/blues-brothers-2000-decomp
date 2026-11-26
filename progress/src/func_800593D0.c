int abs(int);
typedef struct Actor Actor;
struct Actor {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x34 - 0x14];
    s32 unk34;
    u8 pad38[0x64 - 0x38];
    s32 unk64;
    s32 unk68;
    u8 pad6C[0x84 - 0x6C];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    void (*unkA0)(Actor *);
    u8 padA4[0xD0 - 0xA4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    s32 unkD8;
    f32 unkDC;
};

s32 randomRange(s32, s32);
s32 isqrtS32(s32);
s32 atan2S16(s32, s32);
void sendCommand(s32, s32);
void func_8002D124(void);
s32 approachAngle(s32, s32, s32);
s32 tickActorTimer(Actor *);
void func_8003B980(Actor *);
void func_8003BF98(Actor *);
s32 func_8003C9AC(Actor *, s32, s32, s32);
s32 animStepKeys(Actor *);
void func_80043328(Actor *, s32, s32);
void actorSetAnim(Actor *, s32, s32);
void func_8004EB60(Actor *);
void func_80059CA8(Actor *);
s32 enemyTakeHit(Actor *, s32);
void func_8007631C(void);
extern s32 D_800B7FB0;
extern Actor *gCameraTarget;
extern s32 D_8014AAE0;

void func_800593D0(Actor *arg0)
{
    Actor *a = arg0;
    f32 fx, fy, fz;
    s32 dx, dy, dz;
    s32 done;
    s32 r;

    fx = gCameraTarget->x;
    fx -= a->x;
    dx = fx;
    fy = gCameraTarget->y;
    fy -= a->y;
    dy = abs((s32)fy);
    fz = gCameraTarget->z;
    fz -= a->z;
    dz = fz;
    if (dy >= 751) {
        return;
    }
    D_8014AAE0 = isqrtS32(dx * dx + dz * dz);
    switch (a->unk90) {
    case 0:
        a->unk90 = 1;
        a->unk8C = 0;
        actorSetAnim(a, 0x39, 0x100);
        break;
    case 1:
        a->unk68 = -1;
        if (D_8014AAE0 < 1000) {
            func_80043328(a, 0x39, 0x100);
            a->unk68 = 13;
            a->unk90 = 2;
            a->unk8C = 0;
            sendCommand(12, 0x80);
            sendCommand(8, 0x18);
        }
        break;
    case 2:
        done = animStepKeys(a);
        a->unk10 = approachAngle(atan2S16(dx, dz), a->unk10, 0xC00);
        r = enemyTakeHit(a, a->unk90 == 3 && a->unk8C == 1);
        switch (r) {
        case 1:
            sendCommand(12, 0x80);
            sendCommand(8, 0x2E);
            func_8002D124();
            actorSetAnim(a, 0x3B, 0x100);
            a->unk90 = 3;
            a->unk8C = r;
            return;
        case 2:
            sendCommand(12, 0x80);
            sendCommand(8, 0x17);
            func_8002D124();
            actorSetAnim(a, 0x3C, 0x100);
            a->unk90 = 3;
            a->unk8C = 0;
            a->unk88 = a->unk34;
            break;
        }
        switch (a->unk8C) {
        case 0:
            if (done) {
                func_80043328(a, 0x3E, 0x100);
                a->unk8C = 1;
            }
            break;
        case 1:
            if (D_8014AAE0 > 1000) {
                actorSetAnim(a, 0x3A, 0x100);
                a->unk8C = 2;
                break;
            }
            if (done) {
                func_80043328(a, 0x38, 0x100);
            }
            if (D_8014AAE0 < 1000) {
                if (randomRange(0, 100) > 50) {
                    sendCommand(12, 0x80);
                    sendCommand(8, 0x16);
                    actorSetAnim(a, 0x3E, 0x100);
                } else {
                    sendCommand(12, 0x80);
                    sendCommand(8, 0x16);
                    actorSetAnim(a, 0x3D, 0x100);
                }
                D_800B7FB0 = 0;
                a->unk8C = 3;
            }
            break;
        case 2:
            if (done) {
                a->unk68 = -1;
                a->unk90 = 1;
                a->unk8C = 0;
            }
            break;
        case 3:
            if (D_800B7FB0 == 0 && a->unkD0 == 0x3D && 13.0f <= a->unkDC && a->unkDC <= 19.0f) {
                sendCommand(12, 0x80);
                sendCommand(8, 0x2D);
                D_800B7FB0 = 1;
            }
            r = enemyTakeHit(a, a->unk90 == 3 && a->unk8C == 1);
            switch (r) {
            case 1:
                sendCommand(12, 0x80);
                sendCommand(8, 0x2E);
                func_8002D124();
                actorSetAnim(a, 0x3B, 0x100);
                a->unk90 = 3;
                a->unk8C = r;
                return;
            case 2:
                sendCommand(12, 0x80);
                sendCommand(8, 0x17);
                func_8002D124();
                actorSetAnim(a, 0x3C, 0x100);
                a->unk90 = 3;
                a->unk8C = 0;
                a->unk88 = a->unk34;
                break;
            }
            if (a->unkD0 == 0x3E && 13.0f <= a->unkDC && a->unkDC <= 15.0f && (u32)(D_8014AAE0 - 176) < 299) {
                if (D_800B7FB0 == 0) {
                    D_800B7FB0 = 1;
                    sendCommand(12, 0x80);
                    sendCommand(8, 0x2D);
                }
                if (func_8003C9AC(a, 0, 1, 0) != 0) {
                    func_8003BF98(gCameraTarget);
                    func_80059CA8(a);
                }
                a->unk8C = 4;
            }
            if (a->unkD0 == 0x3D && 13.0f <= a->unkDC && a->unkDC <= 19.0f && (u32)(D_8014AAE0 - 176) < 299) {
                if (D_800B7FB0 == 0) {
                    D_800B7FB0 = 1;
                    sendCommand(12, 0x80);
                    sendCommand(8, 0x2D);
                }
                func_8003B980(gCameraTarget);
                a->unk8C = 4;
                break;
            }
            if (done) {
                a->unk8C = 1;
            }
            break;
        case 4:
            if (done) {
                func_80043328(a, 0x38, 0x100);
                a->unk8C = 5;
            }
            break;
        case 5:
            if (a->unk84 == 0) {
                a->unk64 = 200;
                a->unk8C = 6;
            }
            break;
        case 6:
            if (tickActorTimer(a) != 0) {
                a->unk8C = 1;
            }
            break;
        }
        break;
    case 3:
        done = animStepKeys(a);
        switch (a->unk8C) {
        case 0:
            a->unk9C = func_8007631C;
            a->unkD8 = 0;
            break;
        case 1:
            if (done) {
                func_80043328(a, 0x38, 0x100);
                a->unk90 = 2;
                a->unk8C = 0;
            }
            break;
        }
        break;
    case 4:
        func_8004EB60(a);
        a->unkA0(a);
        break;
    }
}
