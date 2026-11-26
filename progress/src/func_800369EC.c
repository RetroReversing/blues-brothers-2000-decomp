typedef struct {
    f32 x, y, z;
} Vec3f;
typedef struct {
    s32 pad0;
    Vec3f pos;
} Obj;
f32 __cosf(f32);
f32 func_80095DC0(f32);
void func_8002DAE0(void *, void *, f32);
void func_8002DB6C(void *, void *, f32);
void func_8002DC84(void *);
void func_8002DD8C(Vec3f *, void *, Vec3f *);
s32 func_80035364(Vec3f *, Vec3f *, s32);
extern Vec3f D_800B4B84[];
extern Obj *D_800BD06C;

s32 func_800369EC(Obj *arg0, s32 dist, s32 yaw, s32 pitch) {
    Vec3f cam;
    Vec3f pt;
    Vec3f pos;
    u8 m1[0x28];
    u8 m2[0x28];
    f32 t;
    f32 u;
    f32 d;
    f32 a;
    f32 b;
    s32 i;

    d = dist;
    b = pitch;
    b *= 9.587379760742188e-05;
    a = yaw;
    a *= 9.587379760742188e-05;
    pos.x = arg0->pos.x;
    pos.y = arg0->pos.y;
    pos.z = arg0->pos.z;
    cam.x = D_800BD06C->pos.x;
    cam.y = D_800BD06C->pos.y + 200.0f;
    cam.z = D_800BD06C->pos.z;
    func_8002DC84(m1);
    func_8002DC84(m2);
    func_8002DB6C(m1, m2, a);
    func_8002DAE0(m2, m1, -b);
    t = d * __cosf(b);
    t *= func_80095DC0(a);
    pos.x = cam.x - t;
    pos.y = cam.y - d * func_80095DC0(b);
    u = d * __cosf(b);
    u *= __cosf(a);
    pos.z = cam.z - u;
    for (i = 1; i < 5; i++) {
        func_8002DD8C(&pt, m2, &D_800B4B84[i]);
        pt.x += pos.x;
        pt.y += pos.y;
        pt.z += pos.z;
        if (func_80035364(&cam, &pt, 0) != 0) {
            return 0;
        }
    }
    return 1;
}
