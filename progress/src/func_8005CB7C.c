typedef struct Actor {
    s32 unk0;
    f32 pos[3];
    s32 angle;
    u8 pad14[0x1C - 0x14];
    s32 home[3];
    u8 pad28[0x40 - 0x28];
    f32 unk40;
    u8 pad44[0x5C - 0x44];
    s32 unk5C;
    u8 pad60[0x70 - 0x60];
    s32 unk70;
    s32 unk74;
    struct Actor *unk78;
    u8 pad7C[0x88 - 0x7C];
    s32 target;
    s32 state;
    s32 mode;
    u8 pad94[0x9C - 0x94];
    void *callback;
    u8 padA0[0xA4 - 0xA0];
    s32 unkA4;
    struct Actor *link;
    u8 padAC[0xC0 - 0xAC];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 anim;
    u8 padD4[0xD8 - 0xD4];
    s32 unkD8;
    f32 unkDC;
    u8 padE0[0xF0 - 0xE0];
    s32 unkF0;
} Actor;

s32 func_8002444C(void);
s32 isqrtS32(s32);
s32 atan2S16(s32, s32);
void sendCommand(s32, s32);
void func_8002ADFC(s32, s32, Actor *);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260();
void func_8002D3E4(Actor *, s32);
void syncActorPrevPos(Actor *);
void func_8002DA80(Actor *);
f32 func_8002DD60(f32);
s32 animStepKeys(Actor *);
s32 func_80043248(Actor *);
void func_80043328(Actor *, s32, s32);
void actorSetAnim(Actor *, s32, s32);
void func_8005ECE0(Actor *);
s32 func_8005EBC0(Actor *);
void func_8005F008(Actor *);
void func_8005F090(Actor *);
s32 func_8005F1B0(Actor *);
s32 updateDistanceCull(void);
void func_800761FC(Actor *);
void func_80080594(Actor *, s32);
void func_800462A0(void);
extern Actor *gCameraTarget;
extern s32 D_8014AB10;

