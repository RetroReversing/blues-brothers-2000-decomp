typedef struct ObjY {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    u8 pad14[0x44 - 0x14];
    f32 f44;
    u8 pad48[0x50 - 0x48];
    f32 f50;
    u8 pad54[0x64 - 0x54];
    s32 f64;
    u8 pad68[0x7C - 0x68];
    s32 f7C;
    u8 pad80[0x88 - 0x80];
    s32 f88;
    u8 pad8C[0x90 - 0x8C];
    s32 f90;
    u8 pad94[0xB0 - 0x94];
    f32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s32 fB8;
    u8 padBC[0xC0 - 0xBC];
    s32 fC0;
} ObjY;

typedef struct { s32 x; s32 pad; s32 z; } Bound;

ObjY *func_80012718(ObjY *);
void func_80013384(ObjY *);
s32 func_8001B990(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_8002D4E0(ObjY *, s32);
s32 func_8002D5CC(ObjY *);
void func_8002D620(ObjY *);
void func_8002DA80(ObjY *);
f32 func_8002DD60(f32);
extern f32 D_800B9EC4;
extern ObjY *D_800BD06C;
extern Bound D_800F4A00[];
extern Bound D_800F6188[];

void func_8001CC2C(ObjY *arg0) {
    s32 flags;
    f32 dx;
    f32 dz;
    f32 dy;
    ObjY *p;
    Bound *lo;
    Bound *hi;
    s32 off;

    flags = func_8001B990(0x100, 0x15) & func_8001B990(0x100, 0x16);
    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        arg0->fC0 = 3;
        arg0->f0 = 0x10E;
        arg0->fB0 = arg0->f50 = 0.0f;
        func_8002D620(arg0);
        arg0->f64 = 0x64;
    }
    if (arg0->f90 != 0 && arg0->y == arg0->f44 && flags != 0) {
        if (arg0->f88 == 0) {
            arg0->f88 = 1;
            func_8002A360(0x1A, 0);
        }
        if (func_8002D5CC(arg0) != 0) {
            arg0->f50 = 3100.0f;
            p = func_80012718(arg0);
            p->x = arg0->x + 300.0f;
            p->y = arg0->y;
            p->z = arg0->z;
            p->f10 = 0x4000;
            func_8002D4E0(p, 0x3E8);
            p = func_80012718(arg0);
            p->x = arg0->x - 300.0f;
            p->y = arg0->y;
            p->z = arg0->z;
            p->f10 = -0x4000;
            func_8002D4E0(p, 0x3E8);
            p = func_80012718(arg0);
            p->x = arg0->z + 300.0f;
            p->y = arg0->y;
            p->z = arg0->x;
            p->f10 = 0;
            func_8002D4E0(p, 0x3E8);
            p = func_80012718(arg0);
            p->x = arg0->z - 300.0f;
            p->y = arg0->y;
            p->z = arg0->x;
            p->f10 = 0x8000;
            func_8002D4E0(p, 0x3E8);
            arg0->f64 = 0x64;
            arg0->f88 = 0;
            func_8002D124();
        }
    } else {
        arg0->f64 = 0x64;
        arg0->fB0 = -1600.0f;
        arg0->f50 += D_800B9EC4 * -1600.0f;
        if (arg0->f88 != 0) {
            func_8002A360(0x1B, 0);
            arg0->f88 = 0;
        }
    }
    dx = D_800BD06C->x - arg0->x;
    dz = D_800BD06C->z - arg0->z;
    dy = D_800BD06C->y - arg0->y;
    if (!(8000.0f < func_8002DD60(dx)) && !(8000.0f < func_8002DD60(dz))) {
        {
        char *base = (char *)D_800F4A00;
        off = arg0->fB8 * sizeof(Bound);
        lo = (Bound *)(base + off);
        }
        if (!(lo->x < dx)) {
            hi = (Bound *)((char *)D_800F6188 + off);
            if (!(dx < hi->x) && !(lo->z < dz) && !(dz < hi->z) && dy < -600.0f) {
                arg0->f50 = 0.0f;
            }
        }
    }
    func_8002DA80(arg0);
    if (arg0->y <= arg0->f44) {
        arg0->y = arg0->f44;
        arg0->f50 = 0.0f;
        arg0->fB0 = 0.0f;
    }
    func_80013384(arg0);
}

