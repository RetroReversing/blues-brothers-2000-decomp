typedef struct Obj {
    u8 p0[0x10]; s32 f10; u8 p1[0x5C]; s32 f70; s32 f74; s32 f78; u8 p2[4]; s32 f80; u8 p3[0xC]; s32 f90;
    u8 p4[0x44]; void *fD8; f32 fDC;
} Obj;
extern s32 approachAngle(s32, s32, s32);
extern s32 func_8002D260(s32);
extern s32 func_8003BF98(Obj *);
extern s32 func_8003C9AC(Obj *, s32, s32, s32);
extern s32 func_80043248(Obj *);
extern s32 func_80043328(Obj *, s32, s32);
extern s32 gCamSpeedScale;

s32 func_80051958(Obj *arg0) {
    f32 temp_fv1;
    s32 var_v0;

    arg0->f10 = approachAngle(arg0->f90, arg0->f10, gCamSpeedScale << 9);
    if ((func_8003C9AC(arg0, 0, 0, 0) != 0) && (arg0->f80 == 0)) {
        temp_fv1 = arg0->fDC;
        if ((8.0f < temp_fv1) && (temp_fv1 < 14.0f)) {
            var_v0 = func_8002D260(arg0->f90 - arg0->f10);
            if (var_v0 < 0) {
                var_v0 = -var_v0;
            }
            if (var_v0 < 0x2328) {
                arg0->f80 = 1;
                func_8003BF98(arg0);
            }
        }
    }
    if (func_80043248(arg0) != 0) {
        if (arg0->f80 == 0) {
            return 1;
        }
        arg0->f78 = 7;
        arg0->f80 = 0;
        arg0->fD8 = func_80043248;
        func_80043328(arg0, arg0->f74 + arg0->f78, 0x100);
        return 0;
    }
    return 0;
}
