typedef struct {
    s32 unk0;
    u8 pad4[0xC];
    u8 unk10[8];
    s16 unk18[8];
} Unk801719E0;

typedef struct {
    s32 unk0[6];
} Unk800820E8_fp;

typedef struct {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    u8 padC[0x70 - 0xC];
    s32 unk70;
} Unk800820E8;

extern Unk801719E0 gComboSlots[];
extern s32 D_80171A70[];
extern s32 D_80171A54;
extern s32 D_800AB9B4;
extern s32 gComboBeat;
typedef struct { u32 w0, w1; } GfxW;
extern GfxW *D_80177E18;

Unk800820E8_fp *getComboSequence(s32, s32, s32);
void setTextColor(s32, s32, s32, s32);
s32 func_80023D58(s32);
void func_80081E1C(s32, s32, s32, s32);
void func_8008203C(s32, s32);
s32 func_80081FA4(s32);
s32 func_80081F0C(s32);
void func_80081E78(s32, s32, s32, s32);

void func_800820E8(Unk800820E8 *arg0) {
    Unk800820E8_fp *fp;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    s32 i;
    s32 scale;
    s32 w;
    s32 r;
    s32 g;
    s32 bl;
    s32 m144;
    s32 m36;

    scale = 1;
    fp = getComboSequence(gComboSlots[arg0->unk70].unk0, D_80171A70[arg0->unk70], D_80171A54);
    x = arg0->unk4;
    y = arg0->unk8;
    w = 24;
    if (D_800AB9B4 != 0) {
        return;
    }
    m144 = gComboBeat % 144;
    m36 = gComboBeat % 36;
    b = 0xFF - m36 * 6;
    if ((a = 0xFF - m144 * 4) < 0x50) {
        a = 0x50;
    }
    r = 0x80;
    if (a >= 0x70) {
        if (fp->unk0[5] == 0x8000) {
            r = 0x70;
            g = 0x70;
            bl = 0xFA;
        } else {
            r = 0x64;
            g = 0xF0;
            bl = 0x64;
        }
    } else {
        g = 0x60;
        bl = 0x60;
    }
    setTextColor(r, g, bl, b);
    func_80081E1C(func_80023D58(0x20A), scale * (w + x - 15), scale * (y - 6), 0);
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xE7000000;
        g->w1 = 0;
    }
    setTextColor(0xFF, 0xFF, 0xFF, b);
    for (i = 0; i < 5; i++) {
        func_8008203C(arg0->unk70, i);
        if (gComboSlots[arg0->unk70].unk10[i] != 0) {
            func_80081E78(func_80081FA4(fp->unk0[i]), x + i * w, y - 8, gComboSlots[arg0->unk70].unk18[i]);
        } else {
            func_80081E78(func_80081F0C(fp->unk0[i]), x + i * w, y - 8, gComboSlots[arg0->unk70].unk18[i]);
        }
    }
    func_8008203C(arg0->unk70, 5);
    setTextColor(0xFF, 0xFF, 0xFF, a);
    func_80081E78(func_80081F0C(fp->unk0[5]), x + w * 5, y - 7, gComboSlots[arg0->unk70].unk18[5]);
}


