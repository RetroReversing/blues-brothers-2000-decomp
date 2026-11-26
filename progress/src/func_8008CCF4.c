extern s32 D_8017B230;
void func_80090238();

u8 *func_8008CCF4(s32 arg0, u8 *arg1) {
    u8 c;

    c = *arg1++;
    if (D_8017B230 == 1) {
        func_80090238(c);
    }
    return arg1;
}

