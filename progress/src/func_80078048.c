typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj Obj;
struct Obj {
    s32 unk0;
    f32 x, y, z;
    u8 pad10[0x64 - 0x10];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[0xA4 - 0x88];
    Obj *unkA4;
    s32 unkA8;
    u8 padAC[0xB8 - 0xAC];
    s32 unkB8;
    u8 padBC[0xD0 - 0xBC];
    s32 unkD0;
};

s32 func_8001B990(s32, s32);
Obj *func_80022028(s32);
s32 randomRange(s32, s32);
s32 tickActorTimer(Obj *);
f32 func_8002D858(Obj *, s32);
void func_8003A9A8(Obj *, s32);
s32 func_80043248(Obj *);
void func_80043328(Obj *, s32, s32);
s16 sins(u16);
int abs(int);
extern s32 gTextWaveTime;
extern Obj *gCameraTarget;
extern Vec3i D_800F4A00[];

void func_80078048(Obj *arg0) {
    s32 r;
    f32 dist;
    s32 hit;
    Obj *p;
    s32 w;

    r = arg0->unk70;
    if (arg0->unk7C == 0) {
        arg0->unk0 = 0x142;
        arg0->unk84 = 0;
        arg0->unkA8 = 0;
        arg0->unk7C = 1;
    }
    dist = func_8002D858(arg0, 0);
    hit = func_8001B990(0x100, arg0->unk70);
    if (arg0->unkA4 != NULL) {
        p = arg0->unkA4;
        p->unk80 = randomRange(-10000, 8000) + 0x3000;
        p->unk70 = (sins((gTextWaveTime * 200) & 0xFFF8) >> 12) + 15;
    }
    if (200.0f < dist && hit != 0 && arg0->unk84 != 0) {
        goto end;
    }
    if (hit != 0 && arg0->unk84 == 0) {
        func_8001B990(0x200, r);
        if (func_80043248(arg0) != 0) {
            p = func_80022028(0);
            p->x = arg0->x;
            p->y = arg0->y + 100.0f;
            p->z = arg0->z;
            p->unk70 = 50;
            p->unk7C = 15;
            p->unk80 = 0x4000;
            p->unk84 = 50;
            p = func_80022028(0);
            p->x = arg0->x;
            p->y = arg0->y + 100.0f;
            p->z = arg0->z;
            p->unk70 = 10;
            p->unk84 = 50;
            p->unk80 -= 0x1000;
            p->unk74 += 200;
            arg0->unkA4 = p;
            arg0->unk84 = 1;
            return;
        }
    }
    if (arg0->unk84 == 0) {
        return;
    }
    D_800F4A00[arg0->unkB8].y = abs((sins((gTextWaveTime * 150) & 0xFFFE) * 225) >> 14) + 150;
    if (dist < 140.0f && arg0->unkA8 != 0) {
        func_80043328(gCameraTarget, 0x20, 0x100);
        arg0->unk64 = 50;
        return;
    }
end:
    if (gCameraTarget->unkD0 == 0x20 && tickActorTimer(arg0) != 0) {
        func_8003A9A8(gCameraTarget, 1);
    }
}
