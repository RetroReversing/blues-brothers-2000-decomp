typedef struct { s32 x, y, z; } Pt;
typedef struct Obj Obj;
struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x34 - 0x14];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x5C - 0x40];
    s32 unk5C;
    u8 pad60[0x64 - 0x60];
    s32 unk64;
    u8 pad68[0x6C - 0x68];
    Obj *unk6C;
    u8 pad70[0x7C - 0x70];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x9C - 0x84];
    void *unk9C;
    u8 padA0[0xA8 - 0xA0];
    s32 unkA8;
    u8 padAC[0xB0 - 0xAC];
    s32 unkB0;
    u8 padB4[0xC0 - 0xB4];
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xDC - 0xD4];
    s32 unkDC;
    u8 padE0[0x104 - 0xE0];
    s32 unk104;
};

s16 coss(u16);
s16 sins(u16);
Obj *func_80023874(s32, s32);
s32 func_80024394(s32, s32);
s32 func_8002D1A0(void);
void func_8002D620(Obj *);
f32 func_8002DD60(f32);
void func_8003CAD4(Obj *, s32);
void func_80043328(Obj *, s32, s32);
void func_80075F58(s32);
Obj *func_8007B880(s32);
void func_80081588(s32, s32);
void func_800899DC(char *);
extern char D_800094D0[];
extern Obj *D_800B3960;
extern s32 D_800B396C;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B9EA0;
extern Obj *D_800BD06C;
extern Pt *D_8014A9A8[];
void func_8001FF64(void);
void func_80034F50(void);
void func_8007ACD4(void);
void func_8007AEBC(void);

void func_8007AFE8(Obj *arg0) {
    Obj *p;
    Obj *q;
    Pt *pts;
    f32 dx, dz, dy;
    s32 i;
    s32 n;
    u16 a;

    if (arg0->unk7C == 0) {
        arg0->unk7C = 1;
        D_800B3970 = 0;
        D_800B3974 = 0;
        D_800B3978 = 0x40;
        D_800B396C = 0x3DE;
        arg0->unk6C = NULL;
        arg0->unkC0 = 0;
        func_80081588(1, 0);
        func_80081588(6, 0);
        func_80075F58(0);
    }
    p = arg0->unk6C;
    if (p == NULL) {
        p = func_80023874(0x120, 0);
        if (p != NULL) {
            arg0->unk6C = p;
        }
    } else {
        dx = D_800BD06C->x - p->x;
        dz = D_800BD06C->z - p->z;
        dy = func_8002DD60(D_800BD06C->y - p->y);
        if (dx * dx + dz * dz < 1960000.0f && dy < 500.0f) {
            func_8003CAD4(D_800BD06C, D_800BD06C->unk10);
            D_800B3960->unk9C = func_8001FF64;
            D_800B3960->unkA8 = 0;
            pts = D_8014A9A8[1];
            if (pts == NULL) {
                func_800899DC(D_800094D0);
            }
            pts += 3;
            D_800B3960->x = pts->x;
            D_800B3960->y = pts->y;
            D_800B3960->z = pts->z;
            func_8002D620(D_800B3960);
            D_800B3960->unk9C = func_80034F50;
            D_800B3960->unkA8 = 0;
            arg0->unk9C = func_8007ACD4;
            arg0->unk64 = 200;
            arg0->unkC0 = 0;
            arg0->unkDC = 0;
            arg0->unkB0 = 0;
            arg0->unkA8 = 0;
            arg0->unk104 = 0;
        }
    }
    if (D_800BD06C->unkD0 == 0x17) {
        arg0->unk80 += D_800B9EA0;
    } else {
        arg0->unk80 = 0;
    }
    if (arg0->unk80 > 200) {
        n = 5;
        for (i = 0; i < n; i++) {
            q = func_8007B880(0);
            a = func_8002D1A0();
            q->x = D_800BD06C->x + ((coss(a) * 75) >> 13);
            q->y = D_800BD06C->y + 200.0f;
            q->z = D_800BD06C->z + ((sins(a) * 75) >> 13);
            q->unk34 = 0x60;
            q->unk38 = 0x60;
            q->unk3C = 0x60;
            q->unk9C = func_8007AEBC;
            q->unk5C = 0;
            func_80043328(q, 0x5F, func_80024394(0x100, 0x190));
            q->unk64 = 1000;
        }
        arg0->unk80 = -10000;
    }
}
