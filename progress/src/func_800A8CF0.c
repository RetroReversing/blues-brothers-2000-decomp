typedef union { struct { s32 high; u32 low; } s; s64 ll; } DIunion;
u64 func_800A8DB0(u64, u64, u64 *);

static inline s64 negdi2(s64 u) {
    DIunion w;
    DIunion uu;

    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((u32)w.s.low > 0);
    return w.ll;
}

s64 func_800A8CF0(s64 u, s64 v) {
    s32 c = 0;
    DIunion uu, vv;
    s64 w;

    uu.ll = u;
    vv.ll = v;
    if (uu.s.high < 0) {
        c = ~c, uu.ll = negdi2(uu.ll);
    }
    if (vv.s.high < 0) {
        c = ~c, vv.ll = negdi2(vv.ll);
    }
    w = func_800A8DB0(uu.ll, vv.ll, (u64 *)0);
    if (c) {
        w = negdi2(w);
    }
    return w;
}
