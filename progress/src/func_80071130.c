typedef struct Task71 {
    u8 pad0[8];
    u32 x8;
    void *xC;
    u8 task[0x40];
    void *x50;
    void *x54;
} Task71;
typedef struct Obj71b {
    u8 pad0[0x3C];
    u8 q3C[0x70];
    u8 qAC[0x38];
    u8 qE4[0x38];
    u8 q11C[0x550];
    s32 x66C;
    s32 x670;
    Task71 *x674;
    s32 x678;
} Obj71b;
void osRecvMesg(void *, void *, s32);
void osSendMesg(void *, void *, s32);
void osViBlack(s32);
void osViSwapBuffer(void *);
void osSpTaskStartGo(void *);
void rspStartTask(void *);
void func_80071220(Obj71b *, Task71 *);

void func_80071130(Obj71b *o) {
    Task71 *t;
    void *dummy;

    dummy = NULL;
    for (;;) {
        osRecvMesg(o->q3C, &t, 1);
        func_80071220(o, t);
        if (o->x670 != 0) {
            o->x674 = t;
            osRecvMesg(o->q11C, &dummy, 1);
            o->x674 = NULL;
        }
        o->x66C = (s32)t;
        rspStartTask(t->task);
        osSpTaskStartGo(t->task);
        osRecvMesg(o->qAC, &dummy, 1);
        o->x66C = 0;
        osRecvMesg(o->qE4, &dummy, 1);
        if (o->x678 != 0) {
            osViBlack(0);
            o->x678 = 0;
        }
        if (t->x8 & 0x40) {
            osViSwapBuffer(t->xC);
        }
        osSendMesg(t->x50, t->x54, 1);
    }
}
