typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x50];
    /* 0x64 */ s32 f64;
    /* 0x68 */ u8 pad68[0x24];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[0x3C];
    /* 0xD0 */ s32 fD0;
    /* 0xD4 */ u8 padD4[8];
    /* 0xDC */ f32 fDC;
} Obj;
void func_8002A360(s32, s32);
void func_8002ADFC(s32, s32, Obj *);
s32 func_8002D5CC(Obj *);
f32 func_8002DD60(f32);
s32 func_8003C9AC(Obj *, s32, s32, s32);
s32 func_8004303C(Obj *);
void func_80043328(Obj *, s32, s32);
void func_8005F470(Obj *);
s32 func_80076080(void);
extern f32 D_80008840;
extern f32 D_8000885C;
extern f32 D_80008860;
extern f64 D_80008880;
extern f64 D_80008888;
extern f32 D_80008890;
extern f64 D_80008898;
extern f64 D_800088A0;
extern f32 D_800088A8;
extern f32 D_800088AC;
extern f32 D_800088B0;
extern s32 D_800B4CF0[];
extern char D_800BD06C[];
extern s32 D_80140200[];

void func_8005F4E0(Obj *arg0) {
    f32 dx;
    f32 dy;
    f32 lim;
    s32 s;

    if (func_80076080() != 0) {
        return;
    }
    dx = (*(Obj **)D_800BD06C)->x - arg0->x;
    dy = ((*(Obj **)D_800BD06C)->y + D_80008840) - arg0->y;
    s = func_8004303C(arg0);
    switch (arg0->f90) {
    case 0:
        arg0->f10 = 0x8000;
        arg0->f90 = 1;
        arg0->f8C = 0;
        break;
    case 1:
        if (arg0->f8C != 0) {
            break;
        }
        func_80043328(arg0, 0x74, 0x100);
        if (s != 0) {
            func_8002ADFC(0x4A, 0x3E8, arg0);
        }
        if (func_8002D5CC(arg0) == 0) {
            break;
        }
        if (func_8002DD60(dy) < 400.0f && func_8003C9AC(arg0, 1, 0, 0) != 0) {
            if (func_8002DD60(dx) < 400.0f) {
                arg0->f90 = 2;
                arg0->f8C = 0;
            }
            if (func_8002DD60(dx) < D_80008860 && D_80140200[0] > D_800B4CF0[0]) {
                arg0->f90 = 2;
                arg0->f8C = 0;
            }
        }
        break;
    case 2:
        switch (arg0->f8C) {
        case 0:
            if ((*(Obj **)D_800BD06C)->fD0 == 0x16) {
                break;
            }
            if (dx >= 0.0f) {
                func_80043328(arg0, 0x75, 0x100);
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x16);
                arg0->f8C = 1;
            } else {
                func_80043328(arg0, 0x76, 0x100);
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x16);
                arg0->f8C = 2;
            }
            break;
        case 1:
            if (D_80008880 <= arg0->fDC && arg0->fDC <= D_80008888 && func_8002DD60(dx) < D_80008890) {
                arg0->f8C = 3;
                break;
            }
            if (s != 0) {
                func_80043328(arg0, 0x74, 0x100);
                arg0->f90 = 1;
                arg0->f8C = 0;
                arg0->f64 = 0x23;
            }
            break;
        case 2:
            if (D_80008898 <= arg0->fDC && arg0->fDC <= D_800088A0 && func_8002DD60(dx) < D_800088A8) {
                arg0->f8C = 3;
                break;
            }
            if (s != 0) {
                func_80043328(arg0, 0x74, 0x100);
                arg0->f90 = 1;
                arg0->f8C = 0;
                arg0->f64 = 0x23;
            }
            break;
        case 3:
            arg0->f64 = 0x23;
            lim = D_800088AC;
            if (func_8002DD60(arg0->y - (*(Obj **)D_800BD06C)->y + lim) < lim || D_800088B0 < func_8002DD60(dx)) {
                arg0->f90 = 1;
                arg0->f8C = 0;
                break;
            }
            func_8005F470(*(Obj **)D_800BD06C);
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x2D);
            arg0->f8C = 4;
            break;
        case 4:
            if (s != 0) {
                func_80043328(arg0, 0x74, 0x100);
                arg0->f90 = 1;
                arg0->f8C = 0;
            }
            break;
        }
        break;
    case 3:
        break;
    case 4:
        break;
    }
}
