#define F(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
void func_8001FF64(void *);
f32 func_8002D340(f32, f32, f32);
void func_80034FEC(void *, s32 *);
void func_80036FB8(void *, s32);
extern s32 D_800B9ECC;
extern void *D_800BD06C;

void func_80064730(void *arg0) {
    s32 sp10[3];

    F(arg0, f32 *, 0xC) = func_8002D340(F(D_800BD06C, f32 *, 0xC) - 1250.0f, F(arg0, f32 *, 0xC), D_800B9ECC * 50);
    F(arg0, f32 *, 4) = F(arg0, f32 *, 0x40);
    F(arg0, f32 *, 8) = F(arg0, f32 *, 0x44) - 200.0f;
    sp10[0] = F(F(arg0, void **, 0xA8), f32 *, 4);
    sp10[1] = F(F(arg0, void **, 0xA8), f32 *, 8);
    sp10[2] = F(F(arg0, void **, 0xA8), f32 *, 0xC);
    func_80034FEC(arg0, sp10);
    func_8001FF64(arg0);
    func_80036FB8(arg0, 0xF);
}
