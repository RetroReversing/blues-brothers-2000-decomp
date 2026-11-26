typedef struct Obj {
    s32 x0;
    u8 pad4[0x4C - 4];
    f32 x4C;
    u8 pad50[4];
    f32 x54;
    u8 pad58[4];
    s32 x5C;
    u8 pad60[0x7C - 0x60];
    s32 x7C;
    u8 pad80[4];
    s32 x84;
    s32 x88;
    u8 pad8C[0x9C - 0x8C];
    void *x9C;
    u8 padA0[4];
    struct Obj *xA4;
    s32 xA8;
} Obj;

extern void func_80043328(Obj *, s32, s32);
extern f32 func_8002D340(f32, f32, f32);
extern void func_800462A0(void);

void func_8005BA74(Obj *o) {
    if (o->x7C == 0) {
        o->x7C = 1;
        o->x88 = 1;
        func_80043328(o, 0xCE, 0x100);
        o->x0 = 0x101;
    }
    o->x4C = func_8002D340(0.0f, o->x4C, 70.0f);
    o->x54 = func_8002D340(0.0f, o->x54, 70.0f);
    o->x5C -= 9;
    if (o->x5C < 9 || o->x84 != 0) {
        if (o->xA4 != NULL) {
            o->xA4->xA8 = 0;
        }
        o->x9C = func_800462A0;
    }
}
