typedef struct Entry {
    u8 pad00[0x78];
    u8 *owner;      /* 0x78 */
    u8 pad7C[0x2A];
    u16 slot;       /* 0xA6 */
    u8 padA8[0x94];
} Entry;

extern s32 D_8017B204;
extern Entry *D_8017B210;
extern s32 D_8017B228;
extern u8 *D_8017B238;
extern u8 *D_8017B23C;
s32 func_8008F5D8(Entry *e, u8 *obj, s32 a, s32 b, s32 c, s32 d);
s32 func_8008F68C(u8 *obj, s32 a, s32 b, s32 c, s32 d);

s32 func_8008D3A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *obj;
    Entry *e;
    s32 i;
    s32 ret;

    if (D_8017B23C != NULL) {
        obj = D_8017B23C;
        D_8017B23C = NULL;
    } else {
        obj = D_8017B238;
        if (obj == NULL) {
            D_8017B228 = 0;
            return 0;
        }
    }
    if (D_8017B228 == 0) {
        D_8017B228 = *(s32 *)(obj + 0x10);
    }
    if (arg3 != 0) {
        e = D_8017B210;
        for (i = 4; i < D_8017B204; i++, e++) {
            if (e->slot == arg0 && e->owner == obj) {
                if (arg4 == -1) {
                    arg4 = *(s32 *)(obj + (arg0 << 3) + 0x1C);
                }
                ret = func_8008F5D8(e, obj, arg0, arg1, arg2, arg4);
                D_8017B228 = 0;
                return ret;
            }
        }
    }
    ret = func_8008F68C(obj, arg0, arg1, arg2, arg4);
    D_8017B228 = 0;
    return ret;
}
