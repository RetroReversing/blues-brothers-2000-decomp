void func_800433A8(void *, s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_8003BC40(void *);
extern s32 D_800BD170[];

typedef struct {
    s32 unk0;
    u8 pad4[4];
    f32 unk8;
    u8 padC[0x54];
    s32 unk60;
    u8 pad64[0x2C];
    s32 unk90;
    u8 pad94[8];
    void (*unk9C)(void *);
} Obj;

extern Obj *D_800BD06C;
Obj *func_80015738(Obj *);

void func_8003CCB4(void) {
    Obj *p;
    Obj *o;
    s32 i;

    p = D_800BD06C;
    if (p->unk90 == 1) {
        func_800433A8(p, 0x1A, 0x100);
        p->unk9C = func_8003BC40;
        p->unk0 = 0x101;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xB);
        func_8002D124();
    }
    for (i = 0; i < 15; i++) {
        o = func_80015738(p);
        o->unk60 = D_800BD170[0];
        o = func_80015738(p);
        o->unk60 = D_800BD170[1];
        o->unk8 += 50.0f;
    }
}
