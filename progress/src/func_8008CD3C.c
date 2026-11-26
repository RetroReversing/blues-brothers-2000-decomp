extern void (*D_8017B240)(s32, u8);
u8 *func_8008CD3C(s32 *arg0, u8 *p) {
    u8 cmd = *p++;
    if (*p++ & 0x80) {
        p++;
    }
    if ((arg0[0] & 3) == 2) {
        if (D_8017B240 != 0) {
            D_8017B240(arg0[0x11], cmd);
        }
    }
    return p;
}
