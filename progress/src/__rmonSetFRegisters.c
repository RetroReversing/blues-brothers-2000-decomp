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
} KKFPRegsetRequest;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectEvent;

s32 __rmonSetFRegisters(RmonMsg91FC *req0) {
    register KKFPRegsetRequest *request = (KKFPRegsetRequest *)req0;
    OSThread *tptr;
    KKObjectEvent reply;
    volatile float f;

    if (((KKHeader *)req0)->method != 0) {
        return -2;
    }

    f = 0.0f;

    tptr = (OSThread *)__rmonGetTCB(request->tid);
    if (tptr == NULL) {
        return -2;
    }

    __rmonCopyWords((u32 *)&tptr->context.fp0, (u32 *)request->registers.fpregs.regs, 32);
    tptr->context.fpcsr = request->registers.fpcsr;

    reply.object = request->tid;
    reply.header.code = request->header.code;
    reply.header.error = 0;

    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}

