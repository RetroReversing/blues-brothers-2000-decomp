typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[0x18];
    f32 f28;
    f32 f2C;
} Obj;
f32 func_8002DD60(f32);
void func_8002DD8C(f32 *, void *, f32 *);
extern Obj *D_800B3960;
extern u8 D_800CD148[];

s32 func_8001F0AC(Obj *o, s32 r) {
    f32 d[3];
    s32 r3;

    d[0] = o->x - D_800B3960->x;
    d[1] = o->y - D_800B3960->y;
    r3 = r / 3;
    d[2] = o->z - D_800B3960->z;
    if (func_8002DD60(d[0]) > r) {
        return 0;
    }
    if (func_8002DD60(d[1]) > r3) {
        return 0;
    }
    func_8002DD8C(&o->f28, D_800CD148, d);
    if (func_8002DD60(o->f28) > r) {
        return 0;
    }
    if (func_8002DD60(o->f2C) > r3) {
        return 0;
    }
    return 1;
}
