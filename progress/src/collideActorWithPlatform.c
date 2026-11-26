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
extern Vec3i gPlatformMaxOffsets[];
extern Vec3i gPlatformMinOffsets[];

/* Tests an actor against a platform's bounding box: landing on top calls handleActorHit and returns 1, and a side hit pushes the actor clear of the box and returns 0. */ s32 collideActorWithPlatform(Obj *actor, Obj *platform) {
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

    minx = platform->x4 + gPlatformMinOffsets[platform->xB8].x;
    maxy = platform->x8 + gPlatformMaxOffsets[platform->xB8].y;
    maxx = platform->x4 + gPlatformMaxOffsets[platform->xB8].x;
    minz = platform->xC + gPlatformMinOffsets[platform->xB8].z;
    flags = 0;
    maxz = platform->xC + gPlatformMaxOffsets[platform->xB8].z;
    y = actor->x8;
    m = 75;
    if (maxy < y) {
        return 0;
    }
    if (y + D_8000087C < platform->x8 + gPlatformMinOffsets[platform->xB8].y) {
        return 0;
    }
    if (maxy <= actor->x44 && y <= maxy && minx - m <= actor->x4 && actor->x4 <= maxx + m &&
        minz - m <= actor->xC && actor->xC <= maxz + m) {
        handleActorHit(actor, maxy + D_80000880);
        platform->xC0 |= 2;
        return 1;
    }
    if (actor->x4 < minx - m) {
        return 0;
    }
    if (maxx + m < actor->x4) {
        return 0;
    }
    if (actor->xC < minz - m) {
        return 0;
    }
    if (maxz + m < actor->xC) {
        return 0;
    }
    dx = actor->x40 - platform->x4;
    if (dx >= gPlatformMaxOffsets[platform->xB8].x + m) {
        flags |= 1;
    }
    if (gPlatformMinOffsets[platform->xB8].x - m >= dx) {
        flags |= 4;
    }
    dz = actor->x48 - platform->xC;
    if (dz >= gPlatformMaxOffsets[platform->xB8].z + m) {
        flags |= 2;
    }
    if (gPlatformMinOffsets[platform->xB8].z - m >= dz) {
        flags |= 8;
    }
    switch (flags) {
    case 1:
    case 3:
    case 9:
        actor->x4 = platform->x4 + gPlatformMaxOffsets[platform->xB8].x + m;
        break;
    case 2:
        actor->xC = platform->xC + gPlatformMaxOffsets[platform->xB8].z + m;
        break;
    case 4:
    case 5:
    case 6:
        actor->x4 = platform->x4 + gPlatformMinOffsets[platform->xB8].x - m;
        break;
    case 8:
        actor->xC = platform->xC + gPlatformMinOffsets[platform->xB8].z - m;
        break;
    }
    return 0;
}
