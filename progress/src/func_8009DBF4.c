/* identical to pi_access_wait in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 D_800BC300;
extern char D_80177060[];
extern char D_801753B8[];
extern char D_8017DB60[];

/* Blocks until the PI access queue (at D_801753B8+0x87A8) receives a message. The first call
   creates that queue, with a one-message buffer, and posts the initial token. */
void func_8009DBF4(void)
{
    s32 msg;

    if (D_800BC300 == 0) {
        D_800BC300 = 1;
        osCreateMesgQueue(D_801753B8 + 0x87A8, D_80177060 + 0x6AF0, 1);
        osSendMesg(D_8017DB60, 0, 0);
    }
    osRecvMesg(D_801753B8 + 0x87A8, &msg, 1);
}
