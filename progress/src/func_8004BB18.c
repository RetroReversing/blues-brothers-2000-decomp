f32 func_80095DC0(f32);
f32 __cosf(f32);

void func_8004BB18(f32 mf[4][4], f32 r, f32 p, f32 h) {
    f32 sr;
    f32 cr;
    f32 sp;
    f32 cp;
    f32 sh;
    f32 ch;

    sr = func_80095DC0(r);
    cr = __cosf(r);
    sp = func_80095DC0(p);
    cp = __cosf(p);
    sh = func_80095DC0(h);
    ch = __cosf(h);
    mf[0][0] = cr * ch + sr * sp * sh;
    mf[0][1] = sr * cp;
    mf[0][2] = cr * -sh + sr * sp * ch;
    mf[0][3] = 0.0f;
    mf[1][0] = -sr * ch + cr * sp * sh;
    mf[1][1] = cr * cp;
    mf[1][2] = -sr * -sh + cr * sp * ch;
    mf[1][3] = 0.0f;
    mf[2][0] = cp * sh;
    mf[2][1] = -sp;
    mf[2][2] = cp * ch;
    mf[2][3] = 0.0f;
    mf[3][0] = 0.0f;
    mf[3][1] = 0.0f;
    mf[3][2] = 0.0f;
    mf[3][3] = 1.0f;
}
