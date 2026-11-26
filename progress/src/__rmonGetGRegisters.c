/* Same-name source lead: __rmonGetGRegisters in 1080 SNOWBOARDING; verified ROM source. Destination verification required. */
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
} KKGregEvent;
s32 __rmonGetGRegisters(void *req0) {
    KKHeader *req = (KKHeader *)req0;
    register KKObjectRequest *request = (KKObjectRequest *)req;
    KKGregEvent reply;
    OSThread *tptr;
    u64 *tcbregptr;
    register s32 i;

    reply.tid = request->object;
    reply.header.code = request->header.code;
    reply.header.error = 0;

    if (req->method == 0) {
        tptr = __rmonGetTCB(request->object);
        if (tptr == NULL) {
            return -2;
        }
        for (i = 1, tcbregptr = &tptr->context.at; i < 26; i++, tcbregptr++) {
            reply.registers.gregs[i] = *tcbregptr;
        }
        for (i = 28, tcbregptr = &tptr->context.gp; i < 34; i++, tcbregptr++) {
            reply.registers.gregs[i] = *tcbregptr;
        }
        reply.registers.gregs[34] = tptr->context.cause;
        reply.registers.gregs[35] = tptr->context.pc;
        reply.registers.gregs[36] = tptr->context.sr;
        reply.registers.gregs[0] = 0;
    } else {
        return -2;
    }

    __rmonSendReply(&reply.header, sizeof(reply), 1);
    return 0;
}
