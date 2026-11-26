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
    struct { u32 gregs[37]; } registers;
} KKGRegsetRequest;
typedef struct {
    KKHeader header;
    s32 object;
} KKObjectEvent;

s32 __rmonSetGRegisters(void *req0) {
    KKHeader *req = (KKHeader *)req0;
    register KKGRegsetRequest *request = (KKGRegsetRequest *)req;
    OSThread *tptr;
    u64 *tcbregptr;
    register s32 i;
    KKObjectEvent reply;

    if (req->method == 0) {
        tptr = __rmonGetTCB(request->tid);
        if (tptr == NULL) {
            return -2;
        }
        for (i = 1, tcbregptr = &tptr->context.at; i < 26; i++, tcbregptr++) {
            *tcbregptr = (s32)request->registers.gregs[i];
        }
        for (i = 28, tcbregptr = &tptr->context.gp; i < 34; i++, tcbregptr++) {
            *tcbregptr = (s32)request->registers.gregs[i];
        }
        tptr->context.cause = request->registers.gregs[34];
        tptr->context.pc = request->registers.gregs[35];
        tptr->context.sr = request->registers.gregs[36];
    } else {
        return -2;
    }

    reply.object = request->tid;
    reply.header.code = request->header.code;
    reply.header.error = 0;

    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}


