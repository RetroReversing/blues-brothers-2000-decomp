void *func_80042F00(s32, s32, s32, s32);
void func_800433A8(void *, s32, s32);
void func_80050460(void *, void *);
extern s32 D_8014AA34;
void func_800504FC(void);
void func_8005053C(void);

void *func_80050610(f32 *pos) {
    s32 x;
    s32 y;
    s32 z;
    void *o;

    if (pos != NULL) {
        x = pos[1];
        y = pos[2];
        z = pos[3];
    }
    func_80050460(func_800504FC, &D_8014AA34);
    o = func_80042F00(0x23, x, y, z);
    func_800433A8(o, 0x87, 0x100);
    *(void **)((s8 *)o + 0x9C) = func_8005053C;
    *(s32 *)o = 0x1019;
    *(f32 *)((s8 *)o + 0x4C) = 9.0f;
    *(f32 *)((s8 *)o + 0x54) = 4.0f;
    return o;
}
