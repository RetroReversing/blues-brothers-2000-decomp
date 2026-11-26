/* identical to viMgrMain in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* VI manager thread: waits on the retrace message queue, applies the VI context every frame,
 * posts the vertical-retrace message every few frames, and tracks frame counts. */
extern u16 D_8017C930;
extern u32 D_8017C844, D_8017C840;
extern u64 D_8017C850;
void *func_8009D240(void);
void __osViSwapContext(void);
u32 func_80097250(void);
void __osTimerInterrupt(void);
void osRecvMesg(s32, void *, s32);
void osSendMesg(s32, s32, s32);

#define F(p, t, o) (*(t *)((u8 *)(p) + (o)))

void viMgrMain(void *arg0) {
    u16 *msg = NULL;
    s32 first = 0;
    u32 count;
    void *ctx;
    void *q;

    ctx = arg0;
    D_8017C930 = F(func_8009D240(), u16, 2);
    if (!D_8017C930) {
        D_8017C930 = 1;
    }
    first = 0;
    q = ctx;
    for (;;) {
        osRecvMesg(F(q, s32, 12), &msg, 1);
        switch (*msg) {
        case 13:
            __osViSwapContext();
            if (--D_8017C930 == 0) {
                ctx = func_8009D240();
                if (F(ctx, s32, 16)) {
                    osSendMesg(F(ctx, s32, 16), F(ctx, s32, 20), 0);
                }
                D_8017C930 = F(ctx, u16, 2);
            }
            D_8017C844++;
            if (first) {
                first = 0;
                count = func_80097250();
                D_8017C850 = count;
            }
            count = D_8017C840;
            D_8017C840 = func_80097250();
            count = D_8017C840 - count;
            D_8017C850 += count;
            break;
        case 14:
            __osTimerInterrupt();
            break;
        }
    }
}
