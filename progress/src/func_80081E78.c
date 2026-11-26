void *func_80023E18();
s32 func_80029738(void *, s32, s32, s32, s32);

void func_80081E78(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *p; s32 x; s32 y; 
    arg2 += 0x10;
    if (arg0 != -1) {
        p = func_80023E18();
        x = p[0]; y = p[1];
        x = x * arg3 / 256;
        y = y * arg3 / 256;
        func_80029738(p, arg1 - x, arg2 - y, arg1 + y, arg2 + y);
    }
}
