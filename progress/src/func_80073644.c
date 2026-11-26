typedef struct Obj73644 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x60 - 0x14];
    s32 unk60;
    u8 pad64[0x68 - 0x64];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x98 - 0x94];
    void *unk98;
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
} Obj73644;

s16 sins(u16);
s16 coss(u16);
Obj73644 *func_800232B4(s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_800242A8(s32, s32, s32, ...);
void func_8002D620(Obj73644 *);
f32 func_800385AC(Obj73644 *);
void func_8003CAD4(Obj73644 *, s32);
void func_80052A30(void);
Obj73644 *func_8006B43C(s32);
Obj73644 *func_80077C48(s32);
void func_800340B4(void);
void func_800393F4(void);
void func_80073394(void);
void func_80073478(void);
void func_800739D4(void);
void func_80073B7C(void);
void func_800740A8(void);
void func_800743F8(void);
extern f64 D_80009138;
extern f64 D_80009140;
extern f32 D_80009148;
extern Obj73644 *D_800B3960;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B5DD4;
extern s32 D_800B83B0;
extern Obj73644 *D_800BD06C;
extern s32 D_800BD280;
extern s32 D_800BD68C;

void func_80073644(Obj73644 *arg0) {
    s32 i;
    s32 a;
    Obj73644 *o;
    Obj73644 *p;
    s32 id;

    if (arg0->unk7C == 0) {
        id = D_800B83B0;
        arg0->unk7C = 1;
        D_800B3978 = 0;
        D_800B3974 = 0;
        arg0->unk90 = 0;
        D_800B3970 = 0;
        D_800B3960->unkC0 = 0;
        arg0->unk6C = id + 470;
        id++;
        D_800B83B0 = id;
        func_800242A8(arg0->unk6C, 0xDAA, 0);
        arg0->unk60 = func_80023D58(0x210);
        arg0->unk98 = func_800739D4;
        arg0->unk68 = 14;
        func_800232B4(1, 0, 0, 0)->unk9C = func_80073394;
        o = func_8006B43C(0);
        o->x = 20.0f;
        o->y = 1281.0f;
        o->z = -5818.0f;
        o = func_80077C48(0);
        o->x = 20.0f;
        o->y = 181.0f;
        o->z = -5818.0f;
        func_8002D620(o);
        arg0->x = o->x;
        arg0->y = o->y + 500.0f;
        arg0->z = o->z - 2000.0f;
        for (i = 0; i < 8; i++) {
            p = func_800232B4(1, o->x, o->y, o->z);
            a = (s32)((f32)i * 45.0f * D_80009138 / D_80009140) & 0xFFFF;
            p->x += (sins(a) * 75) >> 12;
            p->z += (coss(a) * 75) >> 12;
            p->unk9C = func_800740A8;
            p->y = 365.0f;
        }
        for (i = 1; i < 6; i++) {
            o = func_800232B4(1, 0, 0, 0);
            o->unk70 = i;
            o->unk9C = func_800743F8;
        }
        func_80052A30();
        D_800BD06C->y = func_800385AC(D_800BD06C);
        func_8002D620(D_800BD06C);
        func_8003CAD4(D_800BD06C, D_800BD06C->unk10);
        D_800B5DD4 = 0;
        D_800B3960->y = D_800BD68C - 500;
        D_800B3960->z = D_800BD280;
        D_800B3960->unk9C = func_80073478;
        return;
    }
    func_80052A30();
    if (arg0->unk7C == 3) {
        arg0->unk9C = func_80073B7C;
        D_800BD06C->unk9C = func_800393F4;
        D_800B3960->unk9C = func_800340B4;
        D_800B3960->unkC0 = 0;
        D_800B5DD4 = 1;
        arg0->unk7C++;
    }
}

