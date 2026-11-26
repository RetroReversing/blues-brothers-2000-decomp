extern s32 D_800B4980;
extern s32 D_8013FB20;
s32 func_8002ECB8(void) {
    switch (D_800B4980) {
    case 1:
    case 2:
        if (D_8013FB20 == 0xFF) return 1;
        break;
    case 3:
        if (D_8013FB20 == 0) return 1;
        break;
    }
    return 0;
}
