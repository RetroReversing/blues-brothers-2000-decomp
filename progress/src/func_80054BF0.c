s32 func_80024AC4(s32, s32);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D298(s32, s32, s32);
void func_8002D3E4(void *, s32);
void func_8002D620(void *);
void func_8002D858(void *, s32 *);
void func_8002DA80(void *);
s32 func_8003BF98();
s32 func_8004303C(void *);
void func_80043328(void *, s32, s32);
void func_80058F74(void *, void *);
void func_800548C0();
void func_80054E24();
typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 ang;
    /* 0x14 */ u8 pad14[0x2C];
    /* 0x40 */ f32 x0;
    /* 0x44 */ f32 y0;
    /* 0x48 */ f32 z0;
    /* 0x4C */ u8 pad4C[0x10];
    /* 0x5C */ s32 f5C;
    /* 0x60 */ u8 pad60[0x1C];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ s32 f80;
    /* 0x84 */ s32 f84;
    /* 0x88 */ u8 pad88[0x54];
    /* 0xDC */ f32 fDC;
} Obj;
extern s32 D_800B9ECC;
extern Obj *D_800BD06C;
#define FRAMES D_800B9ECC
#define PLAYER D_800BD06C

void func_80054BF0(Obj *arg0) {
    s32 ang;
    s32 r;
    s32 hit;
    f32 t;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 x;
    f32 z;
    f32 d;

    if (arg0->f7C != 0) {
        func_80043328(arg0, 0x45, 0x100);
        arg0->f7C = 0;
        arg0->f80 = 0;
        arg0->f84 = 0;
        return;
    }
    func_8002D858(arg0, &ang);
    arg0->ang = func_8002D204(ang, arg0->ang, FRAMES << 9);
    arg0->f5C = func_8002D298(0x80, arg0->f5C, FRAMES * 2);
    r = func_8004303C(arg0);
    d = arg0->fDC;
    if (9.0f <= d && d <= 20.0f) {
        arg0->f80 = 4000;
    } else {
        arg0->f80 -= func_80024AC4(arg0->f80, 2);
    }
    func_8002D3E4(arg0, arg0->f80);
    func_8002D620(arg0);
    func_8002DA80(arg0);
    dx = arg0->x - arg0->x0;
    dy = arg0->y - PLAYER->y;
    dz = arg0->z - arg0->z0;
    hit = 0;
    if (dy < 300.0f && -300.0f < dy) {
        t = 0.0f;
        for (;;) {
            x = (-PLAYER->x + arg0->x0) + dx * t;
            z = (-PLAYER->z + arg0->z0) + dz * t;
            if (x * x + z * z < 40000.0f) {
                hit = 1;
            } else {
                t += 0.2;
                if (t <= 1.0f) {
                    continue;
                }
            }
            break;
        }
    }
    if (hit) {
        func_8003BF98(PLAYER);
        arg0->f5C = 0xFF;
        arg0->f84 = 1;
    }
    if (r != 0) {
        if (arg0->f84 != 0) {
            func_80058F74(arg0, func_80054E24);
        } else {
            func_80058F74(arg0, func_800548C0);
        }
    }
}
