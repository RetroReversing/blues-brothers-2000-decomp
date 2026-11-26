typedef struct {
    s32 unk0;
    f32 pos[3];
    s32 angle;
    u8 pad14[0x1C - 0x14];
    s32 home[3];
    u8 pad28[0x5C - 0x28];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    u8 pad68[0x74 - 0x68];
    s32 range;
    u8 pad78[0x80 - 0x78];
    s32 unk80;
    s32 unk84;
    s32 target;
    s32 state;
    s32 mode;
    u8 pad94[0x9C - 0x94];
    void *callback;
    u8 padA0[0xD0 - 0xA0];
    s32 anim;
    u8 padD4[0xDC - 0xD4];
    f32 unkDC;
    u8 padE0[0xF0 - 0xE0];
    s32 unkF0;
} Actor;

s32 isqrtS32(s32);
s32 atan2S16(s32, s32);
void sendCommand(s32, s32);
void func_8002D124(void);
s32 func_8002D1A0(void);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260();
void func_8002D3E4(Actor *, s32);
s32 tickActorTimer(Actor *);
void func_8002DA80(Actor *);
f32 func_8002DD60(f32);
s32 func_8003BF98(Actor *);
s32 func_8003C9AC(Actor *, s32, s32, s32);
s32 animStepKeys(Actor *);
s32 func_80043248(Actor *);
void func_80043328(Actor *, s32, s32);
void actorSetAnim(Actor *, s32, s32);
s32 func_8005A90C(Actor *);
void func_8005A9CC(Actor *);
s32 func_80076080(void);
void func_800761FC(Actor *);
void func_80080594(Actor *, s32);
void func_800462A0(void);
extern Actor *gCameraTarget;
extern s32 D_8014AAF0;

