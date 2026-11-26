typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} Vtx_t;
typedef struct {
    u32 w0;
    u32 w1;
} Gwords;
s32 func_8001EAD0(void);
s32 func_8001EB18(s32);
void debugPrintf(char *, ...);
extern char D_80000E78[];
extern Vtx_t D_800BD6C8[];
extern Gwords *D_80177E18;

void drawTextureRect(s32 x0, s32 y0, s32 x1, s32 y1, s32 s, s32 t, s32 alpha) {
    s32 i;
    s32 start;
    Vtx_t *v0;
    Vtx_t *v1;
    Vtx_t *v2;
    Vtx_t *v3;

    start = i = func_8001EAD0();
    if (i == -1) {
        debugPrintf(D_80000E78);
        return;
    }
    v0 = &D_800BD6C8[i++];
    v1 = &D_800BD6C8[i++];
    v2 = &D_800BD6C8[i++];
    v3 = &D_800BD6C8[i++];
    v0->ob[0] = x0;
    v0->ob[1] = y0;
    v0->ob[2] = 0;
    v0->cn[0] = 0xFF;
    v0->cn[1] = 0xFF;
    v0->cn[2] = 0xFF;
    v0->cn[3] = alpha;
    v0->tc[0] = 0;
    v0->tc[1] = 0;
    v1->ob[0] = x1;
    v1->ob[1] = y0;
    v1->ob[2] = 0;
    v1->cn[0] = 0xFF;
    v1->cn[1] = 0xFF;
    v1->cn[2] = 0xFF;
    v1->cn[3] = alpha;
    v1->tc[0] = s;
    v1->tc[1] = 0;
    v2->ob[0] = x1;
    v2->ob[1] = y1;
    v2->ob[2] = 0;
    v2->cn[0] = 0xFF;
    v2->cn[1] = 0xFF;
    v2->cn[2] = 0xFF;
    v2->cn[3] = alpha;
    v2->tc[0] = s;
    v2->tc[1] = t;
    v3->ob[0] = x0;
    v3->ob[1] = y1;
    v3->ob[2] = 0;
    v3->cn[0] = 0xFF;
    v3->cn[1] = 0xFF;
    v3->cn[2] = 0xFF;
    v3->cn[3] = alpha;
    v3->tc[0] = 0;
    v3->tc[1] = t;
    {
        Gwords *g = D_80177E18++;
        g->w0 = 0x01004008;
        g->w1 = (u32)&D_800BD6C8[i - 4];
    }
    {
        Gwords *g = D_80177E18++;
        g->w0 = 0x07000204;
        g->w1 = 0x406;
    }
    {
        Gwords *g = D_80177E18++;
        g->w0 = 0x07000604;
        g->w1 = 0x402;
    }
    func_8001EB18(i - start);
}
