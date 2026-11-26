typedef struct Obj51A74 {
    u8 pad_0[0x40];
    f32 f40;
    u8 pad_44[4];
    f32 f48;
    u8 pad_4C[0x10];
    s32 f5C;
    u8 pad_60[8];
    s32 f68;
    u8 pad_6C[4];
    s32 f70;
    s32 f74;
    s32 f78;
    u8 pad_7C[0x14];
    u8 f90[0x1C];
    f32 fAC;
    u8 pad_B0[0x28];
    s32 (*fD8)(struct Obj51A74 *);
    u8 pad_DC[0x24];
    f32 f100;
    f32 f104;
} Obj51A74;

typedef struct {
    u8 pad_0[0x5C];
    s32 f5C;
    u8 pad_60[8];
    s32 f68;
    u8 pad_6C[0x30];
    void (*f9C)();
} Spawn51A74;

Spawn51A74 *findActor(s32, s32);
void func_8002D3E4(Obj51A74 *, s32);
f32 func_8002D858(Obj51A74 *, void *);
void func_80043328(Obj51A74 *, s32, s32);
s32 func_800516F0(Obj51A74 *);
s32 func_80051958(Obj51A74 *);
void func_80083A28(Obj51A74 *);
void func_80018610();

void func_80051A74(Obj51A74 *arg0) {
    s32 r = 0;
    Spawn51A74 *s;

    if (arg0->fAC == 0.0f) {
        arg0->f74 = 0x129;
        arg0->f78 = 0;
        arg0->fD8 = func_800516F0;
        arg0->f70 = 0;
        arg0->fAC = 0.015f;
        arg0->f104 = 1500.0f;
        arg0->f40 = -703.0f;
        arg0->f48 = 14.0f;
    }
    arg0->f100 = func_8002D858(arg0, arg0->f90);
    if (arg0->fD8 != NULL) {
        r = arg0->fD8(arg0);
    }
    if (r != 0) {
        if (r == 2) {
            arg0->fD8 = func_80051958;
            arg0->f78 = 4;
        } else {
            arg0->fD8 = func_800516F0;
        }
        func_80043328(arg0, arg0->f74 + arg0->f78, 0x100);
    }
    func_80083A28(arg0);
    if (arg0->f78 == 5) {
        s = findActor(0x12D, 0);
        if (s != NULL) {
            s->f9C = func_80018610;
            s->f68 = 4;
            s->f5C = 0;
        }
        func_8002D3E4(arg0, 0);
    }
}
