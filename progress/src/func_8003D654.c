s32 approachS32(s32, s32, s32);
s32 tickActorTimer(void *);
extern s32 D_800B5DD4;
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern s32 D_80107040;
extern s32 D_801073B0;
extern s32 D_801073C0;
extern s32 D_80140228;

s32 func_8003D654(void *arg0) {
    s32 r;

    r = 0;
    *(s32 *)((s8 *)arg0 + 0x70) = approachS32(0xFF, *(s32 *)((s8 *)arg0 + 0x70), gCamSpeedScale * 8);
    D_80140228 = 0;
    D_800B5DD4 = 0;
    if (abs(D_801073B0) < 20 && abs(D_801073C0) < 20) {
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
    }
    if (tickActorTimer(arg0) != 0) {
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
            *(s32 *)((s8 *)arg0 + 0x84) -= gFrameScale;
        }
    }
    return r;
}
