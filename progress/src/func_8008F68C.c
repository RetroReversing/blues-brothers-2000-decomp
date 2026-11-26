typedef struct Entry {
    s32 x0;
    s32 used;       /* 0x04 */
    u8 pad08[0x40];
    s32 prio;       /* 0x48 */
    u8 pad4C[0x2C];
    s32 active;     /* 0x78 */
    u8 pad7C[0xC0];
} Entry;

extern s32 D_8017B204;
extern Entry *D_8017B210;
s32 func_8008F5D8(Entry *e, void *a, s32 b, s32 c, s32 d, s32 f);

s32 func_8008F68C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Entry *found;
    Entry *e;
    s32 i;
    s32 best;

    if (arg4 == -1) {
        arg4 = *(s32 *)(arg0 + (arg1 << 3) + 0x1C);
    }
    best = arg4 + 1;
    i = 4;
    e = D_8017B210;
    for (; i < D_8017B204; i++, e++) {
        if (e->used == 0) {
            return func_8008F5D8(e, arg0, arg1, arg2, arg3, arg4);
        }
        if (e->active != 0 && e->prio < best) {
            best = e->prio;
            found = e;
        }
    }
    if (best < arg4) {
        return func_8008F5D8(found, arg0, arg1, arg2, arg3, arg4);
    }
    return 0;
}
