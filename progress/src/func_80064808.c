typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x30];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[0x5C];
    s32 fA8;
} Obj;
f32 func_8002D340(f32, f32, f32);
void func_80034FEC(Obj *, s32 *);
void func_8001FF64(Obj *);
void func_80036FB8(Obj *, s32);
extern s32 D_800B9ECC;
extern Obj *D_800BD06C;
extern s32 D_80140228;

void func_80064808(Obj *o) {
    s32 v[3];
    s32 speed;

    speed = D_800B9ECC * 100;
    if (o->fA8 != 0) {
        o->y = func_8002D340(o->f44, o->y, speed);
        o->z = func_8002D340(o->f48, o->z, speed);
        v[0] = 0;
        v[2] = 0x5FF;
        v[1] = 700;
    } else {
        o->x = o->f40;
        o->y = func_8002D340(o->f44 - 200.0f, o->y, speed);
        o->z = func_8002D340(D_800BD06C->z - 1250.0f, o->z, speed);
        D_80140228 = 0;
        v[0] = D_800BD06C->x * 0.5f;
        v[2] = D_800BD06C->z;
        v[1] = 500;
    }
    func_80034FEC(o, v);
    func_8001FF64(o);
    func_80036FB8(o, 15);
}
