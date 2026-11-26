typedef struct E8D790 {
    u8 pad0[0x44];
    s32 f44;
    u8 pad48[0xB0 - 0x48];
    s16 fB0;
    u8 padB2[0xBE - 0xB2];
    u8 fBE;
    u8 padBF[0x13C - 0xBF];
} E8D790;
extern s32 D_8017B204;
extern E8D790 *D_8017B20C;

s32 func_8008D790(s32 arg0, s16 arg1) {
    E8D790 *p;
    s32 i;
    s32 n;

    if (arg0 == 0) {
        return 0;
    }
    i = 0;
    n = 0;
    p = D_8017B20C;
    for (; i < D_8017B204; i++, p++) {
        if (p->f44 == arg0) {
            n++;
            p->fB0 = arg1;
            p->fBE = 0xFF;
        }
    }
    return n;
}
