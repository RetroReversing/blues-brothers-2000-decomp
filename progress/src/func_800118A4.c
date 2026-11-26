typedef struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ f32 x0;
    /* 0x44 */ f32 y0;
    /* 0x48 */ u8 pad48[0x34];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0xC];
    /* 0x8C */ s32 f8C;
    /* 0x90 */ u8 pad90[4];
    /* 0x94 */ s32 f94;
} Obj;
s16 coss(u16);
s16 sins(u16);
void func_80011734(Obj *);
extern s32 gTextWaveTime;

void func_800118A4(Obj *arg0) {
    s32 t;
    u16 ang;

    t = gTextWaveTime + arg0->f8C;
    if (arg0->f7C == 0) {
        arg0->f94 /= 4;
        arg0->f7C = 1;
        arg0->f0 = 0x101;
    }
    ang = t * 1500;
    arg0->f38 = (coss(ang) >> 11) + 0x100;
    arg0->f3C = (sins(ang) >> 11) + 0x100;
    arg0->f34 = (sins(ang) >> 11) + 0x100;
    arg0->f10 = (((sins((t * 100) & 0xFFFC) * 45) >> 12) * 0xFFFF) / 360;
    arg0->y = arg0->y0 + ((sins((gTextWaveTime * 100) & 0xFFFC) * 25) >> 15);
    func_80011734(arg0);
}
