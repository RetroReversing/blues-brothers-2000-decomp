typedef struct { s32 x, y, z; } Vec3i;
s16 coss(u16);
s16 sins(u16);
s32 randomRange(s32, s32);

void func_80020B3C(u8 *arg0)
{
    s32 n;
    s32 x, y, z;
    s32 ex, ey, ez;
    s32 ox, oy, oz;
    s32 i;
    Vec3i *p;

    i = 0;
    n = 3;
    *(s32 *)(arg0 + 0x74) = 4;
    x = *(f32 *)(arg0 + 4);
    y = *(f32 *)(arg0 + 8);
    z = *(f32 *)(arg0 + 0xC);
    p = *(Vec3i **)(arg0 + 0xC4);
    ez = z + ((coss(*(u16 *)(arg0 + 0x12)) * 25) >> 11);
    ex = x + ((sins(*(u16 *)(arg0 + 0x12)) * 25) >> 11);
    ey = y;
    for (; i < 4; i++) {
        if (i != 0 && i != n) {
            ox = randomRange(-10, 10);
            oy = randomRange(-10, 10);
            oz = randomRange(-10, 10);
        } else {
            ox = oy = oz = 0;
        }
        p[i].x = ((ex - x) * i) / n + x + ox;
        p[i].y = ((ey - y) * i) / n + y + oy;
        p[i].z = ((ez - z) * i) / n + z + oz;
    }
}
