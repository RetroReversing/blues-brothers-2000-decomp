extern u32 D_800AB9BC;
extern u32 D_800AB9C0;
s32 *func_80023920(s32 arg0, s32 arg1, s32 arg2) {
    u32 p;


    if (arg2 == 0) {
        p = D_800AB9BC;
    } else {
        p = arg2 + 0x108;
    }

    for (; p < D_800AB9C0; p += 0x108) {
        s32 v = *(s32 *)p;
        if (v >= arg0 && arg1 >= v) {
            return (s32 *)p;
        }
    }
    return NULL;
}
