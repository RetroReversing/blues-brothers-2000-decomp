extern s32 D_800BD0E0;

void func_8000C594(void) {
    s32 *temp_v1;
    s32 temp_v0;

    temp_v1 = (s32 *)((char *)&D_800BD0E0);
    temp_v0 = *(s32 *)((char *)temp_v1 + 0x20);
    *(s32 *)((char *)temp_v1 + 0x24) = 0;
    *(s32 *)((char *)temp_v1 + 0x1C) = 0;/*__repair_loop_weight*/do {
    temp_v0 = temp_v0 + 1;} while (0);
    *(s32 *)((char *)temp_v1 + 0x20) = temp_v0;
}
