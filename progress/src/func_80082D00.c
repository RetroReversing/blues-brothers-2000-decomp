s32 func_80023D58(s32);
void func_80026C04(void *, s32, s32, void *);
void func_8002A360(s32, void *);
void func_80033BC0(void);
void func_800433A8(s32, s32, s32);
void func_80081C10(void);
void func_80087160(s32);
void func_800823F0(void);
void func_80082BE0(void);
void func_800836E4(void);

typedef struct Obj {
    char pad0[0x70];
    s32 x70;
    s32 x74;
    char pad78[0x80 - 0x78];
    s32 x80;
    char pad84[0x9C - 0x84];
    void (*fn9C)(void);
    char padA0[0xAC - 0xA0];
    f32 xAC;
    f32 xB0;
    f32 xB4;
} Obj;

extern Obj *D_800B3960;
extern s32 D_800B87E4;
extern s32 D_800B87EC;
extern s32 D_8014A928[];
extern s32 D_801719A8;
extern s32 D_801719AC;
extern s32 D_801719E0[];
extern s32 D_80171A54;

void func_80082D00(Obj *arg0) {
    if (arg0->x80 == 0) {
        func_80087160(func_80023D58(0x21C));
    }
    if (arg0->x80 == 1) {
        func_80087160(func_80023D58(0x21D));
    }
    if (arg0->x80 == 2) {
        func_80087160(func_80023D58(0x21E));
    }
    if (arg0->x80 == 3) {
        func_80087160(func_80023D58(0x21F));
    }
    if (arg0->x80 == 4) {
        func_80087160(func_80023D58(0x220));
    }
    D_80171A54 = arg0->x80;
    func_80081C10();
    D_800B87E4 = 0;
    D_800B87EC = 0;
    func_8002A360(4, 0);
    func_8002A360(0x1F, 0);
    func_8002A360(0x16, func_800823F0);
    func_8002A360(0x1E, 0);
    arg0->fn9C = func_80082BE0;
    func_800433A8(D_801719A8, 0x18A, 0x100);
    func_800433A8(D_801719AC, 0x19A, 0x100);
    func_80033BC0();
    D_800B3960->fn9C = func_800836E4;
    D_800B3960->x74 = 0;
    D_800B3960->x70 = 1;
    D_800B3960->xB4 = D_8014A928[1] / 2;
    D_800B3960->xB0 = D_8014A928[D_800B3960->x70] / 2;
    D_800B3960->xAC = D_8014A928[D_800B3960->x70] / 2;
    func_80026C04(D_801719E0, 0, 0x50, D_800B3960);
}
