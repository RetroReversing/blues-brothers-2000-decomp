typedef struct { u8 pad0[0x20]; s32 x20; u8 pad24[8]; s32 x2C; u8 pad30[0x20]; } ViModeB;
typedef struct { u32 a; u32 b; } FbPair;
void func_800899C4(char *, ...);
void debugPrintf(char *, ...);
void osCreateMesgQueue(void *, void *, s32);
void func_80089FA8(s32);
void osViBlack(s32);
void func_80070C60(void *, s32, s32);
void osViSetSpecialFeatures(s32);
void func_8002A2E0(void);
void func_800706E0(void *);
void func_80025F20(void);
void func_8002CDB0(void);
void func_800258E4(void);
void func_8002E2F0(void);
void buildFrameDisplayList(s32);
void func_8002E46C(void);
void func_80089130(s32, s32, s32);
void func_8002CE84(s32, s32);
void func_80088EE0(void);
s32 func_8007CF64(void);
void func_80089EF0(void);
void func_80089F5C(void);
extern char D_80009C04[];
extern char D_80009C10[];
extern char D_80009C28[];
extern char D_80009C34[];
extern char D_80009C40[];
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s32 D_800B9C7C;
extern s32 D_800B9EBC;
extern ViModeB D_800BB5E0[];
extern u8 D_801771C8[];
extern u8 D_80178150[];
extern u8 D_80176730[];
extern s32 D_801771B8;
extern s32 D_801771BC;
extern s32 D_801705E8;
extern FbPair D_80178230;
extern s32 D_80000300;
extern u8 D_801858A0[];

void func_80088CB0(void) {
    s32 mode;

    mode = (gScreenHeight == 0x1E0) << 3;
    func_800899C4(D_80009C04, D_80009C10, D_80009C28, D_80009C34);
    D_80178230.a = 0x80200000;
    D_80178230.b = 0x80200000 + gScreenWidth * gScreenHeight * 2;
    osCreateMesgQueue(D_801771C8, D_80178150, 1);
    D_801771B8 = D_800BB5E0[mode].x20;
    D_801771BC = D_800BB5E0[mode].x2C;
    func_80089FA8(0);
    if (D_80000300 == 2) {
        mode = 0x1C;
    } else if (D_80000300 == 1) {
        mode = 0;
    } else {
        for (;;) {
            osViBlack(1);
        }
    }
    func_80070C60(D_80176730, mode, 1);
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(0x40);
    func_8002A2E0();
    func_800706E0(D_80176730);
    func_80025F20();
    func_8002CDB0();
    if ((u8 *)(0x80200000 - gScreenWidth * gScreenHeight * 2) < D_801858A0) {
        debugPrintf(D_80009C40);
    }
    func_800258E4();
    func_8002E2F0();
    buildFrameDisplayList(0);
    func_8002E46C();
    func_80089130(0, 0, 0);
    func_8002CE84(6, 0);
    for (;;) {
        while (D_800B9EBC == 0) {
            if (D_801705E8 == 0) {
                func_80088EE0();
            } else {
                func_8007CF64();
            }
        }
        D_800B9EBC = 0;
        func_80089EF0();
        func_80089F5C();
        D_800B9C7C = 0;
    }
}
