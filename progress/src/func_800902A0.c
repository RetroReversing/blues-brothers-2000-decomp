typedef struct DmaBuf {
    struct DmaBuf *f0;
    struct DmaBuf *f4;
    s32 f8;
    s32 fC;
    s32 f10;
} DmaBuf;
s32 osCartRomInit(void);
s32 func_80090CA0(s32);
void func_80090CFC(DmaBuf *, s32, s32);
void osCreateMesgQueue(void *, s32, s32);
s32 func_800904F0(void);
extern s32 D_8017B290;
extern DmaBuf *D_8017B294;
extern DmaBuf *D_8017B298;
extern s32 D_8017B29C;
extern s32 D_8017B2A0;
extern s32 D_8017B2A4;
extern s32 D_8017B2A8;
extern u8 D_8017B2B0[];
extern s32 D_8017B2C8;

void *func_800902A0(s32 n, s32 size) {
    s32 i;

    D_8017B2C8 = osCartRomInit();
    D_8017B29C = func_80090CA0(n * 48);
    D_8017B2A0 = func_80090CA0(n * 8);
    D_8017B298 = (DmaBuf *)func_80090CA0(n * sizeof(DmaBuf));
    func_80090CFC(D_8017B298, 0, n * sizeof(DmaBuf));
    for (i = 0; i < n - 1; i++) {
        D_8017B298[i].f4 = &D_8017B298[i] + 1;
        D_8017B298[i + 1].f0 = &D_8017B298[i];
        D_8017B298[i].f10 = func_80090CA0(size);
        D_8017B298[i].fC = -1;
    }
    D_8017B298[i].f10 = func_80090CA0(size);
    D_8017B298[i].fC = -1;
    D_8017B2A4 = size;
    D_8017B2A8 = 0;
    D_8017B290 = 0;
    D_8017B294 = D_8017B298;
    osCreateMesgQueue(D_8017B2B0, D_8017B2A0, n * 2);
    return func_800904F0;
}
