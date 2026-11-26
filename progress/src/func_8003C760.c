void syncActorPrevPos(void);
f32 func_8002E0D0(f32 *, f32 *);
void func_8002E1CC(void *, f32 *, f32);
void func_8002E234(f32 *, f32 *, void *);
f32 func_800379C8(void *);
void animStepKeys(void *);
void func_80043328(void *, s32, s32);
void func_800393F4(void *);
extern f32 D_80001824;
extern f64 D_80001828;
extern f32 D_80001830;
extern f64 D_80001838;
extern f64 D_80001840;
extern f32 D_800B4C1C[];
extern f32 D_800B4C20[];
extern f32 D_800B9EC4[];
extern s32 D_80140200[];
extern f32 D_8014022C[];

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x40 - 0x10];
    f32 x40;
    f32 x44;
    f32 x48;
    f32 x4C;
    f32 x50;
    f32 x54;
    char pad58[0x90 - 0x58];
    s32 x90;
    char pad94[0x9C - 0x94];
    void (*fn9C)(void *);
} Obj;

void func_8003C760(Obj *arg0) {
    f32 v[3];
    char m[0x10];
    f64 none;
    f32 up;
    f32 dt;
    f32 y;

    syncActorPrevPos();
    if (arg0->x50 < D_80001824) {
        func_80043328(arg0, 0x29, 0x100);
    } else {
        func_80043328(arg0, 1, 0x100);
    }
    animStepKeys(arg0);
    none = D_80001828;
    up = D_80001830;
    v[0] = 0.0f;
    v[2] = 0.0f;
    v[1] = up;
    if (D_8014022C[0] != none) {
        func_8002E1CC(m, D_800B4C1C, func_8002E0D0(v, D_800B4C1C) * D_80001838);
        func_8002E234(v, v, m);
    }
    if (v[1] >= 0.0) {
        v[1] = up;
    }
    y = v[0];
    dt = D_800B9EC4[0];
    arg0->x4C += y * dt;
    arg0->x50 += v[1] * dt;
    arg0->x54 += v[2] * dt;
    arg0->x4 += dt * arg0->x4C;
    arg0->x8 += dt * arg0->x50;
    arg0->xC += dt * arg0->x54;
    y = func_800379C8(arg0);
    D_8014022C[0] = y;
    if (y == none) {
        arg0->x4 = arg0->x40;
        arg0->x8 = arg0->x44;
        arg0->xC = arg0->x48;
        return;
    }
    if (arg0->x8 <= y) {
        arg0->x90 = 1;
        arg0->x8 = y;
        if (D_80001840 <= D_800B4C20[0]) {
            arg0->fn9C = func_800393F4;
            D_80140200[0] = 0;
        }
    } else {
        D_800B4C1C[0] = 0.0f;
        D_800B4C1C[1] = 0.0f;
        D_800B4C1C[2] = 0.0f;
        arg0->x90 = 0;
    }
}
