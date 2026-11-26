typedef struct {
    u8 pad0[0x6C];
    s32 unk6C;
    u8 pad70[0x7C - 0x70];
    s32 unk7C;
    s32 unk80;
    u8 pad84[0x9C - 0x84];
    void *unk9C;
    u8 padA0[0xC0 - 0xA0];
    s32 unkC0;
    u8 padC4[0xD8 - 0xC4];
    s32 unkD8;
} State35238;

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
} Other35238;

extern State35238 *D_800B3960;
extern Other35238 *gCameraTarget;
s32 cameraGetMode(void);
void func_80034E40(State35238 *);
void func_800340B4(void);
void func_800350F4(void);
void func_80035164(void);
void updateCamera(void);
void func_80047558(void);
void cameraUpdateByMode(void);
void func_8007FACC(void);

void func_80035238(void) {
    D_800B3960->unk7C = 1000;
    D_800B3960->unk6C = 0;
    D_800B3960->unk80 = -0x800;
    D_800B3960->unkC0 = 0;
    gCameraTarget->unk14 = 0;
    D_800B3960->unkD8 = 0;
    func_80034E40(D_800B3960);
    switch (cameraGetMode()) {
    case 0x21:
        D_800B3960->unk9C = cameraUpdateByMode;
        break;
    case 0x1:
        D_800B3960->unk9C = (u8 *)func_80047558 + 8;
        break;
    case 0x24:
        D_800B3960->unk9C = updateCamera;
        break;
    case 0x5:
        D_800B3960->unk9C = cameraUpdateByMode;
        break;
    case 0x37:
        D_800B3960->unk9C = cameraUpdateByMode;
        break;
    case 0x25:
        D_800B3960->unk9C = func_8007FACC;
        break;
    case 0x23:
    case 0x30:
        D_800B3960->unk9C = func_800350F4;
        break;
    case 0x36:
        D_800B3960->unk9C = func_80035164;
        break;
    default:
        D_800B3960->unk9C = func_800340B4;
        break;
    }
}
