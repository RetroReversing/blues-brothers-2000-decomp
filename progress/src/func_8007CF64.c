int abs(int);
typedef struct Obj2 {
    u8 pad[0xA0];
    void (*fn)(struct Obj2 *);
} Obj2;
typedef struct {
    u16 a;
    s8 b;
    s8 c;
} Pos2;
typedef struct {
    u8 pad[0xE0];
    s32 e0;
} Cam2;

void func_80025280(s32);
void func_80025D34(void);
void func_80025E10(s32);
void func_80026C04(void *, s32, s32);
void func_80088F60(void);
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s16 D_800B8490;
extern s32 (*D_800B8494[])(void);
extern Cam2 *gCameraTarget;
extern s32 D_80107070;
extern s32 D_80107600;
extern s32 D_80107610;
extern s32 D_80107684;
extern s32 D_80107898;
extern Pos2 D_801704D0;
extern u8 D_801704D8[3];
extern u8 D_801704E0[];
extern s32 D_8017055C;
extern s32 D_801705E8;
extern Obj2 *D_801705EC;
extern Obj2 *D_801705F0;
extern s16 D_801705F6;
extern s16 D_801705F8;

s32 func_8007CF64(void) {
    s32 n;
    s32 d;
    u8 a, b, c;

    func_80025E10(0xF);
    n = 0;
    func_80025D34();
    if (D_800B8490 != 0) {
        D_801705F8 = 0;
        D_801705F0 = NULL;
        D_800B8490 = 0;
        D_801705EC = NULL;
        D_801705F6 = 1;
        func_80026C04(D_801704E0, 0, 0x108);
        if (gCameraTarget->e0 != 0) {
            func_80025280(gCameraTarget->e0);
            gCameraTarget->e0 = 0;
        }
        a = D_800B3970;
        b = D_800B3974;
        c = D_800B3978;
D_800B3978 = 0;
D_800B3974 = 0;
D_800B3970 = 0;
D_80107684 = 0;
D_801704D8[0] = a;
D_801704D8[1] = b;
D_801704D8[2] = c;
    } else {
        if (D_801704D0.a != D_80107070) {
            n = 1;
        }
        if (abs(D_801704D0.b - D_80107600) >= 21) {
            n++;
        }
        if (abs(D_801704D0.c - D_80107610) >= 21) {
            n++;
        }
    }
    D_801704D0.a = D_80107070;
    D_801704D0.b = D_80107600;
    D_801704D0.c = D_80107610;
    if (D_800B8494[D_801705F8] == NULL) {
        D_801705F8 = 1;
    }
    if (D_800B8494[D_801705F8]() != 0) {
        D_8017055C = 0;
        D_801705F6 = 1;
        D_801705F8++;
    } else {
        D_801705F6 = 0;
    }
    func_80088F60();
    if (n != 0) {
        D_800B8490 = 1;
        D_801705F8 = 0;
        D_801705E8 = 0;
        D_80107898 = 1;
        D_80107684 = 1;
        D_800B3970 = D_801704D8[0];
        D_800B3974 = D_801704D8[1];
        D_800B3978 = D_801704D8[2];
        if (D_801705F0 != NULL) {
            D_801705F0->fn(D_801705F0);
            D_801705F0 = NULL;
        }
        if (D_801705EC != NULL) {
            D_801705EC->fn(D_801705EC);
            D_801705EC = NULL;
        }
    }
    return n;
}
