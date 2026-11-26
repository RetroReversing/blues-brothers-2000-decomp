s32 func_80013654(void *);
s32 func_80013784(void *);
s32 func_800137E0(void *);
s32 func_800137F8(void *);
f32 func_8002D66C(void *, f32, s32);
void func_8003AC08(void *, f32, s32);
s16 *func_800851D8(void);
extern void *D_800BD06C[];
extern f32 D_80009394;
extern f32 D_80009398;
extern f32 D_8000939C;
extern f32 D_800093A0;
extern f32 D_800093A4;
extern f32 D_800093A8;
extern f32 D_800093AC;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

s32 func_80079294(void *arg0) {
    f32 top;
    f32 r;
    f32 low;
    f32 y;
    s16 *v;
    s32 h;
    f32 d;
    s32 t;
    s32 res;
    s32 u;
    s32 x;
    s32 w;

    y = F(arg0, f32, 8);
    top = y + D_80009394;
    low = y - D_80009398;
    if (F(arg0, s32, 0xC0) & 0x40) {
ret1:
        return 1;
    }
    r = D_8000939C;
    F(arg0, s32, 0xC0) = 0;
    d = func_8002D66C(arg0, r, 0);
    if (d < D_800093A0) {
        d = D_800093A0;
    }
    if (d < r) {
        if (top < F(D_800BD06C[0], f32, 8)) {
            return 0;
        }
        if (F(D_800BD06C[0], f32, 8) + D_800093A4 < low) {
            return 0;
        }
        if (top <= F(D_800BD06C[0], f32, 0x44) && F(D_800BD06C[0], f32, 8) < top) {
            func_8003AC08(D_800BD06C[0], F(arg0, f32, 8) + D_800093A8, 0);
            if (func_80013784(arg0) != 0) {
                F(arg0, s32, 0xC0) |= 4;
            }
            return 2;
        }
        if (d < D_800093AC) {
            void *p = D_800BD06C[0];
            f32 k = D_800093AC - d;
            f32 dx = F(arg0, f32, 4) - F(p, f32, 4);
            f32 dz = F(arg0, f32, 0xC) - F(p, f32, 0xC);
            F(p, f32, 4) -= dx * k / d;
            F(p, f32, 0xC) -= dz * k / d;
            u = F(arg0, s32, 0xC0);
            F(arg0, s32, 0xC0) = u | 1;
            if (F(p, s32, 0xB8) == 5) {
                F(arg0, s32, 0xC0) = u | 0x103;
            }
        }
        res = func_80013654(D_800BD06C[0]);
        if (res != 0) {
            w = F(arg0, s32, 0xC0);
            F(arg0, s32, 0xC0) = w | 2;
            if (res == 2) {
                F(arg0, s32, 0xC0) = w | 0x82;
            }
        }
        if (func_800137E0(D_800BD06C[0]) != 0) {
            F(arg0, s32, 0xC0) |= 8;
        }
        if (func_80013784(arg0) != 0) {
            F(arg0, s32, 0xC0) |= 4;
        }
        if (func_800137F8(D_800BD06C[0]) != 0) {
            F(arg0, s32, 0xC0) |= 0x12;
        }
        goto ret1;
    }
    return 0;
}
