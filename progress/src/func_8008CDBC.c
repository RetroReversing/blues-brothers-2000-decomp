typedef struct Chan {
    char pad0[0xC9];
    u8 xC9;
    char padCA[0x13C - 0xCA];
} Chan;

typedef struct Voice {
    char pad[0x1C];
} Voice;

typedef struct VoiceCfg {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
} VoiceCfg;

typedef struct Player {
    struct Player *next;
    void *clientData;
    void *handler;
} Player;

typedef struct Config {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    s32 x24;
    char pad28[0x40 - 0x28];
    s32 x40;
} Config;

void MusSetMasterVolume(s32, s32);
void alSynAddPlayer(void *, Player *);
void alSynAllocVoice(void *, Voice *, VoiceCfg *);
void func_8008D990(s32, s32);
void func_8008DB64(s32);
void func_8008DD44(s32);
void func_8008F2A8(Chan *);
void func_80090710(s32);
void func_800908D0(Config *, s32, s32);
void func_80090C50(s32, s32);
void *func_80090CA0(s32);
void func_80090CD4(void);
s32 func_8008DF5C(void *);

extern s32 D_80000300;
extern Player D_8017B1F0;
extern Player *D_8017B1F4;
extern void *D_8017B1F8;
extern s32 D_8017B204;
extern Voice *D_8017B208;
extern Chan *D_8017B20C;
extern Chan *D_8017B210;
extern s32 D_8017B214;
extern s32 D_8017B218;
extern s32 D_8017B220;
extern s32 D_8017B224;
extern s32 D_8017B228;
extern s32 D_8017B22C;
extern s32 D_8017B234;
extern s32 D_8017B238;
extern s32 D_8017B23C;
extern s32 D_8017B240;
extern s32 D_8017B254;
extern s32 D_8017B2CC;
extern char D_8017B4A0[];

void func_8008CDBC(Config *arg0) {
    VoiceCfg cfg;
    s32 i;

    D_8017B2CC = arg0->x40;
    D_8017B254 = arg0->x0;
    D_8017B204 = arg0->x4 + 4;
    if (D_80000300 != 0) {
        D_8017B214 = 60;
    } else {
        D_8017B214 = 50;
    }
    D_8017B218 = 1000000 / D_8017B214;
    func_80090C50(arg0->x10, arg0->x14);
    func_80090710(arg0->x8);
    D_8017B208 = func_80090CA0((D_8017B204 - 4) * sizeof(Voice));
    D_8017B20C = func_80090CA0(D_8017B204 * sizeof(Chan));
    D_8017B210 = D_8017B20C + 4;
    func_8008DD44(arg0->x24);
    D_8017B228 = 0;
    D_8017B22C = 0;
    if (arg0->x18 != 0 && arg0->x1C != 0) {
        func_8008D990(arg0->x18, arg0->x1C);
    }
    D_8017B23C = 0;
    D_8017B238 = 0;
    if (arg0->x20 != 0) {
        func_8008DB64(arg0->x20);
    }
    D_8017B240 = 0;
    D_8017B234 = 2;
    func_800908D0(arg0, D_8017B214, 2);
    MusSetMasterVolume(3, 0x7FFF);
    D_8017B220 = 1;
    D_8017B224 = 0x12345678;
    D_8017B1F0.next = 0;
    D_8017B1F8 = func_8008DF5C;
    D_8017B1F4 = &D_8017B1F0;
    alSynAddPlayer(D_8017B4A0, &D_8017B1F0);
    for (i = 0; i < D_8017B204; i++) {
        D_8017B20C[i].xC9 = 0;
        func_8008F2A8(&D_8017B20C[i]);
        cfg.unityPitch = 0;
        cfg.priority = arg0->xC;
        cfg.fxBus = 0;
        if (i >= 4) {
            alSynAllocVoice(D_8017B4A0, &D_8017B208[i - 4], &cfg);
        }
    }
    func_80090CD4();
}
