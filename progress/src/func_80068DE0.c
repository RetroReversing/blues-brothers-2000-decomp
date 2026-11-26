/* identical to select_set_text_default in V-RALLY-PAL (matched), with its names changed by decompdecomp */
void func_80068CBC(void);
void func_80043248(s32);

/* Resets the select-screen defaults, then sets the select text to the given id. */
void func_80068DE0(s32 textId) {
    func_80068CBC();
    func_80043248(textId);
}