void func_8005CB7C(Actor *arg0) {
    Actor *link;
    s32 hx;
    s32 hz;
    s32 hdist;
    s32 dx;
    s32 dz;
    s32 dy;
    s32 done;

    if (updateDistanceCull() != 0) {
        return;
    }
    link = arg0->link;
    func_8005F090(arg0);
    hx = arg0->pos[0] - arg0->home[0];
    hz = arg0->pos[2] - arg0->home[2];
    hdist = isqrtS32(hx * hx + hz * hz);
    dx = gCameraTarget->pos[0] - arg0->home[0];
    dz = gCameraTarget->pos[2] - arg0->home[2];
    dy = gCameraTarget->pos[1] - arg0->home[1];
    isqrtS32(dx * dx + dz * dz);
    switch (arg0->mode) {
    case 0:
        arg0->home[0] = arg0->pos[0];
        arg0->home[1] = arg0->pos[1];
        arg0->home[2] = arg0->pos[2];
        link->pos[0] = arg0->pos[0];
        link->pos[1] = arg0->pos[1];
        link->pos[2] = arg0->pos[2];
        link->angle = arg0->angle;
        syncActorPrevPos(arg0);
        arg0->mode = 1;
        arg0->state = 0;
        break;
    case 1:
        done = animStepKeys(arg0);
        switch (arg0->state) {
        case 0:
            if (abs(dy) < 150 && abs(dz) < 75 && abs(dx) < 600) {
                arg0->mode = 2;
                arg0->state = 0;
                func_80080594(arg0, 0);
                if (link != NULL) {
                    link->unk70 = 1;
                }
            }
            if (18.0 <= arg0->unkDC && arg0->unkDC <= 22.0 && (func_8002444C() & 1)) {
                func_8005ECE0(arg0);
                func_8002ADFC(0x46, 0x44C, arg0);
            }
            break;
        case 1:
            if (abs(dy) < 150 && abs(dz) < 75 && abs(dx) < 600) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x10);
                arg0->mode = 2;
                if (dx < 0) {
                    arg0->target = -0x4000;
                } else {
                    arg0->target = 0x4000;
                }
                arg0->state = 2;
                func_80080594(arg0, 0);
            }
            break;
        }
        break;
    case 2:
        done = animStepKeys(arg0);
        dx = arg0->pos[0] - gCameraTarget->pos[0];
        dz = arg0->pos[2] - gCameraTarget->pos[2];
        D_8014AB10 = abs(dx);
        switch (func_8005EBC0(arg0)) {
        case 1:
            actorSetAnim(arg0, 0xE4, 0x100);
            arg0->mode = 3;
            arg0->state = 2;
            return;
        case 2:
            actorSetAnim(arg0, 0xE3, 0x100);
            arg0->mode = 3;
            arg0->state = 0;
            if (link != NULL) {
                link->unk74 = 1;
            }
            return;
        }
        switch (arg0->state) {
        case 0:
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x47);
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x48);
            actorSetAnim(arg0, 0xE6, 0x100);
            if (link != NULL) {
                link->unk70 = 1;
                actorSetAnim(link, 0xEA, 0x100);
            }
            arg0->state = 1;
            break;
        case 1:
            if (link != NULL && link->unk70 == 0) {
                link->unk74 = 1;
            }
            if (done != 0) {
                func_80043328(arg0, 0xDE, 0x100);
                {
                    s32 t;

                    if (dx < 0) {
                        t = 0x4000;
                    } else {
                        t = -0x4000;
                    }
                    arg0->target = t;
                }
                arg0->state = 2;
            }
            break;
        case 2:
            arg0->angle = approachAngle(arg0->target, arg0->angle, 0x1000);
            if (arg0->angle == arg0->target) {
                actorSetAnim(arg0, 0xE0, 0x100);
                func_8002D3E4(arg0, 0x1C2);
                arg0->state = 3;
            }
            break;
        case 3:
            if (hdist < 600 && func_8002DD60(gCameraTarget->pos[2] - arg0->pos[2]) < 50.0f) {
                if (func_8005F1B0(arg0) != 0) {
                    arg0->state = 0xD;
                } else {
                    func_8002DA80(arg0);
                    if (isqrtS32(dx * dx + dz * dz) < 200) {
                        actorSetAnim(arg0, 0xE2, 0x100);
                        func_8002D3E4(arg0, 0);
                        arg0->state = 4;
                    }
                }
            } else {
                actorSetAnim(arg0, 0xDE, 0x100);
                func_8002D3E4(arg0, 0);
                arg0->state = 0xD;
            }
            break;
        case 4:
            if (5.0 <= arg0->unkDC) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x16);
                arg0->state = 5;
            }
            break;
        case 5:
            if (7.0 <= arg0->unkDC && arg0->unkDC <= 10.0 && 8.0 <= arg0->unkDC &&
                gCameraTarget->anim != 5 && gCameraTarget->anim != 0x16 && abs(dx) < 200) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x2D);
                func_8005F008(gCameraTarget);
            }
            if (done != 0) {
                arg0->angle = func_8002D260(atan2S16(-dx, -dz));
                if (isqrtS32(dx * dx + dz * dz) < 200 && gCameraTarget->anim != 0x16) {
                    actorSetAnim(arg0, 0xDE, 0x100);
                    arg0->state = 6;
                } else {
                    actorSetAnim(arg0, 0xDE, 0x100);
                    arg0->state = 0xD;
                }
            }
            break;
        case 6:
            if (gCameraTarget->unkF0 == 0) {
                actorSetAnim(arg0, 0xE2, 0x100);
                arg0->state = 4;
            }
            break;
        case 13: {
            f32 d = arg0->pos[0] - arg0->unk40;

            arg0->state = 0xE;
            if (d != 0.0f) {
                arg0->target = 0x4000;
                if (0.0f < d) {
                    arg0->target = -0x4000;
                }
            } else {
                arg0->target = arg0->angle;
            }
            break;
        }
        case 14:
            arg0->angle = approachAngle(arg0->target, arg0->angle, 0x1000);
            if (arg0->angle == arg0->target) {
                actorSetAnim(arg0, 0xDF, 0x100);
                func_8002D3E4(arg0, 0xE1);
                arg0->state = 0xF;
            }
            break;
        case 15:
            func_8002DA80(arg0);
            if (func_8002DD60(arg0->pos[0] - arg0->unk40) < 50.0f) {
                arg0->target = 0x7FFF;
                func_8002D3E4(arg0, 0);
                actorSetAnim(arg0, 0xDE, 0x100);
                arg0->state = 0x10;
            }
            break;
        case 16:
            arg0->angle = approachAngle(arg0->target, arg0->angle, 0x1000);
            if (arg0->angle == arg0->target) {
                arg0->mode = 1;
                arg0->state = 1;
            }
            break;
        }
        break;
    case 3:
        done = func_80043248(arg0);
        switch (arg0->state) {
        case 0:
            if (done != 0) {
                arg0->state = 1;
                arg0->unk0 = 0x101;
            }
            break;
        case 1:
            arg0->unk5C -= 24;
            if (arg0->unk5C < 0) {
                arg0->unk5C = 0;
                arg0->mode = 4;
            }
            break;
        case 2:
            if (done != 0) {
                arg0->mode = 2;
                arg0->state = 3;
                actorSetAnim(arg0, 0xE0, 0x100);
                func_8002D3E4(arg0, 0x1C2);
            }
            break;
        }
        break;
    case 4:
        if (arg0->unk78 != NULL) {
            arg0->unk78->unkC0 = 0x29A;
        }
        func_800761FC(arg0);
        arg0->unkD8 = 0;
        arg0->callback = func_800462A0;
        if (link != NULL) {
            link->unk74 = 1;
            link->unkA4 = 0;
        }
        break;
    }
}
