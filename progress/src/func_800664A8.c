typedef struct { f32 m[4][4]; } Mat44;
s32 func_8002492C(f32, f32);
void func_80033DC4(void *);
void func_80034F50(void *);
void func_8004C020(Mat44 *, s32, s32, s32, s32, s32, s32, f32 *, f32 *, f32 *);
void func_8004DF94(Mat44 *, f32, f32, f32);
void func_8004E008(Mat44 *, f32);
void func_800340B4(void);
extern u8 *D_800B3960;
extern Mat44 D_800B76E0;
extern u8 *D_800BD06C;

void func_800664A8(u8 *arg0) {
    Mat44 m;
    f32 x;
    f32 y;
    f32 z;
    s32 dir;
    f32 angle;

    dir = func_8002492C(*(f32 *)(D_800BD06C + 4) - *(f32 *)(arg0 + 4), *(f32 *)(D_800BD06C + 0xC) - *(f32 *)(arg0 + 0xC));
    angle = (f32)((f32)dir * 6.283185307179586) * 1.52587890625e-05;
    m = D_800B76E0;
    func_8004DF94(&m, *(f32 *)(D_800BD06C + 4), *(f32 *)(D_800BD06C + 8), *(f32 *)(D_800BD06C + 0xC));
    func_8004E008(&m, angle);
    func_8004DF94(&m, 0.0f, 50.0f, 800.0f);
    func_8004C020(&m, 0, 0, 0, 0, 0, 0, &x, &y, &z);
    *(f32 *)(D_800B3960 + 4) = x;
    *(f32 *)(D_800B3960 + 8) = y;
    *(f32 *)(D_800B3960 + 0xC) = z;
    *(s32 *)(D_800B3960 + 0x10) = dir;
    *(s32 *)(D_800B3960 + 0xA8) = 0;
    func_80034F50(D_800B3960);
    func_80033DC4(D_800B3960);
    *(s32 *)(D_800B3960 + 0x6C) = 0;
    *(void **)(D_800B3960 + 0x9C) = func_800340B4;
}
