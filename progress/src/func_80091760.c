typedef struct {
    s32 mode;
    u32 marker;
} InflState91760;

typedef struct {
    u8 *next_in;
    u32 avail_in;
    u32 total_in;
    u8 *next_out;
    u32 avail_out;
    u32 total_out;
    char *msg;
    InflState91760 *state;
} ZStream91760;

s32 func_80090E50(ZStream91760 *);
extern u8 D_80009E78[];

s32 func_80091760(ZStream91760 *z) {
    u32 n;
    u8 *p;
    u32 m;
    u32 r, w;

    if (z == NULL || z->state == NULL)
        return -2;
    if (z->state->mode != 13) {
        z->state->mode = 13;
        z->state->marker = 0;
    }
    if ((n = z->avail_in) == 0)
        return -5;
    p = z->next_in;
    m = z->state->marker;

    while (n && m < 4) {
        if (*p == D_80009E78[m])
            m++;
        else if (*p)
            m = 0;
        else
            m = 4 - m;
        p++, n--;
    }

    z->total_in += p - z->next_in;
    z->next_in = p;
    z->avail_in = n;
    z->state->marker = m;

    if (m != 4)
        return -3;
    r = z->total_in;
    w = z->total_out;
    func_80090E50(z);
    z->total_in = r;
    z->total_out = w;
    z->state->mode = 7;
    return 0;
}
