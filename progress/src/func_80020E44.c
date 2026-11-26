s32 func_80020D64(void *);
void *spawnEffectObj(s32, s32, s32, s32);
s32 randomRange(s32, s32);
s32 heapAlloc(s32);
extern s32 func_800202BC;
extern s32 func_80020E08;
#define F(p, t, o) (*(t *)((s8 *)(p) + (o)))

s32 func_80020E44(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *p;

    p = spawnEffectObj(1, 0, 0, 0);
    F(p, void *, 0x9C) = func_80020D64;
    F(p, void *, 0x98) = &func_800202BC;
    F(p, f32, 4) = arg0;
    F(p, f32, 8) = arg1;
    F(p, f32, 0xC) = arg2;
    F(p, f32, 0x40) = arg0;
    F(p, f32, 0x44) = arg1;
    F(p, f32, 0x48) = arg2;
    F(p, s32, 0x64) = 0x64;
    F(p, s32, 0x68) = 0xE;
    F(p, s32, 0xC4) = heapAlloc(0x180);
    F(p, s32, 0x74) = 4;
    F(p, s32, 0x78) = 0xFF;
    F(p, s32, 0x8C) = randomRange(0, 0xFFFF);
    F(p, s32, 0) = 0x12B;
    F(p, void *, 0xA0) = &func_80020E08;
    F(p, s32, 0x10) = arg3;
    func_80020D64(p);
    return (s32) p;
}
