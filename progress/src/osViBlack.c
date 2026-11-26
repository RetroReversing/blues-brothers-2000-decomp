/* identical to func_800B2E90 in ALL STAR TENNIS '99 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osViBlack in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osViBlack in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800970B0(s32 a0);
void func_800970D0(s32 a0);
extern u16 *D_800BB5B4;

/* Turns the VI blank bit (0x20 in the VI control word at D_800BB5B4) on when
 * active is non-zero, off otherwise. Interrupts are disabled around the update. */
void osViBlack(s32 active)
{
    s32 saved_int;
    u16 *ctrl;

    saved_int = func_800970B0(active);
    if (active & 0xFF) {
        ctrl = D_800BB5B4;
        *ctrl = *ctrl | 0x20;
    } else {
        ctrl = D_800BB5B4;
        *ctrl = *ctrl & 0xFFDF;
    }
    func_800970D0(saved_int);
}
