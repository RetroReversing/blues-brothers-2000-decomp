typedef struct {
    s32 state;
    u8 pad_4[0x8C];
    s32 f90;
    u8 pad_94[8];
    void (*f9C)();
    u8 pad_A0[0x30];
    s32 fD0;
} Player3C9AC;

extern Player3C9AC *gCameraTarget;
void func_800393F4();

s32 isTargetVulnerable(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (gCameraTarget->state != 3) {
        return 0;
    }
    if (gCameraTarget->f9C != func_800393F4) {
        return 0;
    }
    if (arg1 != 0 && gCameraTarget->fD0 == 0xB) {
        return 0;
    }
    if (arg2 != 0 && gCameraTarget->f90 == 0) {
        return 0;
    }
    if (arg3 != 0 && gCameraTarget->fD0 == 0x1A) {
        return 0;
    }
    return 1;
}
