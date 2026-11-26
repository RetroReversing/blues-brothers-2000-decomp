typedef struct {
    u32 w0;
    u32 w1;
} GfxW7B34;

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx7B34;

float sqrtf(float);
extern Vtx7B34 D_80140790[3];
extern f32 D_80140FC8[3];
extern u8 D_800A9480[][3];
extern s32 D_80140148;
extern GfxW7B34 *D_80177E18;

void func_80047B34(void) {
    f32 e1[3];
    f32 e2[3];
    f32 l[3];
    f32 c0[3];
    f32 c1[3];
    f32 c2[3];
    f32 len1;
    f32 len2;
    f32 lenl;
    f32 cos1;
    f32 cos2;
    f32 sin1;
    f32 sin2;
    f32 t;
    f32 u;
    f32 w;
    f32 r;
    f32 g;
    f32 b;
    f32 grey;
    u8 *tint;
    u32 col;
    u32 ri;
    u8 gi;
    u32 bi;

    e1[0] = D_80140790[2].ob[0] - D_80140790[0].ob[0];
    e1[1] = D_80140790[2].ob[1] - D_80140790[0].ob[1];
    e1[2] = D_80140790[2].ob[2] - D_80140790[0].ob[2];
    len1 = sqrtf(e1[0] * e1[0] + e1[1] * e1[1] + e1[2] * e1[2]);
    e2[0] = D_80140790[1].ob[0] - D_80140790[0].ob[0];
    e2[1] = D_80140790[1].ob[1] - D_80140790[0].ob[1];
    e2[2] = D_80140790[1].ob[2] - D_80140790[0].ob[2];
    len2 = sqrtf(e2[0] * e2[0] + e2[1] * e2[1] + e2[2] * e2[2]);
    l[0] = D_80140FC8[0] - D_80140790[0].ob[0];
    l[1] = D_80140FC8[1] - D_80140790[0].ob[1];
    l[2] = D_80140FC8[2] - D_80140790[0].ob[2];
    lenl = sqrtf(l[0] * l[0] + l[1] * l[1] + l[2] * l[2]);
    cos1 = (l[0] * e1[0] + l[1] * e1[1] + l[2] * e1[2]) / (lenl * len1);
    if (cos1 > 1.0) {
        cos1 = 1.0f;
    }
    if (cos1 < -1.0) {
        cos1 = -1.0f;
    }
    cos2 = (l[0] * e2[0] + l[1] * e2[1] + l[2] * e2[2]) / (lenl * len2);
    if (cos2 > 1.0) {
        cos2 = 1.0f;
    }
    if (cos2 < -1.0) {
        cos2 = -1.0f;
    }
    sin1 = sqrtf(1.0 - cos1 * cos1);
    sin2 = sqrtf(1.0 - cos2 * cos2);
    c1[1] = D_80140790[1].cn[1];
    c1[2] = D_80140790[1].cn[2];
    c1[0] = D_80140790[1].cn[0];
    c0[2] = D_80140790[0].cn[2];
    c0[1] = D_80140790[0].cn[1];
    c0[0] = D_80140790[0].cn[0];
    c2[2] = D_80140790[2].cn[2];
    c2[0] = D_80140790[2].cn[0];
    c2[1] = D_80140790[2].cn[1];
    t = lenl / (sin1 * cos2 + cos1 * sin2);
    w = t * sin2;
    w /= len1;
    u = t * sin1 / len2;
    tint = D_800A9480[D_80140148];
    r = ((c1[0] - c0[0]) * u + (c2[0] - c0[0]) * w + c0[0]) * tint[0];
    r /= 255.0;
    g = ((c1[1] - c0[1]) * u + (c2[1] - c0[1]) * w + c0[1]);
    g *= tint[1];
    g /= 255.0;
    b = ((c1[2] - c0[2]) * u + (c2[2] - c0[2]) * w + c0[2]) * tint[2];
    b /= 255.0;
    grey = r * 0.299 + g * 0.387 + b * 0.114;
    ri = grey;
    gi = grey;
    bi = grey;
    col = (ri << 24) | ((gi & 0xFF) << 16) | ((bi & 0xFF) << 8) | 0xFF;
    {
        GfxW7B34 *_g = D_80177E18++;
        _g->w0 = 0xDB0A0018;
        _g->w1 = col;
    }
    {
        GfxW7B34 *_g = D_80177E18++;
        _g->w0 = 0xDB0A001C;
        _g->w1 = col;
    }
}


