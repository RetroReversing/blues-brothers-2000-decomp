typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 ang;
    /* 0x14 */ u8 pad14[0x2C];
    /* 0x40 */ f32 x0;
    /* 0x44 */ f32 y0;
    /* 0x48 */ f32 z0;
    /* 0x4C */ u8 pad4C[0x28];
    /* 0x74 */ s32 f74;
    /* 0x78 */ s32 f78;
    /* 0x7C */ u8 pad7C[0x14];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[0x5C];
    /* 0xF0 */ s32 fF0;
};
s16 coss(u16);
s16 sins(u16);
s32 func_8002D1A0(void);
s32 approachAngle(s32, s32, s32);
void func_8002D3E4(Obj *, s32);
void func_8002DA80(Obj *);
Obj *func_80017344(Obj *);
void func_80043328(Obj *, s32, s32);
f32 sqrtf(f32);
extern s32 gCamSpeedScale;

s32 enemyLeashWander(Obj *arg0) {
    f32 rad;
    f32 dx;
    f32 dz;
    f32 dist;
    u16 a;
    Obj *p;

    rad = arg0->f74;
    rad *= 50.0f;
    arg0->ang = approachAngle(arg0->f90, arg0->ang, (gCamSpeedScale + 1) << 9);
    func_80043328(arg0, 0xC5, 0x100);
    func_8002D3E4(arg0, 700);
    func_8002DA80(arg0);
    dx = arg0->x - arg0->x0;
    dz = arg0->z - arg0->z0;
    dist = sqrtf(dx * dx + dz * dz);
    if (rad < dist) {
        arg0->x = arg0->x0 + dx * rad / dist;
        arg0->z = arg0->z0 + dz * rad / dist;
        return 1;
    }
    if (arg0->f78 == 0) {
        a = func_8002D1A0();
        p = func_80017344(arg0);
        p->y += 350.0f;
        p->x += (sins(a) * 25) >> 13;
        p->z += (coss(a) * 25) >> 13;
        func_8002D3E4(p, 400);
        arg0->fF0 = 0x40;
    }
    arg0->f78++;
    if (arg0->f78 >= 3) {
        arg0->f78 = 0;
    }
    return 0;
}
