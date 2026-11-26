s32 func_8002492C(f32, f32);
s32 func_8002D204(s32, s32, s32);
s32 func_8002D260(s32);
void func_8004303C(void *);
void func_80081990(void *, s32, f32);
void func_80081AC0(f32 *, s32, f32);
s32 func_80084318(void *);
s16 *func_800851D8(void *);
extern s32 D_800B9ECC;
extern s32 D_8014A928[];
extern void *D_8014AAB0;
extern f32 D_801700D0;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

s32 func_80084368(void *arg0) {
    f32 v[3];
    s32 hit;
    f32 pos;
    s32 idx;
    s32 a;

    hit = 0;
    pos = F(arg0, f32, 0xB4) + F(arg0, f32, 0xAC);
    idx = F(arg0, s32, 0x70);
    F(arg0, f32, 0xB4) = pos;
    if (F(arg0, s32, 0xBC) == 1) {
        if (D_8014A928[idx] - 1.1f <= pos) {
            hit = 1;
        }
    } else {
        if (pos < 0.0f) {
            hit = 1;
        }
    }
    func_8004303C(arg0);
    if (F(D_8014AAB0, void *, 0x6C) == arg0) {
        f32 t = F(arg0, f32, 0xB4);
        F(D_8014AAB0, s32, 0x78) = 5;
        F(D_8014AAB0, f32, 0xB4) = t;
    }
    if (hit) {
        F(arg0, f32, 0xAC) = -F(arg0, f32, 0xAC);
        F(arg0, s32, 0xBC) = -F(arg0, s32, 0xBC);
        return 1;
    }
    func_80081990((char *)arg0 + 4, idx, F(arg0, f32, 0xB4));
    func_80081AC0(v, idx, F(arg0, f32, 0xB4));
    a = func_8002492C(v[0], v[2]);
    if (F(arg0, s32, 0xBC) <= 0) {
        a = func_8002D260(a + 0x8000);
    }
    F(arg0, s32, 0x10) = func_8002D204(a, F(arg0, s32, 0x10), D_800B9ECC * 448);
    if (D_801700D0 < (f32)(func_800851D8(arg0)[1] + 10)) {
        return 2;
    }
    return func_80084318(arg0) ? 3 : (F(arg0, s32, 0x64) < 1) * 4;
}
