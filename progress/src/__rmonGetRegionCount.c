s32 __rmonGetRegionCount(KKObjectRequest* req0) {
    KKHeader* req = (KKHeader*)req0;
    KKObjectRequest* request = (KKObjectRequest*)req;
    KKNumberEvent reply;
    reply.header.code = request->header.code;
    reply.header.error = TV_ERROR_NO_ERROR;
    reply.object = request->object;
    reply.number = (req->method == RMON_RSP) ? 2 : 5;
    __rmonSendReply(&reply.header, sizeof(reply), KK_TYPE_REPLY);
    return TV_ERROR_NO_ERROR;
}
