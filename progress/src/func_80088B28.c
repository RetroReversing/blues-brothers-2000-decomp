void osCreatePiManager(s32 pri, void *cmdQ, void *cmdBuf, s32 cmdMsgCnt);
void osCreateThread(void *t, s32 id, void (*entry)(void *), void *arg, void *sp, s32 pri);
void osStartThread(void *t);
void osCreateMesgQueue(void *mq, void *msg, s32 count);
void osSetEventMesg(s32 e, void *mq, s32 m);
void osSetThreadPri(void *t, s32 pri);
extern u8 D_80171A90[];
extern u8 D_80171D40[];
extern u8 D_80171D58[];
extern u8 D_80174DF0[];
extern u8 D_80171C40[];
extern u8 D_80176560[];
extern u8 D_80179A18[];
extern u8 D_80179A38[];
void func_80088C4C(void *);
void func_80088CB0(void *);

void func_80088B28(void *arg0) {
    osCreatePiManager(0x96, D_80179A18, D_80179A38, 8);
    osCreateThread(D_80176560, 3, func_80088CB0, arg0, D_80174DF0, 0xE);
    osStartThread(D_80176560);
    osCreateMesgQueue(D_80171D40, D_80171D58, 1);
    osSetEventMesg(0xE, D_80171D40, 0x29D);
    osCreateThread(D_80171A90, 0x19, func_80088C4C, 0, D_80171C40 + 0x100, 0x7D);
    osStartThread(D_80171A90);
    osSetThreadPri(0, 0);
    for (;;) {
    }
}
