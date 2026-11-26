s16 coss(u16);
s16 sins(u16);
s32 func_8000C43C(void);
s32 func_8001B990(s32, s32);
s32 func_80024394(s32, s32);
s32 func_8002D1A0(void);
void func_8000E7A4(void);

typedef struct ObjL {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    s32 f14;
    u8 pad18[0x34 - 0x18];
    s32 f34;
    s32 f38;
    u8 pad3C[0x58 - 0x3C];
    s32 f58;
    u8 pad5C[0x9C - 0x5C];
    void (*f9C)(void);
    void (*fA0)(struct ObjL *);
    u8 padA4[0xB8 - 0xA4];
    s32 fB8;
} ObjL;

ObjL *func_80023874(s32, ObjL *);
void func_8002D4E0(ObjL *, s32);
void func_8002D620(ObjL *);
ObjL *func_8002E374(s32);

void func_8000E874(ObjL *arg0) {
    ObjL *p;
    s32 i;
    s32 kind;
    s32 a;

    p = NULL;
    if (func_8000C43C() == 0x30 && func_8001B990(0x100, 0x43) != 0) {
        arg0->fA0(arg0);
        return;
    }
    if (func_80023874(0x109, p) == NULL) {
        return;
    }
    kind = arg0->fB8;
    for (i = 0; i < 5; i++) {
        p = func_8002E374(kind);
        a = func_8002D1A0();
        p->f10 = a;
        p->x = arg0->x;
        a &= 0xFFFF;
        p->y = arg0->y;
        p->z = arg0->z;
        p->x += (f32)((sins(a) * 25) >> 12);
        p->z += (f32)((coss(a) * 25) >> 12);
        p->f38 = p->f34 = func_80024394(0x40, 0x80);
        p->f14 = func_80024394(0x2000, 0x3E80);
        func_8002D4E0(p, func_80024394(0x1F4, 0x3E8));
        p->f0 = 0x10D;
        p->f9C = func_8000E7A4;
        p->f58 = arg0->f58;
        func_8002D620(p);
    }
    if (func_8000C43C() == 0x30) {
        func_8001B990(0x200, 0x43);
    }
    arg0->fA0(arg0);
}
