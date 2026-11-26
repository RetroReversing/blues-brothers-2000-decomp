typedef struct Cfg908D0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad10[0x28 - 0x10];
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3C;
} Cfg908D0;
typedef struct A908D0 {
    s32 a;
    s32 b;
    s32 c;
} A908D0;
typedef struct B908D0 {
    s32 a;
    s32 b;
    s32 c;
    s8 d;
    s32 e;
    s32 f;
} B908D0;
typedef struct C908D0 {
    s32 p;
    s32 q;
} C908D0;

s32 func_8008F9A0(void *, A908D0 *);
s32 func_800902A0(s32, s32);
s32 func_80090B90(s32, s32, s32, s32);
s32 func_80090CA0(s32);
s32 func_80090CEC(void);
s32 osAiSetFrequency(s32);
void osCreateThread(void *, s32, void (*)(void *), void *, void *, s32);
void osStartThread(void *);
void func_80090A0C(void *);
extern char D_8017B2E0[];
extern s32 D_8017B490;
extern C908D0 *D_8017B494;
extern s32 D_8017B498;
extern char D_8017B4A0[];

void func_800908D0(Cfg908D0 *arg0, s32 arg1, s8 arg2) {
    A908D0 a;
    B908D0 b;
    s32 n;
    u32 i;

    a.a = a.b = arg0->f4;
    a.c = arg0->f28;
    b.a = func_800902A0(arg0->f38, arg0->f3C);
    b.d = arg2;
    b.c = osAiSetFrequency(arg0->f2C);
    b.b = func_80090CEC();
    func_8008F9A0(D_8017B4A0, &a);
    n = func_80090B90(arg0->f34, b.c, arg1, 30);
    D_8017B498 = func_80090CA0(arg0->f30 * 8);
    D_8017B494 = (C908D0 *)func_80090CA0(0x18);
    for (i = 0; i < 3; i++) {
        D_8017B494[i].p = func_80090CA0(n * 4);
    }
    D_8017B490 = func_80090CA0(0x2000);
    osCreateThread(D_8017B2E0, 3, func_80090A0C, 0, (void *)(D_8017B490 + 0x2000), arg0->fC);
    osStartThread(D_8017B2E0);
}
