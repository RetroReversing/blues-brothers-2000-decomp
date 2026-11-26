typedef struct { u8 pad[0x30]; } Key;
f32 func_80080EB0(Key *, f32);
f32 func_80080EEC(Key *, f32);
f32 func_80080F28(Key *, f32);
extern s32 gSplinePointCount[];
extern u8 gSplineClosed[];
extern Key *gSplineSegs[];

s32 func_80081AC0(f32 *out, s32 i, f32 t) {
    f32 len;
    s32 clamped;
    s32 n;
    Key *key;

    len = (f32)gSplinePointCount[i] - 1.0 + gSplineClosed[i];
    clamped = 0;
    if (t < 0.0f) {
        t = 0.0f;
        clamped = 1;
    }
    if (len <= t) {
        clamped = 1;
        t = len - 0.001;
    }
    n = t;
    t -= n;
    key = gSplineSegs[i] + n;
    out[0] = func_80080EB0(key, t);
    out[1] = func_80080EEC(key, t);
    out[2] = func_80080F28(key, t);
    return clamped;
}
