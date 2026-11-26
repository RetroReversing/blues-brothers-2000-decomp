void func_80025280(void *);
s32 debugPrintf(s32 *);
extern s32 D_800010C4;
extern s32 D_800AE010;

void *func_80025820(void *arg0, u32 arg1) {
    s8 *p = arg0;
    u32 *hdr;
    u32 size;
    u32 *next;
    u32 total;

    hdr = (u32 *)(p - 8);
    size = hdr[0];
    do {} while (0);
    if (size < arg1) {
        debugPrintf(&D_800010C4);
        hdr = (u32 *)(p - 8);
        p = arg0;
    }
    total = arg1 + 8;
    next = (u32 *)((s8 *)hdr + total);
    hdr[0] = arg1;
    hdr[1] = D_800AE010;
    next[0] = (size - total) | 1;
    next[1] = 0;
    func_80025280(next + 2);
    return p;
}
