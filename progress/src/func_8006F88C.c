#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void *func_8002E374();
extern void *gCameraRig;
extern void *D_800B3964;
void func_8006E964();
void func_8006F644();

void func_8006F88C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *p;
    void *a;
    void *b;
p = func_8002E374();
    F(p, void **, 0x9C) = func_8006F644; F(p, void **, 0x98) = func_8006E964; F(p, s32 *, 0x68) = 0xB; a = D_800B3964; b = gCameraRig;
    F(p, f32 *, 0x28) = arg1; F(p, f32 *, 0x2C) = arg2; F(p, f32 *, 0x30) = arg3;
    F(p, s32 *, 0x34) = arg4; F(p, s32 *, 0x38) = arg4; F(p, s32 *, 0x3C) = arg4;
    F(p, s32 *, 0xBC) = F(a, s32 *, 0xBC); F(p, s32 *, 0x74) = F(b, s32 *, 0x74);
}
