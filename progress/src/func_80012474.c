typedef struct ObjU {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s16 f10;
    u16 yaw;
    u8 pad14[0x18 - 0x14];
    s32 f18;
    u8 pad1C[0x58 - 0x1C];
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    u8 pad6C[0x70 - 0x6C];
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    u8 pad80[0x98 - 0x80];
    void *f98;
    void *f9C;
} ObjU;

ObjU *spawnEffectObj(s32, s32, s32, s32);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002CE84(s32, s32);
s32 randomRange(s32, s32);
s32 func_8002D1A0(void);
s16 func_80095F60(u16);
s16 func_800944B0(u16);
void func_8002F8D0(void);
void func_80012418(void);
extern s32 D_800BCFB4;
extern ObjU *gCameraTarget;

ObjU *func_80012474(s32 arg0, s32 arg1, s32 arg2) {
    ObjU *o;

    o = spawnEffectObj(0x101, arg0, arg1, arg2);
    o->f98 = func_8002F8D0;
    o->f9C = func_80012418;
    o->f70 = 90;
    o->f78 = 0xFFFFFF;
    o->f64 = 50;
    o->f74 = 0;
    o->f7C = 1;
    o->f60 = D_800BCFB4;
    o->f58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    o->f68 = 13;
    o->f5C = 0xFF;
    func_8002CE84(3, 0);
    func_8002CE84(2, 5);
    func_8002CE84(4, 0);
    o->f64 = 50;
    o->f70 = randomRange(40, 80);
    o->f18 = func_8002D1A0();
    o->x = gCameraTarget->x + (f32)((func_80095F60(gCameraTarget->yaw) * 45) >> 13);
    o->y = gCameraTarget->y + 160.0f;
    o->z = gCameraTarget->z + (f32)((func_800944B0(gCameraTarget->yaw) * 45) >> 13);
    return o;
}
