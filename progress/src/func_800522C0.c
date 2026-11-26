typedef struct { f32 m[4][4]; } MtxF_;
typedef struct { s32 m[16]; } Mtx_;
void func_80034FEC(void *, s32 *);
void func_800414D0(u8 *);
void guMtxL2F(MtxF_ *, Mtx_ *);
void updateCameraView(void);
extern u8 *D_800B3960;
extern s32 D_800B74E4;
extern s32 D_80140260[];
extern Mtx_ *D_80140310[];

void func_800522C0(u8 *arg0) {
    Mtx_ a;
    Mtx_ b;
    s32 pos[3];
    MtxF_ *p;

    D_80140260[0] = 0x1F;
    D_80140310[0] = &a;
    D_80140260[1] = 0x20;
    D_80140310[1] = &b;
    D_800B74E4 = 2;
    func_800414D0(arg0);
    p = *(MtxF_ **)(arg0 + 0x8C);
    guMtxL2F(p++, &a);
    guMtxL2F(p++, &b);
    p -= 2;
    *(f32 *)(D_800B3960 + 4) = p->m[3][0];
    *(f32 *)(D_800B3960 + 8) = p->m[3][1];
    *(f32 *)(D_800B3960 + 0xC) = p->m[3][2];
    *(f32 *)(D_800B3960 + 4) += *(f32 *)(arg0 + 4);
    *(f32 *)(D_800B3960 + 8) += *(f32 *)(arg0 + 8);
    *(f32 *)(D_800B3960 + 0xC) += *(f32 *)(arg0 + 0xC);
    p++;
    pos[0] = p->m[3][0];
    pos[1] = p->m[3][1];
    pos[2] = p->m[3][2];
    pos[0] += *(f32 *)(arg0 + 4);
    pos[1] += *(f32 *)(arg0 + 8);
    pos[2] += *(f32 *)(arg0 + 0xC);
    func_80034FEC(D_800B3960, pos);
    *(void **)(D_800B3960 + 0x9C) = updateCameraView;
}
