/* Same-name source lead: __rmonIOputw in 1080 SNOWBOARDING; verified ROM source. Destination verification required. */
void __rmonIOputw(s32 arg0) {
    s32 totalRecv;
    char* p;
    totalRecv = 0;
    p = (char*)&arg0;
    do {
        register s32 recv = __osRdbSend(p + totalRecv, 4 - totalRecv, 8);
        totalRecv += recv;
    } while (totalRecv < 4);
}
