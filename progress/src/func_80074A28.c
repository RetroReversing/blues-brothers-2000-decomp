typedef struct Obj {
    s32 f0;
    f32 x, y, z;
    u8 pad10[0x24];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad40[0x18];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0xC];
    s32 f70;
    u8 pad74[8];
    s32 f7C;
    u8 pad80[0x10];
    s32 f90;
    u8 pad94[4];
    void (*f98)(void);
    void (*f9C)(struct Obj *);
    u8 padA0[0x30];
    s32 fD0;
    u8 padD4[0x1C];
    s32 fF0;
} Obj;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_8002ADC8(s32);
void func_8004FC60(Obj *, s32);
void func_800741F8(void);
void func_8007491C(Obj *);
f32 sqrtf(f32);
extern s32 D_800B83AC;
extern Obj *gCameraTarget;

void func_80074A28(Obj *o) {
    f32 dx;
    f32 dz;
    f32 d;

    if (o->f7C == 0) {
        o->f7C = 1;
        o->f58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
        o->f5C = 0xE0;
        o->f98 = func_800741F8;
        o->f60 = func_80023D58(0x1FB);
        o->f0 = 0x123;
        o->f34 = 0x180;
        o->f3C = 0x180;
        func_8004FC60(o, o->f70);
    }
    dx = o->x - gCameraTarget->x;
    dx *= dx;
    dz = o->z - gCameraTarget->z;
    dz *= dz;
    d = sqrtf(dx + dz);
    if (D_800B83AC == 0) {
        if (d < 500.0f && gCameraTarget->f90 != 0 && gCameraTarget->fF0 == 0 && o->fD0 != 0x16) {
            o->f9C = func_8007491C;
            func_8002ADC8(1);
            o->f9C(o);
            D_800B83AC = 1;
            return;
        }
        func_8004FC60(o, o->f70);
        o->y = 15.0f;
    }
}
