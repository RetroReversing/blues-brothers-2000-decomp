typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x6C - 0x14];
    s32 x6C;
} Obj;

typedef struct Level {
    char pad0[0x1C];
    u8 *x1C;
} Level;

s32 countLiveObjects(s32);
s32 func_800252D8(void);
s32 func_8002D260(s32);
s32 approachS32(s32, s32, s32);
void setTextColor(s32, s32, s32, s32);
void setTextPos(s32, s32);
void func_80027158(s32, s32);
void func_800271A8(s32, s32);
void drawInt(s32);
void drawFloat(f32);
void func_80028710(u8 *);
void drawText(char *);
int sprintf(char *, const char *, ...);

extern char D_80000AE8[];
extern char D_80000B04[];
extern char D_80000B0C[];
extern char D_80000B14[];
extern char D_80000B18[];
extern char D_80000B1C[];
extern char D_80000B20[];
extern char D_80000B24[];
extern char D_80000B28[];
extern char D_80000B38[];
extern Level D_800AA134[];
extern s32 D_800AB9B4;
extern s32 D_800AB9B8;
extern s32 D_800B83B4;
extern s32 gTextWaveTime;
extern s32 gCamSpeedScale;
extern s32 D_800BD058;
extern Obj *gCameraTarget;
extern s32 D_800BD0FC;
extern s32 D_800BD100;
extern s32 D_800BD114;
extern s32 D_80107040;
extern s32 D_801073B0;
extern s32 gStickY;
extern s32 D_801402F8;
extern Obj *D_8014AAB0;
extern s32 D_8017826C;
extern s32 D_80178270;

/* Debug stats overlay: frame time, memory, object counts, camera position and the
   elapsed time. It fades out while the pad is moving the view and fades back in when idle. */
void drawDebugStats(Obj *overlay) {
    char text[0x40];
    u8 *entry;
    s32 activity;
    s32 a;
    s32 seconds;
    s32 minutes;
    s32 stickX;
    s32 stickY;

    entry = D_800AA134[D_800BD100].x1C;
    if (D_800AB9B4 != 0) {
        return;
    }
    if (D_8014AAB0->x0 == 0x145) {
        return;
    }
    stickX = D_801073B0;
    stickY = gStickY;
    if (stickX < 0) {
        stickX = -stickX;
    }
    activity = stickX < 11;
    stickY = abs(stickY);
    activity ^= 1;
    if (stickY > 10) {
        activity++;
    }
    if (D_80107040 != 0) {
        activity++;
    }
    if (activity == 0) {
        overlay->x6C = approachS32(0xFF, overlay->x6C, gCamSpeedScale * 8);
    } else {
        if (overlay->x6C == 0) {
            return;
        }
        overlay->x6C = approachS32(0, overlay->x6C, gCamSpeedScale * 8);
    }
    setTextColor(0xFF, 0xFF, 0xFF, overlay->x6C);
    entry += D_800BD0FC * 0x3C;
    func_800271A8(0xD7, 4);
    drawText(D_80000B04);
    drawInt(D_80178270);
    func_800271A8(0xD7, 5);
    drawText(D_80000B0C);
    drawInt((func_800252D8() + 0x200) / 1024);
    func_80027158(0xFA, 0x64);
    drawText(D_80000B14);
    func_80027158(0x10E, 0x64);
    drawInt(D_800BD114);
    D_800BD114 = 0;
    func_80027158(0xFA, 0x6E);
    drawText(D_80000B18);
    func_80027158(0x10E, 0x6E);
    drawInt(D_800BD058);
    D_800BD058 = 0;
    func_80027158(0xFA, 0x78);
    drawText(D_80000B1C);
    func_80027158(0x10E, 0x78);
    drawInt(D_8017826C);
    func_80027158(0xFA, 0x82);
    drawText(D_80000B20);
    func_80027158(0x10E, 0x82);
    drawInt(D_801402F8);
    D_801402F8 = 0;
    func_80027158(0xF0, 0x8C);
    drawText(D_80000B24);
    func_80027158(0x10E, 0x8C);
    drawInt(D_800B83B4);
    D_800B83B4 = 0;
    if (gCameraTarget != NULL) {
        func_80027158(0x28, 0x64);
        drawFloat(gCameraTarget->x4);
        func_80027158(0x28, 0x6E);
        drawFloat(gCameraTarget->x8);
        func_80027158(0x28, 0x78);
        drawFloat(gCameraTarget->xC);
        func_80027158(0x28, 0x8C);
        drawInt(func_8002D260(gCameraTarget->x10));
    }
    setTextPos(0x1E, 0xC8);
    seconds = gTextWaveTime / 100;
    minutes = seconds / 60;
    sprintf(text, D_80000B28, minutes / 60, minutes % 60, seconds % 60);
    drawText(text);
    setTextPos(0xA0, 0xD2);
    func_80028710(entry + 4);
    setTextColor(0x60, 0xFF, 0xFF, 0xFF);
    setTextPos(0x1E, 0x3C);
    drawText(D_80000AE8);
    drawInt(countLiveObjects(0));
    drawText(D_80000B38);
    drawInt(D_800AB9B8);
}
