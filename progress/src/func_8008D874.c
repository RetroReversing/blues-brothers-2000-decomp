typedef struct {
    u8 pad0[0x44];
    s32 i44;
    u8 pad48[0x98 - 0x48];
    s16 h98;
    u8 pad9A[2];
    s16 h9C;
    u8 pad9E[0xA8 - 0x9E];
    u16 hA8;
    u8 padAA[0x13C - 0xAA];
} Rec;

extern s32 D_8017B204;
extern Rec *D_8017B20C;

s32 func_8008D874(s32 id, s32 val) {
    s32 i;
    s32 n;
    Rec *e;

    if (id == 0) {
        return 0;
    }
    if (val <= 0) {
        val = 1;
    } else if (val >= 0x101) {
        val = 0x100;
    }
    n = 0;
    e = D_8017B20C;
    for (i = 0; i < D_8017B204; i++, e++) {
        if (e->i44 == id) {
            n++;
            e->h98 = val;
            e->h9C = (e->hA8 * val) >> 7;
        }
    }
    return n;
}
