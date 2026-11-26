typedef struct { u32 w0; u32 w1; } GfxW;
void func_8001F1D0(void *);
void func_8001F230(void);
void buildObjectMatrix(void *, void *, s32);
void func_80024A3C(void *, void *, s32);
void func_80024B58(void *, void *, s32);
void func_80024BE0(void *, void *, s32);
void func_80024FE8(void *);
void func_80027060(s32, s32, s32, s32);
void setRenderState(s32, GfxW *);
extern GfxW *D_80177E18;

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1[0x5C - 0x1C];
    s32 f5C;
    u8 pad2[0xE4 - 0x60];
    u32 fE4;
} ObjN;

s32 func_80020F50(ObjN *arg0) {
    char sp10[0x28];
    char sp38[0x28];
    GfxW *g1;
    GfxW *g2;
    GfxW *g3;

    func_8001F230();
    g1 = D_80177E18++;
    g1->w0 = 0xE7000000;
    g1->w1 = 0;
    func_80027060(0xFF, 0xFF, 0xFF, arg0->f5C);
    g2 = D_80177E18++;
    g2->w0 = 0xFCFFFFFF;
    g2->w1 = 0xFFFDF6FB;
    func_8001F1D0(arg0);
    func_80024FE8(sp10);
    func_80024B58(sp38, sp10, arg0->f10);
    func_80024A3C(sp10, sp38, arg0->f14);
    func_80024BE0(sp38, sp10, arg0->f18);
    buildObjectMatrix(arg0, sp38, 1);
    g3 = D_80177E18++;
    g3->w0 = 0xDE000000;
    g3->w1 = arg0->fE4;
    setRenderState(-1, g3);
    return 1;
}
