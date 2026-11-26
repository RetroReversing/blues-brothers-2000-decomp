typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x54];
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[8];
    /* 0x74 */ s32 f74;
    /* 0x78 */ u8 pad78[4];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[8];
    /* 0x88 */ s32 f88;
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[8];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[4];
    /* 0xA4 */ Obj *fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x14];
    /* 0xC0 */ s32 fC0;
};
Obj *func_800232B4(s32, s32, s32, s32);
Obj *func_80023874(s32, s32);
f32 func_8002D340(f32, f32, f32);
f32 func_8002DD60(f32);
s32 func_8003C9AC(Obj *, s32, s32, s32);
void func_80065260();
void func_8006542C();
void func_800656B4();
void func_80065770();
extern f32 D_80008C10;
extern f32 D_80008C14;
extern f32 D_80008C18;
extern f32 D_80008C1C;
extern f32 D_80008C20;
extern f32 D_80008C24;
extern f32 D_80008C28;
extern f32 D_80008C2C;
extern char D_800B3964[];
extern s32 D_800B5DD4[];
extern char D_800BD06C[];
extern s32 D_80140214[];

void func_80064F08(Obj *arg0) {
    f32 ax;
    f32 az;
    f32 d1;
    f32 d2;
    f32 lim;
    f32 t;
    f32 k;
    Obj *p;
    Obj *o;

    if ((*(Obj **)D_800B3964)->fC0 == 2) {
        return;
    }
    ax = func_8002DD60(arg0->x - (*(Obj **)D_800BD06C)->x);
    az = func_8002DD60(arg0->z - (*(Obj **)D_800BD06C)->z);
    d1 = func_8002DD60((f32)arg0->f8C - (*(Obj **)D_800BD06C)->y);
    d2 = func_8002DD60((f32)arg0->f90 - (*(Obj **)D_800BD06C)->y);
    lim = D_80008C10;
    if (arg0->fC0 == 2) {
        if (!((*(Obj **)D_800BD06C)->z >= D_80008C14)) {
            return;
        }
        if ((*(Obj **)D_800BD06C)->f10 < -0x6D60 || (*(Obj **)D_800BD06C)->f10 > 0x6D60) {
            return;
        }
        arg0->fC0 = 0;
    }
    if (lim < ax) {
        return;
    }
    if (lim < d1 && lim < d2) {
        return;
    }
    if (d2 < d1) {
        d1 = arg0->f90;
    } else {
        d1 = arg0->f8C;
    }
    if (d1 != arg0->y) {
        arg0->y = func_8002D340(d1, arg0->y, 100.0f);
    } else if ((*(Obj **)D_800BD06C)->z >= D_80008C18 && ax < D_80008C1C && func_8003C9AC(arg0, 1, 1, 1) != 0) {
        p = *(Obj **)D_800BD06C;
        if (p->f10 < -0x6D60 || p->f10 > 0x6D60) {
            p->f9C = func_8006542C;
            p->fA4 = arg0;
            D_80140214[0] = 0;
            p->z = D_80008C20;
            arg0->fA8 = p;
            arg0->f74 = 0;
        }
    }
    if (arg0->y < arg0->f8C) {
        arg0->y = arg0->f8C;
    }
    if (arg0->f90 < arg0->y) {
        arg0->y = arg0->f90;
    }
    if (ax < D_80008C24 && az < D_80008C24) {
        D_800B5DD4[0] = 0;
        arg0->f9C = func_80065260;
        arg0->f7C = 0;
        arg0->f88 = 0;
        k = D_80008C2C;
        o = func_800232B4(0x101, arg0->x, arg0->y + D_80008C28, arg0->z - k);
        o->f9C = func_800656B4;
        o->fA4 = arg0;
        o = func_800232B4(0x101, arg0->x, arg0->y + k, arg0->z - k);
        o->f9C = func_80065770;
        o->fA4 = arg0;
        o = func_80023874(6, 0);
        if (o != 0) {
            o->f68 = -1;
        }
    }
}
