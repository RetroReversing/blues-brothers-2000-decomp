#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80024394(s32, s32);
void func_8002D3E4(void *, s32);
s32 func_8002D5CC();
f32 func_8002D66C(void *, f32, s32 *);
void func_8002DA80(void *);
void func_8003C140(void *);
void func_8004303C(void *);
extern s32 D_800B9ECC;
extern void *D_800BD06C;

void func_8007AEBC(void *arg0) {
    s32 sp10;
    f32 dist;
    f32 dz;
    s32 k;

    if (func_8002D5CC() != 0) {
        F(arg0, void (**)(void *), 0xA0)(arg0);
        return;
    }
    F(arg0, s32 *, 0x5C) += D_800B9ECC * 8;
    if (F(arg0, s32 *, 0x5C) >= 0x100) {
        F(arg0, s32 *, 0x5C) = 0xFF;
    }
    func_8004303C(arg0);
    dist = func_8002D66C(arg0, 500.0f, &sp10);
    F(arg0, s32 *, 0x10) = sp10 + func_80024394(-300, 300);
    k = 0x8A;
    if (dist < 140.0f) {
        k = 0;
    }
    dz = F(D_800BD06C, f32 *, 8) - F(arg0, f32 *, 8);
    func_8002D3E4(arg0, k);
    func_8002DA80(arg0);
    if (dist < 150.0f && dz < 150.0f) {
        F(D_800BD06C, s32 *, 0xF0) = func_80024394(0x80, 0xFF);
        func_8003C140(D_800BD06C);
    }
}
