s32 cameraGetMode(void);
void func_80023A74(s32, s32);
void setSlotAsset(s32, s32, s32);

void func_8005AE90(void) {
    func_80023A74(0x32, 0x303);
    setSlotAsset(0xC6, 0x2FF, 0);
    setSlotAsset(0xC7, 0x305, 0);
    setSlotAsset(0xC8, 0x306, 0);
    setSlotAsset(0xC9, 0x304, 0);
    setSlotAsset(0xCA, 0x300, 0);
    setSlotAsset(0xCB, 0x301, 0);
    setSlotAsset(0xCC, 0x2FC, 0);
    setSlotAsset(0xCD, 0x2FD, 0);
    setSlotAsset(0xCE, 0x2FE, 0);
    if (cameraGetMode() != 1) {
        setSlotAsset(0xCF, 0x302, 0);
    }
}
