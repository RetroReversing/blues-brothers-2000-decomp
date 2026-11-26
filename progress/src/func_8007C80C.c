void func_8002710C(s32, s32, s32, s32);
s32 func_80023E18(s32);
void func_800272E0(s32, s32, s32, s32);
extern s32 D_801700F0;
extern s32 D_80170100;

void func_8007C80C(s32 *arg0) {
    s32 q;
    s32 r;

    func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800272E0(func_80023E18(D_80170100), 0x90, 0x68, 0);
    q = arg0[0x90 / 4] / 6;
    r = arg0[0x90 / 4] % 6;
    switch (q) {
    case 4:
        func_8002710C(0xFF, 0xFF, 0xFF, r * 42);
        func_800272E0(func_80023E18(D_801700F0), 0x7E, 0x28, 0);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800272E0(func_80023E18(D_801700F0), 0x9E, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xBE, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xDE, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 3:
        func_8002710C(0xFF, 0xFF, 0xFF, r * 42);
        func_800272E0(func_80023E18(D_801700F0), 0x9E, 0x28, 0);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800272E0(func_80023E18(D_801700F0), 0xBE, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xDE, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 2:
        func_8002710C(0xFF, 0xFF, 0xFF, r * 42);
        func_800272E0(func_80023E18(D_801700F0), 0xBE, 0x28, 0);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800272E0(func_80023E18(D_801700F0), 0xDE, 0x28, 0);
        func_800272E0(func_80023E18(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 1:
        func_8002710C(0xFF, 0xFF, 0xFF, r * 42);
        func_800272E0(func_80023E18(D_801700F0), 0xDE, 0x28, 0);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800272E0(func_80023E18(D_801700F0), 0xFE, 0x28, 0);
        break;
    case 0:
        func_8002710C(0xFF, 0xFF, 0xFF, r * 42);
        func_800272E0(func_80023E18(D_801700F0), 0xFE, 0x28, 0);
        func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
        break;
    }
}
