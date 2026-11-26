/* Same-name source lead: __rmonSendHeader in 1080 SNOWBOARDING; verified ROM source. Destination verification required. */
void __rmonSendHeader(KKHeader* block, s32 size, s32 type) {
    s32 totalSent;
    s32 sent;
    char* p = (char*)block;

    block->rev = KK_REV;
    block->type = type;
    for (totalSent = 0; (u32)totalSent < (u32)size; totalSent += sent) {
        sent = __osRdbSend(p + totalSent, size - totalSent, 8);
    }
}
