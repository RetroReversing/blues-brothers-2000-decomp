s32 osCreateMesgQueue(void *, void *, s32);
s32 osSetEventMesg(u32, void *, void *);
s32 osRecvMesg(void *, void *, s32);
s32 __rmonExecute(void *);
u32 __osRdbSend(u8 *buf, u32 size, u32 type);
extern u8 D_80180780[];
extern u8 D_80180798[];
extern u8 *D_801807A0;
extern u8 D_801807A8[];

void __rmonIOhandler(void) {
    int sent;
    u8 tstr[2];

    osCreateMesgQueue(D_80180780, D_80180798, 1);
    osSetEventMesg(0x14, D_80180780, NULL);
    D_801807A0 = D_801807A8;

    while (1) {
        osRecvMesg(D_80180780, NULL, 1);
        __rmonExecute(D_801807A8);
        D_801807A0 = D_801807A8;

        sent = 0;
        while (sent <= 0) {
            sent += __osRdbSend(tstr, 1, 0xB);
        }
    }
}


