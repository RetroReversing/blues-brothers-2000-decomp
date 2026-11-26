typedef struct Obj800A8 {
    u8 pad_0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad_1C[0x18];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad_40[0x1C];
    s32 f5C;
    u8 pad_60[0x10];
    s32 f70;
    u8 pad_74[8];
    s32 f7C;
    u8 pad_80[0x18];
    void (*f98)();
    u8 pad_9C[4];
    void (*fA0)(struct Obj800A8 *);
    u8 pad_A4[8];
    s32 fAC;
    f32 fB0;
    s32 fB4;
} Obj800A8;

s32 func_80024394(s32, s32);
s32 func_8002D1A0(void);
void func_8002D4E0(Obj800A8 *, s32);
void func_8002D9B0(Obj800A8 *);
void func_8002D9F8(Obj800A8 *);
void func_8007FE5C(Obj800A8 *);
extern Obj800A8 *D_800B3964;
extern s32 D_800B9ECC;
extern Obj800A8 *D_800BD06C;
void func_8001F26C();

void func_800800A8(Obj800A8 *arg0) {
    s32 t;
    if (arg0->f7C == 0) {
        arg0->x = D_800BD06C->x;
        arg0->y = D_800BD06C->y;
        arg0->z = D_800BD06C->z;
        arg0->f98 = func_8001F26C;
        arg0->f14 = func_80024394(-0x7D0, 0x7D0) + 0x2AF8;
        arg0->f10 = func_8002D1A0();
        func_8002D4E0(arg0, 0x3E8);
        t = arg0->f34 * 3;
        arg0->f34 = t;
        arg0->f7C = 1;
        arg0->f38 = t;
        arg0->f3C = arg0->f34;
    }
    arg0->fAC = 0;
    arg0->fB4 = 0;
    arg0->fB0 = -1000.0f;
    func_8002D9F8(arg0);
    func_8002D9B0(arg0);
    arg0->f18 += D_800B9ECC << 8;
    arg0->f5C -= D_800B9ECC * 2;
    if (arg0->f5C <= 0) {
        D_800B3964->f70--;
        func_8007FE5C(arg0);
        arg0->fA0(arg0);
    }
}
