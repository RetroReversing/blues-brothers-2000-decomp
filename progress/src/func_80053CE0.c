typedef struct Obj Obj;
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ u8 pad4[0xC];
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ u8 pad18[0x10];
    /* 0x28 */ f32 f28;
    /* 0x2C */ f32 f2C;
    /* 0x30 */ f32 f30;
    /* 0x34 */ u8 pad34[0x24];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[0xC];
    /* 0x68 */ s32 f68;
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x18];
    /* 0x98 */ void *f98;
    /* 0x9C */ u8 pad9C[4];
    /* 0xA0 */ void (*fA0)(Obj *);
    /* 0xA4 */ u8 padA4[0x14];
    /* 0xB8 */ s32 fB8;
    /* 0xBC */ u8 padBC[0x28];
    /* 0xE4 */ s32 fE4;
};
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80023E3C(s32);
void func_80053C38(Obj *);
s16 sins(u16);
void func_8001FE50();
extern char D_800B4988[];
extern char D_800B9EA4[];
extern char D_8014AA98[];
extern s32 D_8014AAA0[];
extern f32 D_80008238;
extern f32 D_8000823C;
extern f32 D_80008240;
#define G(x) (*(s32 *)x)

void func_80053CE0(Obj *arg0) {
    s32 pad;
    s32 big;
    s32 v;
    f32 f;
    s32 s;
    s32 t;

    pad = 0;
    big = arg0->f0 == 0x802;
    if (G(D_800B4988) != 0) {
        pad = 15;
    }
    if (arg0->f7C == 0) {
        if (big) {
            arg0->fB8 = 0x88;
            arg0->fE4 = func_80023E3C(0x88);
            arg0->f2C = pad - 170;
            arg0->f28 = D_80008238;
            arg0->f30 = D_80008240;
        } else {
            if (D_8014AAA0[0] == 0) {
                arg0->fA0(arg0);
                return;
            }
            arg0->fB8 = 0x89;
            arg0->fE4 = func_80023E3C(0x89);
            arg0->f2C = 170 - pad;
            arg0->f28 = D_8000823C;
            arg0->f30 = D_80008240;
        }
        arg0->f10 = 0x8000;
        if (D_8014AAA0[0] == 0x56F && arg0->fB8 == 0x89) {
            arg0->f58 = func_800221C0(0, 1, 2, 3, 0, 0, 1, 0);
        } else {
            arg0->f58 = func_800221C0(1, 1, 0, 3, 0, 0, 1, 0);
        }
        arg0->f98 = func_8001FE50;
        arg0->f68 = 0xD;
        arg0->f7C = 1;
    }
    if (G(D_8014AA98) == big) {
        arg0->f68 = 0xD;
    } else {
        arg0->f68 = -1;
    }
    pad = 0x1800;
    if (arg0->f2C > 0.0f) {
        pad = -0x1800;
    }
    t = (sins((G(D_800B9EA4) * 100) & 0xFFFC) >> 4) + 0x8000; arg0->f10 = pad + t;
    arg0->f14 = sins((G(D_800B9EA4) * 50) & 0xFFFE) >> 5;
    func_80053C38(arg0);
}
