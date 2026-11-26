typedef struct {
    s32 type;
    s32 acc;
    s32 n;
    s32 pad;
    u8 b[8];
    s16 h[8];
} Rec;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} Info;
extern Rec D_801719E0[];
extern s32 D_80171A70[];
extern s32 D_80171A54;
extern s32 D_80171994;
extern s32 D_80171980;
extern Info D_800B9000[];
s32 *func_80081BF0(s32, s32, s32);

s32 func_800833D0(s32 i)
{
    s32 *t;
    s32 m;
    Rec *rec;
    Rec *base;
    s32 j;

    t = func_80081BF0(D_801719E0[i].type, D_80171A70[i], D_80171A54);
    m = D_80171980 % 144;
    if (D_80171994 == 0 && i == 1) {
        rec = &D_801719E0[1];
        if (t[rec->n] != 0) {
            goto end;
        }
        rec->acc += D_800B9000[rec->type].c;
        return 1;
    }
    base = D_801719E0;
    rec = base + i;
    if (t[rec->n] != 0) {
        goto end;
    }
    if ((u32)(m - 30) >= 100) {
        rec->acc += D_800B9000[rec->type].c;
        return 1;
    }
    rec->n--;
    D_801719E0[i].h[rec->n] = 0x76;
    D_801719E0[i].b[rec->n] = 0;
    for (j = rec->n; j > 0; j--) {
        D_801719E0[i].h[j] = 0;
    }
    for (j = D_801719E0[i].n; j > 0; j--) {
        D_801719E0[i].h[j] = 0x76;
        D_801719E0[i].b[j] = 0;
    }
    D_801719E0[i].n = D_800B9000[D_801719E0[i].type].a;
end:
    return 0;
}
