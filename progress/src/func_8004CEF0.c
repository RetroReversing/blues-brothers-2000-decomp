typedef struct {
    s32 w[16];
} Blk40;

void func_8004C78C(s32 arg0, f32 *a, f32 *b, f32 *c, f32 *d, f32 *e, f32 *f, f32 *x, f32 *y, f32 *z);
void func_8002DD8C(f32 *out, void *m, f32 *v);
f32 func_8002DD60(f32);
void func_8004BB18(f32 mf[4][4], f32 r, f32 p, f32 h);
void func_80022EDC(Blk40 *out, s32 *rot, s32 n, f32 *v);
extern f32 D_80007DF4;
extern f64 D_80007DF8;
extern f32 *D_800B3960;
extern char D_800CD148[];

s32 func_8004CEF0(s32 arg0, Blk40 *arg1) {
    f32 d[3];
    f32 v[3];
    f32 mf[4][4];
    s32 rot[9];
    Blk40 tmp;
    f32 a, b, c, p, q, r, x, y, z;
    f32 lim;

    func_8004C78C(arg0, &a, &b, &c, &p, &q, &r, &x, &y, &z);
    d[0] = x - D_800B3960[1];
    d[1] = y - D_800B3960[2];
    d[2] = z - D_800B3960[3];
    func_8002DD8C(v, D_800CD148, d);
    lim = 8000.0f;
    if (lim < func_8002DD60(v[0])) {
        return 0;
    }
    if (lim < func_8002DD60(v[1])) {
        return 0;
    }
    if (lim < func_8002DD60(v[2])) {
        return 0;
    }
    func_8004BB18(mf, r, p, q);
    rot[0] = mf[0][0] * 32767.0;
    rot[1] = mf[0][1] * 32767.0;
    rot[2] = mf[0][2] * 32767.0;
    rot[3] = mf[1][0] * 32767.0;
    rot[4] = mf[1][1] * 32767.0;
    rot[5] = mf[1][2] * 32767.0;
    rot[6] = mf[2][0] * 32767.0;
    rot[7] = mf[2][1] * 32767.0;
    rot[8] = mf[2][2] * 32767.0;
    func_80022EDC(&tmp, rot, 1, v);
    *arg1 = tmp;
    return 1;
}
