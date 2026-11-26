typedef struct { f32 x, y, z, w; } V4;
typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x6C - 0x18];
    s32 unk6C;
    u8 pad70[0x78 - 0x70];
    s32 unk78;
    s32 unk7C;
} Obj;

f32 __cosf(f32);
f32 func_80095DC0(f32);
void func_8002DAE0(void *, void *, f32);
void func_8002DB6C(void *, void *, f32);
void func_8002DC84(void *);
f32 func_8002E080(V4 *);
f32 func_8002E0D0(V4 *, void *);
void func_8002E1CC(V4 *, V4 *, f32);
V4 *func_8002E1FC(V4 *, V4 *, V4 *);
void func_8002E234(V4 *, V4 *, V4 *);
s32 func_80035364(V4 *, V4 *, V4 *);
extern s32 D_800B4B34[];
extern Obj *D_800BD06C;
extern u8 D_8013FFC0[];

void func_80035A90(Obj *arg0) {
    V4 d;
    V4 hit;
    V4 from;
    V4 to;
    u8 m1[0x28];
    u8 m2[0x28];
    f32 r;
    f32 t;
    f32 yaw, pitch;
    s32 dist;

    r = -D_800B4B34[arg0->unk6C];
    to.x = arg0->x;
    to.y = arg0->y;
    to.z = arg0->z;
    from.x = D_800BD06C->x;
    from.y = D_800BD06C->y + 200.0f;
    from.z = D_800BD06C->z;
    yaw = arg0->unk10;
    yaw *= 9.587379760742188e-05;
    pitch = arg0->unk14;
    pitch *= 9.587379760742188e-05;
    func_8002DC84(m1);
    func_8002DC84(m2);
    func_8002DB6C(m1, m2, yaw);
    func_8002DAE0(m2, m1, -pitch);
    t = r * __cosf(pitch);
    t *= func_80095DC0(yaw);
    to.x = from.x + t;
    to.y = from.y + r * func_80095DC0(pitch);
    r *= __cosf(pitch);
    r *= __cosf(yaw);
    to.z = from.z + r;
    if (func_80035364(&from, &to, &hit) != 0) {
        dist = func_8002E080(func_8002E1FC(&d, &hit, &from));
        arg0->unk7C = dist;
        if (dist < arg0->unk78) {
            arg0->unk78 = dist;
            arg0->x = hit.x;
            arg0->z = hit.z;
            arg0->y = hit.y;
            func_8002E1FC(&d, &hit, &from);
            func_8002E1CC(&d, &d, 1.0 - 150.0 / -func_8002E0D0(&d, D_8013FFC0));
            func_8002E234(&hit, &d, &from);
        }
    } else {
        arg0->unk7C = D_800B4B34[arg0->unk6C];
    }
}
