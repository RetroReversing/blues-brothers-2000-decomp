/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 D_800BC450;
extern char D_80179C60[];
extern char D_80177FB8[];
extern char D_80180760[];

/* Blocks until the PI access queue (at D_80177FB8+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
void func_800A34C4(void)
{
    s32 msg;

    if (D_800BC450 == 0) {
        D_800BC450 = 1;
        osCreateMesgQueue(D_80177FB8 + 0x87A8, D_80179C60 + 0x6AF0, 1);
        osSendMesg(D_80180760, 0, 0);
    }
    osRecvMesg(D_80177FB8 + 0x87A8, &msg, 1);
}
