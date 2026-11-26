typedef struct {
    s32 unk0;
    f32 pos[3];
    s32 angle;
    u8 pad14[0x1C - 0x14];
    s32 home[3];
    u8 pad28[0x5C - 0x28];
    s32 unk5C;
    u8 pad60[0x70 - 0x60];
    s32 unk70;
    u8 pad74[0x78 - 0x74];
    s32 unk78;
    u8 pad7C[0x88 - 0x7C];
    s32 target;
    s32 state;
    s32 mode;
    u8 pad94[0x9C - 0x94];
    void *callback;
    u8 padA0[0xD8 - 0xA0];
    s32 unkD8;
    f32 unkDC;
    u8 padE0[0x104 - 0xE0];
    f32 range;
} Actor;

s32 func_80024B0C(s32);
s32 func_80025100(s32, s32);
void func_8002A360(s32, s32);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D260();
void func_8002D3E4(Actor *, s32);
s32 func_8002D5CC(Actor *);
void func_8002D620(Actor *);
void func_8002DA80(Actor *);
s32 func_8003C9AC(Actor *, s32, s32, s32);
s32 func_8004303C(Actor *);
s32 func_80043248(Actor *);
void func_80043328(Actor *, s32, s32);
void func_800433A8(Actor *, s32, s32);
s32 func_8004FF2C(Actor *, s32);
s32 func_8005EBC0(Actor *);
void func_8005F008(Actor *);
s32 func_80076080(void);
void func_800761FC(Actor *);
void func_80080594(Actor *, s32);
void func_800462A0(void);
extern Actor *D_800BD06C;
extern s32 D_8014AB10;

