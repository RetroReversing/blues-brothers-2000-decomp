typedef struct Obj57 {
    u8 pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[0x24];
    s32 x34;
    s32 x38;
    s32 x3C;
    u8 pad40[0x1C];
    s32 x5C;
    u8 pad60[0x3C];
    void *x9C;
} Obj57;
s16 coss();
s16 sins();
Obj57 *func_80017344();
s32 func_80024394();
s32 func_8002D1A0();
s32 func_8002D3E4();
extern s32 D_800B9ECC;
void func_800462A0(void);

void func_80057020(Obj57 *arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    Obj57 *temp_v0_2;
    s32 i;

    if (func_80024394(0, 0x64) >= 0x47) {
        temp_s0 = func_8002D1A0();
        temp_v0_2 = func_80017344(arg0);
        temp_s0_2 = temp_s0 & 0xFFFF;
        temp_v0_2->x8 += *(f32 *)0x80008410;
        temp_v0_2->x4 += (f32) ((s32) (sins(temp_s0_2) * 0x19) >> 0xD);
        temp_v0_2->xC += (f32) ((s32) (coss(temp_s0_2) * 0x19) >> 0xD);
        func_8002D3E4(temp_v0_2, 0x12C);
    }
    arg0->x5C -= D_800B9ECC * 5;
    for (i = 0; i < D_800B9ECC; i++) {
        arg0->x34 = arg0->x34 * 0x101;
        arg0->x3C = arg0->x3C * 0x101;
        arg0->x38 = arg0->x38 * 0xFE;
        arg0->x34 = arg0->x34 >> 8;
        arg0->x38 = arg0->x38 >> 8;
        arg0->x3C = arg0->x3C >> 8;
    }
    if (arg0->x5C <= 0) {
        arg0->x9C = func_800462A0;
    }
}
