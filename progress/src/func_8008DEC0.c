extern s32 D_8017B244;
extern s32 D_8017B248;
extern s32 D_8017B24C;
extern s32 D_8017B250;
void func_80090D28(void *, void *, s32);

s32 func_8008DEC0(void *arg0) {
    s32 next;

    next = (D_8017B248 + 1) % D_8017B24C;
    if (next == D_8017B244) {
        return 0;
    }
    func_80090D28((void *)(D_8017B250 + D_8017B248 * 8), arg0, 8);
    D_8017B248 = next;
    return 1;
}
