void osViSetMode(void *);
void osViSetSpecialFeatures(u32);
extern s32 D_800B9C74;
extern s32 D_800B9C78;
extern s16 D_800B9EE0[8];
extern s32 D_800BB5E0[20];
extern s32 D_801771B8;

void func_80089FA8(s32 arg0)
{
    D_800B9EE0[0] = D_800B9C74 * 2;
    D_800B9EE0[1] = D_800B9C78 * 2;
    D_800B9EE0[5] = D_800B9C78 * 2;
    D_800B9EE0[4] = D_800B9C74 * 2;
    if (D_800B9C74 != 320 && D_800B9C78 != 480) {
        D_800BB5E0[2] = D_800B9C74;
        D_800BB5E0[10] = D_800B9C74 * 2;
        D_800BB5E0[8] = (D_800B9C74 * D_801771B8) / 320;
    }
    if (arg0 != 0) {
        osViSetMode(D_800BB5E0);
        osViSetSpecialFeatures(2);
        osViSetSpecialFeatures(0x40);
    }
}
