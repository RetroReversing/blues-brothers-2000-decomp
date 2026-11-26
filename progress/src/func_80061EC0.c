typedef struct Obj61 {
    u8 pad4[4];
    f32 x4;
    u8 pad8[4];
    f32 xC;
    u8 pad10[0x90];
    void (*fn)(struct Obj61 *);
    u8 padA4[0x1C];
    s32 xC0;
} Obj61;
Obj61 *func_80023874(s32, Obj61 *);
f32 func_8002DD60(f32);

void func_80061EC0(Obj61 *a) {
    Obj61 *p;
    f32 k, t, t0;

    p = func_80023874(0x11E, NULL);
    if (p != NULL) {
        k = *(f32 *)0x800089C0;
        do {
            func_8002DD60(a->x4 - p->x4);
            t = func_8002DD60(a->xC - p->xC);
            if (t < k) {
                if (t < k) {
                    p->xC0 = 1;
                    break;
                }
            }
            p = func_80023874(0x11E, p);
        } while (p != NULL);
    }
    a->fn(a);
}
