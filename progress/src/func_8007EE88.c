typedef struct O7EE88 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 pad10[0xC0 - 0x10];
    s32 fC0;
} O7EE88;
s32 func_80013654(O7EE88 *);
f32 func_8002D858(O7EE88 *, s32);
extern O7EE88 *gCameraTarget;

s32 func_8007EE88(O7EE88 *arg0) {
    f32 d;
    f32 k;
    f32 dx;
    f32 dz;
    O7EE88 *o;

    d = func_8002D858(arg0, 0);
    arg0->fC0 = 0;
    if (d == 0.0) {
        return 0;
    }
    {
        if (d < 800.0) {
            k = 800.0 - d;
            o = gCameraTarget;
            dx = (arg0->f4 - o->f4) * k / d;
            dz = (arg0->fC - o->fC) * k / d;
            o->f4 -= dx;
            o->fC -= dz;
            arg0->fC0 |= 1;
        }
        if (d < 1500.0f && func_80013654(arg0) != 0) {
            arg0->fC0 |= 0xF;
        }
    }
    return 0;
}
