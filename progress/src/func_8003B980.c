typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    s32 f10;
    u8 pad14[0x44];
    s32 f58;
    u8 pad5C[0xC];
    s32 f68;
    u8 pad6C[4];
    s32 f70;
    u8 pad74[0x1C];
    s32 f90;
    u8 pad94[8];
    void *f9C;
} Obj;
Obj *func_80012718(Obj *);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
Obj *func_80042F00(s32, s32, s32, s32);
void actorSetAnim(Obj *, s32, s32);
extern s32 D_800B4CE0;
extern s32 D_800B7B0C;
extern s32 *gCameraTarget;
extern char func_80023078[];
void func_800393F4(void);
void func_8003BAF0(void);

Obj *func_8003B980(Obj *o) {
    Obj *n;

    if (*gCameraTarget == 3) {
        if (o->f9C != func_800393F4) {
            return o;
        }
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x83);
        func_8002D124();
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 9);
        n = func_80042F00(8, o->x, o->y, o->z);
        actorSetAnim(n, 0x19B, 0x100);
        n->f58 = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
        n->f9C = func_8003BAF0;
        n->f90 = 0;
        n->f10 = o->f10;
        o->f9C = func_80023078 + 8;
        o->f68 = -1;
        o->f0 = 0x101;
        n = func_80012718(o);
        n->f70 = 60;
        n = func_80012718(o);
        n->f70 = 60;
        n = func_80012718(o);
        n->f70 = 60;
        D_800B4CE0 = 1;
        return n;
    }
}
