s32 func_80024394(s32, s32);
typedef struct { s16 a; s16 b; s16 c; s16 d; } Rec8;
typedef struct { s32 id; s32 pad[3]; } Rec16;
extern Rec8 D_800B7B10[];
extern Rec16 D_800B9410[];
extern s32 func_80023078;
extern s32 func_8004303C;

void func_800852CC(void *arg0, void *arg1) {
    s32 n;
    s32 t;
    Rec16 *p;

    if (*(void **)((s8 *)arg0 + 0x9C) == (s8 *)&func_80023078 + 8) {
        *(void **)((s8 *)arg0 + 0x9C) = &func_8004303C;
    }
    if (arg1 != NULL) {
        *(f32 *)((s8 *)arg0 + 4) = *(f32 *)((s8 *)arg1 + 4);
        *(f32 *)((s8 *)arg0 + 8) = *(f32 *)((s8 *)arg1 + 8);
        *(f32 *)((s8 *)arg0 + 0xC) = *(f32 *)((s8 *)arg1 + 0xC);
        *(s32 *)((s8 *)arg0 + 0x6C) = *(s32 *)((s8 *)arg1 + 0x6C);
        *(s32 *)((s8 *)arg0 + 0x70) = *(s32 *)((s8 *)arg1 + 0x70);
    }
    n = *(s32 *)((s8 *)arg0 + 0xB8);
    if (n < 0xA9) {
        if (n >= 10 && n < 0x65) {
            t = D_800B7B10[n - 10].c;
            *(s32 *)((s8 *)arg0 + 0xFC) = t;
            if (t >= 4) {
                *(s32 *)((s8 *)arg0 + 0xFC) += func_80024394(-1, 1);
            }
            if (*(s32 *)((s8 *)arg0 + 0xFC) <= 0) {
                *(s32 *)((s8 *)arg0 + 0xFC) = 1;
            }
            *(s32 *)((s8 *)arg0 + 0xFC) *= 35;
        }
        p = D_800B9410;
        if (p->id != 0) {
            do {
                if (*(s32 *)((s8 *)arg0 + 0xB8) == p->id) {
                    *(Rec16 **)((s8 *)arg0 + 0xC8) = p;
                    return;
                }
                p++;
            } while (p->id != 0);
        }
    }
}
