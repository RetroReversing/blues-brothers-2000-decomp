typedef struct { s32 m[16]; } Mtx;
s32 func_800414D0(void *arg0);
s32 guMtxL2F(Mtx *, s32 *);
extern s32 D_800B74E4;
extern s32 D_80140260;
extern s32 D_80140310;
void func_8006776C(Mtx *arg0) {
    char sp10[0x40];
    char sp50[0x40];
    (*(s32 *)((s8 *)&D_80140260 + 0)) = 0;
    (*(s32 **)((s8 *)&D_80140310 + 0)) = (s32 *)sp10;
    (*(s32 *)((s8 *)&D_80140260 + 4)) = 0xE;
    (*(s32 **)((s8 *)&D_80140310 + 4)) = (s32 *)sp50;
    D_800B74E4 = 2;
    func_800414D0(arg0);
    arg0 = *(Mtx **)((s8 *)arg0 + 0x8C);
    guMtxL2F(arg0++, (s32 *)sp10);
    guMtxL2F(arg0, (s32 *)sp50);
}
