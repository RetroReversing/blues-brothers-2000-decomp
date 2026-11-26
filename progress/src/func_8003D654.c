s32 func_8002D298(s32, s32, s32);
s32 func_8002D5CC(void *);
extern s32 D_800B5DD4;
extern s32 D_800B9EA0;
extern s32 D_800B9ECC;
extern s32 D_80107040;
extern s32 D_801073B0;
extern s32 D_801073C0;
extern s32 D_80140228;

s32 func_8003D654(void *arg0) {
    s32 r;

    r = 0;
    *(s32 *)((s8 *)arg0 + 0x70) = func_8002D298(0xFF, *(s32 *)((s8 *)arg0 + 0x70), D_800B9ECC * 8);
    D_80140228 = 0;
    D_800B5DD4 = 0;
    if (abs(D_801073B0) < 20 && abs(D_801073C0) < 20) {
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
    }
    if (func_8002D5CC(arg0) != 0) {
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
        if (D_801073C0 > 30) {
            r = 1;
            *(s32 *)((s8 *)arg0 + 0x64) = 15;
            *(s32 *)((s8 *)arg0 + 0x88) -= 1;
        }
        if (D_801073C0 < -30) {
            r = 1;
            *(s32 *)((s8 *)arg0 + 0x64) = 15;
            *(s32 *)((s8 *)arg0 + 0x88) += 1;
        }
        if (*(s32 *)((s8 *)arg0 + 0x84) <= 0) {
            if (D_80107040 & 0x400) {
                r = 1;
                *(s32 *)((s8 *)arg0 + 0x84) = 15;
                *(s32 *)((s8 *)arg0 + 0x88) += 1;
            }
            if (D_80107040 & 0x800) {
                r = 1;
                *(s32 *)((s8 *)arg0 + 0x84) = 15;
                *(s32 *)((s8 *)arg0 + 0x88) -= 1;
            }
        } else {
            *(s32 *)((s8 *)arg0 + 0x84) -= D_800B9EA0;
        }
    }
    return r;
}
