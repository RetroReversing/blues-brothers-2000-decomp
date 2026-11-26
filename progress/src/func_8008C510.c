typedef struct Voice {
    u8 pad0[0x74];
    s32 channel;   /* 0x74 */
    u8 pad78[0x9C - 0x78];
    s16 vol;       /* 0x9C */
    u8 pad9E[0xA8 - 0x9E];
    s16 base;      /* 0xA8 */
    u8 padAA[0x13C - 0xAA];
} Voice;
extern s32 D_8017B214;
extern Voice *D_8017B20C;
extern s32 D_8017B204;

u8 *func_8008C510(u8 *ch, u8 *ptr) {
    s32 value;
    s32 scaled;
    s32 i;
    Voice *v;

    value = (*ptr * 0x6000 / 120) / D_8017B214;
    scaled = (value * *(s16 *) (ch + 0x98)) >> 7;
    ptr++;
    if (*(s32 *) (ch + 0x78) != 0) {
        *(s16 *) (ch + 0x9C) = value;
    } else {
        v = D_8017B20C;
        for (i = 0; i < D_8017B204; i++, v++) {
            if (v->channel == *(s32 *) (ch + 0x74)) {
                v->base = value;
                v->vol = scaled;
            }
        }
    }
    return ptr;
}
