typedef struct { u8 pad0[0x70]; f32 x, y, z; } Bone;
typedef struct Obj Obj;
struct Obj {
    u8 pad0[4];
    f32 x, y, z;
    u16 unk10;
    u16 unk12;
    u8 pad14[0x64 - 0x14];
    s32 unk64;
    u8 pad68[0x74 - 0x68];
    s32 unk74;
    u8 pad78[0x7C - 0x78];
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[0x8C - 0x88];
    u8 *unk8C;
    s32 unk90;
    u8 pad94[0x9C - 0x94];
    void *unk9C;
    u8 padA0[0xA8 - 0xA0];
    Obj *unkA8;
    u8 padAC[0xBC - 0xAC];
    s32 unkBC;
    s32 unkC0;
    u8 padC4[0xD0 - 0xC4];
    s32 unkD0;
    u8 padD4[0xD8 - 0xD4];
    void *unkD8;
    f32 unkDC;
};

s16 coss(u16);
s16 sins(u16);
s32 randomRange(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
f32 approachF32(f32, f32, f32);
s32 tickActorTimer(Obj *);
f32 func_8002DD60(f32);
void func_80043328(Obj *, s32, s32);
s32 func_80052B24(s32, void *, Obj *);
void func_80066368(Obj *);
extern u8 D_80008CCC[];
extern Obj *D_800B3960;
extern Obj *D_800B3964;
extern s32 D_800B5DD4;
extern Obj *gCameraTarget;
void func_80034F50(void);
void func_80066EA4(void);
void func_80066FDC(void);
void func_80067150(void);

s32 func_80066764(Obj *arg0) {
    s32 t[3];
    s32 r[3];
    f32 speed;
    f32 *v;

    if (arg0->unk7C == 0) {
        arg0->unk64 = 500;
        func_80043328(arg0, 0xF5, 0x100);
        arg0->unk74 = 0;
        arg0->unk7C = 1;
        arg0->unk84 = 0;
    }
    speed = arg0->unk80;
    arg0->x = approachF32(gCameraTarget->x, arg0->x, speed);
    arg0->z = approachF32(gCameraTarget->z, arg0->z, speed);
    if ((arg0->unkC0 & ~1) && D_800B3964->unk74 == 0) {
        D_800B3964->unk74 = 1;
        arg0->unk7C = 0;
        arg0->unkD8 = func_80066FDC;
        func_80052B24(arg0->unkBC, D_80008CCC, arg0);
        return;
    }
    if (arg0->unk64 < 400 && arg0->unk90 < 200) {
        func_80043328(arg0, 0xFA, 0x100);
        arg0->unk84 = 1;
    }
    if (arg0->unk64 < 200 && arg0->unk84 == 0) {
        func_80043328(arg0, 0xFA, 0x100);
        arg0->unk84 = 1;
    }
    if (arg0->unkC0 & 1) {
        func_80043328(arg0, 0xFA, 0x100);
        arg0->unk84 = 1;
    }
    if (arg0->unkD0 == 0xFA && 17.0f < arg0->unkDC && arg0->unkDC < 24.0f) {
        v = (f32 *)(arg0->unk8C + 0x40);
        t[0] = v[12] - 95.0f;
        t[1] = v[13];
        t[2] = v[14];
        r[0] = ((t[0] * coss(arg0->unk12)) >> 15) + ((t[2] * sins(arg0->unk12)) >> 15);
        r[2] = -((t[0] * sins(arg0->unk12)) >> 15) + ((t[2] * coss(arg0->unk12)) >> 15);
        r[1] = t[1];
        r[0] = r[0] + arg0->x;
        r[1] = r[1] + arg0->y;
        r[2] = r[2] + arg0->z;
        if (func_8002DD60(r[0] - gCameraTarget->x) < 250.0f && func_8002DD60(r[2] - gCameraTarget->z) < 250.0f) {
            arg0->unkD8 = func_80066EA4;
            arg0->unk74 = 1;
            arg0->unk84 = 2;
            arg0->unk7C = 0;
            D_800B5DD4 = 0;
            func_8002A360(0xC, 0x80);
            func_8002A360(8, randomRange(0, 1) + 0xD0);
            func_8002D124();
            D_800B3960->unk9C = func_80034F50;
            D_800B3960->unkA8 = arg0;
            func_80066368(arg0);
            return;
        }
    }
    if (tickActorTimer(arg0) != 0) {
        arg0->unk7C = 0;
        arg0->unkD8 = func_80067150;
    }
}
