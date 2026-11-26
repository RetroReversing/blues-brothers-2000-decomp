typedef struct G G;
struct G {
    u8 p0[0x10]; s32 f10; u8 p1[0x54]; s32 f68; u8 p2[0x10]; s32 f7C; u8 p3[8]; s32 f88; u8 p4[0x1C]; G *fA8;
};
extern f32 getCameraTargetDist(G *, f32, s32);
extern s32 func_80023DBC(s32);
extern void func_80052A5C(s32);
extern s32 startStoryDialog(s32, void *, G *);
extern s32 findActor(s32, s32);
extern void func_8001B990(s32, s32);
extern void animStepKeys(G *);
extern void func_8007A2E8(G *);
extern u8 D_80008398[];
extern u8 D_800083A0[];
extern u8 D_800083A8[];
extern u8 D_800BCFED;

void func_8005668C(G *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;
    s32 temp_s1;
    s32 temp_s2;
    s32 var_v0;
    G *temp_a0;

    if (arg0->f88 == 0) {
        temp_a0 = arg0->fA8;
        arg0->f88 = 1;
        if (temp_a0 != NULL) {
            temp_a0->f10 = arg0->f10;
            temp_a0->f68 = 4;
        }
    }
    temp_fs1 = 400.0f;
    temp_fs0 = getCameraTargetDist(arg0, temp_fs1, 0);
    temp_s2 = func_80023DBC(0xE99);
    if (arg0->f7C == 0) {
        if (temp_fs0 < temp_fs1) {
            func_80052A5C(0x568);
            if (startStoryDialog(temp_s2, D_80008398, arg0) != 0) {
                arg0->f7C = 1;
            }
        }
    }
    temp_s1 = arg0->f7C;
    if ((temp_s1 == 1) && (findActor(0x801, 0) == 0)) {
        if (D_800BCFED == temp_s1) {
            func_8001B990(0x200, 0x1F);
            startStoryDialog(temp_s2, D_800083A0, arg0);
            var_v0 = 2;
        } else {
            startStoryDialog(temp_s2, D_800083A8, arg0);
            var_v0 = 3;
        }
        arg0->f7C = var_v0;
    }
    if (arg0->f7C == 2) {
        if (findActor(0x801, 0) == 0) {
            arg0->f7C = 5;
        }
    }
    if ((arg0->f7C == 3) && (findActor(0x801, 0) == 0)) {
        arg0->f7C = 5;
    }
    animStepKeys(arg0);
    animStepKeys(arg0->fA8);
    func_8007A2E8(arg0);
}
