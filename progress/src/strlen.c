/* identical to func_8004A0D8 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to strlen in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to str_len in Shadowman (local match library) (matched), with its names changed by decompdecomp */
/* identical to strlen in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Returns length of a null‑terminated string */
s32 strlen(u8 *str) {
    u8 *p = str;
    if (*str != 0) {
        do {
            p += 1;
        } while (*p != 0);
    }
    return p - str;
}
