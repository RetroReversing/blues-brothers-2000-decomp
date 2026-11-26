typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern f32 D_80000474;
extern void func_800393F4(void);

s32 func_8000C3C4(void) {
    void *temp_v0;

    temp_v0 = func_80042F00(1, 0, 0, 0);
    M2C_FIELD_PTR(temp_v0, s32 *, 0xD0) = -1;
    M2C_FIELD(temp_v0, void (**)(void), 0x9C) = &func_800393F4;
    M2C_FIELD(temp_v0, s32 *, 0xBC) = 0;
    M2C_FIELD(temp_v0, s32 *, 0) = 3;
    M2C_FIELD(temp_v0, f32 *, 8) = D_80000474;
    M2C_FIELD(temp_v0, f32 *, 0x44) = D_80000474;
    actorSetAnim(temp_v0, 1, 0x100);
    return (s32) temp_v0;
}
