extern s32 D_8017B214;
extern s32 D_8017B228;
extern s32 D_8017B22C;

void func_8008F2A8(u8 *cp) {
    u8 old;
    u8 *work;
    u32 i;
    s16 v;
    s32 w;

    old = cp[0xC9];
    *(s32 *) (cp + 0x4) = 0;
    work = cp;
    for (i = 0; i < 0x13C; i++) {
        *work++ = 0;
    }
    cp[0xCC] = 0xFF;
    cp[0xBE] = 0xFF;
    v = 0x6000 / D_8017B214;
    cp[0xD3] = 0x7F;
    cp[0xBC] = 0x7F;
    cp[0xBD] = 0x40;
    cp[0xBF] = 1;
    cp[0xC1] = 0x7F;
    cp[0xC7] = 0xFF;
    cp[0xC2] = 0x7F;
    cp[0xC6] = 1;
    cp[0xC8] = 0xF;
    w = D_8017B228;
    *(u16 *) (cp + 0xA0) = 0xFFFF;
    *(s16 *) (cp + 0x9A) = 1;
    *(s16 *) (cp + 0xA2) = 1;
    *(f32 *) (cp + 0x28) = 99.9f;
    *(s16 *) (cp + 0xA4) = 1;
    *(s32 *) (cp + 0x10) = -1;
    *(s16 *) (cp + 0x9E) = 0x80;
    *(s16 *) (cp + 0xB0) = 0x80;
    *(f32 *) (cp + 0x6C) = 0.03125f;
    *(f32 *) (cp + 0x58) = 1.0f;
    *(s16 *) (cp + 0x98) = 0x80;
    *(f32 *) (cp + 0x5C) = 0.003921569f;
    *(f32 *) (cp + 0x60) = 0.06666667f;
    *(s16 *) (cp + 0xA8) = v;
    *(s16 *) (cp + 0x9C) = v;
    if (w == 0) {
        w = D_8017B22C;
    }
    *(s32 *) (cp + 0x7C) = w;
    cp[0xC9] = old;
}
