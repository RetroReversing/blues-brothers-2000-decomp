typedef struct Obj {
    f32 x00;
    f32 x;      /* 0x04 */
    f32 y;
    f32 z;      /* 0x0C */
    s32 x10;    /* 0x10 */
    u8 pad14[0x2C];
    f32 x40;    /* 0x40 */
    f32 x44;
    f32 x48;    /* 0x48 */
    u8 pad4C[0xB8];
    f32 radius; /* 0x104 */
} Obj;

typedef struct Info { s16 x0; s16 h; } Info;

s32 func_8004303C(Obj *);
f32 func_8002D858(Obj *, s32 *);
void func_8002D3E4(Obj *, s32);
void func_8002DA80(Obj *);
Info *func_800851D8(Obj *);

s32 func_80083EDC(Obj *arg0) {
    s32 tmp;
    f32 d;
    f32 dx;
    f32 dz;

    func_8004303C(arg0);
    d = func_8002D858(arg0, &tmp);
    arg0->x10 = tmp;
    func_8002D3E4(arg0, 0x22B);
    func_8002DA80(arg0);
    if (d <= func_800851D8(arg0)->h + 50.0f) {
        return 2;
    }
    dx = arg0->x - arg0->x40;
    dz = arg0->z - arg0->x48;
    d = sqrtf(dx * dx + dz * dz);
    if (arg0->radius <= d) {
        arg0->x = arg0->x40 + dx * arg0->radius / d;
        arg0->z = arg0->x48 + dz * arg0->radius / d;
        return 1;
    }
    return 0;
}
