void func_80017F78(s32);
s32 func_8001B990(s32, s32);
void *func_80023874(s32, s32);
void func_80018610(void);

void func_8001835C(void *arg0) {
    s32 pos[3] = { 0x947, -0x29C, 0x473 };
    void *o;

    if (*(s32 *)((s8 *)arg0 + 0x80) == 0 && func_8001B990(0x100, 0x19) != 0) {
        o = func_80023874(0x12D, 0);
        if (o != NULL) {
            *(void **)((s8 *)o + 0x9C) = func_80018610;
            *(s32 *)((s8 *)o + 0x68) = 4;
            *(s32 *)((s8 *)o + 0x5C) = 0;
            func_80017F78(10);
        }
        *(s32 *)((s8 *)arg0 + 0x80) = 1;
    }
}
