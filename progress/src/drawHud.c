typedef struct {
    s32 unk0;
    s32 unk4[4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Game;

typedef struct { u8 level, tex, color, flag; } Rec;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    u8 pad8[0x90 - 0x8];
    s32 unk90;
} Hud;

s32 func_8001B990(s32, s32);
s32 findActor(s32, s32);
s32 getImageAsset(s32);
void func_80027038(s32);
void setTextColor(s32, s32, s32, s32);
void func_80027158(s32, s32);
void drawImage(s32, s32, s32, s32);
void func_80028710(char *);
void func_8002A360(s32, s32);
s32 approachS32(s32, s32, s32);
void func_8003CA98(void *);
void func_80081E1C(s32, s32, s32, s32);
extern char D_80000AA0[];
extern s32 D_800A9540;
extern s32 D_800A9544;
extern u8 D_800A9554[];
extern Rec D_800A9560[];
extern s32 D_800AB9B4;
extern s32 D_800B4988;
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern s32 D_800BD028[];
extern void *gCameraTarget;
extern s32 D_800BD07C;
extern Game D_800BD0E0;
extern s32 D_800BD118;
extern s32 D_800BD160;
extern s32 D_800BD1E4;
extern s32 D_800BD23C;
extern s32 D_800BD240[];
extern s32 D_800BD26C;
extern s32 D_80140028;

/* Draws the HUD each frame: counters, collected item icons and remaining lives. */ void drawHud(Hud *hud)
{
    u8 unused[0x28];
    s32 d[3];
    s32 scrollX;
    s32 itemX;
    s32 xx;
    s32 bigNum;
    s32 i;
    Rec *p;
    s32 hasBonus;
    s32 hudX;
    s32 *digitImages;

    scrollX = hud->unk4;
    setTextColor(255, 255, 255, 255);
    hasBonus = findActor(0x801, 0);
    if (D_800AB9B4 != 0 || D_800B4988 != 0 || hasBonus != 0) {
        hud->unk90 = approachS32(0, hud->unk90, gCamSpeedScale * 16);
    } else {
        hud->unk90 = approachS32(255, hud->unk90, gCamSpeedScale * 8);
    }
    if (hud->unk90 >= 256) {
        hud->unk90 = 255;
    }
    if (hud->unk90 != 0) {
        hud->unk4 = 0.0f;
        func_80027038(0);
        setTextColor(255, 255, 255, hud->unk90);
        if (D_800A9544 != 0) {
            func_80027158(40, 200);
            func_80028710(D_80000AA0);
            D_800BD26C += gFrameScale;
        } else {
            D_800BD26C = 0;
        }
        if (D_800BD26C > 2000) {
            func_8003CA98(gCameraTarget);
        }
        if (D_800BD0E0.unk0 < 0) {
            D_800BD0E0.unk0 = 0;
        }
        if (D_800BD0E0.unk0 >= 10) {
            D_800BD0E0.unk0 = 9;
        }
        if (D_800BD0E0.unk4[D_800BD0E0.unk20] >= 1000) {
            D_800BD0E0.unk4[D_800BD0E0.unk20] = 999;
        }
        hudX = -scrollX;
        drawImage(getImageAsset(D_800BD160), hudX + 215, 180, 0);
        digitImages = D_800BD240;
        drawImage(getImageAsset(digitImages[D_800BD0E0.unk0]), hudX + 234, 200, 0);
        d[0] = D_800BD0E0.unk4[D_800BD0E0.unk20];
        d[1] = d[0] / 10;
        d[2] = d[0] / 100;
        d[0] -= d[1] * 10;
        d[1] -= d[2] * 10;
        d[2] %= 10;
        if (d[2] == 0) {
            func_80081E1C(digitImages[d[1]], hudX + 255, 200, 0);
            func_80081E1C(digitImages[d[0]], hudX + 263, 200, 0);
        } else {
            func_80081E1C(digitImages[d[2]], hudX + 255, 200, 0);
            func_80081E1C(digitImages[d[1]], hudX + 263, 200, 0);
            func_80081E1C(digitImages[d[0]], hudX + 271, 200, 0);
        }
        bigNum = D_800BD23C;
        bigNum /= 100;
        if (bigNum >= 100) {
            bigNum = 99;
        }
        if (bigNum != 0) {
            drawImage(getImageAsset(D_800BD240[bigNum / 10]), hudX + 255, 185, 0);
            drawImage(getImageAsset(D_800BD240[bigNum % 10]), hudX + 263, 185, 0);
        }
        if (D_80140028 != 0) {
            if (D_80140028 == 8) {
                func_8002A360(12, 128);
                func_8002A360(8, 66);
            }
            drawImage(getImageAsset(D_800BD118), 270, 180, 0);
            D_80140028 -= gCamSpeedScale;
            if (D_80140028 < 0) {
                D_80140028 = 0;
            }
        }
        setTextColor(255, 255, 255, hud->unk90);
        itemX = 260;
        for (i = 0; ; i++) {
            u8 f = D_800A9560[i].flag;
            u8 *c;
            s32 cr, cg, cb;

            if (f == 0) {
                break;
            }
            if (D_800A9560[i].level != D_800BD0E0.unk20) {
                continue;
            }
            c = &D_800A9554[D_800A9560[i].color * 3];
            cr = c[0];
            cg = c[1];
            cb = c[2];
            if (func_8001B990(256, f) != 0) {
                setTextColor(cr, cg, cb, hud->unk90);
            } else {
                setTextColor(cr, cg, cb, hud->unk90 / 4);
            }
            drawImage(getImageAsset(D_800BD028[D_800A9560[i].tex]), itemX, 30, 0);
            itemX -= 18;
        }
        setTextColor(255, 255, 255, hud->unk90);
        if (D_800BD0E0.unk14 > D_800A9540) {
            D_800BD0E0.unk14 = D_800A9540;
        }
        for (i = 0; i < D_800A9540; i++) {
            if (i < D_800BD0E0.unk14) {
                drawImage(getImageAsset(D_800BD1E4), scrollX + (i * 15 + 30), 35, 0);
            } else {
                drawImage(getImageAsset(D_800BD07C), scrollX + (i * 15 + 30), 35, 0);
            }
        }
    }
}
