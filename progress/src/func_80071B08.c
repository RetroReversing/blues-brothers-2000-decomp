typedef struct Actor71B08 {
    s32 unk0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    u8 pad14[0x40 - 0x14];
    f32 unk40[3];
    u8 pad4C[0x64 - 0x4C];
    s32 unk64;
    u8 pad68[0x9C - 0x68];
    void (*unk9C)(struct Actor71B08 *);
} Actor71B08;

s16 sins(u16);
s16 coss(u16);
f32 func_8002DD60(f32);
void func_8002E100(f32 *, f32 *);
f32 func_8002E0D0(f32 *, f32 *);
f32 *func_8002E1FC(f32 *, f32 *, f32 *);
void func_8002E1CC(f32 *, f32 *, f32);
void func_8002E234(f32 *, f32 *, f32 *);
void func_8002D620(Actor71B08 *);
void func_80033BDC(s32);
f32 func_800379C8(Actor71B08 *);
void func_800433A8(Actor71B08 *, s32, s32);
Actor71B08 *func_800232B4(s32, s32, s32, s32);
void func_80071ACC(Actor71B08 *);
void func_80080AF0(Actor71B08 *);
extern Actor71B08 *D_800B3960;
extern Actor71B08 *D_800BD06C;

void func_80071B08(Actor71B08 *arg0) {
    f32 hit[3];
    f32 dir[3];
    f32 rel[3];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lim;
    f32 d0;
    f32 d1;
    f32 lo;
    f32 hi;
    f32 t;
    f32 frac;
    Actor71B08 *a;

    dx = D_800BD06C->x - arg0->x;
    dy = D_800BD06C->y - arg0->y;
    dz = D_800BD06C->z - arg0->z;
    lim = 2000.0f;
    if (lim < func_8002DD60(dx)) {
        return;
    }
    if (lim < func_8002DD60(dy)) {
        return;
    }
    if (lim < func_8002DD60(dz)) {
        return;
    }
    dir[0] = sins(arg0->unk10);
    dir[1] = 0.0f;
    dir[2] = coss(arg0->unk10);
    func_8002E100(dir, dir);
    d0 = func_8002E0D0(dir, func_8002E1FC(rel, D_800BD06C->unk40, &arg0->x));
    d1 = func_8002E0D0(dir, func_8002E1FC(rel, &D_800BD06C->x, &arg0->x));
    lo = arg0->x + (-(coss(arg0->unk10) * 200) >> 15);
    hi = arg0->x + ((coss(arg0->unk10) * 25) >> 12);
    if (hi < lo) {
        t = lo;
        lo = hi;
        hi = t;
    }
    if (0.0f <= d0 && d1 < 0.0f) {
        frac = d0 / (d0 - d1);
        func_8002E1FC(rel, &D_800BD06C->x, D_800BD06C->unk40);
        func_8002E1CC(rel, rel, frac);
        func_8002E234(hit, rel, D_800BD06C->unk40);
        if (lo <= hit[0] && hit[0] <= hi && arg0->y - 50.0f <= hit[1] && hit[1] < hit[1] + 400.0f) {
            D_800B3960->unk10 = arg0->unk10;
            func_80033BDC(2);
            D_800BD06C->x = arg0->x + ((sins(arg0->unk10 - 0x8000) * 75) >> 14);
            D_800BD06C->z = arg0->z + ((coss(arg0->unk10 - 0x8000) * 75) >> 14);
            D_800BD06C->unk9C = func_80071ACC;
            D_800BD06C->unk64 = 100;
            func_8002D620(D_800BD06C);
            D_800BD06C->y = func_800379C8(D_800BD06C);
            func_800433A8(D_800BD06C, 1, 0x100);
            a = func_800232B4(1, 0, 0, 0);
            a->unk9C = func_80080AF0;
            a->unk9C(a);
        }
    }
    if (d0 <= 0.0f && 0.0f < d1) {
        frac = d0 / (d0 - d1);
        func_8002E1FC(rel, &D_800BD06C->x, D_800BD06C->unk40);
        func_8002E1CC(rel, rel, frac);
        func_8002E234(hit, rel, D_800BD06C->unk40);
        if (lo <= hit[0] && hit[0] <= hi && arg0->y - 50.0f <= hit[1] && hit[1] < hit[1] + 400.0f) {
            D_800B3960->unk10 = arg0->unk10 + 0x8000;
            func_80033BDC(0);
            D_800BD06C->x = arg0->x + ((sins(arg0->unk10) * 75) >> 14);
            D_800BD06C->z = arg0->z + ((coss(arg0->unk10) * 75) >> 14);
            D_800BD06C->unk9C = func_80071ACC;
            D_800BD06C->unk64 = 100;
            D_800BD06C->y = func_800379C8(D_800BD06C);
            func_800433A8(D_800BD06C, 1, 0x100);
            func_8002D620(D_800BD06C);
            a = func_800232B4(1, 0, 0, 0);
            a->unk9C = func_80080AF0;
            a->unk9C(a);
        }
    }
}
