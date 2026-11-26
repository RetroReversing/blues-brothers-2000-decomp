s32 randomRange(s32, s32);
s32 func_8002492C(f32, f32);
void func_8002A360(s32, s32);
s32 tickActorTimer(void *);
void animStepKeys(void *);
void actorSetAnim(void *, s32, s32);
void func_80081990(void *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
extern f64 D_80008318;
extern f32 D_80008320;
extern s32 gSplinePointCount[];
void func_80055A94(void *);

typedef struct {
    u8 pad0[4];
    u8 unk4[0xC];
    s32 unk10;
    u8 pad14[0x50];
    s32 unk64;
    u8 pad68[8];
    s32 unk70;
    u8 pad74[0x28];
    void (*unk9C)(void *);
    u8 padA0[0x14];
    f32 unkB4;
    u8 padB8[8];
    s32 unkC0;
    u8 padC4[0x2C];
    s32 unkF0;
} Obj;

void func_80055AD4(Obj *arg0) {
    f32 v[3];
    f32 lim;

    if (arg0->unkC0 & ~1) {
        actorSetAnim(arg0, 0x4D, 0x100);
        arg0->unk9C = func_80055A94;
        arg0->unkF0 = 0xFF;
        return;
    }
    if (tickActorTimer(arg0) != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x6A);
        arg0->unk64 = randomRange(0xC8, 0x1F4);
    }
    animStepKeys(arg0);
    arg0->unkB4 += 0.05;
    lim = gSplinePointCount[arg0->unk70] - 1.0f;
    if (lim <= arg0->unkB4) {
        arg0->unkB4 -= lim;
    }
    func_80081990(arg0->unk4, arg0->unk70, arg0->unkB4);
    func_80081AC0(v, arg0->unk70, arg0->unkB4);
    arg0->unk10 = func_8002492C(v[0], v[2]);
}
