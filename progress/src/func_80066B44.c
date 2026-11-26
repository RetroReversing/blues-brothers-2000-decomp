#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)

s16 coss(u16);
void func_800393F4(void *);
void func_8003BF98(void *);
void actorSetAnim(void *, s32, s32);
void func_800664A8(void *, s32);
s16 sins(u16);
extern void *gCameraRig;
extern s32 D_800B4CE0;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
void func_800340B4(void *);
void func_80065F84(void *);

void func_80066B44(void *arg0) {
    s32 temp_a1;
    void (*fp)(void *);

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        fp = func_80065F84;
        M2C_FIELD(arg0, void **, 0x9C) = fp;
        actorSetAnim(arg0, 0xFD, 0x100);
        M2C_FIELD(gCameraTarget, f32 *, 4) = M2C_FIELD(arg0, f32 *, 4) + (f32) ((sins(M2C_FIELD(arg0, u16 *, 0x12)) * 0x2D7) >> 0xE);
        M2C_FIELD(gCameraTarget, f32 *, 0xC) = M2C_FIELD(arg0, f32 *, 0xC) + (f32) ((coss(M2C_FIELD(arg0, u16 *, 0x12)) * 0x2D7) >> 0xE);
        M2C_FIELD(gCameraTarget, f32 *, 8) = M2C_FIELD(arg0, f32 *, 8);
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(gCameraTarget, s32 *, 0) = 3;
        M2C_FIELD(gCameraTarget, void **, 0x9C) = func_800393F4;
        M2C_FIELD(gCameraTarget, s32 *, 0x10) = temp_a1;
        func_800664A8(arg0, temp_a1);
        D_800B4CE0 = 1;
        M2C_FIELD(gCameraRig, void **, 0x9C) = func_800340B4;
        M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        func_8003BF98(gCameraTarget);
        D_800B4CE0 = 0;
        D_800B5DD4 = 1;
        fp = M2C_FIELD(gCameraTarget, void (**)(void *), 0x9C);
        fp(gCameraTarget);
    }
}
