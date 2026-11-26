typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 pad10[0x54];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[4];
    /* 0x70 */ s32 f70;
    /* 0x74 */ u8 pad74[0x20];
    /* 0x94 */ s32 f94;
    /* 0x98 */ u8 pad98[4];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[8];
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x2C];
    /* 0xD8 */ void *fD8;
    /* 0xDC */ f32 fDC;
};
Obj *findActor(s32, s32);
Obj *func_8002E374(s32);
Obj *func_80030B90(Obj *);
s32 func_80043248(Obj *);
void func_8007FE50(Obj *, Obj *);
void func_800768E8();
void func_8007F898();
void func_800802A4();
extern Obj *D_800B3964;
extern s32 D_80140228;

s32 func_8007EAC4(Obj *arg0) {
    s32 r;
    Obj *c;
    Obj *t;

    if (29.0f < arg0->fDC) {
        D_80140228 = 1;
    }
    func_80043248(arg0->fA8);
    r = func_80043248(arg0);
    if (r != 0) {
        func_80030B90(arg0)->f9C = func_8007F898;
        c = func_80030B90(arg0);
        c->f68 = -1;
        c->f64 = 100;
        c->f9C = func_800768E8;
        c->fD8 = func_8007F898;
        c = func_80030B90(arg0);
        c->f68 = -1;
        c->f64 = 200;
        c->f9C = func_800768E8;
        c->fD8 = func_8007F898;
        t = findActor(0x11F, 0);
        if (t != 0 && t->fA8 == 0) {
            c = func_8002E374(D_800B3964->f94);
            c->x = t->x;
            c->y = t->y;
            c->z = t->z;
            c->f9C = func_800802A4;
            c->f70 = D_800B3964->f70;
            func_8007FE50(c, t);
            D_800B3964->f70++;
        }
        t = findActor(0x120, 0);
        if (t != 0 && t->fA8 == 0) {
            c = func_8002E374(D_800B3964->f94);
            c->x = t->x;
            c->y = t->y;
            c->z = t->z;
            c->f9C = func_800802A4;
            c->f70 = D_800B3964->f70;
            func_8007FE50(c, t);
            D_800B3964->f70++;
        }
    }
    return r;
}

