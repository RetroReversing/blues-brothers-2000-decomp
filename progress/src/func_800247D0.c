f32 func_80024468(f32);
extern f32 D_800AE020;

f32 func_800247D0(f32 y, f32 x) {
    s32 q;
    f32 a;

    if (y == 0.0f) {
        if (x < 0.0f) {
            return D_800AE020;
        }
        return 0.0f;
    }
    if (x == 0.0f) {
        if (y < 0.0f) {
            return D_800AE020 * 3.0f * 0.5f;
        }
        return D_800AE020 * 0.5f;
    }
    q = 0;
    if (y < 0.0) {
        q = 1;
        y = -y;
    }
    if (x < 0.0) {
        q |= 2;
        x = -x;
    }
    a = func_80024468(y / x);
    switch (q) {
    case 0:
        return a;
    case 1:
        return D_800AE020 + D_800AE020 - a;
    case 2:
        return D_800AE020 - a;
    case 3:
        return D_800AE020 + a;
    }
    return 0.0f;
}
