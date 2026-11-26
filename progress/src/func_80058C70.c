extern s32 D_800B81D0;
void func_80023A74(s32, s32);
void setSlotAsset(s32, s32, s32);

void func_80058C70(void) {
    func_80023A74(0xC, 0x115);
    if (D_800B81D0 == 0) {
        setSlotAsset(0x4E, 0x119, 0);
        setSlotAsset(0x4F, 0x11B, 0);
        setSlotAsset(0x50, 0x118, 0);
        setSlotAsset(0x52, 0x116, 0);
        setSlotAsset(0x51, 0x11C, 1);
        setSlotAsset(0x53, 0x117, 1);
        setSlotAsset(0x54, 0x11A, 1);
    } else {
        setSlotAsset(0x4F, 0x11B, 0);
        setSlotAsset(0x51, 0x11C, 1);
    }
}
