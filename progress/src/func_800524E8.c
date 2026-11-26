/* identical to select_set_text_default in V-RALLY-PAL (matched), with its names changed by decompdecomp */
void func_80043248(void);
void fireActorEvents(s32);

/* Resets the select-screen defaults, then sets the select text to the given id. */
void func_800524E8(s32 textId) {
    func_80043248();
    fireActorEvents(textId);
}
