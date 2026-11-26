/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern s32 D_8017B4F0;
extern s32 D_8017B4F4;
extern s32 D_8017B4FC;

s32 func_80090B90(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    s32 temp_v0;
    u32 temp;
    s32 temp2;

    do {
    temp = (((u32) ((u32) (((arg0 * arg1) + arg2) - 1) / arg2) >> 4) + 1) * 0x10;
    D_8017B4F0 = temp;
    D_8017B4F4 = temp - 0x10;
    temp_v0 = (temp * arg3) / 100;
    D_8017B4FC = temp_v0;
    } while (0);
    temp2 = temp_v0 + 0x10;
    return ((((u32) ((u32) (((arg0 * arg1) + arg2) - 1) / arg2) >> 4) + 1) * 0x10) + temp2;
}
