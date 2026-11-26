typedef struct Obj73644 {
    s32 kind;
    f32 x, y, z;
    s32 unk10;
    u8 pad14[0x60 - 0x14];
    s32 unk60;
    u8 pad64[0x68 - 0x64];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0x90 - 0x80];
    s32 unk90;
    u8 pad94[0x98 - 0x94];
    void *unk98;
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
} Obj73644;

s16 sins(u16);
s16 coss(u16);
Obj73644 *func_800232B4(s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_800242A8(s32, s32, s32, ...);
void syncActorPrevPos(Obj73644 *);
f32 func_800385AC(Obj73644 *);
void func_8003CAD4(Obj73644 *, s32);
void func_80052A30(void);
Obj73644 *func_8006B43C(s32);
Obj73644 *func_80077C48(s32);
void func_800340B4(void);
void func_800393F4(void);
void func_80073394(void);
void func_80073478(void);
void func_800739D4(void);
void func_80073B7C(void);
void func_800740A8(void);
void func_800743F8(void);
extern f64 D_80009138;
extern f64 D_80009140;
extern f32 D_80009148;
extern Obj73644 *gCameraRig;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B5DD4;
extern s32 D_800B83B0;
extern Obj73644 *gCameraTarget;
extern s32 D_800BD280;
extern s32 D_800BD68C;

/* Camera rig state machine: on the first call it spawns the camera target, the ring of eight markers around the start point and five trailing objects, then moves to state 3; state 3 hands the rig and target over to their follow update functions. */
void cameraRigUpdate(Obj73644 *rig) {
    s32 i;
    s32 angle;
    Obj73644 *obj;
    Obj73644 *marker;
    s32 spawnId;

    if (rig->unk7C == 0) {
        spawnId = D_800B83B0;
        rig->unk7C = 1;
        D_800B3978 = 0;
        D_800B3974 = 0;
        rig->unk90 = 0;
        D_800B3970 = 0;
        gCameraRig->unkC0 = 0;
        rig->unk6C = spawnId + 470;
        spawnId++;
        D_800B83B0 = spawnId;
        func_800242A8(rig->unk6C, 0xDAA, 0);
        rig->unk60 = func_80023D58(0x210);
        rig->unk98 = func_800739D4;
        rig->unk68 = 14;
        func_800232B4(1, 0, 0, 0)->unk9C = func_80073394;
        obj = func_8006B43C(0);
        obj->x = 20.0f;
        obj->y = 1281.0f;
        obj->z = -5818.0f;
        obj = func_80077C48(0);
        obj->x = 20.0f;
        obj->y = 181.0f;
        obj->z = -5818.0f;
        syncActorPrevPos(obj);
        rig->x = obj->x;
        rig->y = obj->y + 500.0f;
        rig->z = obj->z - 2000.0f;
        for (i = 0; i < 8; i++) {
            marker = func_800232B4(1, obj->x, obj->y, obj->z);
            angle = (s32)((f32)i * 45.0f * D_80009138 / D_80009140) & 0xFFFF;
            marker->x += (sins(angle) * 75) >> 12;
            marker->z += (coss(angle) * 75) >> 12;
            marker->unk9C = func_800740A8;
            marker->y = 365.0f;
        }
        for (i = 1; i < 6; i++) {
            obj = func_800232B4(1, 0, 0, 0);
            obj->unk70 = i;
            obj->unk9C = func_800743F8;
        }
        func_80052A30();
        gCameraTarget->y = func_800385AC(gCameraTarget);
        syncActorPrevPos(gCameraTarget);
        func_8003CAD4(gCameraTarget, gCameraTarget->unk10);
        D_800B5DD4 = 0;
        gCameraRig->y = D_800BD68C - 500;
        gCameraRig->z = D_800BD280;
        gCameraRig->unk9C = func_80073478;
        return;
    }
    func_80052A30();
    if (rig->unk7C == 3) {
        rig->unk9C = func_80073B7C;
        gCameraTarget->unk9C = func_800393F4;
        gCameraRig->unk9C = func_800340B4;
        gCameraRig->unkC0 = 0;
        D_800B5DD4 = 1;
        rig->unk7C++;
    }
}
