typedef struct { u8 data[0x20]; } PfsState;
s32 osPfsFileState(void *, s32, PfsState *);
s32 osPfsFreeBlocks(void *, s32 *);
s32 osPfsInitPak(void *, void *, s32);
s32 osPfsIsPlug(void *, u8 *);
s32 osPfsNumFiles(void *, s32 *, s32 *);
extern s32 D_800AE174;
extern s32 D_800AE178;
extern s32 D_800AE19C;
extern s32 D_800AE1A0;
extern u8 D_80107050;
extern u8 D_80107058[];
extern s32 D_801071B0[];
extern u8 D_80107210[];
extern PfsState D_801073D0[];

s32 func_80026848(s32 arg0) {
    s32 max;
    s32 ret;
    s32 i;

    max = 0x10;
    osPfsIsPlug(D_80107058, &D_80107050);
    if (arg0 != 0) {
        D_800AE178 = 0;
        ret = osPfsInitPak(D_80107058, D_80107210, 0);
        if (ret == 10 || ret == 11) {
            if (ret == 10) {
                D_800AE174 = 1;
            } else {
                D_800AE174 = 0;
            }
            D_80107050 &= 0xFE;
            return 0;
        }
        D_800AE174 = 0;
        D_800AE178 = 1;
    }
    ret = osPfsNumFiles(D_80107210, &max, &D_800AE19C);
    if (ret != 0) {
        if (ret == 2) {
            return 0;
        }
    }
    for (i = 0; i < 0x10; i++) {
        D_801071B0[i] = osPfsFileState(D_80107210, i, &D_801073D0[i]);
    }
    ret = osPfsFreeBlocks(D_80107210, &D_800AE1A0);
    if (ret != 0) {
        if (ret == 2) {
            return 0;
        }
    }
    return 1;
}
