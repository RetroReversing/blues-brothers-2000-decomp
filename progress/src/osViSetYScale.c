/* identical to osViSetYScale in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osViSetYScale in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800970B0();
void func_800970D0(s32);
extern void *D_800BB5B4;

/* Sets the VI controller's Y scale and turns on the scale enable bit, with interrupts off. */
void osViSetYScale(f32 yScale)
{
    s32 savedInt;

    savedInt = func_800970B0();
    *(f32 *)((s8 *)D_800BB5B4 + 0x24) = yScale;
    *(u16 *)((s8 *)D_800BB5B4 + 0) = (u16)(*(u16 *)((s8 *)D_800BB5B4 + 0) | 4);
    func_800970D0(savedInt);
}
