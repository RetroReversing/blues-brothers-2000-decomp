typedef struct Obj { char pad[0x1C]; f32 y; } Obj;
typedef struct Act { char pad[0xDC]; f32 y; Obj *obj; } Act;
void animSampleKeys(Obj *, f32);
extern s32 gCamSpeedScale;
extern s32 D_801402F8;

s32 func_800430F4(Act *arg0) {
    s32 c, d, var_v0;
    f32 x, arg, old, now;
    Obj *temp_s0;

    temp_s0 = arg0->obj;
    if (temp_s0 != 0) {
        c = D_801402F8;
        d = gCamSpeedScale;
        x = temp_s0->y;
        D_801402F8 = c + 1;
        arg = x + (f32)(d / 2);
        old = temp_s0->y;
        animSampleKeys(temp_s0, arg);
        now = temp_s0->y;
        var_v0 = 1;
        arg0->y = now;
        if (!(now < old)) var_v0 = 0;
    } else {
        var_v0 = 0;
    }
    return var_v0;
}
