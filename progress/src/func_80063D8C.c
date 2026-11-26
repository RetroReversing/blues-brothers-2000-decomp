/* identical to select_set_text_default in V-RALLY-PAL (matched), with its names changed by decompdecomp */
void func_8002D604(void);
void func_8001BF38(s32);

/* Resets the select-screen defaults, then sets the select text to the given id. */
void func_80063D8C(s32 textId) {
    func_8002D604();
    func_8001BF38(textId);
}
