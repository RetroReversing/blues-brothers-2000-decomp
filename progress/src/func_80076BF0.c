void *func_800232B4(s32, s32, s32, s32);
void *func_800239E0(void);
s32 randomRange(s32, s32);
extern s32 func_80023848;
extern s32 func_800768E8;

void *func_80076BF0(void *arg0) {
    void *p;
    void *q;

    q = func_800239E0();
    if (q != NULL) {
        return q;
    }
    if (arg0 != NULL) {
        p = func_800232B4(1, *(f32 *)((s8 *)arg0 + 4), *(f32 *)((s8 *)arg0 + 8), *(f32 *)((s8 *)arg0 + 0xC));
    } else {
        p = func_800232B4(1, 0, 0, 0);
    }
    *(s32 **)((s8 *)p + 0x9C) = &func_800768E8;
    *(s32 **)((s8 *)p + 0xD8) = &func_80023848;
    *(s32 *)((s8 *)p + 0x64) = randomRange(0x32, 0x96);
    return p;
}
