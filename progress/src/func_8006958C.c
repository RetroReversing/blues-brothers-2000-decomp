typedef struct G G;
typedef void (*Fn)(G *);
struct G {
    s32 f0; f32 f4; f32 f8; f32 fC; s32 f10; u8 p0[0x88]; Fn f9C; Fn fA0; u8 pA[4]; G *fA8;
};
typedef struct H { u8 p0[0x74]; s32 f74; } H;
extern G *findActor(s32, G *);
extern void debugPrintf();
extern f32 approachF32(f32, f32, f32);
extern s32 approachAngle(s32, s32, s32);
extern void func_8002D604(G *);
extern void func_80069768(G *);
extern G *D_800B3960;
extern H *D_800B3964;

void func_8006958C(G *arg0) {
    f32 temp_fs0;
    f32 temp_fv0;
    G *temp_v0;
    G *var_a0;
    volatile u64 scratch[2];

    arg0->f0 = 0x120;
    temp_v0 = findActor(0x121, NULL);
    if (temp_v0 == NULL) {
        debugPrintf("DropPoint not defined!!!!!");
    }
    D_800B3960->fA8 = temp_v0;
    D_800B3964->f74 = 1;
    temp_fs0 = 50.0f;
    arg0->f4 = approachF32(temp_v0->f4, arg0->f4, temp_fs0);
    arg0->f8 = approachF32(temp_v0->f8, arg0->f8, temp_fs0);
    temp_fv0 = approachF32(temp_v0->fC, arg0->fC, temp_fs0);
    arg0->fC = temp_fv0;
    if ((arg0->f4 == temp_v0->f4) && (arg0->f8 == temp_v0->f8) && (temp_fv0 == temp_v0->fC)) {
        arg0->f10 = approachAngle(0, arg0->f10, 0x1F4);
        var_a0 = findActor(0x120, NULL);
        if (var_a0 == arg0) {
            var_a0 = findActor(0x120, arg0);
        }
        if ((var_a0 != NULL) && (var_a0->fC == arg0->fC) && (var_a0->f4 == arg0->f4)) {
            arg0->f9C = func_80069768;
            arg0->fC = arg0->fC + 250.0f;
            arg0->f8 = arg0->f8 + 100.0f;
            var_a0->fA0(var_a0);
        }
    } else {
        func_8002D604(arg0);
        func_8002D604(arg0);
        func_8002D604(arg0);
    }
}
