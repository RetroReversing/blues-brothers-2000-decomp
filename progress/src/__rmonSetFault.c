/* Same-name source lead: __rmonSetFault in 1080 SNOWBOARDING; verified ROM source. Destination verification required. */
s32 __rmonSetFault(RmonMsg* msg) {
    RmonMsg* p = msg;
    RmonHdr16 hdr;
    hdr.type = p->type;
    hdr.flags = 0;
    hdr.id = p->id;
    __rmonSendReply(&hdr, 0x10, 1);
    return 0;
}
