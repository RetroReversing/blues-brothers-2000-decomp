/* identical to coss in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Cosine of a 16-bit angle (0x10000 = full turn): sin of the angle advanced by a quarter turn. */
extern s16 func_80095F60(s32);

s16 coss(s32 angle) {
    return func_80095F60((angle + 0x4000) & 0xFFFF);
}
