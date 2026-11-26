typedef struct E8D618 {
    s32 flags;
    u8 pad4[0xC];
    s32 f10;
    u8 pad14[8];
    s32 f1C;
    u8 pad20[0x24];
    s32 f44;
    u8 pad48[0x13C - 0x48];
} E8D618;
extern s32 D_8017B204;
extern E8D618 *D_8017B20C;

s32 func_8008D618(s32 arg0, s32 arg1) {
    E8D618 *p;
    s32 i;
    s32 n;
    s32 v;

    if (arg0 == 0) {
        return 0;
    }
    v = arg1;
    if (arg1 == 0) {
        v = 1;
    }
    i = 0;
    n = 0;
    p = D_8017B20C;
    for (; i < D_8017B204; i++, p++) {
        if (p->f44 == arg0 && p->f10 == -1) {
            if (p->flags & 1) {
                p->f1C = 1;
                p->f10 = 0;
                p->flags &= ~1;
            } else {
                p->f1C = v;
                p->f10 = arg1;
            }
            n++;
        }
    }
    return n;
}
