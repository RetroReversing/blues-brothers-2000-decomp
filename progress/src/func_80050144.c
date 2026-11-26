typedef struct {
    s32 x, y, z;
} Vec3i_50144;

typedef struct {
    f32 x, y, z;
} Vec3f_50144;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    u8 pad14[0x6C - 0x14];
    s32 unk6C;
    u8 pad70[0x74 - 0x70];
    s32 unk74;
    u8 pad78[0x80 - 0x78];
    s32 unk80;
    s32 unk84;
    s32 unk88;
} Unk80050144;

extern s32 D_8014A928[];
extern Vec3i_50144 *D_8014A9A8[];
extern s32 D_800B9ECC;
extern char D_80007FD4[];

void func_800899DC(void *, ...);
s32 func_8002E1FC(void *arg0, void *arg1, void *arg2);
s32 func_8002E1CC(void *arg0, void *arg1, f32 arg2);
s32 func_8002E234(void *arg0, void *arg1, void *arg2);
s32 func_8002492C(f32, f32);
s32 func_8002D204(s32 arg0, s32 arg1, s32 arg2);

s32 func_80050144(Unk80050144 *arg0, s32 arg1) {
    s32 *count;
    Vec3i_50144 *pts;
    s32 i;
    s32 next;
    s32 ret;
    Vec3f_50144 a;
    Vec3f_50144 b;
    Vec3f_50144 c;
    Vec3f_50144 d;
    f32 t;
    f32 dx;
    f32 dz;
    s32 angle;
    s32 step;

    i = arg0->unk88;
    pts = D_8014A9A8[arg1];
    count = &D_8014A928[arg1];
    ret = 0;
    if (*count == 0) {
        func_800899DC(D_80007FD4, arg1);
    }
    next = i + 1;
    if (next >= *count - 1) {
        next = 0;
    }
    a.x = pts[i].x;
    a.y = pts[i].y;
    a.z = pts[i].z;
    b.x = pts[next].x;
    b.y = pts[next].y;
    b.z = pts[next].z;
    t = (f32)arg0->unk84 * 0.00390625f;
    dx = b.x - a.x;
    dz = b.z - a.z;
    func_8002E1FC(&c, &b, &a);
    func_8002E1CC(&d, &c, t);
    func_8002E234(&d, &d, &a);
    if (arg0->unk84 >= 0x100) {
        if (arg0->unk88 + 1 < *count - 2) {
            arg0->unk84 -= 0x100;
            arg0->unk88++;
        } else {
            ret = 1;
            arg0->unk84 = 0xFF;
            if (arg0->unk74 != 0) {
                arg0->unk80 = -arg0->unk80;
                return ret;
            }
        }
    }
    if (arg0->unk84 < 0) {
        if (arg0->unk88 - 1 >= 0) {
            arg0->unk84 += 0x100;
            arg0->unk88--;
        } else {
            ret++;
            arg0->unk84 = 1;
            if (arg0->unk74 != 0) {
                arg0->unk80 = -arg0->unk80;
                return 1;
            }
        }
    }
    if (ret == 0) {
        step = D_800B9ECC * 2;
        arg0->unk84 += arg0->unk80 * step;
    }
    arg0->unk4 = d.x;
    arg0->unk8 = d.y;
    arg0->unkC = d.z;
    angle = func_8002492C(dx, dz);
    if (arg0->unk6C == 0xB94598) {
        arg0->unk10 = func_8002D204(angle + (angle - arg0->unk10) * 2, arg0->unk10, D_800B9ECC << 5);
    }
    if (arg0->unk6C == 0xB8FD2A) {
        arg0->unk10 = func_8002D204(angle, arg0->unk10, D_800B9ECC << 9);
    } else {
        arg0->unk10 = func_8002D204(angle, arg0->unk10, D_800B9ECC << 6);
    }
    return ret;
}
