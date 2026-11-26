void func_800134F0(void *);
void func_80013550(void *);
s32 func_8001B990(s32, s32);
s32 func_8002492C(f32, f32);
s32 func_8002D260(s32);
void func_8002D620(void *);
f32 func_8002DD60(f32);
s32 func_80080DE0(s32);
s32 func_80081188(s32, f32 *, s32);
void func_80081588(s32, s32);
void func_80081990(f32 *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
void func_800768E8(void *);

typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x40 - 0x14];
    f32 x40;
    f32 x44;
    f32 x48;
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x64 - 0x58];
    s32 x64;
    s32 x68;
    char pad6C[0x70 - 0x6C];
    s32 x70;
    char pad74[0x7C - 0x74];
    s32 x7C;
    s32 x80;
    char pad84[0x9C - 0x84];
    void *x9C;
    char padA0[0xA8 - 0xA0];
    s32 xA8;
    f32 xAC;
    char padB0[0xB4 - 0xB0];
    f32 xB4;
    char padB8[0xBC - 0xB8];
    s32 xBC;
    char padC0[0xD8 - 0xC0];
    void *xD8;
    char padDC[0x104 - 0xDC];
    f32 x104;
} Obj;

extern f32 D_80000BE0;
extern f32 D_80000BE4;
extern u8 D_800BD06C[];
#define BD (*(Obj **)D_800BD06C)
extern s32 D_8014A928[];

void func_8001A7C8(Obj *arg0) {
    f32 v[3];
    s32 id;
    s32 done;
    s32 ang;
    void *old;

    id = arg0->x70;
    done = 0;
    if (arg0->x7C == 0) {
        arg0->x7C = 1;
        arg0->x80 = 1;
        arg0->xBC = 1;
        arg0->xB4 = 0.0f;
        arg0->xAC = D_80000BE0;
        arg0->x104 = arg0->x8;
        if (func_80080DE0(id) == 0) {
            func_80081588(arg0->x70, done);
        }
    }
    if (func_8001B990(0x100, 0x1E) == 0) {
        arg0->x68 = -1;
        arg0->x0 = 0x101;
        return;
    }
    arg0->x68 = 5;
    arg0->x0 = 0x10E;
    func_8002D620(arg0);
    func_80081990(&arg0->x4, id, arg0->xB4);
    func_80081AC0(v, id, arg0->xB4);
    ang = func_8002492C(v[0], v[2]);
    arg0->x10 = ang;
    if (arg0->xBC <= 0) {
        arg0->x10 = func_8002D260(ang + 0x8000);
    }
    if (arg0->xA8 != 0) {
        arg0->xB4 += arg0->xAC;
        arg0->x4C = arg0->x4 - arg0->x40;
        arg0->x54 = arg0->xC - arg0->x48;
        func_800134F0(arg0);
        func_80013550(arg0);
    } else {
        arg0->x4C = arg0->x54 = 0.0f;
        if (func_80081188(id, &BD->x4, 0) > (s32)arg0->xB4) {
            arg0->xB4 = arg0->xB4 + func_8002DD60(arg0->xAC);
        } else {
            arg0->xB4 = arg0->xB4 - func_8002DD60(arg0->xAC);
        }
    }
    if (arg0->xBC == 1) {
        if ((f32)D_8014A928[id] - D_80000BE4 <= arg0->xB4) {
            do { done++; } while (0);
        }
    } else if (arg0->xB4 < 0.0f) {
        done++;
    }
    if (done != 0) {
        old = arg0->x9C;
        arg0->x9C = func_800768E8;
        arg0->x64 = 500;
        arg0->xAC = -arg0->xAC;
        arg0->xBC = -arg0->xBC;
        arg0->xD8 = old;
        func_8001B990(0x200, 0x23);
    }
}
