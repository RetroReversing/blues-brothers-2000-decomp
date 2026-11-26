typedef struct Actor {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ f32 y;
    /* 0x0C */ u8 padC[0x1C];
    /* 0x28 */ f32 f28;
    /* 0x2C */ f32 f2C;
    /* 0x30 */ f32 f30;
    /* 0x34 */ s32 v34;
    /* 0x38 */ s32 v38;
    /* 0x3C */ s32 v3C;
    /* 0x40 */ u8 pad40[0x10];
    /* 0x50 */ f32 f50;
    /* 0x54 */ u8 pad54[0x18];
    /* 0x6C */ s32 v6C;
    /* 0x70 */ u8 pad70[0xC];
    /* 0x7C */ s32 state;
    /* 0x80 */ s32 pad80;
    /* 0x84 */ s32 count;
    /* 0x88 */ u8 pad88[0x10];
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
    /* 0xA0 */ void (*fA0)(struct Actor *);
    /* 0xA4 */ s32 *fA4;
    /* 0xA8 */ struct Actor *fA8;
    /* 0xAC */ s32 vAC;
    /* 0xB0 */ f32 fB0;
    /* 0xB4 */ s32 vB4;
} Actor;
f32 func_8002D280(f32, s32);
void func_8002D604(Actor *);
f32 func_8002D858(Actor *, s32);
void func_8002D9B0(Actor *);
void func_8002D9F8(Actor *);
void func_8007FDF4(Actor *, s32);
void func_8007FE5C(void);
extern Actor *D_800B3964;
void func_8001F878(void);
void func_8007E0B4(void);
void func_800801C0(void);

void func_800802A4(Actor *arg0) {
    Actor *other;
    s32 n;

    other = D_800B3964->fA8;
    if (other != NULL && other->f9C == func_8007E0B4) {
        func_8007FE5C();
        arg0->fA0(arg0);
        return;
    }
    func_8002D604(arg0);
    arg0->v6C = 0x44444;
    if (arg0->state == 0) {
        arg0->vAC = 0;
        arg0->vB4 = 0;
        arg0->fB0 = -3000.0f;
        func_8002D9F8(arg0);
        func_8002D9B0(arg0);
        if (arg0->y < -2050.0f) {
            if (arg0->count < 3) {
                arg0->f50 = -func_8002D280(arg0->f50, 1);
                arg0->count++;
            } else {
                arg0->state = 1;
            }
            arg0->y = -2050.0f;
        }
    } else if (func_8002D858(arg0, 0) < 250.0f) {
        func_8007FDF4(arg0, 1);
        arg0->f9C = func_800801C0;
        arg0->f98 = func_8001F878;
        n = *arg0->fA4 == 0x120;
        arg0->f28 = n * 85 - 360;
        arg0->f2C = -240.0f;
        arg0->f30 = 995.0f;
        arg0->v34 = arg0->v34 / 3;
        arg0->v38 = arg0->v34;
        arg0->v3C = arg0->v34;
    }
}
