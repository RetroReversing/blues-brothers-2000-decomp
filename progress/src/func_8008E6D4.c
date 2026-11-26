void alSynSetPan(void *synth, void *voice, s32 pan);
void alSynSetVol(void *synth, void *voice, s16 vol, s32 t);
extern u8 *D_8017B208;
extern s32 D_8017B218;
extern u16 D_8017B21C;
extern u16 D_8017B21E;
extern u8 D_8017B4A0[];

void func_8008E6D4(u8 *cp, s32 x) {
    u32 vol;
    u32 master;

    vol = (u32) (cp[0xBC] * cp[0xC4] * cp[0xBB] * *(s16 *) (cp + 0x9E)) >> 13;
    if (vol > 0x7FFF) {
        vol = 0x7FFF;
    }
    if (*(s32 *) (cp + 0x78) == 0) {
        master = D_8017B21E;
    } else {
        master = D_8017B21C;
    }
    vol *= master;
    vol >>= 15;
    if (*(s32 *) (cp + 0x10) != -1) {
        vol = (vol * *(s32 *) (cp + 0x10)) / *(u32 *) (cp + 0x1C);
    }
    if (vol != *(u16 *) (cp + 0xA0)) {
        *(u16 *) (cp + 0xA0) = vol;
        alSynSetVol(D_8017B4A0, D_8017B208 + x * 0x1C, vol, D_8017B218);
    }
    vol = ((cp[0xBD] * *(s16 *) (cp + 0xB0)) >> 7) & 0x7F;
    if (vol != cp[0xBE]) {
        cp[0xBE] = vol;
        alSynSetPan(D_8017B4A0, D_8017B208 + x * 0x1C, vol);
    }
}
