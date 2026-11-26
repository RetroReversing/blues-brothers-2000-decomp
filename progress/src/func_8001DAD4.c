typedef struct Obj {
    u8 pad0[8];
    f32 x8;
    u8 padC[0x44 - 0xC];
    f32 x44;
    u8 pad48[0x70 - 0x48];
    s32 x70;
    u8 pad74[0xC0 - 0x74];
    s32 xC0;
} Obj;

extern f32 func_8002D858(Obj *, s32);
extern s32 func_8001B990(s32, s32);
extern void func_8002A360(s32, s32);
extern s32 D_800B9ECC;

void func_8001DAD4(Obj *o) {
    f32 d;

    d = func_8002D858(o, 0);
    switch (o->xC0) {
    case 0:
        if (d < 250.0f && func_8001B990(0x100, o->x70) != 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x72);
            o->xC0 = 1;
        }
        break;
    case 1:
        o->x8 += (f32)(D_800B9ECC * 10);
        if (o->x44 + 2000.0f < o->x8) {
            o->xC0 = 2;
        }
        break;
    case 2:
        if (350.0f < d) {
            o->x8 -= (f32)(D_800B9ECC * 10);
            if (o->x8 <= o->x44) {
                o->x8 = o->x44;
                o->xC0 = 0;
            }
        }
        break;
    }
}
