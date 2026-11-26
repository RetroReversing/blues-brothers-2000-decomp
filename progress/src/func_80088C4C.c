extern s32 D_80171D40;
s32 osRecvMesg(void *, void *, s32);
void func_80025D00(s32);
void func_8002AB5C(void);
void func_80088C10(void);
void osViSetYScale(f32);
void osViBlack(s32);

void func_80088C4C(void) {
    s32 msg;

    osRecvMesg(&D_80171D40, &msg, 1);
    func_80025D00(0);
    func_80025D00(0);
    func_80025D00(0);
    func_8002AB5C();
    func_80088C10();
    osViSetYScale(*(f32 *)0x80009C00);
    osViBlack(1);
    for (;;);
}
