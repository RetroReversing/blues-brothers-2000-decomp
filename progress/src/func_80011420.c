s16 coss(u16);
s16 sins(u16);
void *func_8001B91C(void);
s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80023E3C(s32);
void func_8002ADFC(s32, s32, void *);
void *func_8002B240(s32, s32, s32, s32, s32, s32);
void func_8002D604(void *);
f32 func_8002DD60(f32);
void func_800433A8(void *, s32, s32);
void func_8003BC40();
typedef struct Obj Obj;
typedef void (*Fn)(Obj *);
struct Obj {
    /* 0x00 */ s32 f0;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ s32 ang;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ s32 f34;
    /* 0x38 */ s32 f38;
    /* 0x3C */ s32 f3C;
    /* 0x40 */ u8 pad40[0x18];
    /* 0x58 */ s32 f58;
    /* 0x5C */ u8 pad5C[0x10];
    /* 0x6C */ s32 f6C;
    /* 0x70 */ s32 f70;
    /* 0x74 */ s32 f74;
    /* 0x78 */ s32 f78;
    /* 0x7C */ s32 f7C;
    /* 0x80 */ u8 pad80[0x10];
    /* 0x90 */ s32 f90;
    /* 0x94 */ u8 pad94[8];
    /* 0x9C */ void *f9C;
    /* 0xA0 */ Fn fA0;
    /* 0xA4 */ s32 fA4;
    /* 0xA8 */ Obj *fA8;
    /* 0xAC */ u8 padAC[0xC];
    /* 0xB8 */ s32 fB8;
    /* 0xBC */ u8 padBC[0x28];
    /* 0xE4 */ s32 fE4;
    /* 0xE8 */ u8 padE8[8];
    /* 0xF0 */ s32 fF0;
};
extern f32 D_800AA1EC[3];
extern Obj *D_800B3960;
extern s32 D_800B9EA4;
extern Obj *D_800BD06C;
extern s32 D_800BD100;
extern u8 D_800BD1F0[];

void func_80011420(Obj *arg0) {
    f32 dz;
    f32 dy;
    f32 lim;

    if (arg0->f7C == 0) {
        if (D_800BD1F0[D_800BD100 * 10 + arg0->f70] == 1) {
            arg0->fA0(arg0);
            return;
        }
        arg0->f58 = func_800221C0(1, 1, 0, 2, 0, 1, 1, 0);
        arg0->f0 = 0x101;
        arg0->f7C = 1;
        arg0->fB8 = 0x98;
        arg0->fE4 = func_80023E3C(0x98);
        if (arg0->f74 == 0) {
            arg0->fA8 = func_8002B240(arg0->x, arg0->y, arg0->z, 0xBF, 3000, 0);
        }
    }
    D_800AA1EC[0] = arg0->x - D_800BD06C->x;
    D_800AA1EC[1] = dz = arg0->z - D_800BD06C->z;
    D_800AA1EC[2] = dy = arg0->y - D_800BD06C->y;
    lim = 180.0f;
    if (func_8002DD60(D_800AA1EC[0]) < lim && func_8002DD60(dy) < 360.0f && func_8002DD60(dz) < lim) {
        func_8002ADFC(6, 1000, arg0);
        if (D_800BD06C->f90 == 1) {
            D_800BD06C->fF0 = 0xFF;
            D_800BD06C->ang = D_800B3960->ang + 0x8000;
            func_800433A8(D_800BD06C, 0x1A, 0x100);
            D_800BD06C->f9C = func_8003BC40;
            D_800BD06C->fF0 = 0xFF;
            D_800BD06C->f0 = 0x101;
        } else {
            D_800BD06C->f6C = 2;
        }
        D_800BD1F0[D_800BD100 * 10 + arg0->f70] = 1;
        func_8001B91C();
        if (arg0->fA8 != 0) {
            arg0->fA8->fA0(arg0->fA8);
        }
        arg0->fA0(arg0);
        return;
    }
    func_8002D604(arg0);
    arg0->f38 = (coss((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
    arg0->f3C = (sins((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
    arg0->f34 = (sins((D_800B9EA4 * 2000) & 0xFFF0) >> 11) + 0x100;
}
