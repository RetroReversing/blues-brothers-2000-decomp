s16 coss(u16);
s16 sins(u16);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80024394(s32, s32);
void *func_800253A0(s32);
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

extern s32 D_800B9EA0;
extern s32 D_801073C0;

void func_80021060(Obj *arg0) {
    Part *p;
    s32 i;
    s32 spd;
    s32 a;
    s32 b;

    if (arg0->xC4 == 0) {
        arg0->x68 = 13;
        p = func_800253A0(arg0->x84 * sizeof(Part));
        arg0->xC4 = p;
        for (i = 0; i < arg0->x84; i++) {
            p[i].x = func_80024394(-1000, 1000);
            p[i].y = func_80024394(-1000, 1000);
            p[i].z = func_80024394(-1000, 1000);
            p[i].vx = 0;
            p[i].vy = 0;
            p[i].vz = 0;
        }
        arg0->x58 = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
    }
    p = arg0->xC4;
    for (i = 0; i < arg0->x84; i++) {
        p[i].x += (p[i].vx * D_800B9EA0) / 100;
        p[i].y += (p[i].vy * D_800B9EA0) / 100;
        p[i].z += (p[i].vz * D_800B9EA0) / 100;
        if (i == arg0->x88) {
            spd = (D_801073C0 * 3000) / 80;
            a = func_8002D1A0();
            b = func_80024394(0x2000, 0x2FA0);
            p[i].vx = (((spd * sins(a)) >> 15) * coss(b)) >> 15;
            p[i].vz = (((spd * coss(a)) >> 15) * coss(b)) >> 15;
            p[i].vy = (spd * sins(b)) >> 15;
            p[i].vy = func_80024394(100, 200);
            p[i].vx = 0;
            p[i].vz = 0;
            p[i].y = 10;
            p[i].x = func_80024394(-100, 100);
            p[i].z = func_80024394(-100, 100);
        }
    }
    if (++arg0->x88 >= 100) {
        arg0->x88 = 0;
    }
}
