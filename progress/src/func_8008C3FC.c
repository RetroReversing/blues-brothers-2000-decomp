typedef struct {
    u8 pad0[0x58];
    f32 rate[3];
    s32 step;
    u8 pad68[0xBF - 0x68];
    u8 div;
    u8 val[3];
    u8 pad[3];
    u8 len[3];
} Env;

u8 *func_8008C3FC(Env *e, u8 *p) {
    u8 n;
    s32 v;

    n = *p++;
    if (n == 0) {
        n = 1;
    }
    e->div = n;
    e->step = 0x400 / n;
    e->val[0] = *p++;
    n = *p++;
    e->len[0] = n;
    v = *p++;
    e->val[1] = v;
    e->rate[0] = (1.0 / (f32)n) * (f32)(v - e->val[0]);
    n = *p++;
    e->len[1] = n;
    v = *p++;
    e->val[2] = v;
    e->rate[1] = (1.0 / (f32)n) * (f32)(v - e->val[1]);
    n = *p++;
    e->len[2] = n;
    e->rate[2] = 1.0 / (f32)n;
    return p;
}
