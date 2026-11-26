f32 func_80024468(f32);
f32 sqrtf(f32);
extern f32 D_800AE020;

f32 func_80024984(f32 x) {
    if (x == 1.0) {
        return D_800AE020 * 0.5;
    }
    if (x == -1.0) {
        return D_800AE020 * -0.5;
    }
    return func_80024468(x / sqrtf(1.0 - x * x));
}
