s32 func_8000C4A0(void);
s32 func_8000C594(void);
void func_8000C874(void);
void func_8000CDF0(void);
void func_8000CF30(void);
void func_8000D394(void);
void func_80023C10(s32);
s32 func_80023D58(s32);
void func_8002A360(s32, s32);
s32 func_8002D5CC(void *);
void func_8002E7B8(s32, s32);
void func_80030C40(void *, s32);
void func_80030C6C(void *, void *);
void func_80088ED0(void);
void func_80088F40(void);
void func_8001DCAC(void *);
void func_80023078(void *);
void func_8003130C(void *);
void func_80032BF0(void *);

typedef struct Obj {
    char pad0[0x60];
    s32 x60;
    s32 x64;
    char pad68[0x7C - 0x68];
    s32 x7C;
    s32 x80;
    s32 x84;
    s32 x88;
    s32 x8C;
    s32 x90;
    char pad94[0x98 - 0x94];
    void *x98;
    char pad9C[0xC0 - 0x9C];
    s32 xC0;
} Obj;

extern s32 D_800AB408;
extern s32 D_800B3968;
extern s32 D_800B4A00[];
extern s32 D_800B5DD4;

void func_80030FDC(Obj *arg0) {
    s32 n;

    if (arg0->x7C != 0) {
        func_8000CF30();
        arg0->x98 = (u8 *)func_80023078 + 8;
        arg0->x7C = 0;
        arg0->x90 = 0;
        arg0->x64 = 3000;
        arg0->x8C = 0;
        arg0->xC0 = 0;
        arg0->x60 = 0;
        func_8002E7B8(0, 0);
        D_800B5DD4 = 1;
    }
    if (arg0->xC0 == 0) {
        if (arg0->x90 == 2) {
            D_800AB408 = 0;
            D_800B5DD4 = 0;
            arg0->x90 = 0;
            func_8002A360(4, 0);
            func_8002A360(0x1F, 0);
            func_8002A360(2, 0);
            func_8000CDF0();
            func_8000D394();
            func_80030C6C(arg0, func_8003130C);
            func_80088ED0();
            return;
        }
        if (arg0->x90 == 1) {
            func_8002A360(4, 0);
            func_8002A360(0x1F, 0);
            func_8002A360(2, 0);
            D_800B5DD4 = 0;
            arg0->x90 = 0;
            arg0->x64 = 0;
            arg0->xC0 = 1;
        }
        if (arg0->x88 != 0 && func_8002D5CC(arg0) != 0) {
            arg0->xC0 = 1;
        }
    }
    switch (arg0->xC0) {
    case 1:
        if (func_8002D5CC(arg0) != 0) {
            if (arg0->x88 != 0) {
                n = func_8000C4A0();
            } else {
                n = func_8000C594();
            }
            if (n >= 4) {
                func_8000CDF0();
                func_8000D394();
                func_80030C40(arg0, 1);
                return;
            }
            arg0->x84 = n * 3;
            arg0->x80 = 0;
            func_8002A360(4, 0);
            func_8002A360(0x1F, 0);
            func_8002A360(2, 0);
            func_8000CDF0();
            func_80088F40();
            arg0->x64 = 300;
            if (D_800B3968 == 0) {
                arg0->x60 = func_80023D58(D_800B4A00[arg0->x84 + arg0->x80]);
                arg0->x98 = func_80032BF0;
                arg0->xC0++;
            } else {
                arg0->x80 = 6;
                arg0->x98 = func_8001DCAC;
                arg0->xC0++;
            }
        }
        break;
    case 2:
        if (func_8002D5CC(arg0) != 0) {
            if (++arg0->x80 >= 3) {
                func_80023C10(arg0->x60);
                func_8000C874();
                func_80088F40();
                arg0->x64 = 500;
                arg0->xC0 = 0;
                arg0->x98 = (u8 *)func_80023078 + 8;
                return;
            }
            func_80023C10(arg0->x60);
            arg0->x60 = func_80023D58(D_800B4A00[arg0->x84 + arg0->x80]);
            arg0->x64 = 300;
        }
        break;
    }
}
