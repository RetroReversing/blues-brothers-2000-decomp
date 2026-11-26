extern s32 D_800AB390;
extern s32 D_800AB9A0;
extern s32 D_800BD6B0[2];
extern s32 D_800BD6B8;
extern s32 D_800BD6BC;
extern s32 D_800BD6C0;
extern s32 D_800CD0E0;
extern s32 D_800CD0E8;
extern s32 D_800CD0EC;
extern s32 D_800CD0F0;
extern s32 D_800CD108[3];

void func_8001EBF4(s32 arg0) {
    D_800AB390 = -1;
    D_800AB9A0 = 0;
    if (arg0 != 0) {
        D_800BD6C0 = 1000;
    } else {
        D_800BD6C0 = 2500;
    }
    D_800CD0E8 = 0;
    D_800CD0E0 = D_800BD6C0;
    D_800BD6B8 = 0;
    D_800CD108[2] = 0xFF;
    D_800CD108[1] = 0;
    D_800CD0EC = 0;
    D_800CD108[0] = 0;
    D_800CD0F0 = 0;
    D_800BD6BC = 0;
    D_800BD6B0[1] = 0;
    D_800BD6B0[0] = 0;
}
