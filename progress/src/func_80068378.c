typedef struct Obj68378 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x58 - 0x1C];
    s32 unk58;
    u8 pad5C[0x64 - 0x5C];
    s32 unk64;
    u8 pad68[0x70 - 0x68];
    s32 unk70;
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    u8 pad80[0x84 - 0x80];
    s32 unk84;
    s32 unk88;
    u8 pad8C[0x9C - 0x8C];
    void *unk9C;
    u8 padA0[0xA8 - 0xA0];
    struct Obj68378 *unkA8;
    u8 padAC[0xC0 - 0xAC];
    s32 unkC0;
    u8 padC4[0x108 - 0xC4];
} Obj68378;

typedef struct {
    s32 x, y, z;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Entry68378;

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Player68378;

s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
Obj68378 *func_800232B4(s32, s32, s32, s32);
Obj68378 *findActor(s32, Obj68378 *);
void func_800242A8(s32, s32, s32);
void syncActorPrevPos(Obj68378 *);
Obj68378 *func_8002E374(s32);
Obj68378 *func_80051BE8(s32);
void func_80052A30(void);
void func_800682CC(void);
Obj68378 *func_80068A34(s32);
Obj68378 *func_8006AE5C(Obj68378 *);
void func_80017880(void);
void func_800646C0(void);
void func_80064730(void);
void cameraUpdateByMode(void);
void func_80068768(void);
void func_800690B0(void);
void func_8006982C(void);
extern Obj68378 *D_800AB9BC;
extern Obj68378 *D_800AB9C0;
extern Obj68378 *D_800B3960;
extern s32 D_800B5DD4;
extern Entry68378 D_800B8000[];
extern s32 D_800B83B0;
extern Player68378 *gCameraTarget;

void func_80068378(Obj68378 *arg0) {
    s32 i;
    s32 id;
    Entry68378 *e;
    Obj68378 *o;
    Obj68378 *keep;
    Obj68378 *o2;
    Obj68378 *p;
    Obj68378 *end;

    if (arg0->unkC0 == 0) {
        i = 0;
        arg0->unkC0 = 1;
        arg0->unk64 = 100;
        arg0->unk7C = 0;
        arg0->unk74 = 0;
        arg0->unk88 = 0;
        arg0->unk84 = 0;
        gCameraTarget->unk3C = 320;
        gCameraTarget->unk38 = 320;
        gCameraTarget->unk34 = 320;
        func_800682CC();
        D_800B5DD4 = 0;
        func_80052A30();
        id = D_800B83B0 + 470;
        D_800B83B0++;
        func_800242A8(id, 0xDC9, i);
        for (i = 0; i < 14; i++) {
            o = func_8002E374(id);
            o->x = D_800B8000[i].x;
            o->y = D_800B8000[i].y;
            o->z = D_800B8000[i].z;
            o->unk10 = -(D_800B8000[i].unk10 << 16) / 360;
            o->unk14 = (D_800B8000[i].unkC << 16) / 360;
            o->unk18 = (D_800B8000[i].unk14 << 16) / 360;
            o->unk74 = D_800B8000[i].unk18;
            o->unk70 = D_800B8000[i].unk1C;
            o->unk9C = func_800690B0;
        }
        keep = findActor(0x13C, NULL);
        if (keep != NULL) {
            keep->x = -593.0f;
            keep->y = 371.0f;
            keep->z = 2101.0f;
        }
        o = func_80068A34(0);
        o->x = 0.0f;
        o->y = -35.0f;
        o->z = 1535.0f;
        keep = func_8006AE5C(arg0);
        keep->unk10 = 0x8000;
        keep->x = -500.0f;
        keep->y = 900.0f;
        keep->z = -2080.0f;
        keep->unk58 = packDrawFlags(1, 1, 2, 3, 0, 0, 1, 0);
        o = func_80051BE8(0);
        o->x = 406.0f;
        o->y = 726.0f;
        o->z = 1870.0f;
        arg0->unk10 = 0x7000;
        o = func_800232B4(1, 0, 0, 0);
        o->unk9C = func_800646C0;
        o->unk70 = 4;
        o->y = 800.0f;
        o->z = -1850.0f;
    }
    if (arg0->unk7C == 0) {
        o = findActor(0x8001, NULL);
        if (o != NULL) {
            o2 = findActor(0x1012, NULL);
            if (o2 != NULL) {
                o->unk9C = cameraUpdateByMode;
                o->x = 0.0f;
                o->unkC0 = 0;
                o->unkA8 = o2;
                o->y = 815.0f;
                o->z = -2920.0f;
                syncActorPrevPos(o);
                arg0->unk7C = 1;
            }
        }
        o = D_800AB9BC;
        arg0->unk7C = 1;
        for (; o <= D_800AB9C0; o++) {
            if (o->unk9C == func_80017880) {
                o->unk9C = func_8006982C;
                o->unk7C = 0;
            }
        }
    }
    if (arg0->unk7C == 1) {
        arg0->unk9C = func_80068768;
        arg0->unk7C = 0;
        arg0->unk70 = 0;
    }
    D_800B3960->unkA8 = keep;
    D_800B3960->unk9C = func_80064730;
}
