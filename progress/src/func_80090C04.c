extern s32 D_8017B4F0;
extern u32 D_8017B4F4;
extern s32 D_8017B4FC;

u32 func_80090C04(s32 arg0) {
    u32 t;
    s32 a;
    a = arg0 - 0x10;
    t = (D_8017B4F0 + D_8017B4FC - a) & ~0xF;
    if (t < D_8017B4F4) {
        return D_8017B4F4;
    }
    return t;
}
