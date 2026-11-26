void *func_80023124();
s32 func_80026C04(void *, s32, s32);
extern s32 func_80023078;
extern s32 func_80023848;
s32 func_800232B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_a0;
    void *temp_v0;
    f32 temp_f;
    f32 tg;

    temp_v0 = func_80023124(arg0, arg1, arg2, arg3);
    func_80026C04(temp_v0, 0, 0x108);
    (*(f32 *)((s8 *)temp_v0 + 4)) = (f32) arg1;
    temp_f = (f32) arg3;
    (*(s32 *)((s8 *)temp_v0 + 0)) = arg0;
    (*(f32 *)((s8 *)temp_v0 + 8)) = (f32) arg2;
    (*(s32 *)((s8 *)temp_v0 + 184)) = arg0;
    temp_a0 = &func_80023078 + 0x2;
    (*(f32 *)((s8 *)temp_v0 + 12)) = temp_f;
    (*(void * *)((s8 *)temp_v0 + 156)) = temp_a0;
    (*(s32 * *)((s8 *)temp_v0 + 160)) = &func_80023848;
    (*(s32 *)((s8 *)temp_v0 + 52)) = 0x100;
    (*(s32 *)((s8 *)temp_v0 + 56)) = 0x100;
    (*(s32 *)((s8 *)temp_v0 + 60)) = 0x100;
    (*(s32 *)((s8 *)temp_v0 + 212)) = 0x100;
    (*(s32 *)((s8 *)temp_v0 + 104)) = 1;
    (*(void * *)((s8 *)temp_v0 + 152)) = temp_a0;
    (*(void * *)((s8 *)temp_v0 + 216)) = temp_a0;
    (*(s32 *)((s8 *)temp_v0 + 92)) = 0xFF;
    return (s32) temp_v0;
}
