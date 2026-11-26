s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
void *func_8002E374(s32);
extern s32 func_8000EF3C;
#define F(e, t, o) (*(t)((s8 *)(e) + (o)))
void *func_8000F044(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8002E374(0x98);
    F(temp_v0, s32 *, 0x64) = 0x12C;
    F(temp_v0, f32 *, 4) = F(arg0, f32 *, 4);
    F(temp_v0, f32 *, 8) = F(arg0, f32 *, 8);
    F(temp_v0, f32 *, 0xC) = F(arg0, f32 *, 0xC);
    F(temp_v0, s32 *, 0x68) = 0xD;
    F(temp_v0, s32 **, 0x9C) = &func_8000EF3C;
    F(temp_v0, s32 *, 0x58) = func_800221C0(1, 1, 1, 3, 0, 1, 1, 0);
    return temp_v0;
}
