typedef struct Obj {
    s32 x0;
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x6C - 0x14];
    s32 x6C;
} Obj;

typedef struct Level {
    char pad0[0x1C];
    u8 *x1C;
} Level;

s32 func_800238CC(s32);
s32 func_800252D8(void);
s32 func_8002D260(s32);
s32 func_8002D298(s32, s32, s32);
void func_8002710C(s32, s32, s32, s32);
void func_8002713C(s32, s32);
void func_80027158(s32, s32);
void func_800271A8(s32, s32);
void func_800271D8(s32);
void func_800272AC(f32);
void func_80028710(u8 *);
void func_8002889C(char *);
int sprintf(char *, const char *, ...);

extern char D_80000AE8[];
extern char D_80000B04[];
extern char D_80000B0C[];
extern char D_80000B14[];
extern char D_80000B18[];
extern char D_80000B1C[];
extern char D_80000B20[];
extern char D_80000B24[];
extern char D_80000B28[];
extern char D_80000B38[];
extern Level D_800AA134[];
extern s32 D_800AB9B4;
extern s32 D_800AB9B8;
extern s32 D_800B83B4;
extern s32 D_800B9EA4;
extern s32 D_800B9ECC;
extern s32 D_800BD058;
extern Obj *D_800BD06C;
extern s32 D_800BD0FC;
extern s32 D_800BD100;
extern s32 D_800BD114;
extern s32 D_80107040;
extern s32 D_801073B0;
extern s32 D_801073C0;
extern s32 D_801402F8;
extern Obj *D_8014AAB0;
extern s32 D_8017826C;
extern s32 D_80178270;

void func_80019620(Obj *arg0) {
    char buf[0x40];
    u8 *name;
    s32 n;
    s32 a;
    s32 t;
    s32 m;
    s32 x;
    s32 y;

    name = D_800AA134[D_800BD100].x1C;
    if (D_800AB9B4 != 0) {
        return;
    }
    if (D_8014AAB0->x0 == 0x145) {
        return;
    }
    x = D_801073B0;
    y = D_801073C0;
    if (x < 0) {
        x = -x;
    }
    n = x < 11;
    y = abs(y);
    n ^= 1;
    if (y > 10) {
        n++;
    }
    if (D_80107040 != 0) {
        n++;
    }
    if (n == 0) {
        arg0->x6C = func_8002D298(0xFF, arg0->x6C, D_800B9ECC * 8);
    } else {
        if (arg0->x6C == 0) {
            return;
        }
        arg0->x6C = func_8002D298(0, arg0->x6C, D_800B9ECC * 8);
    }
    func_8002710C(0xFF, 0xFF, 0xFF, arg0->x6C);
    name += D_800BD0FC * 0x3C;
    func_800271A8(0xD7, 4);
    func_8002889C(D_80000B04);
    func_800271D8(D_80178270);
    func_800271A8(0xD7, 5);
    func_8002889C(D_80000B0C);
    func_800271D8((func_800252D8() + 0x200) / 1024);
    func_80027158(0xFA, 0x64);
    func_8002889C(D_80000B14);
    func_80027158(0x10E, 0x64);
    func_800271D8(D_800BD114);
    D_800BD114 = 0;
    func_80027158(0xFA, 0x6E);
    func_8002889C(D_80000B18);
    func_80027158(0x10E, 0x6E);
    func_800271D8(D_800BD058);
    D_800BD058 = 0;
    func_80027158(0xFA, 0x78);
    func_8002889C(D_80000B1C);
    func_80027158(0x10E, 0x78);
    func_800271D8(D_8017826C);
    func_80027158(0xFA, 0x82);
    func_8002889C(D_80000B20);
    func_80027158(0x10E, 0x82);
    func_800271D8(D_801402F8);
    D_801402F8 = 0;
    func_80027158(0xF0, 0x8C);
    func_8002889C(D_80000B24);
    func_80027158(0x10E, 0x8C);
    func_800271D8(D_800B83B4);
    D_800B83B4 = 0;
    if (D_800BD06C != NULL) {
        func_80027158(0x28, 0x64);
        func_800272AC(D_800BD06C->x4);
        func_80027158(0x28, 0x6E);
        func_800272AC(D_800BD06C->x8);
        func_80027158(0x28, 0x78);
        func_800272AC(D_800BD06C->xC);
        func_80027158(0x28, 0x8C);
        func_800271D8(func_8002D260(D_800BD06C->x10));
    }
    func_8002713C(0x1E, 0xC8);
    t = D_800B9EA4 / 100;
    m = t / 60;
    sprintf(buf, D_80000B28, m / 60, m % 60, t % 60);
    func_8002889C(buf);
    func_8002713C(0xA0, 0xD2);
    func_80028710(name + 4);
    func_8002710C(0x60, 0xFF, 0xFF, 0xFF);
    func_8002713C(0x1E, 0x3C);
    func_8002889C(D_80000AE8);
    func_800271D8(func_800238CC(0));
    func_8002889C(D_80000B38);
    func_800271D8(D_800AB9B8);
}
