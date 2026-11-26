/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
extern u32 D_800AB9B0;
extern s32 D_800AB9B8;
extern u32 D_800AB9BC;
extern u32 D_800AB9C0;
extern u32 D_800AB9C4;
extern char D_800F48F0[];

u32 func_800231FC(void) {
    u32 temp_v0;
    u32 var_a1;

    var_a1 = D_800AB9BC;
    if ((u32) D_800AB9C0 >= var_a1) {
        for (;;) {
            if (*(s32 *)var_a1 != 0) {
                var_a1 += 0x108;
                if ((u32) D_800AB9C0 >= var_a1) {
                    continue;
                }
            }
            break;
        }
    }
    if (var_a1 >= (u32) D_800AB9C0) {
        temp_v0 = var_a1 + 0x108;
        D_800AB9C0 = temp_v0;
        if ((u32) D_800AB9C4 < temp_v0) {
            D_800AB9C0 = D_800AB9C4;
            D_800AB9B8 -= 1;
        }
        *(s32 *)D_800AB9C0 = 0;
    }
    if ((u32) D_800AB9C0 >= (u32) D_800AB9B0) {
        return (u32) &D_800F48F0;
    }
    D_800AB9B8 += 1;
    return var_a1;
}
