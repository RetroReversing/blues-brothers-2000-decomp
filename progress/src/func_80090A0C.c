typedef struct { u32 w0, w1; } Acmd;
typedef struct {
    Acmd *list;
    s32 size;
    void *a;
    void *b;
} AudMsg;
typedef struct {
    void (*init)(void);
    void (*wait)(void);
    void (*send)(AudMsg *);
} AudFuncs;
typedef struct {
    s32 addr;
    s32 len;
} AudBuf;
void ai_dma_start(s32, s32);
Acmd *alAudioFrame(Acmd *, s32 *, s32, s32);
void func_80090418(void);
s32 func_80090C04(u32);
u32 func_8009C7A0(void);
s32 func_8009C7B0(void);
s32 osVirtualToPhysical(s32);
extern u8 D_8008B540[];
extern u8 D_800BA380[];
extern AudFuncs *D_800BA92C;
extern AudBuf *D_800BA930;
extern AudBuf *D_8017B494;
extern Acmd *D_8017B498;

void func_80090A0C(void) {
    AudMsg msg;
    s32 cmdLen;
    u32 i;
    s32 status;
    u32 len;
    AudBuf *buf;
    Acmd *end;

    msg.list = D_8017B498;
    msg.a = D_8008B540;
    msg.b = D_800BA380;
    i = 0;
    D_800BA92C->init();
    for (;;) {
        do {
            D_800BA92C->wait();
            status = func_8009C7B0();
            len = func_8009C7A0() >> 2;
        } while (status & 0x80000000);
        func_80090418();
        if (D_800BA930 != NULL && cmdLen != 0) {
            ai_dma_start(D_800BA930->addr, D_800BA930->len << 2);
        }
        buf = &D_8017B494[i];
        buf->len = func_80090C04(len);
        end = alAudioFrame(D_8017B498, &cmdLen, osVirtualToPhysical(buf->addr), buf->len);
        if (cmdLen != 0) {
            msg.size = (end - D_8017B498) * sizeof(Acmd);
            D_800BA92C->send(&msg);
            D_800BA930 = buf;
        }
        i = (i + 1) % 3;
    }
}
