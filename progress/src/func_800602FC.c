typedef struct O602FC {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    u8 pad14[0x4C - 0x14];
    f32 f4C;
    f32 f50;
    f32 f54;
    u8 pad58[0x80 - 0x58];
    s32 f80;
} O602FC;
s32 func_8002492C(f32, f32);
void func_8002DA80(O602FC *);
f32 func_8002DD60(f32);
void updateBlockerEnemy(O602FC *);
void func_80060214(O602FC *);
s32 func_80076080(void);

void func_800602FC(O602FC *arg0) {
    if (func_80076080() != 0) {
        return;
    }
    func_80060214(arg0);
    if (arg0->f80 != 0) {
        return;
    }
    func_8002DA80(arg0);
    if (arg0->f4 < -750.0f) {
        arg0->f4C = func_8002DD60(arg0->f4C);
    }
    if (arg0->f4 > 2400.0f) {
        arg0->f4C = -func_8002DD60(arg0->f4C);
    }
    if (arg0->fC < 3450.0f) {
        arg0->f54 = func_8002DD60(arg0->f54);
    }
    if (arg0->fC > 6400.0f) {
        arg0->f54 = -func_8002DD60(arg0->f54);
    }
    arg0->f10 = func_8002492C(arg0->f4C, arg0->f54);
    updateBlockerEnemy(arg0);
}
