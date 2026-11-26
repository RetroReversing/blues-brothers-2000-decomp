s32 func_8000C43C(void);
void func_80023A74(s32, s32);
void func_80023A98(s32, s32, s32);

void func_8005AE90(void) {
    func_80023A74(0x32, 0x303);
    func_80023A98(0xC6, 0x2FF, 0);
    func_80023A98(0xC7, 0x305, 0);
    func_80023A98(0xC8, 0x306, 0);
    func_80023A98(0xC9, 0x304, 0);
    func_80023A98(0xCA, 0x300, 0);
    func_80023A98(0xCB, 0x301, 0);
    func_80023A98(0xCC, 0x2FC, 0);
    func_80023A98(0xCD, 0x2FD, 0);
    func_80023A98(0xCE, 0x2FE, 0);
    if (func_8000C43C() != 1) {
        func_80023A98(0xCF, 0x302, 0);
    }
}
