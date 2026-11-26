typedef struct E8DA30 {
    u8 pad0[0x44];
    s32 f44;
    u8 pad48[0x7C - 0x48];
    s32 f7C;
    u8 pad80[0x13C - 0x80];
} E8DA30;
extern s32 D_8017B204;
extern E8DA30 *D_8017B20C;

s32 func_8008DA30(s32 arg0) {
    E8DA30 *p;
    s32 i;

    if (arg0 == 0) {
        return 0;
    }
    i = 0;
    p = D_8017B20C;
    for (; i < D_8017B204; i++, p++) {
        if (p->f44 == arg0) {
            return p->f7C;
        }
    }
    return 0;
}
