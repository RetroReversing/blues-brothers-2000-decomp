/* Same-name source lead: __rmonThreadStatus in 1080 SNOWBOARDING; verified ROM source. Destination verification required. */
s32 __rmonThreadStatus(KKObjectRequest* req) {
    KKObjectRequest* p = req;
    KKStatusEvent reply;
    if (__rmonGetThreadStatus(p->header.method, p->object, &reply) != 0) {   /* __rmonGetThreadStatus */
        return TV_ERROR_INVALID_ID;
    }
    reply.header.code = p->header.code;
    reply.header.error = TV_ERROR_NO_ERROR;
    __rmonSendReply(&reply, sizeof(KKStatusEvent), KK_TYPE_REPLY);
    return 0;
}
