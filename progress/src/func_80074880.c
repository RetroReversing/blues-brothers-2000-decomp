#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80043248(s32);
void func_8004796C(void *);
void actorSetAnim(void *, s32, s32);
void func_8003BF98(void *);
void func_800393F4();
extern s32 D_800B4CE0;
extern s32 D_800B83AC;
extern void *gCameraTarget;
extern s32 D_801407C0;
extern f32 D_8014AB90[3];
void func_80074880(s32 arg0, s32 arg1, s32 arg2) {
    if (func_80043248(arg0) != 0) {
        func_8004796C(gCameraTarget);
        F(gCameraTarget, s32 *, 0xE8) = D_801407C0;
        F(gCameraTarget, f32 *, 4) = D_8014AB90[0];
        F(gCameraTarget, f32 *, 8) = D_8014AB90[1];
        F(gCameraTarget, f32 *, 0xC) = D_8014AB90[2];
        F(gCameraTarget, void **, 0x9C) = func_800393F4;
        actorSetAnim(gCameraTarget, 1, 0x100);
        D_800B4CE0 = 1;
        func_8003BF98(gCameraTarget);
        D_800B4CE0 = 0;
        D_800B83AC = 0;
    }
}
