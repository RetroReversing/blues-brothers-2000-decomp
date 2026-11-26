s32 func_80013654(void *);
void sendCommand(s32, s32);
f32 getCameraTargetDist(void *, f32, s32);
extern s32 func_8001CB68;

void func_80017460(void *arg0) {
    f32 temp_fs0;

    temp_fs0 = 300.0f;
    if ((getCameraTargetDist(arg0, temp_fs0, 0) < temp_fs0) && (func_80013654(arg0) != 0)) {
        *(s32 *)((s8 *)arg0 + 0xC0) = 2;
    }
    if (*(s32 *)((s8 *)arg0 + 0xC0) == 2) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x4D);
        *(s32 **)((s8 *)arg0 + 0x9C) = &func_8001CB68;
    }
}
