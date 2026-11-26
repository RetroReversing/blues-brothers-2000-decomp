typedef struct { f32 x, y, z; } Vec3f;
typedef struct Actor {
    u8 pad00[4];
    Vec3f pos;          /* 0x04 */
    u8 pad10[0x8C];
    void (*update)(void); /* 0x9C */
    u8 padA0[8];
    s32 xA8;            /* 0xA8 */
} Actor;

typedef struct { s32 a[3]; } Triple;
typedef struct Spawn { u8 pad[4]; Vec3f pos; } Spawn;

Spawn *func_80017DEC(s32);
void func_80017ECC(s32, f32, f32, f32, s32, s32, s32);
s32 func_8001B990(s32, u32, ...);
s32 func_80023DBC(s32, Spawn *);
void func_80052B24(s32, void *, void *);
void func_80034F50(void);
extern Triple D_80000A40;
extern s32 D_80000A4C;
extern Actor *gCameraRig;
extern s32 *gCameraTarget;
extern u8 gPlatformMaxOffsets[];

s32 func_80018048(s32 *arg0) {
    Triple col = D_80000A40;
    Spawn *v;
    s32 ret;
    s32 *p = (s32 *)gPlatformMaxOffsets;

    p[0x2E0 / 4] = 100;
    p[0x2EC / 4] = 100;
    p[0x2F8 / 4] = 100;
    func_8001B990(0x300, 0x17);
    func_8001B990(0x300, 0x18);
    func_8001B990(0x300, 0x19);
    v = func_80017DEC(0);
    if (v == NULL) {
        ret = 0;
    } else {
        gCameraTarget[4] = 0x4000;

gCameraRig->pos.x = v->pos.x;
gCameraRig->pos.y = v->pos.y;
gCameraRig->pos.z = v->pos.z;
gCameraRig->update = func_80034F50;
gCameraRig->xA8 = 0;
        func_80052B24(func_80023DBC(0xE27, v), &D_80000A4C, gCameraTarget);
        func_80017ECC(10, 1286.0f, 537.0f, 2028.0f, 0x5840, -0x1C00, 0);
        func_80017ECC(11, 1331.0f, -248.0f, 2715.0f, 0x7200, -0x1840, 0);
        arg0[0x80 / 4] = 0;
        ret = 1;
    }
    return ret;
}
