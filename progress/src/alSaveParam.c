/* identical to alSaveParam in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* Saves value into the parameter block for codes 1 (word 0) and 6 (word 5); other codes are ignored. */
s32 func_8009B948(s32 *params, s32 code, s32 value) {
    switch (code) {
    case 1:
        params[0] = value;
        break;
    case 6:
        params[5] = value;
        break;
    }
    return 0;
}
