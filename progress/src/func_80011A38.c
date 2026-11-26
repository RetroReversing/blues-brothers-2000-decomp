s32 cameraGetMode(void);
void func_80011734(void *);
void func_8002D604(void *);
s16 sins(u16);
void func_80011CA4();
typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
    /* 0x1C */ u8 pad1C[0x34];
    /* 0x50 */ f32 f50;
    /* 0x54 */ u8 pad54[0x10];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ s32 f80;
    /* 0x84 */ s32 f84;
    /* 0x88 */ u8 pad88[0x14];
    /* 0x9C */ void *f9C;
} Obj;
extern char gTextWaveTime[];
extern char D_8014022C[];
extern f32 D_80000758;
extern f32 D_8000075C;
extern f32 D_80000760;
extern f32 D_80000764;
extern f32 D_80000768;
extern f32 D_8000076C;

void func_80011A38(Obj *arg0) {
    f32 lim;
    f32 t;
    f32 v;

    lim = (*(f32 *)D_8014022C) + D_80000758;
    if (arg0->f7C == 0) {
        arg0->f64 = 100;
        arg0->f7C = arg0->y;
        arg0->f80 = arg0->x;
        arg0->f84 = arg0->z;
        arg0->f50 = D_80000760;
        arg0->f50 = D_8000075C;
    }
    v = arg0->f50;
    if (D_80000764 < v) {
        arg0->f50 = v - D_80000768;
    }
    func_8002D604(arg0);
    func_8002D604(arg0);
    arg0->f18 = (sins(((*(s32 *)gTextWaveTime) * 400) & 0xFFF0) * 31) >> 8;
    arg0->f10 = (sins(((*(s32 *)gTextWaveTime) * 200) & 0xFFF8) * 127) >> 10;
    arg0->y = arg0->f7C + (sins(((*(s32 *)gTextWaveTime) * 500) & 0xFFFC) >> 9);
    arg0->x = arg0->f80 + (sins(((*(s32 *)gTextWaveTime) * 250) & 0xFFFE) >> 9);
    arg0->z = arg0->f84 + (sins(((*(s32 *)gTextWaveTime) * 125) & 0xFFFF) >> 9);
    if (cameraGetMode() == 1) {
        arg0->z = D_8000076C;
    }
    t = arg0->f7C;
    if (lim < t) {
        arg0->f7C = t + arg0->f50;
    }
    if (arg0->y <= lim) {
        arg0->f9C = func_80011CA4;
        arg0->y = lim;
        arg0->f80 = 50;
        arg0->f7C = arg0->f68;
    }
    func_80011734(arg0);
}
