extern void *spawnEffectObj(int,int,int,int);
extern int func_80023D58(int);
extern float D_8000123C;
extern int drawRingEffect;
extern int func_80030B2C;
void *func_80030B90(void *arg0) {
    void *temp_v0;
    float k;
    temp_v0 = spawnEffectObj(1, 0, 0, 0);
    *(void **)((s8*)temp_v0+0x98) = &drawRingEffect;
    *(int *)((s8*)temp_v0+0x70) = 0xC8;
    *(int *)((s8*)temp_v0+0x78) = 0xFFFFFF;
    *(int *)((s8*)temp_v0+0x5C) = 0xFF;
    *(int *)((s8*)temp_v0+0x60) = func_80023D58(0x212);
    *(void **)((s8*)temp_v0+0x9C) = &func_80030B2C;
    if (arg0 != 0) {
        *(float*)((s8*)temp_v0+4)=*(float*)((s8*)arg0+4);
        k = 100.0f;
        *(float*)((s8*)temp_v0+8)=*(float*)((s8*)arg0+8)+k;
        *(float*)((s8*)temp_v0+0xC)=*(float*)((s8*)arg0+0xC);
    }
    return temp_v0;
}
