typedef struct { f32 x, y, z; } Vec;
typedef struct Spl {
    /* 0x00 */ u8 pad0[0x7C];
    /* 0x7C */ s32 flags;
} Spl;
void func_8004E134(Spl *arg0, f32 t, Vec *out);
f32 func_8002DD60(f32 arg0);
extern f32 D_80007E68;
extern f64 D_80007E70;
extern f64 D_80007E78;
extern f64 D_80007E80;
extern f32 D_80007E88;
extern f64 D_80007E90;

f32 func_8004E388(Spl *arg0, f32 t, f32 dist) {
    Vec a;
    Vec b;
    Vec d;
    f32 step;
    f32 nt;
    f32 len;
    f32 diff;
    s32 n;

    n = 0;
    step = D_80007E68;
    func_8004E134(arg0, t, &a);
    do {
        nt = t + step;
        func_8004E134(arg0, nt, &b);
        d.x = b.x - a.x;
        d.y = b.y - a.y;
        d.z = b.z - a.z;
        len = func_8002DD60(d.z);
        diff = dist - len;
        if (diff < D_80007E70 && D_80007E78 < diff) {
            return nt;
        }
        if (diff > 0.0 && !(arg0->flags & 1) && D_80007E80 <= nt) {
            return D_80007E88;
        }
        if (diff < 0.0 && !(arg0->flags & 1) && nt == 0.0) {
            return 0.0f;
        }
        n++;
        step *= dist / len;
        if (n >= 501) {
            return t + D_80007E90;
        }
    } while (1);
}
