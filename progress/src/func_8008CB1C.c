/* Partial candidate from function #317827580862 in project #74; rechecked locally. */
/* adapted from similar verified C in func_8008A388 in ARMYMEN SARGE 2 (matched), with its names changed by decompdecomp */
/* identical to func_800800E8 in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_80098B48 in ARMYMENAIRCOMBAT (local match library) (matched), with its names changed by decompdecomp */
/* identical to func_800683D4 in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in FrandNote in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 func_8008F218(s32 scale);

/* Reads two bytes of note data: the first is scaled by a random value and stored at arg0+0xB5, then the second is added and stored there too. Returns the data pointer past both bytes. */
unsigned char *func_8008CB1C(char *arg0, unsigned char *arg1) {
    int v = func_8008F218(*arg1++);
    arg0[188] = v;
    v += *arg1;
    arg0[188] = v;
    return arg1 + 1;
}
