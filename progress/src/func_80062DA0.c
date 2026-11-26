typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
typedef struct {
    s32 m[4][4];
} Mtx;
typedef f32 MtxF[4][4];
typedef struct {
    u8 pad0[0x18];
    s32 ids[6];
    Mtx mtx[6];
    Mtx view[9];
    s32 unk3F0;
} Scene;

void func_800414D0(s32);
void guMtxL2F(Mtx *m, MtxF mf);
s32 func_8004CEF0(void *, Mtx *);
void func_8004C004(Mtx *m, f32 *v);
void func_80063010(f32 *a, f32 *b);
extern s32 D_800B74E4;
extern s32 D_800B76E0[];
extern Scene *D_800B7FE0;
extern s32 D_800B9EB8;
extern s32 D_80140260[];
extern MtxF *D_80140310[];
extern Gfx *D_80177E18;

void func_80062DA0(s32 arg0) {
    MtxF mf[6];
    f32 a[3];
    f32 b[3];

    D_80140260[D_800B74E4] = D_800B7FE0->ids[0]; D_80140310[D_800B74E4] = &mf[0]; D_800B74E4++;
    D_80140260[D_800B74E4] = D_800B7FE0->ids[1]; D_80140310[D_800B74E4] = &mf[1]; D_800B74E4++;
    D_80140260[D_800B74E4] = D_800B7FE0->ids[2]; D_80140310[D_800B74E4] = &mf[2]; D_800B74E4++;
    D_80140260[D_800B74E4] = D_800B7FE0->ids[3]; D_80140310[D_800B74E4] = &mf[3]; D_800B74E4++;
    D_80140260[D_800B74E4] = D_800B7FE0->ids[4]; D_80140310[D_800B74E4] = &mf[4]; D_800B74E4++;
    D_80140260[D_800B74E4] = D_800B7FE0->ids[5]; D_80140310[D_800B74E4] = &mf[5]; D_800B74E4++;
    func_800414D0(arg0);
    guMtxL2F(&D_800B7FE0->mtx[0], mf[0]);
    guMtxL2F(&D_800B7FE0->mtx[1], mf[1]);
    guMtxL2F(&D_800B7FE0->mtx[2], mf[2]);
    guMtxL2F(&D_800B7FE0->mtx[3], mf[3]);
    guMtxL2F(&D_800B7FE0->mtx[4], mf[4]);
    guMtxL2F(&D_800B7FE0->mtx[5], mf[5]);
    if (func_8004CEF0(D_800B76E0, &D_800B7FE0->view[D_800B9EB8]) != 0) {
        { Gfx *_g = D_80177E18++; _g->w0 = 0xDA380003; _g->w1 = (u32)&D_800B7FE0->view[D_800B9EB8]; }
        D_800B7FE0->unk3F0 = 0;
        func_8004C004(&D_800B7FE0->mtx[2], a);
        func_8004C004(&D_800B7FE0->mtx[3], b);
        b[1] = 0;
        func_80063010(a, b);
        func_8004C004(&D_800B7FE0->mtx[4], a);
        func_8004C004(&D_800B7FE0->mtx[5], b);
        b[1] = 0;
        func_80063010(a, b);
    }
}
