typedef struct {
    char pad0[6];
    u8 unk6;
    char pad7;
} Rec80048F5C;

extern s32 D_800B76A8;
extern Rec80048F5C *gObjTriLists[];
extern s32 gObjTriCounts[];

void func_80048F5C(void) {
    s32 i;
    s32 j;

    if (D_800B76A8 > 0) {
        for (i = 0; i < 0x1F6; i++) {
            if (gObjTriLists[i] != NULL) {
                for (j = 0; j < gObjTriCounts[i]; j++) {
                    gObjTriLists[i][j].unk6 &= 0xF3;
                }
            }
        }
        D_800B76A8 = 0;
    }
}
