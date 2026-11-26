typedef struct {
    unsigned type : 6;
    unsigned length : 2;
    char buf[3];
} rdbPacket;
extern u8 D_8017C5C0[12];
extern u32 D_800BB220;
extern u8 *D_800BB240;
void send(u8 *s, u32 n);

static u32 string_to_u32(u8 *s) {
    u32 k;

    k = ((s[0] & 0xFF) << 0x18);
    k |= ((s[1] & 0xFF) << 0x10);
    k |= ((s[2] & 0xFF) << 0x8);
    k |= (s[3] & 0xFF);

    return k;
}

void kdebugserver(rdbPacket packet) {
    u32 i;
    u32 length;
    u8 *addr;

    for (i = 0; i < 3; i++) {
        D_8017C5C0[D_800BB220++] = packet.buf[i];
    }

    if (D_8017C5C0[0] == 2) {
        send(D_800BB240 + 0x20, 0x190);
        D_800BB220 = 0;
    } else if (D_800BB220 >= 9 && D_8017C5C0[0] == 1) {
        addr = (u8 *)string_to_u32(&D_8017C5C0[1]);
        length = string_to_u32(&D_8017C5C0[5]);
        send(addr, length);
        D_800BB220 = 0;
    }
}
