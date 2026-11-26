void __rmonSendReply(KKHeader* reply, s32 size, s32 type) {
    s32 sent = 0;
    s32 len;
    reply->length = size;
    while (sent < 4) {
        sent += __osRdbSend((u8*)&size + sent, 4 - sent, 8);
    }
    sent = 0;
    len = size;
    reply->rev = 2;
    reply->type = type;
    while ((u32)sent < (u32)len) {
        sent += __osRdbSend((u8*)reply + sent, len - sent, 8);
    }
    __rmonIOflush();
}
