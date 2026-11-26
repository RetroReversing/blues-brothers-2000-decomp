s16 coss(u16);
s16 sins(u16);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 randomRange(s32, s32);
void *heapAlloc(s32);
s32 func_8002D1A0(void);

typedef struct Part {
    s32 x, y, z;
    s32 vx, vy, vz;
} Part;

typedef struct Obj {
    char pad0[0x58];
    s32 x58;
    char pad5C[0x68 - 0x5C];
    s32 x68;
    char pad6C[0x84 - 0x6C];
    s32 x84;
    s32 x88;
    char pad8C[0xC4 - 0x8C];
    Part *xC4;
} Obj;

extern s32 gFrameScale;
extern s32 gStickY;

void func_80021060(Obj *arg0) {
    Part *p;
    s32 i;
    s32 spd;
    s32 a;
    s32 b;

    if (arg0->xC4 == 0) {
        arg0->x68 = 13;
        p = heapAlloc(arg0->x84 * sizeof(Part));
        arg0->xC4 = p;
        for (i = 0; i < arg0->x84; i++) {
            p[i].x = randomRange(-1000, 1000);
            p[i].y = randomRange(-1000, 1000);
            p[i].z = randomRange(-1000, 1000);
            p[i].vx = 0;
            p[i].vy = 0;
            p[i].vz = 0;
        }
        arg0->x58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    }
    p = arg0->xC4;
    for (i = 0; i < arg0->x84; i++) {
        p[i].x += (p[i].vx * gFrameScale) / 100;
        p[i].y += (p[i].vy * gFrameScale) / 100;
        p[i].z += (p[i].vz * gFrameScale) / 100;
        if (i == arg0->x88) {
            spd = (gStickY * 3000) / 80;
            a = func_8002D1A0();
            b = randomRange(0x2000, 0x2FA0);
            p[i].vx = (((spd * sins(a)) >> 15) * coss(b)) >> 15;
            p[i].vz = (((spd * coss(a)) >> 15) * coss(b)) >> 15;
            p[i].vy = (spd * sins(b)) >> 15;
            p[i].vy = randomRange(100, 200);
            p[i].vx = 0;
            p[i].vz = 0;
            p[i].y = 10;
            p[i].x = randomRange(-100, 100);
            p[i].z = randomRange(-100, 100);
        }
    }
    if (++arg0->x88 >= 100) {
        arg0->x88 = 0;
    }
}
