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
void sendCommand(s32, s32);
void func_8002D124(void);
f32 approachF32(f32, f32, f32);
s32 tickActorTimer(Obj *);
f32 func_8002DD60(f32);
void func_80043328(Obj *, s32, s32);
s32 startStoryDialog(s32, void *, Obj *);
void func_80066368(Obj *);
extern u8 D_80008CCC[];
extern Obj *gCameraRig;
extern Obj *D_800B3964;
extern s32 D_800B5DD4;
extern Obj *gCameraTarget;
void func_80034F50(void);
void func_80066EA4(void);
void func_80066FDC(void);
void func_80067150(void);

/* Warden chase state: follows the camera target and starts the punch once the player is in range. */ s32 wardenChase(Obj *warden) {
    s32 localOffset[3];
    s32 hitPos[3];
    f32 speed;
    f32 *bone;

    if (warden->unk7C == 0) {
        warden->unk64 = 500;
        func_80043328(warden, 0xF5, 0x100);
        warden->unk74 = 0;
        warden->unk7C = 1;
        warden->unk84 = 0;
    }
    speed = warden->unk80;
    warden->x = approachF32(gCameraTarget->x, warden->x, speed);
    warden->z = approachF32(gCameraTarget->z, warden->z, speed);
    if ((warden->unkC0 & ~1) && D_800B3964->unk74 == 0) {
        D_800B3964->unk74 = 1;
        warden->unk7C = 0;
        warden->unkD8 = func_80066FDC;
        startStoryDialog(warden->unkBC, D_80008CCC, warden);
        return;
    }
    if (warden->unk64 < 400 && warden->unk90 < 200) {
        func_80043328(warden, 0xFA, 0x100);
        warden->unk84 = 1;
    }
    if (warden->unk64 < 200 && warden->unk84 == 0) {
        func_80043328(warden, 0xFA, 0x100);
        warden->unk84 = 1;
    }
    if (warden->unkC0 & 1) {
        func_80043328(warden, 0xFA, 0x100);
        warden->unk84 = 1;
    }
    if (warden->unkD0 == 0xFA && 17.0f < warden->unkDC && warden->unkDC < 24.0f) {
        bone = (f32 *)(warden->unk8C + 0x40);
        localOffset[0] = bone[12] - 95.0f;
        localOffset[1] = bone[13];
        localOffset[2] = bone[14];
        hitPos[0] = ((localOffset[0] * coss(warden->unk12)) >> 15) + ((localOffset[2] * sins(warden->unk12)) >> 15);
        hitPos[2] = -((localOffset[0] * sins(warden->unk12)) >> 15) + ((localOffset[2] * coss(warden->unk12)) >> 15);
        hitPos[1] = localOffset[1];
        hitPos[0] = hitPos[0] + warden->x;
        hitPos[1] = hitPos[1] + warden->y;
        hitPos[2] = hitPos[2] + warden->z;
        if (func_8002DD60(hitPos[0] - gCameraTarget->x) < 250.0f && func_8002DD60(hitPos[2] - gCameraTarget->z) < 250.0f) {
            warden->unkD8 = func_80066EA4;
            warden->unk74 = 1;
            warden->unk84 = 2;
            warden->unk7C = 0;
            D_800B5DD4 = 0;
            sendCommand(0xC, 0x80);
            sendCommand(8, randomRange(0, 1) + 0xD0);
            func_8002D124();
            gCameraRig->unk9C = func_80034F50;
            gCameraRig->unkA8 = warden;
            func_80066368(warden);
            return;
        }
    }
    if (tickActorTimer(warden) != 0) {
        warden->unk7C = 0;
        warden->unkD8 = func_80067150;
    }
}