void func_8005DEF8(Actor *arg0) {
    s32 hx;
    s32 dy;
    s32 hz;
    s32 hdist;
    s32 dx;
    s32 dz;
    s32 pdist;
    s32 done;

    if (func_80076080() != 0) {
        return;
    }
    hx = arg0->pos[0] - arg0->home[0];
    hz = arg0->pos[2] - arg0->home[2];
    hdist = func_80024B0C(hx * hx + hz * hz);
    dx = D_800BD06C->pos[0] - arg0->home[0];
    dz = D_800BD06C->pos[2] - arg0->home[2];
    dy = D_800BD06C->pos[1] - arg0->home[1];
    pdist = func_80024B0C(dx * dx + dz * dz);
    switch (arg0->mode) {
    case 0:
        arg0->home[0] = arg0->pos[0];
        arg0->home[1] = arg0->pos[1];
        arg0->home[2] = arg0->pos[2];
        func_8002D620(arg0);
        arg0->mode = 1;
        arg0->state = 1;
        break;
    case 1:
        done = func_8004303C(arg0);
        switch (arg0->state) {
        case 1:
            if (abs(dy) < 150 && pdist < (s32)arg0->range) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x10);
                arg0->mode = 2;
                arg0->target = func_8002D260(func_80025100(dx, dz));
                arg0->state = 7;
                func_80080594(arg0, 0);
            }
            if (func_8004FF2C(arg0, arg0->unk70) != 0) {
                func_800433A8(arg0, 0xE1, 0x100);
                arg0->state = 2;
            }
            arg0->home[0] = arg0->pos[0];
            arg0->home[1] = arg0->pos[1];
            arg0->home[2] = arg0->pos[2];
            break;
        case 2:
            if (done != 0) {
                arg0->state = 1;
                func_800433A8(arg0, 0xDF, 0x100);
            }
            break;
        }
        break;
    case 2:
        done = func_8004303C(arg0);
        dx = arg0->pos[0] - D_800BD06C->pos[0];
        dz = arg0->pos[2] - D_800BD06C->pos[2];
        D_8014AB10 = func_80024B0C(dx * dx + dz * dz);
        switch (func_8005EBC0(arg0)) {
        case 1:
            func_800433A8(arg0, 0xE4, 0x100);
            arg0->mode = 3;
            arg0->state = 2;
            return;
        case 2:
            func_800433A8(arg0, 0xE3, 0x100);
            arg0->mode = 3;
            arg0->state = 0;
            return;
        }
        switch (arg0->state) {
        case 7:
            func_80080594(arg0, 0);
            arg0->state = 8;
            break;
        case 8:
            arg0->angle = func_8002D260(func_80025100(-dx, -dz), arg0->angle, 0x1000);
            func_80043328(arg0, 0xE0, 0x100);
            if (arg0->range < (f32)hdist) {
                func_800433A8(arg0, 0xDE, 0x100);
                func_8002D3E4(arg0, 0);
                arg0->state = 0xD;
            } else {
                if (D_8014AB10 < 200) {
                    func_800433A8(arg0, 0xE2, 0x100);
                    func_8002D3E4(arg0, 0);
                    arg0->state = 9;
                    arg0->unk78 = 0;
                }
                func_8002D3E4(arg0, 0x1C2);
                func_8002DA80(arg0);
            }
            break;
        case 9:
            arg0->angle = func_8002D260(func_80025100(-dx, -dz), arg0->angle, 0x1000);
            if (arg0->unk78 == 0 && 5.0f <= arg0->unkDC) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x16);
                arg0->unk78 = 1;
            }
            if (7.0f < arg0->unkDC && arg0->unkDC < 13.0f) {
                s32 a = D_8014AB10;
                if (a < 0) {
                    a = -a;
                }
                if (a < 200 && func_8003C9AC(arg0, 0, 1, 1) != 0) {
                    func_8002A360(0xC, 0x80);
                    func_8002A360(8, 0x2D);
                    func_8005F008(D_800BD06C);
                }
            }
            if (done != 0) {
                arg0->unk78 = 0;
                arg0->state = 0x11;
            }
            break;
        case 13:
            dx = arg0->pos[0] - arg0->home[0];
            dz = arg0->pos[2] - arg0->home[2];
            func_80024B0C(dx * dx + dz * dz);
            arg0->target = func_8002D260(func_80025100(-dx, -dz));
            arg0->state = 0xE;
            func_800433A8(arg0, 0xE1, 0x100);
            break;
        case 14:
            if (done != 0) {
                arg0->angle = arg0->target;
                func_800433A8(arg0, 0xDF, 0x100);
                func_8002D3E4(arg0, 0x1C2);
                arg0->state = 0xF;
            }
            break;
        case 15:
            if (func_80024B0C(dx * dx + dz * dz) < 400) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x10);
                arg0->mode = 2;
                arg0->target = func_8002D260(func_80025100(dx, dz));
                arg0->state = 7;
                func_80080594(arg0, 0);
            }
            func_8002DA80(arg0);
            if (func_80024B0C(hx * hx + hz * hz) < 25) {
                arg0->target = 0x7FFF;
                func_8002D3E4(arg0, 0);
                func_800433A8(arg0, 0xDF, 0x100);
                arg0->state = 0x10;
            }
            break;
        case 16:
            arg0->angle = func_8002D204(arg0->target, arg0->angle, 0x1000);
            if (arg0->angle == arg0->target) {
                arg0->mode = 1;
                arg0->state = 1;
            }
            break;
        case 17:
            func_80043328(arg0, 0xDE, 0x100);
            if (func_8002D5CC(arg0) != 0 && done != 0) {
                arg0->state = 8;
            }
            break;
        default:
            arg0->state = 0xD;
            break;
        }
        break;
    case 3:
        done = func_80043248(arg0);
        switch (arg0->state) {
        case 0:
            if (done != 0) {
                arg0->state = 1;
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
                arg0->state = 7;
                func_800433A8(arg0, 0xE0, 0x100);
                func_8002D3E4(arg0, 0x1C2);
            }
            break;
        }
        break;
    case 4:
        func_800761FC(arg0);
        arg0->callback = func_800462A0;
        arg0->unkD8 = 0;
        break;
    }
    if (6650.0f < arg0->pos[0] && 2100.0f < arg0->pos[2]) {
        arg0->pos[0] = 6650.0f;
        if (arg0->mode == 2) {
            arg0->state = 0xD;
        }
    }
}
