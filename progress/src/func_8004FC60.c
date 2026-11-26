/* adapted from similar verified C in func_8004F9D0 in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
typedef struct { s32 x, y, z; } Pt;
typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 ang;
    /* 0x14 */ u8 pad14[0x58];
    /* 0x6C */ s32 f6C;
    /* 0x70 */ u8 pad70[0x14];
    /* 0x84 */ s32 f84;
    /* 0x88 */ s32 f88;
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
} Obj;
s32 func_8002492C(f32, f32);
s32 func_8002D204(s32, s32, s32);
void func_8002E1CC(f32 *, f32 *, f32);
void func_8002E1FC(f32 *, f32 *, f32 *);
void func_8002E234(f32 *, f32 *, f32 *);
void func_800899DC(char *);
extern char D_80007F84[];
extern s32 D_800B9ECC;
extern s32 D_8014A928[];
extern Pt *D_8014A9A8[];

void func_8004FC60(Obj *arg0, s32 path) {
    f32 a[4];
    f32 b[4];
    f32 d[4];
    f32 p[4];
    s32 i;
    s32 j;
    Pt *pts;
    f32 t;
    f32 dx;
    f32 dz;
    s32 ang;

    i = arg0->f88;
    pts = D_8014A9A8[path];
    if (D_8014A928[path] == 0) {
        func_800899DC(D_80007F84);
    }
    j = i + 1;
    if (j > D_8014A928[path] - 1) {
        j = 0;
    }
    a[0] = pts[i].x;
    a[1] = pts[i].y;
    a[2] = pts[i].z;
    b[0] = pts[j].x;
    b[1] = pts[j].y;
    b[2] = pts[j].z;
    t = arg0->f84 * 0.00390625f;
    dx = b[0] - a[0];
    dz = b[2] - a[2];
    func_8002E1FC(d, b, a);
    func_8002E1CC(p, d, t);
    func_8002E234(p, p, a);
    arg0->f84 += arg0->f90 * D_800B9ECC / arg0->f8C;
    if (arg0->f84 >= 256) {
        arg0->f84 -= 256;
        arg0->f88++;
        if (arg0->f88 > D_8014A928[path] - 1) {
            arg0->f88 = 0;
        }
    }
    if (arg0->f84 < 0) {
        arg0->f84 += 256;
        arg0->f88--;
        if (arg0->f88 < 0) {
            arg0->f88 = D_8014A928[path] - 1;
        }
    }
    arg0->x = p[0];
    arg0->y = p[1];
    arg0->z = p[2];
    ang = func_8002492C(dx, dz);
    if (arg0->f6C == 0xB94598) {
        arg0->ang = func_8002D204(ang + (ang - arg0->ang) * 2, arg0->ang, D_800B9ECC << 5);
    }
    if (arg0->f6C == 0xB8FD2A) {
        arg0->ang = func_8002D204(ang, arg0->ang, D_800B9ECC << 8);
    } else {
        arg0->ang = func_8002D204(ang, arg0->ang, D_800B9ECC << 6);
    }
}

