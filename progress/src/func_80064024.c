typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x34];
    f32 f44;
} Obj;
f32 func_8002D340(f32, f32, f32);
void func_80036F44(Obj *);
float sqrtf(float);
extern s32 D_800B9ECC;
extern Obj *D_800BD06C;

void func_80064024(Obj *o) {
    f32 dx;
    f32 dz;
    f32 d;
    f32 h;
    f32 target;

    dx = D_800BD06C->x - o->x;
    dz = D_800BD06C->z - o->z;
    d = sqrtf(dx * dx + dz * dz);
    if (d < 800.0) {
        h = 400.0 - d * 0.5f;
        o->y = func_8002D340(o->f44 + (h + h), o->y, D_800B9ECC * 20);
    } else {
        o->y = func_8002D340(o->f44, o->y, D_800B9ECC * 20);
    }
    func_80036F44(o);
}
