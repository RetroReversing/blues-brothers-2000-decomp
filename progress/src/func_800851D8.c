void func_800899DC();
extern char D_80009A7C[];
extern char D_800B7B10[];
extern char D_800B9B30[];
char *func_800851D8(void *arg0) {
    char *base;
    u32 v;

    base = D_800B7B10;
    if (arg0 == NULL) {
        func_800899DC(D_80009A7C);
    }
    if (*(s32 *)((s8 *)arg0 + 0xB8) < 0xA9) {
        v = *(s32 *)((s8 *)arg0 + 0xB8) - 0xA;
        if (v < 0x5BU) goto ok;
    }
    return D_800B9B30;
ok:
    do { do { return base + v * 8; } while (0); } while (0);
}
