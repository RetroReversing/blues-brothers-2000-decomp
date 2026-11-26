typedef struct Obj Obj;
typedef s32 (*Fn)(Obj *);
struct Obj {
    u8 p0[4]; f32 f4; f32 f8; f32 fC; s32 f10; u8 p1[0x5C]; s32 f70; s32 f74; u8 p2[4]; s32 f7C; s32 f80; u8 p3[4];
    s32 f88; s32 f8C; u8 p4[0x18]; Obj *fA8; f32 fAC; u8 p5[4]; f32 fB4; u8 p6[0x20]; Fn fD8;
};
extern s32 func_8002444C();
extern s32 func_80078634(Obj *);
extern s32 func_8007855C(Obj *);
extern void func_80078720();
extern void debugPrintf(char *);
extern void actorSetAnim(Obj *, s32, s32);
extern s32 gSplinePointCount[];

void func_800787E8(Obj *arg0) {
    f32 temp_ft0;
    Fn temp_v0;
    s32 temp_a0;
    s32 temp_v0_2;
    s32 var_s2;
    Obj *temp_s1;

    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        arg0->fD8 = func_80078634;
        arg0->fAC = 0.142f;
        arg0->f74 = 0;
        if (arg0->f80 == 0) {
            func_80078720();
        }
        temp_ft0 = (f32) arg0->f80;
        temp_ft0 = temp_ft0 * 0.01f;
        temp_a0 = arg0->f70;
        if (!(temp_a0 & 1)) {
            arg0->fB4 = 0.0f;
            arg0->f10 = 0x8000;
            arg0->fB4 = temp_ft0 + arg0->fB4;
        } else {
            arg0->fB4 = (f32) (gSplinePointCount[temp_a0] - 1) - temp_ft0;
            arg0->fAC = -arg0->fAC;
            arg0->f10 = 0;
        }
    }
    temp_s1 = arg0->fA8;
    if (temp_s1 == NULL) {
        debugPrintf("punk has no skateboard!");
    }
    temp_v0 = arg0->fD8;
    if (temp_v0 != NULL) {
        var_s2 = temp_v0(arg0);
    }
    if (var_s2 != 0) {
        temp_v0_2 = arg0->f74;
        if (temp_v0_2 == 0) {
            arg0->fD8 = func_8007855C;
            arg0->f74 = (func_8002444C() & 1) + 1;
        } else if ((arg0->f74 >= 0) && (temp_v0_2 < 3)) {
            arg0->fD8 = func_80078634;
            arg0->f74 = 0;
        } else {
            debugPrintf("[Error] you're a punk!");
        }
        actorSetAnim(arg0, arg0->f74 + 0x11D, 0x100);
        actorSetAnim(temp_s1, arg0->f74 + 0x120, 0x100);
        arg0->f88 = 0;
        arg0->f8C = 0;
    }
    temp_s1->f4 = arg0->f4;
    temp_s1->f8 = arg0->f8;
    temp_s1->fC = arg0->fC;
    temp_s1->f10 = arg0->f10;
}
