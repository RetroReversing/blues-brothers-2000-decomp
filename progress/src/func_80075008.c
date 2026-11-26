typedef struct Obj Obj;
struct Obj {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x50];
    s32 unk68;
    u8 pad6C[0x30];
    void (*unk9C)(Obj *);
    void (*unkA0)(Obj *);
    u8 padA4[8];
    f32 unkAC;
    s32 padB0;
    f32 unkB4;
    s32 padB8;
    s32 unkBC;
    s32 unkC0;
};

Obj *findActor(s32, s32);
s32 func_8002492C(f32, f32);
s32 approachAngle(s32, s32, s32);
f32 func_8002D858(Obj *, s32);
void func_8003C140(Obj *);
void func_8003C37C(Obj *);
void animStepKeys(Obj *);
void func_80074FB4(Obj *);
f32 func_800812B4(s32, f32 *, s32, s32);
s32 func_80081990(f32 *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
void func_800853E8(Obj *);
extern Obj *D_800B3964;
extern s32 D_800B83C8;
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;
extern s32 D_800BD0E0;
extern s32 D_800BD100;
extern f32 D_801700D0;

s32 func_80075008(Obj *arg0) {
    f32 v[3];
    Obj *p;
    f32 dx;
    f32 dz;
    f32 d;
    f32 e;

    if (D_800B3964->unkC0 == 0) {
        arg0->unk68 = -1;
        arg0->unkBC = 0;
        return 1;
    }
    animStepKeys(arg0);
    func_800853E8(arg0);
    arg0->unk68 = 4;
    if (gCameraTarget->unk9C == func_8003C37C) {
        if (D_800BD0E0 > 0) {
            arg0->unk9C = func_80074FB4;
        } else {
            arg0->unk9C = animStepKeys;
        }
        return 1;
    }
    arg0->unkB4 += arg0->unkAC;
    p = findActor(0x13A, 0);
    if (p != NULL) {
        dx = p->x - arg0->x;
        dz = p->z - arg0->z;
        if (sqrtf(dx * dx + dz * dz) < 350.0f) {
            arg0->unkBC = 1;
        }
    }
    if (func_80081990(&arg0->x, 6, arg0->unkB4) != 0) {
        arg0->unkA0(arg0);
        return 1;
    }
    func_80081AC0(v, 6, arg0->unkB4);
    arg0->unk10 = approachAngle(arg0->unk10, func_8002492C(v[0], v[2]), gCamSpeedScale << 8);
    if (D_800BD100 == 1) {
        arg0->unk14 = func_8002492C(v[1], sqrtf(v[0] * v[0] + v[2] * v[2]));
    }
    d = func_8002D858(arg0, 0);
    D_801700D0 = d;
    e = func_800812B4(6, &gCameraTarget->x, 0, 0);
    if (d < 420.0f || e < arg0->unkB4) {
        if (arg0->unkBC == 0) {
            D_800B83C8 = 0;
            func_8003C140(gCameraTarget);
            arg0->unk9C = func_80074FB4;
        }
        return 1;
    }
    return 0;
}
