typedef struct {
    u8 pad_0[0x20];
    f32 f20;
    u8 pad_24[0x92];
    u8 fB6;
    u8 pad_B7[0x1E];
    u8 fD5;
    u8 pad_D6[6];
    f32 fDC;
} Obj8C630;

u8 *func_8008C630(Obj8C630 *o, u8 *p) {
    o->fB6 = *p++;
    o->fD5 = *p++;
    o->f20 = (f32)*p / 50.0;
    o->fDC = 6.2831852 / (f32)o->fD5;
    return p + 1;
}
