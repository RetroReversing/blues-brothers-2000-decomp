int abs(int);
typedef struct {
    u16 a;
    s8 b;
    s8 c;
} Pos2;
typedef struct {
    u8 pad[0x9C];
    void (*fn)(void);
} Obj3;
void func_80030FDC(void);
extern Obj3 *D_8013FB74;
extern s32 D_800AE17C;
extern s32 D_80107070;
extern s32 D_80107600;
extern s32 D_80107610;
extern Pos2 D_801704D0;
extern s32 D_801705E8;
extern u16 D_801705F8;
extern u16 D_800B9EA2;

s32 func_8007CE60(void) {
    s32 n;

    n = 0;
    if (D_8013FB74->fn != func_80030FDC) {
        return 0;
    }
    if (D_800AE17C != 0) {
        return 0;
    }
    if (D_801704D0.a != D_80107070) {
        n = 1;
    }
    if (abs(D_801704D0.b - D_80107600) >= 21) {
        n++;
    }
    if (abs(D_801704D0.c - D_80107610) >= 21) {
        n++;
    }
    D_801704D0.a = D_80107070;
    D_801704D0.b = D_80107600;
    D_801704D0.c = D_80107610;
    if (n == 0) {
        D_801705F8 += D_800B9EA2;
        if ((s16)D_801705F8 >= 30000) {
            D_801705E8 = 1;
        }
    } else {
        D_801705F8 = 0;
    }
    return n;
}
