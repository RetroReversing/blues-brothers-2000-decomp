typedef struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x40 - 0x14];
    f32 unk40;
    f32 unk44;
    f32 unk48;
    u8 pad4C[0x64 - 0x4C];
    s32 unk64;
    u8 pad68[0x74 - 0x68];
    s32 unk74;
    u8 pad78[0x8C - 0x78];
    s32 unk8C;
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    u8 padA0[0xB8 - 0xA0];
    s32 unkB8;
    u8 padBC[0x104 - 0xBC];
    f32 unk104;
} Obj;

s32 func_8002D260(s32);
void func_8002D3E4(Obj *, s32);
s32 func_8002D5E8(Obj *);
void func_8002D858(Obj *, s32 *);
void func_8002DA80(Obj *);
f32 func_8002DD60(f32);
void animStepKeys(Obj *);
void actorSetAnim(Obj *, s32, s32);
s32 func_800772FC(Obj *);
float sqrtf(float);
extern Obj *gCameraTarget;
extern f32 D_801700D0;
void func_8008427C(void);

s32 func_80083B04(Obj *arg0) {
    s32 pos;
    s32 ret;
    s32 a;
    f32 dx, dz;
    f32 dist;
    f32 dy;

    ret = 0;
    if (arg0->unk64 <= 0) {
        return 1;
    }
    func_8002D3E4(arg0, 0x87);
    func_8002DA80(arg0);
    if (func_8002D5E8(arg0) != 0) {
        ret = func_800772FC(arg0);
        if (ret != 0) {
            ret = 3;
            arg0->unk8C = 0;
            arg0->unk10 += 0x8000;
        }
        arg0->unk90 = 150;
    }
    animStepKeys(arg0);
    if (arg0->unk8C != 0) {
        return ret;
    }
    dx = gCameraTarget->x - arg0->unk40;
    dz = gCameraTarget->z - arg0->unk48;
    dist = sqrtf(dx * dx + dz * dz);
    dy = gCameraTarget->y - arg0->y;
    if (dist < arg0->unk104 && func_8002DD60(dy) < 300.0f) {
        if (arg0->unkB8 != 12) {
            return 2;
        }
        func_8002D858(arg0, &pos);
        a = func_8002D260(pos - arg0->unk10);
        if (a >= -0x36B0 && a <= 0x36B0) {
            return 2;
        }
        actorSetAnim(arg0, arg0->unk74 + 3, 0x100);
        arg0->unk9C = func_8008427C;
        return 4;
    }
    if (D_801700D0 < 250.0f) {
        return 5;
    }
    return ret;
}
