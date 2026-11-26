/* identical to func_80056FE0 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_801950B0 in BATMAN BEYOND RETURN (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_8005E7B0 in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800C2EC0 in AIDYN_CHRONICLES (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80064B80 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800A9350 in TWINE (local match library) (matched), with its names changed by decompdecomp */
s32 func_8009D8B0(void);
s32 func_8009D860(s32 arg0, s32 *arg1) {
    if (func_8009D8B0() != 0) return -1;
    *arg1 = *(volatile s32 *)((u32)arg0 | 0xA0000000U);
    return 0;
}
