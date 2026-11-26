/* identical to order_post_wakeup in V-RALLY-PAL (matched), with its names changed by decompdecomp */
extern char D_80177FB8[];
void func_80097B20(char *a, int b, int c);
/* Posts a zero-valued blocking message to the order state's message queue. */
/* Wakes the order thread by posting a zero message to the queue at D_80177FB8+0x87A8 (no wait). */ void func_800A3530(void) { func_80097B20(D_80177FB8 + 0x87A8, 0, 0); }
