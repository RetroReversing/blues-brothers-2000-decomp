typedef struct O5C860 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    union { s32 f10; struct { u16 f10h; u16 f12; } s; } u10;
    u8 pad14[0x84 - 0x14];
    s32 f84;
    s32 f88;
    u8 pad8C[0x94 - 0x8C];
    s32 f94;
    s32 f98;
    void (*f9C)(void);
    u8 padA0[4];
    struct O5C860 *fA4;
    u8 padA8[0xDC - 0xA8];
    f32 fDC;
} O5C860;
s16 coss(u16);
s16 sins(u16);
void sendCommand(s32, s32);
void actorSetAnim(O5C860 *, s32, s32);
void func_800393F4(void);

void func_8005C860(O5C860 *arg0) {
    if (arg0->fA4->fDC >= 85.0f) {
        sendCommand(12, 0x80);
        sendCommand(8, 0x1C);
        arg0->f4 = arg0->fA4->f4 + ((sins(arg0->fA4->u10.s.f12) * 195) >> 14);
        arg0->f8 = arg0->fA4->f8 + 400.0f;
        arg0->fC = arg0->fA4->fC + ((coss(arg0->fA4->u10.s.f12) * 195) >> 14);
        arg0->u10.f10 = arg0->fA4->u10.f10;
        actorSetAnim(arg0, 0x10, 0x100);
        arg0->f94 = 2000;
        arg0->f9C = func_800393F4;
        arg0->f98 = arg0->fA4->f88;
        arg0->fA4->f84 = 0;
        arg0->fA4->f88 = 0;
    }
}
