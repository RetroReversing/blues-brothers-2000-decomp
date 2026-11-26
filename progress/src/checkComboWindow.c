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
extern Rec gComboSlots[];
extern s32 D_80171A70[];
extern s32 D_80171A54;
extern s32 D_80171994;
extern s32 gComboBeat;
extern Info gComboDefs[];
s32 *getComboSequence(s32, s32, s32);

s32 checkComboWindow(s32 i)
{
    s32 *t;
    s32 m;
    Rec *rec;
    Rec *base;
    s32 j;

    t = getComboSequence(gComboSlots[i].type, D_80171A70[i], D_80171A54);
    m = gComboBeat % 144;
    if (D_80171994 == 0 && i == 1) {
        rec = &gComboSlots[1];
        if (t[rec->n] != 0) {
            goto end;
        }
        rec->acc += gComboDefs[rec->type].c;
        return 1;
    }
    base = gComboSlots;
    rec = base + i;
    if (t[rec->n] != 0) {
        goto end;
    }
    if ((u32)(m - 30) >= 100) {
        rec->acc += gComboDefs[rec->type].c;
        return 1;
    }
    rec->n--;
    gComboSlots[i].h[rec->n] = 0x76;
    gComboSlots[i].b[rec->n] = 0;
    for (j = rec->n; j > 0; j--) {
        gComboSlots[i].h[j] = 0;
    }
    for (j = gComboSlots[i].n; j > 0; j--) {
        gComboSlots[i].h[j] = 0x76;
        gComboSlots[i].b[j] = 0;
    }
    gComboSlots[i].n = gComboDefs[gComboSlots[i].type].a;
end:
    return 0;
}
