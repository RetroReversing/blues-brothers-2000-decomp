typedef struct { u32 w0; u32 w1; } GfxW;
extern GfxW *D_80177E18;
void func_8001F230(void);
void func_8002DC84(void *);
void func_8002DAE0(void *, void *, f32);
void func_8002DB6C(void *, void *, f32);
s32 func_80022C2C(void *, void *, s32);

s32 func_80015980(u8 *obj) {
    f32 rx;
    f32 ry;
    u8 m1[0x28];
    u8 m2[0x28];
    GfxW *g1;
    GfxW *g2;
    GfxW *g3;

    rx = *(s32 *) (obj + 0x10);
    rx = rx * 9.587379760742188e-05;
    ry = *(s32 *) (obj + 0x14);
    ry = ry * 9.587379760742188e-05;
    func_8001F230();
    *(f32 *) (obj + 0x28) = 0;
    *(f32 *) (obj + 0x2C) = 0;
    *(f32 *) (obj + 0x30) = 0;
    func_8002DC84(m1);
    func_8002DAE0(m2, m1, ry);
    func_8002DB6C(m1, m2, rx);
    func_80022C2C(obj, m1, 1);
    g1 = D_80177E18++;
    g1->w0 = 0xE200001C;
    g1->w1 = 0x0F0A4000;
    g2 = D_80177E18++;
    g2->w0 = 0xDE000000;
    g3 = D_80177E18++;
    g2->w1 = *(u32 *) (obj + 0xE4);
    g3->w0 = 0xE7000000;
    g3->w1 = 0;
    return 1;
}
