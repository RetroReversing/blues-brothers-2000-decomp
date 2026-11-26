s32 updateCameraView(void *);
s32 func_8002D260(s32);
s32 func_80034FEC(void *, s32 *);
s32 func_80036FB8(void *, s32);
extern s32 *gCameraTarget;

void func_80019D6C(void *arg0_in) {
    s32 sp10[3];
    s32 *var_v1;
    s32 temp_v0;

    var_v1 = (*(s32 **)((s8 *)arg0_in + 0xA8));
    if (var_v1 == NULL) {
        var_v1 = gCameraTarget;
    } else if (*var_v1 == 0) {
        var_v1 = gCameraTarget;
        (*(s32 **)((s8 *)arg0_in + 0xA8)) = NULL;
    }
    sp10[0] = (s32) (*(f32 *)((s8 *)var_v1 + 4));
    sp10[1] = (s32) (*(f32 *)((s8 *)var_v1 + 8) + 200.0f);
    sp10[2] = (s32) (*(f32 *)((s8 *)var_v1 + 0xC));
    func_80034FEC(arg0_in, sp10);
    temp_v0 = func_8002D260((*(s32 *)((s8 *)arg0_in + 0x10)));
    (*(s32 *)((s8 *)arg0_in + 0x10)) = temp_v0;
    if (temp_v0 < -0x4BB8) {
        (*(s32 *)((s8 *)arg0_in + 0x10)) = -0x4BB8;
    }
    if ((*(s32 *)((s8 *)arg0_in + 0x10)) >= -0x3447) {
        (*(s32 *)((s8 *)arg0_in + 0x10)) = -0x3448;
    }
    updateCameraView(arg0_in);
    func_80036FB8(arg0_in, 0xF);
}
