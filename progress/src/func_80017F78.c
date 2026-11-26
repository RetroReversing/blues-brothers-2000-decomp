typedef struct {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    s32 unk14;
    char pad18[0x4C];
    s32 unk64;
    char pad68[0x34];
    void *unk9C;
} Obj80017F78;

Obj80017F78 *func_80017DEC(void);
extern Obj80017F78 *gCameraRig;
extern void *D_800BCFB0;
extern void *D_800BCFFC;
extern s32 D_800BD05C;
extern s32 D_800BD068;
extern Obj80017F78 *gCameraTarget;
extern f32 D_800BD070;
extern f32 D_800BD074;
extern f32 D_800BD078;
void func_80017E34(void *);
void func_80023078(void *);

void func_80017F78(void) {
    Obj80017F78 *src;
    f32 x;
    void *saved;

    src = func_80017DEC();
    if (src != NULL) {
        x = gCameraRig->unk4;
        gCameraRig->unk4 = src->unk4;
        D_800BD070 = x;
        D_800BD074 = gCameraRig->unk8;
        D_800BD078 = gCameraRig->unkC;
        gCameraRig->unk8 = src->unk8;
        D_800BD05C = gCameraRig->unk10;
        gCameraRig->unkC = src->unkC;
        D_800BD068 = gCameraRig->unk14;
        D_800BCFB0 = gCameraRig->unk9C;
        gCameraRig->unk10 = src->unk10;
        gCameraRig->unk14 = src->unk14;
        saved = gCameraTarget->unk9C;
        gCameraRig->unk9C = func_80017E34;
        gCameraTarget->unk9C = (void *)((s8 *)func_80023078 + 8);
        gCameraRig->unk64 = 0xC8;
        D_800BCFFC = saved;
    }
}
