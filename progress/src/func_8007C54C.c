s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void *func_800232B4(s32, s32, s32, s32);
void func_8002A360(s32, s32);
s32 func_8002D260(s32);
void func_8002FEDC(void *);
void func_8007C4CC(void *);
void func_8007C544(void *);

typedef struct Obj {
    char pad0[0x10];
    s32 x10;
    s32 x14;
    s32 x18;
    char pad1C[0x28 - 0x1C];
    f32 x28;
    f32 x2C;
    f32 x30;
    char pad34[0x58 - 0x34];
    s32 x58;
    s32 x5C;
    s32 x60;
    s32 x64;
    s32 x68;
    char pad6C[0x70 - 0x6C];
    s32 x70;
    s32 x74;
    s32 x78;
    s32 x7C;
    s32 x80;
    char pad84[0x98 - 0x84];
    void *x98;
    void *x9C;
    char padA0[0xC0 - 0xA0];
    s32 xC0;
} Obj;

extern f32 D_8000959C;
extern f32 D_800095A0;
extern f32 D_800095A4;
extern f32 D_800095A8;
extern f32 D_800095AC;
extern f32 D_800095B0;
extern u8 D_800B3960[];
extern u8 gCameraTarget[];
#define B60 (*(Obj **)D_800B3960)
#define BD (*(Obj **)gCameraTarget)
extern s32 D_801700F8[];

Obj *func_8007C54C(void) {
    Obj *o;

    o = func_800232B4(0x1008, 0, 0, 0);
    o->x98 = func_8002FEDC;
    o->x28 = D_8000959C;
    o->x2C = D_800095A0;
    o->x30 = D_800095A4;
    o->x60 = D_801700F8[0];
    o->x58 = packDrawFlags(0, 0, 2, 2, 0, 0, 1, 1);
    o->x68 = 14;
    o->x5C = 0xFF;
    o->x64 = 25;
    o->xC0 = 0;
    o->x70 = 0x40;
    o->x74 = 0;
    o->x78 = 0xFFFFFF;
    o->x7C = 1;
    o->x80 = 0;
    o->x10 = func_8002D260(BD->x10);
    o->x14 = B60->x14;
    o->x18 = 0x8000;
    o->x9C = func_8007C544;
    o = func_800232B4(0x1008, 0, 0, 0);
    o->x98 = func_8002FEDC;
    o->x28 = D_800095A8;
    o->x2C = D_800095AC;
    o->x30 = D_800095B0;
    o->x60 = D_801700F8[1];
    o->x58 = packDrawFlags(0, 0, 2, 2, 0, 0, 1, 1);
    o->x68 = 14;
    o->x5C = 0xFF;
    o->x64 = 25;
    o->xC0 = 0;
    o->x70 = 0x40;
    o->x74 = 0;
    o->x78 = 0xFFFFFF;
    o->x7C = 1;
    o->x80 = 0;
    o->x10 = BD->x10;
    o->x14 = B60->x14;
    o->x18 = 0;
    o->x9C = func_8007C4CC;
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0x42);
    return o;
}
