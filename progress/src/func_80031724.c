void *func_800232B4(s32, s32, s32, s32);
void func_80030C40(void *, s32);
void func_80030C6C(void *, void (*)(void));
extern s32 D_800B4A34;
extern s32 D_800B4A84;
extern void *D_8013FB74;
void func_8003130C(void);

void func_80031724(void) {
    void *o;
    s32 st;
    s32 *q;

    o = func_800232B4(4, 0, 0, 0);
    D_8013FB74 = o;
    q = &D_800B4A34;
    st = D_800B4A84;
    *(s32 **)((char *)o + 0x74) = q;
    *(s32 *)((char *)o + 0x68) = 0xF;
    if (st == 0) {
        func_80030C40(o, 0);
    } else if (st == 1) {
        func_80030C6C(o, func_8003130C);
    } else if (st == 2) {
        func_80030C6C(o, func_8003130C);
    } else if (st == 3) {
        D_800B4A84 = 0;
    }
}
