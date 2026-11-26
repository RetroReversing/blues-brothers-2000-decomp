void func_8000C5B4(void);
void func_8002A360(s32, s32);
void func_8002D124(void);
void func_8002D3E4(void *, s32);
void func_8003C5B4(void);
void func_800433A8(void *, s32, s32);
void func_800340B4();
void func_800393F4();
typedef struct { s32 f0; s32 pad[4]; s32 f14; } S0E0;
extern S0E0 D_800BD0E0;
extern void *D_800B3960;
extern s32 D_800B4CE0;
extern s32 D_800B4D2C;
extern void *D_800BD06C;
extern s32 D_80140230;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

s32 func_8003BF98(void) {
    if (F(D_800BD06C, s32, 0x90) == 0) {
        F(D_800BD06C, s32, 0x6C) = 1;
        F(D_800BD06C, s32, 0xF0) = 0xFF;
        func_8002D3E4(D_800BD06C, 0);
        D_800B4CE0 = 1;
        return D_800BD0E0.f14;
    }
    if (F(D_800BD06C, s32, 0) != 3 || D_800B4D2C != 0) {
        return D_800BD0E0.f14;
    }
    func_8000C5B4();
    if (F(D_800B3960, void *, 0x9C) == func_800340B4) {
        F(D_800B3960, s32, 0xC0) = 0;
    }
    D_800BD0E0.f14--;
    F(D_800BD06C, s32, 0x68) = 4;
    if (D_800BD0E0.f14 <= 0) {
        D_800B4D2C = 1;
        D_800BD0E0.f14 = 0;
        D_800BD0E0.f0--;
        if (D_800BD0E0.f0 < 0) {
            D_800BD0E0.f0 = 0;
        }
        F(D_800BD06C, s32, 0x34) = 0x100;
        F(D_800BD06C, s32, 0x38) = 0x100;
        F(D_800BD06C, s32, 0x3C) = 0x100;
        F(D_800BD06C, s32, 0) = 0x101;
        func_8003C5B4();
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x7D);
        func_8002D124();
    } else if (D_800B4CE0 != 0) {
        F(D_800BD06C, s32, 0xF0) = 0x80;
        F(D_800BD06C, void *, 0x9C) = func_800393F4;
        D_80140230 = 0xC8;
    } else {
        func_800433A8(D_800BD06C, 0x1B, 0x100);
        D_80140230 = 0xC8;
        F(D_800BD06C, s32, 0xF0) = 0xFF;
        F(D_800BD06C, s32, 0) = 0x101;
    }
    D_800B4CE0 = 0;
    return D_800BD0E0.f14;
}
