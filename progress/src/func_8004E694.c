extern f32 func_8004E694(s32, s32, s32, f32);

f32 func_8004E694(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    f32 r;
    f32 t;
    s32 *hi;
    s32 *lo;

    if (arg1 == 1) {
        r = 0.0f;
        if (((f32) ((s32 *) arg2)[arg0] <= arg3) && (arg3 < (f32) ((s32 *) arg2)[arg0 + 1])) {
            r = 1.0f;
        }
    } else {
        hi = (s32 *) (((arg0 + arg1) * 4) + arg2);
        lo = (s32 *) ((arg0 * 4) + arg2);
        if (hi[-1] == lo[0]) {
            if (hi[0] == lo[1]) {
                r = 0.0f;
            } else {
                t = func_8004E694(arg0 + 1, arg1 - 1, arg2, arg3);
                r = (((f32) hi[0] - arg3) / (f32) (hi[0] - lo[1])) * t;
            }
        } else if (hi[0] == lo[1]) {
            t = func_8004E694(arg0, arg1 - 1, arg2, arg3);
            r = ((arg3 - (f32) lo[0]) / (f32) (hi[-1] - lo[0])) * t;
        } else {
            t = func_8004E694(arg0, arg1 - 1, arg2, arg3);
            r = (((arg3 - (f32) lo[0]) / (f32) (hi[-1] - lo[0])) * t) + ((((f32) hi[0] - arg3) / (f32) (hi[0] - lo[1])) * func_8004E694(arg0 + 1, arg1 - 1, arg2, arg3));
        }
    }
    return r;
}
