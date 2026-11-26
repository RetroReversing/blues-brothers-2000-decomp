s32 func_800253A0(s32);
void func_80023D28(void);
extern s32 D_800CD0C8[2];
extern s32 D_800CD0D4;
extern s32 D_800CD0D8[2];

void func_8001EB70(void) {
    s32 size = 0x25800;

    D_800CD0D8[0] = func_800253A0(0x25800);
    D_800CD0D8[1] = func_800253A0(0x25800);
    D_800CD0C8[1] = D_800CD0D8[1] + size - 1000;
    D_800CD0C8[0] = D_800CD0D8[0] + size - 1000;
    D_800CD0D4 = 0;
    func_80023D28();
}
