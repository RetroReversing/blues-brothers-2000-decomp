s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void *spawnEffectObj(s32, s32, s32, s32);
s32 func_8002B240(s32, s32, s32, s32, s32, s32);
extern s32 D_800BD218[];
extern void func_80012228(void);
extern s32 drawQuadSprite;

#define F(p, T, o) (*(T *)((s8 *)(p) + (o)))

void *func_8001230C(void *arg0) {
    void *temp_v0;
    s32 g;

    temp_v0 = spawnEffectObj(1, (s32) F(arg0, f32, 4), (s32) F(arg0, f32, 8), (s32) F(arg0, f32, 0xC));
    F(temp_v0, void *, 0x98) = &drawQuadSprite;
    g = D_800BD218[0];
    F(temp_v0, void *, 0x9C) = &func_80012228;
    F(temp_v0, s32, 0x70) = 0x5A;
    F(temp_v0, s32, 0x74) = 0;
    F(temp_v0, s32, 0x78) = 0xFFFFFF;
    F(temp_v0, s32, 0x7C) = 0;
    F(temp_v0, s32, 0x60) = g;
    F(temp_v0, s32, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    F(temp_v0, s32, 0x68) = 0xB;
    F(temp_v0, s32, 0x5C) = 0xFF;
    F(temp_v0, s32, 0xA8) = func_8002B240((s32) F(temp_v0, f32, 4), (s32) F(temp_v0, f32, 8), (s32) F(temp_v0, f32, 0xC), 0x29, 0x3E8, 0);
    return temp_v0;
}
