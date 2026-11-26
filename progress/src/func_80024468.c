f32 sqrtf(f32);
extern f64 D_80000F60;
extern f64 D_80000F68;
extern f32 D_80000F70;
extern f64 D_80000F78;
extern f64 D_80000F80;
extern f32 D_80000F88;
extern f32 D_80000F8C;
extern f32 D_80000F90;
extern f32 D_80000F94;
extern f32 D_80000F98;
extern f32 D_80000F9C;
extern f32 D_80000FA0;
extern f32 D_80000FA4;
extern f32 D_80000FA8;
extern f32 D_80000FAC;
extern f32 D_80000FB0;
extern f32 D_80000FB4;
extern f64 D_80000FB8;
extern f64 D_80000FC0;
extern f32 D_80000FC8;
extern f32 D_80000FCC;
extern f32 D_80000FD0;
extern f32 D_80000FD4;
extern f32 D_80000FD8;
extern f32 D_80000FDC;
extern f32 D_80000FE0;
extern f32 D_80000FE4;
extern f32 D_80000FE8;
extern f32 D_80000FEC;
extern f32 D_80000FF0;
extern f32 D_800AE020[];

#define SERIES(c3, c5, c7, c9, c11) \
    ({ f32 x3, x5, x7, x9, x11; x2 = x * x; x3 = x * x2; x5 = x3 * x2; x7 = x5 * x2; x9 = x7 * x2; x11 = x9 * x2; \
     x - x3 / c3 + x5 / c5 - x7 / c7 + x9 / c9 - x11 / c11; })

f32 func_80024468(f32 x) {
    f64 one;
    f64 d;
    f32 x2;
    f32 res;

    one = D_80000F60;
    d = x;
    if (one <= d || d < D_80000F68) {
        x = D_80000F70 / x;
        d = x;
        if (D_80000F78 < d || d <= D_80000F80) {
            x = (sqrtf(x * x + D_80000F70) - one) / d;
            res = SERIES(D_80000F8C, D_80000F90, D_80000F94, D_80000F98, D_80000F9C); res = D_800AE020[0] * D_80000F88 - 2.0f * res;
        } else {
            res = SERIES(D_80000FA4, D_80000FA8, D_80000FAC, D_80000FB0, D_80000FB4); res = D_800AE020[0] * D_80000FA0 - res;
        }
    } else if (D_80000FB8 < d || d <= D_80000FC0) {
        x = (sqrtf(x * x + D_80000FC8) - one) / d;
        res = 2.0f * SERIES(D_80000FCC, D_80000FD0, D_80000FD4, D_80000FD8, D_80000FDC);
    } else {
        res = SERIES(D_80000FE0, D_80000FE4, D_80000FE8, D_80000FEC, D_80000FF0);
    }
    return res;
}
