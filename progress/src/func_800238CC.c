/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
extern u32 D_800AB9BC;
extern u32 D_800AB9C0;

s32 func_800238CC(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;
    u32 var_a1;

    var_a1 = D_800AB9BC;
    /*__repair_loop_weight*/do { do { do { var_v1 = 0; } while (0); } while (0); } while (0);
    if (var_a1 < (u32) D_800AB9C0) {
        do {
            do { do { if (((*(s32 *)var_a1) != 0) && ((arg0 == 0) || ((*(s32 *)var_a1) == arg0))) {
                do { do { do { var_v1 += 1; } while (0); } while (0); } while (0);
            } } while (0); } while (0);
            do { var_a1 += 0x108; } while (0);
        } while (var_a1 < (u32) D_800AB9C0);
    }
    return var_v1;
}
