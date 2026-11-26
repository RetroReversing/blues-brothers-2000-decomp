typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x44];
    s32 f58;
    u8 pad5C[0xC];
    s32 f68;
    u8 pad6C[0x24];
    s32 f90;
    u8 pad94[8];
    void *f9C;
} Obj;
Obj *func_800171C0(Obj *);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002A360(s32, s32);
void func_8002D15C(s32);
Obj *func_80042F00(s32, s32, s32, s32);
void func_800433A8(Obj *, s32, s32);
extern s32 D_800B4CE0;
extern s32 D_800B7B0C;
extern s32 *D_800BD06C;
extern char func_80023078[];
void func_800393F4(void);
void func_8003BAF0(void);

Obj *func_8003B828(Obj *o, s32 arg1) {
    Obj *n;

    if (*D_800BD06C == 3) {
        if (o->f9C != func_800393F4) {
            return o;
        }
        n = func_80042F00(3, o->x, o->y, o->z);
        func_800433A8(n, 0x1D, 0x100);
        n->f58 = func_800221C0(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
        n->f9C = func_8003BAF0;
        D_800B4CE0 = 1;
        n->f90 = arg1;
        n->f10 = o->f10;
        o->f9C = func_80023078 + 8;
        o->f68 = -1;
        o->f0 = 0x101;
        n = func_800171C0(o);
        n->y += 300.0f;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x58);
        func_8002D15C(0x32);
        return n;
    }
}
