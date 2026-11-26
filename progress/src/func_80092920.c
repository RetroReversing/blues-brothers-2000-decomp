void *memcpy(void *, const void *, u32);

void func_80092920(void *arg0, void *arg1, u32 arg2) {
    s32 temp_v0;

    memcpy(*(void **)((u8 *)arg0 + 0x24), arg1, arg2);
    temp_v0 = *(s32 *)((u8 *)arg0 + 0x24) + arg2;
    *(s32 *)((u8 *)arg0 + 0x30) = temp_v0;
    *(s32 *)((u8 *)arg0 + 0x2C) = temp_v0;
}
