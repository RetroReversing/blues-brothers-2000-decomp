typedef struct Obj {
    u8 pad0[0x74];
    s32 x74;
} Obj;

extern s32 func_800291AC(u8 *);
extern void func_800271A8(s32, s32);
extern void func_80028410(s32, s32, s32, s32);
extern s32 D_800B4988;
extern s32 D_800B9C74;
extern s32 D_800B9C78;
extern u8 *D_8014AA88;
extern s32 D_8014AA8C;
extern s32 D_8014AA98;

s32 func_80053B34(Obj *o) {
    s32 k;
    s32 w;
    s32 t;
    s32 y;
    s32 x;

    k = 0;
    if (o->x74 < 0x3C) {
        o->x74 = 0x3C;
    }
    if (D_800B4988 != 0) {
        k = 1;
    }
    if (D_8014AA8C != 0) {
        func_800271A8(0x3E, k + 1);
    } else {
        func_800271A8(0x22, 0xB - k);
    }
    if (D_8014AA88 != NULL) {
        t = func_800291AC(D_8014AA88);
        o->x74 = 0x3C;
        if (o->x74 < t) {
            o->x74 = t;
        }
    }
    w = 0x19;
    if (D_800B4988 != 0) {
        w = 0x23;
    }
    y = D_800B9C74 - 0x1E;
    if (D_8014AA98 == 0) {
        func_80028410(0x1E, w, y, w + o->x74);
    } else {
        x = D_800B9C78 - w;
        func_80028410(0x1E, x - o->x74, y, x);
    }
    return 0;
}
