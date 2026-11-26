typedef struct {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x60];
    s32 unk78;
} Obj;

void func_8002DC84(f32 m[3][3]);
void func_8002DB6C(f32 a[3][3], f32 b[3][3], f32 angle);
void func_8002DAE0(f32 a[3][3], f32 b[3][3], f32 angle);
void func_8002DD8C(f32 *out, f32 m[3][3], f32 *v);
f32 __cosf(f32);
f32 func_80095DC0(f32);
void func_80036CF8(f32 *a, f32 *b, f32 *p, f32 *c);
void func_80036BD0(f32 *a, f32 *b, f32 *p, f32 *c);
void func_80048820(f32 *a, f32 *b, s32 n);
s32 func_80035364(f32 *c, f32 *p, s32 n);
extern Obj *D_800BD06C;
extern f32 D_800B4B84[][3];

s32 func_80036780(Obj *arg0) {
    f32 c[8];
    f32 pos[3];
    f32 m1[3][3];
    f32 m2[3][3];
    f32 pts[5][3];
    f32 lo[4];
    f32 hi[4];
    f32 pitch;
    f32 yaw;
    f32 r;
    f32 t;
    s32 i;
    s32 bit;
    s32 res;

    yaw = (f32)arg0->unk14;
    pitch = (f32)arg0->unk10;
    yaw = yaw * 9.587379760742188e-05;
    r = (f32)arg0->unk78;
    pos[0] = arg0->x;
    pos[1] = arg0->y;
    pos[2] = arg0->z;
    pitch = pitch * 9.587379760742188e-05;
    c[0] = D_800BD06C->x;
    c[1] = D_800BD06C->y + 200.0f;
    c[2] = D_800BD06C->z;
    func_8002DC84(m1);
    func_8002DC84(m2);
    func_8002DB6C(m1, m2, pitch);
    func_8002DAE0(m2, m1, -yaw);
    t = r * __cosf(yaw);
    t *= func_80095DC0(pitch);
    pos[0] = c[0] - t;
    pos[1] = c[1] - r * func_80095DC0(yaw);
    res = 0;
    r = r * __cosf(yaw);
    bit = 1;
    r *= __cosf(pitch);
    pos[2] = c[2] - r;
    for (i = 1; i < 5; i++) {
        func_8002DD8C(pts[i], m2, D_800B4B84[i]);
        pts[i][0] += pos[0];
        pts[i][1] += pos[1];
        pts[i][2] += pos[2];
        if (i == 1) {
            func_80036CF8(lo, hi, pts[1], c);
        } else {
            func_80036BD0(lo, hi, pts[i], c);
        }
    }
    func_80048820(lo, hi, 3);
    for (i = 1; i < 5; i++) {
        if (func_80035364(c, pts[i], 0) != 0) {
            res |= bit;
        }
        bit <<= 1;
    }
    return res;
}
