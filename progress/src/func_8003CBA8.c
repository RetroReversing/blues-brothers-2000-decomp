typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    s32 f0; u8 p0[4]; f32 f8; u8 p1[0x54]; s32 f60; u8 p2[0x2C]; s32 f90; u8 p3[8]; Fn f9C;
};
extern void actorSetAnim(G *, s32, s32);
extern void func_8003BC40(G *);
extern void func_8002A360(s32, s32);
extern void func_8002D124();
extern G *func_80015738(G *);
extern G *gCameraTarget;
extern s32 D_800BD170[];

void func_8003CBA8(void) {
    f32 temp_fs0;
    f32 temp_fs1;
    s32 var_s1;
    G *temp_s0;
    G *temp_v0;

    temp_s0 = gCameraTarget;
    if (temp_s0->f90 == 1) {
        actorSetAnim(temp_s0, 0x18, 0x100);
        temp_s0->f9C = func_8003BC40;
        temp_s0->f0 = 0x101;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xB);
        func_8002D124();
    }
    var_s1 = 0;
    temp_fs1 = 50.0f;
    temp_fs0 = 100.0f;
    do {
        func_80015738(temp_s0)->f60 = D_800BD170[3];
        temp_v0 = func_80015738(temp_s0);
        temp_v0->f60 = D_800BD170[2];
        temp_v0->f8 = temp_v0->f8 + temp_fs1;
        temp_v0 = func_80015738(temp_s0);
        var_s1 += 1;
        temp_v0->f60 = D_800BD170[1];
        temp_v0->f8 = temp_v0->f8 + temp_fs0;
    } while (var_s1 < 0xA);
}
