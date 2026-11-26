typedef struct {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[0xB6 - 0x24];
    u8 bB6;
    u8 padB7[0xD5 - 0xB7];
    u8 bD5;
    u8 padD6[0xDC - 0xD6];
    f32 fDC;
} Obj;

u8 *func_8008C698(Obj *obj, u8 *p) {
    f32 a;
    f32 b;

    obj->bB6 = *p++;
    obj->bD5 = *p++;
    a = 6.2831852 / (f32)obj->bD5;
    b = -(f32)*p++ / 50.0;
    obj->fDC = a;
    obj->f20 = b;
    return p;
}
