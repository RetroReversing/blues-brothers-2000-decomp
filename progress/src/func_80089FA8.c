void osViSetMode(void *);
void osViSetSpecialFeatures(u32);
extern s32 gScreenWidth;
extern s32 gScreenHeight;
extern s16 D_800B9EE0[8];
extern s32 D_800BB5E0[20];
extern s32 D_801771B8;

void func_80089FA8(s32 arg0)
{
    D_800B9EE0[0] = gScreenWidth * 2;
    D_800B9EE0[1] = gScreenHeight * 2;
    D_800B9EE0[5] = gScreenHeight * 2;
    D_800B9EE0[4] = gScreenWidth * 2;
    if (gScreenWidth != 320 && gScreenHeight != 480) {
        D_800BB5E0[2] = gScreenWidth;
        D_800BB5E0[10] = gScreenWidth * 2;
        D_800BB5E0[8] = (gScreenWidth * D_801771B8) / 320;
    }
    if (arg0 != 0) {
        osViSetMode(D_800BB5E0);
        osViSetSpecialFeatures(2);
        osViSetSpecialFeatures(0x40);
    }
}
