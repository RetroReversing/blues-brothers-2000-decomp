s16 coss(u16);
void func_80027038(s32);
void func_80027060(s32, s32, s32, s32);
void setTextColor(s32, s32, s32, s32);
void setTextPos(s32, s32);
void func_80027158(s32, s32);
void func_800271A8(s32, s32);
void func_80028710(void *);
void func_8002E838(s32);
void drawCenteredMessage(s32);
void drawMessage(s32);
extern char D_800AA134[];
extern s32 gTextWaveTime;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_8003D1B4(void *arg0) {
    char *rec;
    char *e;
    char *q;
    s32 c;
    s32 b;
    s32 n;
    s32 i;
    s32 y;

    rec = D_800AA134 + (F(arg0, s32, 0x90) << 5);
    e = F(rec, char *, 0x1C);
    func_8002E838(F(arg0, s32, 0x70) / 2);
    func_80027038(0);
    setTextColor(0xCE, 0x10, 0x25, F(arg0, s32, 0x70));
    setTextPos(0xA0, 0x14);
    drawCenteredMessage(0x9A);
    b = 0xFF - (((coss((gTextWaveTime * 400) & 0xFFF0) * 127) >> 15) + 0x80) / 2;
    func_80027060(b, b, b, F(arg0, s32, 0x70));
    setTextPos(0x28, 0xA5);
    drawMessage(0x9D);
    setTextPos(0x28, 0xB9);
    drawMessage(0x9E);
    setTextPos(0x28, 0xCD);
    drawMessage(0x9B);
    setTextColor(0xFF, 0xFF, 0xFF, F(arg0, s32, 0x70));
    func_80027158(0xA0, 0x42);
    n = 4;
    if (F(arg0, s32, 0x8C) == 0) {
        n = F(rec, s32, 0x18);
    }
    for (i = 0; i < n; i++) {
        func_800271A8(0xA0, i + 2);
        c = 0;
        if (i == F(arg0, s32, 0x88)) {
            c = 0xFF;
        }
        setTextColor(c, 0xFF, c, F(arg0, s32, 0x70));
        if (F(arg0, s32, 0x8C) == 0) {
            func_80028710(e + i * 0x3C + 4);
            if (F(e + i * 0x3C, s32, 0x1C) == -1) {
                func_80027158(0x28, i * 10 + 0x50);
                drawMessage(0x17);
            }
        } else {
            func_80028710(D_800AA134 + i * 0x20);
        }
    }
}
