/* identical to osLeoDiskInit in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
extern u8 D_8017F6D4[];
extern s32 D_8017F6DC;
extern s32 D_8017F6E0;
extern s32 D_8017F744;
extern s32 D_800BC43C;
s32 bzero(void *, s32);
s32 func_800970B0(void);
void func_800970D0(s32);

void *osLeoDiskInit(void) {
    u8 *p = D_8017F6D4;
    s32 old;
    s32 v;

    p[0] = 2;
    D_8017F6DC = 0xA5000000;
    p[1] = 3;
    p[4] = 6;
    p[2] = 6;
    p[5] = 1;
    p[3] = 2;
    *(volatile s32 *)0xA4600024 = 3;
    *(volatile s32 *)0xA4600028 = 6;
    *(volatile s32 *)0xA460002C = 6;
    *(volatile s32 *)0xA4600030 = 2;
    D_8017F6E0 = 0;
    bzero(p + 0x10, 0x60);
    v = func_800970B0();
    old = D_800BC43C;
    D_800BC43C = (s32)(p - 4);
    D_8017F744 = (s32)(p - 4);
    *(s32 *)(p - 4) = old;
    func_800970D0(v);
    return p - 4;
}
