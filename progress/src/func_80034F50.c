s32 func_8001FF64(void *);
s32 func_80034FEC(void *, s32 *);
s32 func_80036FB8(void *, s32);
extern s32 *D_800BD06C;

void func_80034F50(void *arg0_in) {
    s32 sp10[3];
    s32 *var_v1;

    var_v1 = (*(s32 **)((s8 *)arg0_in + 0xA8));
    if (var_v1 == NULL) {
        var_v1 = D_800BD06C;
    } else if (*var_v1 == 0) {
        var_v1 = D_800BD06C;
        (*(s32 **)((s8 *)arg0_in + 0xA8)) = NULL;
    }
    sp10[0] = (s32) (*(f32 *)((s8 *)var_v1 + 4));
    sp10[1] = (s32) (*(f32 *)((s8 *)var_v1 + 8) + 200.0f);
    sp10[2] = (s32) (*(f32 *)((s8 *)var_v1 + 0xC));
    func_80034FEC(arg0_in, sp10);
    func_8001FF64(arg0_in);
    func_80036FB8(arg0_in, 0xF);
}
