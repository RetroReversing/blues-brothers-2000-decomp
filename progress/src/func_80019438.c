typedef struct Rec60 {
    s32 f0;
    s32 f4;
    u8 pad8[0x3C - 0x8];
} Rec60;

typedef struct Lvl {
    u8 pad0[0x1C];
    Rec60 *recs;
} Lvl;

typedef struct GameSt {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
} GameSt;

typedef struct ObjX {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
} ObjX;

void func_800271A8(s32, s32);
void drawText(char *);
s32 func_800252D8(void);
void drawInt(s32);
s32 func_80025644(void);
s32 countLiveObjects(s32);
void drawFloat(f32);
void setTextPos(s32, s32);
void func_80028710(s32 *);
extern Lvl D_800AA134[];
extern GameSt D_800BD0E0;
extern ObjX *gCameraTarget;
extern s32 D_80178270;
extern u8 D_801858A0[];
extern char D_80000AA4[];
extern char D_80000AAC[];
extern char D_80000AB0[];
extern char D_80000AB8[];
extern char D_80000AE4[];
extern char D_80000AE8[];
extern char D_80000AF0[];
extern char D_80000AF4[];
extern char D_80000AF8[];
extern char D_80000AFC[];

void func_80019438(void) {
    char buf[64];
    Rec60 *r;

    r = D_800AA134[D_800BD0E0.f20].recs;
    r += D_800BD0E0.f1C;
    func_800271A8(20, 0);
    drawText(D_80000AA4);
    drawInt((func_800252D8() + 0x200) / 1024);
    drawText(D_80000AE4);
    drawInt(func_80025644());
    func_800271A8(20, 1);
    drawText(D_80000AB0);
    drawInt(D_80178270);
    func_800271A8(20, 2);
    drawText(D_80000AB8);
    drawInt(((u32)D_801858A0 - 0x80000000) >> 10);
    drawText(D_80000AAC);
    func_800271A8(20, 3);
    drawText(D_80000AE8);
    drawInt(countLiveObjects(0));
    func_800271A8(20, 11);
    drawText(D_80000AF0);
    drawFloat(gCameraTarget->x);
    func_800271A8(20, 12);
    drawText(D_80000AF4);
    drawFloat(gCameraTarget->y);
    func_800271A8(20, 13);
    drawText(D_80000AF8);
    drawFloat(gCameraTarget->z);
    func_800271A8(20, 14);
    drawText(D_80000AFC);
    drawInt(gCameraTarget->f10);
    setTextPos(160, 210);
    func_80028710(&r->f4);
}
