typedef struct {
    s16 a;
    s32 b;
} Msg;
extern s32 osSendMesg(void *, void *, s32);
extern Msg D_801075D0;
extern s32 D_801075E0;

void func_80025CC8(s32 arg0) {
    D_801075D0.a = 1;
    D_801075D0.b = arg0;
    osSendMesg(&D_801075E0, &D_801075D0, 1);
}
