typedef struct {
    s32 unk0;
    u8 pad4[0x8 - 0x4];
    f32 unk8;
    u8 padC[0x10 - 0xC];
    s32 unk10;
    u8 pad14[0x50 - 0x14];
    f32 unk50;
    u8 pad54[0x6C - 0x54];
    s32 unk6C;
    u8 pad70[0x84 - 0x70];
    s32 unk84;
    u8 pad88[0x90 - 0x88];
    s32 unk90;
    s32 unk94;
    u8 pad98[0x9C - 0x98];
    void *unk9C;
    u8 padA0[0xB0 - 0xA0];
    s32 unkB0;
    u8 padB4[0xB8 - 0xB4];
    s32 unkB8;
    s32 unkBC;
    u8 padC0[0xD0 - 0xC0];
    s32 unkD0;
    u8 padD4[0xF0 - 0xD4];
    s32 unkF0;
} Actor;

void func_80012718(Actor *);
void sendCommand(s32, s32);
void func_8002ACAC(void);
void func_8002D124(void);
f32 func_8002DD60(f32);
void func_8003A9A8(Actor *, s32);
void func_8003BC40(void);
void func_8003BF98(Actor *);
void func_80043328(Actor *, s32, s32);
void actorSetAnim(Actor *, s32, s32);
extern s32 D_800B3838;
extern Actor *gCameraRig;
extern s32 D_800B4CEC[];
extern s32 D_800B4CF8;
extern Actor *gCameraTarget;
extern s32 D_80107040[];
extern s32 D_80140200;
extern s32 D_80140228;
extern s32 D_80140238;
extern s32 D_80140240;
extern f32 D_80140248;

/* Handles an actor hit or fall: sets its death/effect state by actor type and plays the matching sound. */ void handleActorHit(Actor *actor, f32 height, s32 altPath)
{
    actor->unk94 = 0;
    if (altPath == 0 && (D_80140248 < -3500.0 || actor->unk6C == 1)) {
        actor->unk8 = height;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        actor->unk90 = 1;
        if (actor->unk6C == 1) {
            func_8003BF98(actor);
            actor->unk6C = 0;
            return;
        }
        actorSetAnim(actor, 0x15, 0x100);
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        sendCommand(12, 0x80);
        sendCommand(8, 0x83);
        func_8002D124();
        gCameraRig->unk6C = 0;
        actor->unk6C = 0;
        return;
    }
    if (actor->unk6C == 2) {
        actor->unk90 = 1;
        actor->unk8 = height;
        actor->unk6C = 0;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        gCameraTarget->unkF0 = 0xFF;
        gCameraTarget->unk10 = gCameraRig->unk10 + 0x8000;
        actorSetAnim(gCameraTarget, 0x1A, 0x100);
        gCameraTarget->unk9C = func_8003BC40;
        gCameraTarget->unkF0 = 0xFF;
        gCameraTarget->unk0 = 0x101;
        func_8002D124();
        return;
    }
    actor->unk50 = 0.0f;
    switch (actor->unkD0) {
    case 43:
        if ((D_800B4CF8 & 8) && (D_80107040[0] & 0x4000)) {
            if (D_80140238 >= 2) {
                func_80043328(actor, 0x2C, 0x100);
                actor->unk8 = height;
                actor->unk50 = 0.0f;
                actor->unk84 = 0;
                actor->unk90 = 1;
                actor->unk94 = 0;
                D_80140228 = 1;
                func_80012718(actor);
                func_80012718(actor);
                func_80012718(actor);
                func_80012718(actor);
                sendCommand(12, 0x80);
                sendCommand(8, 0x84);
                func_8002D124();
            } else {
                func_80043328(actor, 0x2D, 0x100);
                actor->unk8 = height;
                actor->unkB0 = 0;
                actor->unk50 = D_80140238 * 200 + 2500;
                D_80140238++;
                func_80012718(actor);
                func_80012718(actor);
                func_80012718(actor);
                func_80012718(actor);
                sendCommand(12, 0x80);
                sendCommand(8, 0x84);
                func_8002D124();
            }
        } else {
            func_80043328(actor, 0x2C, 0x100);
            actor->unk8 = height;
            actor->unk50 = 0.0f;
            actor->unk84 = 0;
            actor->unk90 = 1;
            actor->unk94 = 0;
            D_80140228 = 1;
            func_80012718(actor);
            func_80012718(actor);
            func_80012718(actor);
            func_80012718(actor);
            sendCommand(12, 0x80);
            sendCommand(8, 0x84);
            func_8002D124();
        }
        break;
    case 16:
        if (altPath != 0) {
            actor->unk8 = height;
            actor->unk50 = D_80140240 * 3 / 2;
            actor->unk8 += 1.0f;
            actorSetAnim(actor, 0x10, 0x100);
            sendCommand(12, 0x80);
            sendCommand(8, 0x7B);
            func_8002D124();
            break;
        }
        func_80043328(actor, 0x11, 0x100);
        actor->unk8 = height;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        actor->unk90 = 1;
        actor->unk94 = 0;
        sendCommand(12, 0x80);
        sendCommand(8, 0x35);
        func_8002D124();
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        break;
    case 5:
        if (altPath != 0) {
            actor->unk8 = height;
            actor->unk50 = 1500.0f;
            actor->unk8 += 1.0f;
            actorSetAnim(actor, 5, 0x100);
            func_8002ACAC();
            break;
        }
        if (actor->unkB8 == 6 && func_8002DD60(actor->unk50) > 100.0f) {
            actor->unk8 = height;
            actor->unk50 = func_8002DD60(actor->unk50 * 0.5f);
            actor->unk8 += 1.0f;
            actorSetAnim(actor, 5, 0x100);
            func_8002ACAC();
            break;
        }
        actor->unk90 = 1;
        actor->unk8 = height;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        if (D_80140200 > D_800B4CEC[0]) {
            func_8003A9A8(actor, 0);
        } else {
            actorSetAnim(actor, 0x23, 0x100);
        }
        if (D_800B3838 != 0) {
            sendCommand(12, 0x80);
            sendCommand(8, 0x19);
            func_8002D124();
            D_800B3838 = 0;
        } else {
            sendCommand(12, 0x80);
            sendCommand(8, 0x34);
            func_8002D124();
        }
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        func_80012718(actor);
        break;
    case 12:
        actor->unk90 = 1;
        actor->unk8 = height;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        if (D_80107040[actor->unkBC] & 0x8000) {
            actorSetAnim(actor, 5, 0x100);
            actor->unk50 = D_80140240;
            if (actor->unkB8 == 6) {
                actor->unk50 = D_80140240 * 3 / 2;
            }
            actor->unk8 += 1.0f;
            break;
        }
        func_8003A9A8(actor, 0);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 44:
    case 45:
    case 46:
    case 47:
    default:
        actor->unk8 = height;
        actor->unk50 = 0.0f;
        actor->unk84 = 0;
        actor->unk90 = 1;
        break;
    }
}
