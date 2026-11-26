extern s32 __rmonGetThreadStatus(s32, s32, KKStatusEvent*);
extern OSThread* func_800A41F0(void);
extern s32 func_800A5620(void);
extern void func_800A5688(void);
extern void __rmonSendReply(KKHeader*, s32, s32);
extern u8 D_801810C0;

s32 __rmonRunThread(KKRunThreadRequest* request) {
    KKObjectEvent reply;
    KKStatusEvent event;
    OSThread* tptr;
    s32 start;

    switch (request->header.method) {
    case 0:
        tptr = func_800A41F0();
        while (tptr->priority != -1) {
            if (tptr->id == request->tid) {
                break;
            }
            tptr = tptr->tlnext;
        }
        if (tptr->priority == -1) {
            return -2;
        }
        if (tptr->state != 1) {
            return -4;
        }
        tptr->flags &= 0xFFFC;
        if (request->actions.flags & 2) {
            tptr->context.pc = request->actions.vaddr;
        }
        if (request->actions.flags & 1) {
            if (__rmonSetSingleStep(request->tid, tptr->context.pc) == 0) {
                return -4;
            }
        }
        start = 1;
        break;
    case 1:
        if (func_800A5620() != 0) {
            return -4;
        }
        if (request->actions.flags & 2) {
            __rmonWriteWordTo(0x04080000, request->actions.vaddr - 0x04001000);
        }
        if (request->actions.flags & 1) {
            if ((__rmonGetBranchTarget(1, 0x3E8, __rmonReadWordAt(0x04080000) + 0x04001000) & 3) == 0) {
                func_800A5688();
            }
            func_800A5688();
            D_801810C0 = 1;
        } else {
            D_801810C0 = 0;
            __rmonRunRCP();
        }
        reply.header.code = request->header.code;
        reply.header.error = 0;
        reply.object = request->tid;
        __rmonSendReply(&reply.header, 0x10, 1);
        if (request->actions.flags & 1) {
            __rmonGetThreadStatus(1, 0x3E8, &event);
            __rmonGetExceptionStatus(&event);
            __rmonSendReply(&event.header, 0x4C, 2);
        }
        return 0;
    default:
        return -4;
    }
    reply.header.code = request->header.code;
    reply.header.error = 0;
    reply.object = request->tid;
    __rmonSendReply(&reply.header, 0x10, 1);
    if (start != 0) {
        osStartThread(tptr);
    }
    return 1;
}
