extern void *D_800BD06C;
void func_8000C37C(void *arg0) {
    u8 __repair_frame[16];
    *(s32 *)((s8*)D_800BD06C + 0x68) = -1;
    *(f32 *)((s8*)arg0 + 4) = *(f32 *)((s8*)D_800BD06C + 4);
    *(f32 *)((s8*)arg0 + 8) = *(f32 *)((s8*)D_800BD06C + 8) + 100.0f;
    *(f32 *)((s8*)arg0 + 0xC) = *(f32 *)((s8*)D_800BD06C + 0xC);
    *(s32 *)((s8*)arg0 + 0x10) = *(s32 *)((s8*)D_800BD06C + 0x10);
}
