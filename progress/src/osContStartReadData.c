/* identical to osContStartReadData in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osContStartReadData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_8017DBC0[];
extern u8 D_8017DC00;
s32 osRecvMesg(s32, s32, s32);
void func_8009DBF4(void);
void func_8009DC60(void);
void __osPackReadData(void);
s32 func_8009DB00(s32, void *);

/* Starts a controller read: if the last PIF command was not a button read, sends the
   packed command first and waits for the reply. Then starts the PIF read DMA and
   returns its result. Holds the PIF lock for the whole sequence. */
s32 osContStartReadData(s32 mq)
{
    s32 ret;

    func_8009DBF4();
    if (D_8017DC00 != 1) {
        __osPackReadData();
        func_8009DB00(1, D_8017DBC0);
        osRecvMesg(mq, 0, 1);
    }
    ret = func_8009DB00(0, D_8017DBC0);
    D_8017DC00 = 1;
    func_8009DC60();
    return ret;
}
