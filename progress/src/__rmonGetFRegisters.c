typedef struct {
    s32 length;
    s8 code;
    s8 type;
    s16 error;
    u8 rev;
    u8 method;
    s16 notused;
} KKHeader;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectRequest;
typedef struct {
    KKHeader header;
    s32 tid;
    struct {
        struct { u32 regs[32]; } fpregs;
        u32 fpcsr;
        u32 fppad;
    } registers;
} KKFPregEvent;

s32 __rmonGetFRegisters(RmonMsg91FC *req0) {
    register KKObjectRequest *request = (KKObjectRequest *)req0;
    KKFPregEvent reply;
    OSThread *tptr;
    volatile float f;

    if (((KKHeader *)req0)->method != 0) {
        return -2;
    }

    f = 0.0f;

    tptr = (OSThread *)__rmonGetTCB(request->object);
    if (tptr == NULL) {
        return -2;
    }

    __rmonCopyWords((u32 *)reply.registers.fpregs.regs, (u32 *)&tptr->context.fp0, 32);

    reply.registers.fpcsr = tptr->context.fpcsr;
    reply.header.code = request->header.code;
    reply.header.error = 0;
    reply.tid = request->object;

    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}

