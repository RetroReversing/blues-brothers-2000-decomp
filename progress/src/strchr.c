/* identical to func_8004A0A0 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to strchr in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to strchr in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Returns a pointer to the first occurrence of ch in the NUL-terminated str, or NULL. */
u8 *strchr(u8 *str, s32 ch) {
    u8 *p = str;
    u8 v = *p;
    u8 c = ch;

    if (v != c) {
        do {
            if (v == 0) {
                return NULL;
            }
            p++;
            v = *p;
        } while (v != c);
    }
    return p;
}
