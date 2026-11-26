typedef struct Obj { u8 p0[8]; f32 f8; u8 p1[4]; s32 f10; u8 p2[0x3C]; f32 f50; u8 p3[0x48]; void *f9C; u8 p4[0x1C]; s32 fBC; } Obj;
typedef struct Ctx { u8 p0[0x10]; s32 f10; } Ctx;
extern s32 atan2S16(s32, s32);
extern void func_8002ACAC();
extern s32 func_8002D1C4(s32, s32, s32);
extern void animStepKeys();
extern void actorSetAnim(Obj *, s32, s32);
extern Ctx *D_800B3960;
extern s32 gPadPressed[];
extern s32 D_801073B0[];
extern s32 D_801073C0[];
extern s32 D_80140240;
extern void func_800393F4(void);

void func_8003C2A0(Obj *arg0) {
    animStepKeys();
    arg0->f10 = func_8002D1C4(D_800B3960->f10 + atan2S16(D_801073B0[arg0->fBC], D_801073C0[arg0->fBC]), arg0->f10, 1);
    if (gPadPressed[arg0->fBC] & 0x8000) {
        arg0->f50 = (f32) D_80140240;
        arg0->f8 = arg0->f8 + 1.0f;
        actorSetAnim(arg0, 5, 0x100);
        func_8002ACAC();
        arg0->f9C = func_800393F4;
    }
}