void func_80059D80(Actor *arg0) {
    s32 hx;
    s32 hz;
    s32 hdist;
    s32 dx;
    s32 dz;
    s32 pdist;
    f32 dy;
    s32 done;
    s32 sq;
    s32 r;

    if (func_80076080() != 0) {
        return;
    }
    hx = arg0->pos[0] - arg0->home[0];
    hz = arg0->pos[2] - arg0->home[2];
    hdist = isqrtS32(hx * hx + hz * hz);
    dx = gCameraTarget->pos[0] - arg0->home[0];
    dz = gCameraTarget->pos[2] - arg0->home[2];
    pdist = isqrtS32(dx * dx + dz * dz);
    dy = func_8002DD60(arg0->pos[1] - gCameraTarget->pos[1]);
    switch (arg0->mode) {
    case 0:
        arg0->home[0] = arg0->pos[0];
        arg0->home[1] = arg0->pos[1];
        arg0->home[2] = arg0->pos[2];
        arg0->angle = func_8002D260(func_8002D1A0());
        func_8002D3E4(arg0, 0x96);
        arg0->mode = 1;
        arg0->state = 0;
        arg0->unk84 = 0;
        break;
    case 1:
        done = animStepKeys(arg0);
        if (pdist < arg0->range * 50 && dy < 400.0f) {
            arg0->mode = 2;
            arg0->state = 0;
            break;
        }
        switch (arg0->state) {
        case 0:
            if (hdist >= arg0->range * 50) {
                arg0->state = 1;
                arg0->target = func_8002D260(atan2S16(-hx, -hz));
            } else if (tickActorTimer(arg0) != 0 && done != 0) {
                func_80080594(arg0, 2);
                arg0->state = 2;
                func_80043328(arg0, 0x6B, 0x100);
            } else {
                func_8002DA80(arg0);
            }
            break;
        case 1:
            arg0->angle = approachAngle(arg0->target, arg0->angle, 0x1000);
            func_8002D3E4(arg0, 0x96);
            func_8002DA80(arg0);
            if (arg0->angle == arg0->target) {
                arg0->unk64 = 500;
                arg0->state = 0;
            }
            break;
        case 2:
            if (done != 0) {
                func_80043328(arg0, 0x6D, 0x100);
                arg0->state = 0;
                arg0->unk64 = 500;
            }
            break;
        }
        break;
    case 2:
        done = animStepKeys(arg0);
        dx = arg0->pos[0] - gCameraTarget->pos[0];
        dz = arg0->pos[2] - gCameraTarget->pos[2];
        sq = dx * dx + dz * dz;
        D_8014AAF0 = isqrtS32(sq);
        r = func_8005A90C(arg0);
        if (r != 0) {
            if (r != 3) {
                arg0->unkF0 = 0xFF;
                actorSetAnim(arg0, 0x6F, 0x100);
                arg0->mode = 3;
                arg0->state = 0;
                func_8002D3E4(arg0, 0);
                if (r == 1 || r == 2) {
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0xCE);
                    func_8002D124();
                }
            } else {
                arg0->unkF0 = 0;
            }
            break;
        }
        r = 1;
        switch (arg0->state) {
        case 0:
            func_80080594(arg0, 0);
        set_state1:
            arg0->state = r;
            break;
        case 1:
            arg0->angle = approachAngle(atan2S16(-dx, -dz), arg0->angle, 0x1000);
            func_80043328(arg0, 0x73, 0x100);
            func_8002D3E4(arg0, 0x1C2);
            func_8002DA80(arg0);
            if (arg0->range * 50 < hdist) {
                actorSetAnim(arg0, 0x6D, 0x100);
                func_8002D3E4(arg0, 0x96);
                arg0->mode = r;
                goto set_state1;
            } else if (isqrtS32(sq) < 250) {
                func_8002D3E4(arg0, 0);
                func_80043328(arg0, 0x6E, 0x100);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0xCF);
                arg0->state = 2;
                arg0->unk80 = 0;
            }
            break;
        case 2: {
            s32 t = isqrtS32(sq);

            if (t < 250 && func_8003C9AC(arg0, 0, 1, 1) != 0 && arg0->unk80 == 0) {
                s32 a = 8.0 <= arg0->unkDC && arg0->unkDC <= 12.0;
                s32 b = 21.0 <= arg0->unkDC && arg0->unkDC <= 25.0;

                if ((a || b) && func_8003BF98(gCameraTarget) != 0) {
                    arg0->unk80 = 1;
                    func_8005A9CC(arg0);
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0x2E);
                    arg0->state = 3;
                }
            }
            if (done != 0) {
                if (t >= arg0->range * 50) {
                    func_8002D3E4(arg0, 0x96);
                    arg0->mode = 1;
                    arg0->state = 0;
                    func_80043328(arg0, 0x6D, 0x100);
                } else {
                    arg0->state = 1;
                }
            }
            break;
        }
        case 3:
            arg0->angle = approachAngle(atan2S16(-dx, -dz), arg0->angle, 0x1000);
            if (done != 0) {
                if (arg0->anim == 0x6C) {
                    goto set_state1;
                } else {
                    func_80043328(arg0, 0x6C, 0x100);
                }
            }
            break;
        }
        break;
    case 3: {
        s32 ey;

        dx = arg0->pos[0] - gCameraTarget->pos[0];
        ey = arg0->pos[1] - gCameraTarget->pos[1];
        dz = arg0->pos[2] - gCameraTarget->pos[2];
        D_8014AAF0 = isqrtS32(dx * dx + ey * ey + dz * dz);
        if (func_8005A90C(arg0) == 3 && arg0->state < 3) {
            arg0->unkF0 = 0xFF;
            arg0->state = 3;
            break;
        }
        switch (arg0->state) {
        case 0:
            if (animStepKeys(arg0) != 0) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x17);
                func_80043328(arg0, 0x70, 0x100);
                arg0->state = 1;
            }
            break;
        case 1:
            if (animStepKeys(arg0) != 0) {
                if (arg0->unk84 < 6) {
                    func_80043328(arg0, 0x70, 0x100);
                    arg0->unk84++;
                } else {
                    func_80043328(arg0, 0x72, 0x100);
                    arg0->state = 2;
                }
            }
            break;
        case 2:
            if (animStepKeys(arg0) != 0) {
                func_8002D3E4(arg0, 0x96);
                arg0->mode = 1;
                arg0->state = 0;
                arg0->unk84 = 0;
                func_80043328(arg0, 0x6D, 0x100);
            }
            break;
        case 3:
            done = func_80043248(arg0);
            if (done != 0) {
                arg0->state = 4;
            }
            break;
        case 4:
            func_80043248(arg0);
            arg0->unk5C -= 24;
            if (arg0->unk5C < 0) {
                arg0->unk5C = 0;
                arg0->mode = 4;
            }
            break;
        }
        break;
    }
    case 4:
        func_800761FC(arg0);
        arg0->callback = func_800462A0;
        break;
    }
}
