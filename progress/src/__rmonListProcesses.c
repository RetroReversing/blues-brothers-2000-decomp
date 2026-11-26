s32 __rmonListProcesses(KKHeader* req) {
    KKHeader* p = req;
    KKObjsEvent reply;
    s32 pid;
    reply.object = 0;
    reply.objs.number = 1;
    if (p->method == 1) {
        pid = 0x3E9;
    } else {
        pid = 0x3EA;
    }
    reply.objs.objects[0] = pid;
    reply.header.code = p->code;
    reply.header.error = TV_ERROR_NO_ERROR;
    __rmonSendReply(&reply, sizeof(KKObjsEvent), KK_TYPE_REPLY);
    return 0;
}
