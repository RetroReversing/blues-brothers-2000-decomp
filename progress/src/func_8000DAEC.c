/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s32 gCamSpeedScale;

void func_8000DAEC(void *arg0) {
    s32 temp_v1;

    { (*(s32 *)((char *)(arg0) + 0x10)) = (s32) ((*(s32 *)((char *)(arg0) + 0x10)) + (*(s32 *)((char *)(arg0) + 0x7C))); }
    temp_v1 = (*(s32 *)((char *)(arg0) + 0x5C)) - (gCamSpeedScale * 5);
    (*(s32 *)((char *)(arg0) + 0x7C)) = (s32) ((*(s32 *)((char *)(arg0) + 0x7C)) + 0x200);
    (*(s32 *)((char *)(arg0) + 0x5C)) = temp_v1;
    if (temp_v1 <= 0) {
        (*(s32 (**)(void *, void *))((char *)(arg0) + 0xA0))(arg0, arg0);
    }
}
