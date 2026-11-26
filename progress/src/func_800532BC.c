typedef struct Obj Obj;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void func_800271A8(s32, s32);
s32 func_800291AC(u8 *);
void sendCommand(s32, s32);
s32 tickActorTimer(void *);
Obj *func_8002E374(s32);
s32 strlen(const char *);
void func_8001FE50();
void func_800530C0();
void func_80053990();
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ u8 pad4[0x24];
    /* 0x28 */ s32 f28;
    /* 0x2C */ f32 f2C;
    /* 0x30 */ f32 f30;
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ u8 pad40[0x18];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[8];
    /* 0x64 */ s32 f64;
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[0xC];
    /* 0x78 */ s32 f78;
    /* 0x7C */ s32 f7C;
    /* 0x80 */ s32 f80;
    /* 0x84 */ s32 f84;
    /* 0x88 */ u8 *f88;
    /* 0x8C */ u8 pad8C[4];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[4];
    /* 0x98 */ void *f98;
    /* 0x9C */ void *f9C;
    /* 0xA0 */ u8 padA0[4];
    /* 0xA4 */ Obj *fA4;
};
typedef struct { s32 mode; u8 *text; } Msg;
extern char D_800B4988[];
extern char gPadPressed[];
extern char D_8014AA98[];
#define gFlag (*(s32 *)D_800B4988)
#define gPad (*(s32 *)gPadPressed)
#define gMode (*(s32 *)D_8014AA98)
extern f32 D_80008180;

s32 func_800532BC(Obj *arg0, Msg *arg1) {
    u8 *text;
    s32 len;
    s32 pad;
    Obj *o;
    s32 n;
    s32 x;
    s32 m;

    text = arg1->text;
    len = strlen(text);
    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        m = arg1->mode;
        arg0->f84 = m;
        if (m == 1) {
            gMode = m;
        } else {
            gMode = 0;
        }
        pad = 0;
        arg0->f68 = 0xE;
        arg0->f64 = len * 8;
        arg0->f88 = text;
        arg0->f98 = func_800530C0;
        if (gFlag != 0) {
            pad = 20;
        }
        o = func_8002E374(0x87);
        o->f28 = 0;
        if (gMode == 0) {
            func_800271A8(0x3E, pad / 20 + 1);
        } else {
            func_800271A8(0x22, 11 - pad / 20);
        }
        n = func_800291AC(text) / 15;
        n -= 4;
        if (n < 0) {
            n = 0;
        }
        n *= 20;
        if (gMode != 0) {
            o->f2C = pad - 0x6A;
        } else {
            x = 0x2A - n;
            x -= pad;
            o->f2C = x;
        }
        o->f34 = 0;
        o->f38 = 0;
        o->f3C = 0;
        o->f30 = D_80008180;
        o->f58 = packDrawFlags(0, 1, 0, 3, 0, 0, 1, 0);
        o->f9C = func_80053990;
        o->fA4 = arg0;
        o->f78 = arg0->f78;
        o->f98 = func_8001FE50;
        o->f68 = 0xD;
        o->f90 = 1;
        o->f0 = 0x80F;
    }
    if (arg0->f80 != 0) {
        arg0->f80 = 0;
        return 1;
    }
    if (tickActorTimer(arg0) != 0) {
        if (arg0->f64 < -1000) {
            return 0;
        }
        if (gPad & 0x8000) {
            sendCommand(0xC, 0x80);
            sendCommand(8, 0xA3);
            return 0;
        }
    }
    if (arg0->f64 < len * 14 - 50 && (gPad & 0x8000)) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xA3);
        arg0->f64 = -1;
        arg0->f80 = 1;
    }
    return 1;
}
