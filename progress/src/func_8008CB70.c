/* Partial candidate from function #317827580863 in project #74; rechecked locally. */
/* adapted from similar verified C in func_8008A3D8 in ARMYMEN SARGE 2 (matched), with its names changed by decompdecomp */
/* identical to func_80080138 in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80098B98 in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80068424 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in FrandNote in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 func_8008F218(s32 scale);

/* Reads two bytes of note data: the first is scaled by a random value and stored at arg0+0xB5, then the second is added and stored there too. Returns the data pointer past both bytes. */
unsigned char *func_8008CB70(char *arg0, unsigned char *arg1) {
    int v = func_8008F218(*arg1++);
    arg0[189] = v;
    v += *arg1;
    arg0[189] = v;
    return arg1 + 1;
}
