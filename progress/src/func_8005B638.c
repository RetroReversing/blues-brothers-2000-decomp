f32 func_8002D340(f32, f32, f32);
void func_80043328(void *, s32, s32);
void func_8005B6F8(void);

s32 func_8005B638(void *arg0) {
    void *t;

    *(s32 *)((s8 *)arg0 + 0x10) = 0x8000;
    if (*(s32 *)((s8 *)arg0 + 0x7C) == 0) {
        *(s32 *)((s8 *)arg0 + 0x7C) = 1;
        func_80043328(arg0, 0xC7, 0x120);
    }
    *(f32 *)((s8 *)arg0 + 0xC) = func_8002D340(180.0f, *(f32 *)((s8 *)arg0 + 0xC), 45.0f);
    t = *(void **)((s8 *)arg0 + 0xA8);
    if (t != NULL && *(f32 *)((s8 *)arg0 + 0xC) < *(f32 *)((s8 *)t + 0xC) - 50.0f) {
        *(s32 *)((s8 *)t + 0xC0) = 2;
        *(void **)((s8 *)arg0 + 0xA8) = NULL;
    }
    if (*(f32 *)((s8 *)arg0 + 0xC) <= 180.0f) {
        *(void **)((s8 *)arg0 + 0xD8) = func_8005B6F8;
        *(s32 *)((s8 *)arg0 + 0x7C) = 0;
    }
}
