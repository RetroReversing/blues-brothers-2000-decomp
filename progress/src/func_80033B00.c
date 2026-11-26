s32 func_80026B50(u8 *, char *);
extern char D_80001294[];
extern char D_8000129C[];
extern s32 D_800B3968;
extern s32 D_800BD0E0[];

void func_80033B00(u8 *arg0) {
    if (func_80026B50(arg0, D_8000129C) == 0) {
        if (arg0[7] == 0xFF) {
            D_800BD0E0[7] = arg0[8] & 0xF;
            D_800BD0E0[8] = (arg0[8] >> 4) & 3;
        }
        D_800B3968 = 0x1001;
    }
    if (func_80026B50(arg0, D_80001294) == 0) {
        D_800B3968 = 0x1002;
        if (arg0[7] == 0xFF) {
            D_800BD0E0[7] = arg0[8] & 0xF;
            D_800BD0E0[8] = arg0[8] >> 4;
        }
    }
}
