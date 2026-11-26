#define FLD(e, T, off) (*(T *)((u8 *)(e) + (off)))
void *findActor(s32, s32);
s32 func_80082400(void);
void func_80027030(s32, s32);
void func_8000C5E4(void);
u8 *getImageAsset(s32);
void debugPrintf(char *, ...);
void func_800242A8(s32, s32, s32);
void *spawnEffectObj(s32, s32, s32, s32);
void func_80053EF0(u8 *);
s32 func_80026B50(char *, char *);
void func_80043328(u8 *, s32, s32);
void func_80053C94(void);
void func_80053CE0(void);
void func_80052EC0(void);
void animStepKeys(void);
extern char D_800080F0[];
extern char D_8000811C[];
extern u8 *gCameraTarget;
extern u8 *gCameraRig;
extern s32 D_800AE010;
extern s32 D_8014AA90;
extern f32 *D_8014AA94;
extern s32 D_8014AA98;
extern s32 D_8014AA9C;
extern s32 D_8014AAA0;
extern s32 D_800B5DD4;
extern s32 gPadPressed;
extern s32 D_80107040;
extern s32 D_80140228;

/* Starts a story/dialog scene: finds the record named storyName in the loaded story data, spawns its dialog actor at startPos, and takes over the camera. Returns 0 if a scene is already running or the story can't start. */ s32 startStoryDialog(s32 assetId, char *storyName, f32 *startPos) {
    s32 found = 0;
    u8 *dialogActor;
    u8 *storyData;
    u8 *storyRecord;
    s32 i;
    s32 *cue;
    u8 *camTarget;
    s32 savedCamFn;
    u8 *camRig;

    if (findActor(0x800, 0) != 0) {
        return 0;
    }
    camTarget = gCameraTarget;
    i = 0;
    if (FLD(camTarget, s32, 0) == 3) {
        if (FLD(camTarget, f32, 0x50) <= 0.0f) {
            i = FLD(camTarget, s32, 0x90) == 1;
        }
    }
    if (!i) {
        if (func_80082400() == -1) {
            return 0;
        }
    }
    D_8014AA90 = D_800AE010;
    D_8014AA9C = 0;
    D_8014AA94 = 0;
    D_800B5DD4 = 0;
    gPadPressed = 0;
    D_80107040 = 0;
    D_800AE010 = 0x12345678;
    func_80027030(2, D_8014AA90);
    D_80140228 = 0;
    do { func_8000C5E4(); camRig = gCameraRig; FLD(camRig, s32, 0xC0) = 2; storyData = getImageAsset(assetId); } while (0);
    if (storyData == NULL) {
        debugPrintf(D_800080F0);
    }
    func_800242A8(0x88, 0x560, 0);
    if (D_8014AAA0 != 0) {
        func_800242A8(0x89, D_8014AAA0, 0);
    }
    if (findActor(0x801, 0) == NULL) {
        FLD(spawnEffectObj(0x801, 0, 0, 0), void *, 0x9C) = func_80053C94;
    }
    if (findActor(0x802, 0) == NULL) {
        FLD(spawnEffectObj(0x802, 0, 0, 0), void *, 0x9C) = func_80053CE0;
    }
    dialogActor = findActor(0x803, 0);
    if (dialogActor == NULL) {
        FLD(spawnEffectObj(0x803, 0, 0, 0), void *, 0x9C) = func_80053CE0;
    } else {
        FLD(dialogActor, s32, 0x7C) = 0;
    }
    func_80053EF0(storyData);
    storyRecord = FLD(storyData, u8 *, 8);
    if (storyName != NULL) {
        {
            for (i = 0; i < FLD(storyData, s16, 4); i++, storyRecord += 12) {
                if (func_80026B50(storyName, FLD(storyRecord, char *, 0)) == 0) {
                    found = 1;
                    dialogActor = spawnEffectObj(0x800, 0, 0, 0);
                    if (startPos != NULL) {
                        FLD(dialogActor, f32, 4) = startPos[1];
                        FLD(dialogActor, f32, 8) = startPos[2];
                        D_8014AA94 = startPos;
                        FLD(dialogActor, f32, 0xC) = startPos[3];
                        FLD(dialogActor, f32 *, 0xA4) = startPos;
                    }
                    camRig = gCameraRig;
                    FLD(camRig, s32, 0xD8) = FLD(camRig, s32, 0x9C);
                    camTarget = gCameraTarget;
                    FLD(dialogActor, u8 *, 0x70) = storyData;
                    FLD(dialogActor, u8 *, 0x74) = storyRecord;
                    FLD(dialogActor, void *, 0x9C) = func_80052EC0;
                    FLD(dialogActor, s32, 0x64) = 0xC8;
                    FLD(dialogActor, s32, 0xD8) = 0;
                    savedCamFn = FLD(camTarget, s32, 0x9C);
                    FLD(camTarget, void *, 0x9C) = animStepKeys;
                    FLD(camTarget, s32, 0x4C) = 0;
                    FLD(camTarget, s32, 0x50) = 0;
                    FLD(camTarget, s32, 0x54) = 0;
                    FLD(camTarget, s32, 0xD8) = savedCamFn;
                    func_80043328(camTarget, 1, 0x100);
                    break;
                }
            }
        }
    }
    if (found == 0) {
        debugPrintf(D_8000811C, storyName);
    }
    cue = FLD(storyRecord, s32 *, 4);
    while (cue[0] != -1) {
        if (cue[0] == 0) {
            D_8014AA98 = 0;
            break;
        }
        if (cue[0] == 1) {
            D_8014AA98 = 1;
            break;
        }
        cue += 2;
    }
    D_800AE010 = D_8014AA90;
    return 1;
}

