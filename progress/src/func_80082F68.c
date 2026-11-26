typedef struct Slot {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    u8 x10[8];
    s16 x18[8];
} Slot;

typedef struct Pair {
    s32 x0;
    s32 x4;
    s32 x8;
} Pair;

s32 *func_80081BF0(s32, s32, s32);
s32 func_800833D0(s32);

extern Pair D_800B9000[];
extern s32 D_801070A0[];
extern s32 D_801073B0[];
extern s32 D_801073C0[];
extern s32 D_80171960[];
extern s32 D_80171970[];
extern s32 D_80171980;
extern Slot D_801719E0[];
extern s32 D_80171A54;
extern s32 D_80171A70[];

void func_80082F68(s32 p) {
    s32 phase;
    s32 *seq;
    s32 sx;
    s32 sy;
    s32 btn;
    s32 i;

    phase = D_80171980 % 144;
    seq = func_80081BF0(D_801719E0[p].x0, D_80171A70[p], D_80171A54);
    sx = D_801073B0[p];
    sy = D_801073C0[p];
    if (abs(sx) * 2 > abs(sy)) {
        sy = 0;
    }
    if (abs(sx) < abs(sy) * 2) {
        sx = 0;
    }
    if (abs(sx) < 10) {
        sx = 0;
    }
    if (abs(sy) < 10) {
        sy = 0;
    }
    if (sx > 20 && D_80171960[p] <= 20) {
        D_801070A0[p] |= 0x100;
    }
    if (sx < -20 && D_80171960[p] >= -20) {
        D_801070A0[p] |= 0x200;
    }
    if (sy > 20 && D_80171970[p] <= 20) {
        D_801070A0[p] |= 0x800;
    }
    if (sy < -20 && D_80171970[p] >= -20) {
        D_801070A0[p] |= 0x400;
    }
    D_80171960[p] = sx;
    D_80171970[p] = sy;
    btn = D_801070A0[p];
    if (btn != 0) {
        if (btn == seq[D_801719E0[p].x8]) {
            D_801719E0[p].x10[D_801719E0[p].x8] = 1;
            D_801719E0[p].x18[D_801719E0[p].x8] = 0xFF;
            D_801719E0[p].x8++;
            D_801719E0[p].xC = func_800833D0(p);
        } else {
            for (i = D_801719E0[p].x8; i > 0; i--) {
                D_801719E0[p].x10[i] = 0;
                D_801719E0[p].x18[i] = 0x76;
            }
            D_801719E0[p].x8 = D_800B9000[D_801719E0[p].x0].x0;
        }
    }
    if (D_801719E0[p].xC == 0 && phase >= 31 && phase < 36) {
        for (i = D_801719E0[p].x8; i > 0; i--) {
            D_801719E0[p].x10[i] = 0;
            D_801719E0[p].x18[i] = 0x76;
        }
        D_801719E0[p].x8 = D_800B9000[D_801719E0[p].x0].x0;
    }
}
