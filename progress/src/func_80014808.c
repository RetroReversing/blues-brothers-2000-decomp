/* adapted from similar verified C in func_8002D270 in V-RALLY-PAL (matched), with its names changed by decompdecomp */
extern char D_800BD06C[];
s32 func_8003C140(s32);
extern s32 D_8009693C;

/* Receives the next message for the order task whose pointer is stored at D_8009693C+0x58F4. */
void func_80014808(void)
{
    func_8003C140(*(s32 *)((u8 *)&D_800BD06C));
}
