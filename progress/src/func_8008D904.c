typedef struct {
    u8 pad0[0x44];
    s32 i44;
    u8 pad48[0xCB - 0x48];
    u8 bCB;
    u8 bCC;
    u8 padCD[0x13C - 0xCD];
} Rec;

extern s32 D_8017B204;
extern Rec *D_8017B20C;

s32 func_8008D904(s32 id, s32 val) {
    s32 i;
    s32 n;
    Rec *e;

    if (id == 0) {
        return 0;
    }
    if (val < 0) {
        val = 0;
    } else if (val >= 0x80) {
        val = 0x7F;
    }
    n = 0;
    e = D_8017B20C;
    for (i = 0; i < D_8017B204; i++, e++) {
        if (e->i44 == id) {
            n++;
            e->bCB = val;
            e->bCC = 0xFF;
        }
    }
    return n;
}
