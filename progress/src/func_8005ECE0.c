typedef struct O5ECE0 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 pad10[0x58 - 0x10];
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    u8 pad90[0x98 - 0x90];
    void (*f98)(void);
    void (*f9C)(void);
} O5ECE0;
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
O5ECE0 *spawnEffectObj(s32, s32, s32, s32);
s32 randomRange(s32, s32);
extern s32 D_8014AB14;
void func_8002F8D0(void);
void func_8005EE10(void);

O5ECE0 *func_8005ECE0(O5ECE0 *arg0) {
    O5ECE0 *o;

    o = spawnEffectObj(1, (s32)arg0->f4, (s32)arg0->f8, (s32)arg0->fC);
    o->f64 = 200;
    o->f98 = func_8002F8D0;
    o->f9C = func_8005EE10;
    o->f70 = 7;
    o->f7C = 1;
o->f78 = 0xFFFFFF;
o->f74 = 0;
o->f8C = 0;
o->f8 += 250.0f;
o->f60 = D_8014AB14;
    while (o->f88 == 0) {
        o->f88 = randomRange(-1, 1);
    }
    o->f5C = 0xB0;
    o->f58 = packDrawFlags(0, 1, 1, 3, 0, 0, 2, 0);
    o->f4 += randomRange(-100, -50);
    o->f68 = 13;
    return o;
}
