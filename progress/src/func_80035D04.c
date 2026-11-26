typedef struct { f32 x, y, z; } Vec3;
f32 __cosf(f32);
s32 func_80024AC4(s32, s32);
void func_8002DAE0(void *, void *, f32);
void func_8002DB6C(void *, void *, f32);
void func_8002DC84(void *);
void func_8002DD8C(void *, void *, void *);
s32 func_80035364(void *, void *, s32);
void func_80036BD0(void *, void *, void *, void *);
void func_80036CF8(void *, void *, void *, void *);
void func_80048820(void *, void *, s32);
f32 func_80095DC0(f32);
extern Vec3 D_800B4B84[];
extern f32 *D_800BD06C;
extern s32 D_8013FFA4;
extern s32 D_8013FFA8;

typedef struct {
    u8 pad0[4];
    f32 x, y, z;
    u8 pad10[4];
    s32 unk10;
    s32 unk14;
} Obj35D04;

void func_80035D04(s32 *arg0) {
    f32 sp10[8];
    f32 sp30[4];
    f32 sp40[10];
    f32 sp68[10];
    Vec3 pts[5];
    f32 spD0[4];
    f32 spE0[4];
    s32 t;
    f32 r;
    f32 a;
    f32 b;
    f32 k;
    s32 i;
    s32 mask;
    s32 bit;
    s32 dx;
    s32 dz;

    D_8013FFA8 -= func_80024AC4(D_8013FFA8 * 3, 3);
    t = func_80024AC4(D_8013FFA4 * 3, 3);
    a = arg0[0x14 / 4];
    a *= (3.1415926 / 32768.0);
    b = arg0[0x10 / 4];
    b *= (3.1415926 / 32768.0);
    r = arg0[0x78 / 4];
    sp30[0] = ((f32 *)arg0)[1];
    sp30[1] = ((f32 *)arg0)[2];
    sp30[2] = ((f32 *)arg0)[3];
    sp10[0] = D_800BD06C[1];
    D_8013FFA4 -= t;
    sp10[1] = D_800BD06C[2] + 200.0f;
    sp10[2] = D_800BD06C[3];
    func_8002DC84(sp40);
    func_8002DC84(sp68);
    func_8002DB6C(sp40, sp68, b);
    func_8002DAE0(sp68, sp40, -a);
    k = r * __cosf(a);
    k *= func_80095DC0(b);
    sp30[0] = sp10[0] - k;
    sp30[1] = sp10[1] - r * func_80095DC0(a);
    r *= __cosf(a);
    r *= __cosf(b);
    sp30[2] = sp10[2] - r;
    mask = 0;
    bit = 1;
    for (i = 1; i < 5; i++) {
        func_8002DD8C(&pts[i], sp68, &D_800B4B84[i]);
        pts[i].x += sp30[0];
        pts[i].y += sp30[1];
        pts[i].z += sp30[2];
        if (i == 1) {
            func_80036CF8(spD0, spE0, &pts[1], sp10);
        } else {
            func_80036BD0(spD0, spE0, &pts[i], sp10);
        }
    }
    func_80048820(spD0, spE0, 3);
    for (i = 1; i < 5; i++) {
        if (func_80035364(sp10, &pts[i], 0) != 0) {
            mask |= bit;
        }
        bit <<= 1;
    }
    if (mask != 0) {
        dz = 0;
        dx = 0;
        if ((mask & 6) == 6) {
            dz = -0x200;
        }
        if ((mask & 9) == 9) {
            dz += 0x200;
        }
        if ((mask & 3) == 3) {
            dx = 0x200;
        }
        if ((mask & 0xC) == 0xC) {
            dx -= 0x200;
        }
        if ((mask & 0xD) == 0xD) {
            dx -= 0x200;
        }
        if ((mask & 7) == 7) {
            dx -= 0x200;
        }
        if ((mask & 0xE) == 0xE) {
            dx -= 0x200;
        }
        if ((mask & 0xB) == 0xB) {
            dx -= 0x200;
        }
        if ((mask & 0xF) == 0xF) {
            dx -= 0x200;
        }
        D_8013FFA8 += dx;
        D_8013FFA4 += dz;
    }
}
