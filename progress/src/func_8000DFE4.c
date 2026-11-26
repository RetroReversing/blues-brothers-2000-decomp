typedef struct { s32 x, y, z; } Rec;
typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ u8 pad10[0x54];
    /* 0x64 */ s32 f64;
    /* 0x68 */ u8 pad68[0x28];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[0x24];
    /* 0xB8 */ s32 fB8;
} Obj;
typedef struct { s32 a; f32 x, y, z; u8 pad[0xF8]; } Hit;
void func_8000DF10(Hit *);
s32 func_8002D5CC(Obj *);
extern s32 D_800B3838;
extern Obj *D_800BD06C;
extern Rec D_800F4A00[];
extern Rec D_800F6188[];
extern s32 D_80140224;

void func_8000DFE4(Obj *arg0) {
    Hit h;
    s32 n;
    f32 v;
    f32 top;
    Rec *lo;
    Rec *hi;
    Obj *p;
    Rec *tbl;

    p = D_800BD06C;
    tbl = D_800F4A00;
    arg0->f0 = 0x101;
    lo = &tbl[arg0->fB8];
    n = 0;
    if (p->x <= arg0->x + lo->x) {
        n = 1;
    }
    hi = &D_800F6188[arg0->fB8];
    if (arg0->x + hi->x <= p->x) {
        n++;
    }
    if (p->z <= arg0->z + lo->z) {
        n++;
    }
    if (arg0->z + hi->z <= p->z) {
        n++;
    }
    if (D_80140224 == 0 && arg0->f64 > 0) {
        arg0->f64 = 20;
    }
    if (n == 4) {
        if (D_800BD06C->y <= (top = arg0->y + D_800F4A00[arg0->fB8].y)) {
            h.x = D_800BD06C->x;
            h.z = D_800BD06C->z;
            h.y = arg0->y + D_800F4A00[arg0->fB8].y;
            if (func_8002D5CC(arg0) != 0 || D_800BD06C->f90 == 0) {
                func_8000DF10(&h);
                arg0->f64 = 20;
            }
            D_800B3838 = 1;
        } else if (D_800BD06C->y <= top + 50.0f && D_800BD06C->f90 == 0) {
            D_800B3838 = 1;
        } else {
            D_800B3838 = 0;
        }
    } else {
        arg0->f64 = -1;
    }
}
