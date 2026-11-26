typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x3C];
    /* 0x50 */ s32 f50;
    /* 0x54 */ u8 pad54[0x14];
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x10];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[8];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[8];
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0x10];
    /* 0xBC */ s32 fBC;
};
void func_8001B990(s32, s32);
Obj *findActor(s32, s32);
s32 func_80023DBC(s32);
s32 func_8002D260(s32);
void animStepKeys(Obj *);
void func_80052A5C(s32);
s32 startStoryDialog(s32, char *, Obj *);
void debugPrintf(char *);
f32 sqrtf(f32);
void func_8006B1D8();
extern char D_80008EE8[];
extern char D_80008EEC[];
extern char gCameraRig[];
extern char D_800B3964[];
extern char gCameraTarget[];
extern f32 D_80008F00;
#define P3960 (*(Obj **)gCameraRig)
#define P3964 (*(Obj **)D_800B3964)
#define PBD06C (*(Obj **)gCameraTarget)

void func_8006B244(Obj *arg0) {
    Obj *o;
    Obj *c;
    Obj *t;
    f32 dx;
    f32 dy;
    f32 dz;

    if (arg0->f7C == 0) {
        arg0->f10 = func_8002D260(P3960->f10 + 0x8000);
        c = arg0->fA8;
        if (c != 0) {
            c->x = arg0->x;
            c->y = arg0->y;
            c->z = arg0->z;
            c->f10 = arg0->f10;
        }
        arg0->f7C = 1;
        return;
    }
    animStepKeys(arg0);
    if (arg0->fA8 != 0) {
        animStepKeys(arg0->fA8);
    }
    o = findActor(0x1023, 0);
    if (o == 0) {
        func_80052A5C(0x565);
        o = PBD06C;
        o->f90 = 1;
        o->f0 = 3;
        o->f50 = 0;
        if (startStoryDialog(func_80023DBC(0xEB1), D_80008EE8, arg0) != 0) {
            arg0->f7C = 0;
            func_8001B990(0x200, 0x25);
            arg0->f9C = func_8006B1D8;
            P3964->f68 = -1;
            return;
        }
        arg0->f7C++;
    } else if (o->fBC >= 8) {
        t = findActor(0x121, 0);
        if (t != 0) {
            dx = t->x - arg0->x;
            dy = t->y - arg0->y;
            dz = t->z - arg0->z;
            if (sqrtf(dx * dx + dy * dy + dz * dz) < D_80008F00 && arg0->f7C != 2) {
                P3964->f7C = 0x10;
                arg0->f7C = 2;
            }
        }
    }
    if (arg0->f7C == 0x3C) {
        debugPrintf(D_80008EEC);
    }
}

