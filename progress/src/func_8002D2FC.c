
f32 func_8002D2FC(f32 x) {
    f32 r;
    if (!(x < 0.0f)) {
        r = 1.0f;
        if (!(x > 0.0f)) {
            r = 0.0f;
        }
    } else {
        r = -1.0f;
    }
    return r;
}
