typedef struct Vec3i {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x40 - 0x10];
    f32 x40;
    f32 x44;
    f32 x48;
    char pad4C[0xB8 - 0x4C];
    s32 xB8;
    char padBC[0xC0 - 0xBC];
    s32 xC0;
} Obj;

void handleActorHit(Obj *, f32);

extern f32 D_8000087C;
extern f32 D_80000880;
extern Vec3i D_800F4A00[];
extern Vec3i D_800F6188[];

s32 func_80016318(Obj *arg0, Obj *arg1) {
    f32 minx;
    f32 maxy;
    f32 maxx;
    f32 minz;
    f32 maxz;
    f32 y;
    s32 flags;
    s32 m;
    s32 dx;
    s32 dz;

    minx = arg1->x4 + D_800F6188[arg1->xB8].x;
    maxy = arg1->x8 + D_800F4A00[arg1->xB8].y;
    maxx = arg1->x4 + D_800F4A00[arg1->xB8].x;
    minz = arg1->xC + D_800F6188[arg1->xB8].z;
    flags = 0;
    maxz = arg1->xC + D_800F4A00[arg1->xB8].z;
    y = arg0->x8;
    m = 75;
    if (maxy < y) {
        return 0;
    }
    if (y + D_8000087C < arg1->x8 + D_800F6188[arg1->xB8].y) {
        return 0;
    }
    if (maxy <= arg0->x44 && y <= maxy && minx - m <= arg0->x4 && arg0->x4 <= maxx + m &&
        minz - m <= arg0->xC && arg0->xC <= maxz + m) {
        handleActorHit(arg0, maxy + D_80000880);
        arg1->xC0 |= 2;
        return 1;
    }
    if (arg0->x4 < minx - m) {
        return 0;
    }
    if (maxx + m < arg0->x4) {
        return 0;
    }
    if (arg0->xC < minz - m) {
        return 0;
    }
    if (maxz + m < arg0->xC) {
        return 0;
    }
    dx = arg0->x40 - arg1->x4;
    if (dx >= D_800F4A00[arg1->xB8].x + m) {
        flags |= 1;
    }
    if (D_800F6188[arg1->xB8].x - m >= dx) {
        flags |= 4;
    }
    dz = arg0->x48 - arg1->xC;
    if (dz >= D_800F4A00[arg1->xB8].z + m) {
        flags |= 2;
    }
    if (D_800F6188[arg1->xB8].z - m >= dz) {
        flags |= 8;
    }
    switch (flags) {
    case 1:
    case 3:
    case 9:
        arg0->x4 = arg1->x4 + D_800F4A00[arg1->xB8].x + m;
        break;
    case 2:
        arg0->xC = arg1->xC + D_800F4A00[arg1->xB8].z + m;
        break;
    case 4:
    case 5:
    case 6:
        arg0->x4 = arg1->x4 + D_800F6188[arg1->xB8].x - m;
        break;
    case 8:
        arg0->xC = arg1->xC + D_800F6188[arg1->xB8].z - m;
        break;
    }
    return 0;
}
