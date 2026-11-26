typedef struct O7855C {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    union { s32 f10; struct { u16 f10h; u16 f12; } s; } u10;
    u8 pad14[0x70 - 0x14];
    s32 f70;
    u8 pad74[0xA8 - 0x74];
    struct O7855C *fA8;
    f32 fAC;
} O7855C;
s16 coss(u16);
void func_8002ADFC(s32, s32, O7855C *);
s32 func_8002D260(s32);
s32 func_80043248(O7855C *);

s32 func_8007855C(O7855C *arg0) {
    O7855C *other;
    s32 r;
    s32 k;

    other = arg0->fA8;
    r = func_80043248(arg0);
    if (other != NULL) {
        func_80043248(other);
    }
    if (r == 0) {
        return 0;
    }
    k = 0x1B4;
    arg0->f4 += (s32)((s64)coss(arg0->u10.s.f12) * k) >> 15;
    arg0->u10.f10 = func_8002D260(arg0->u10.f10 + 0x8000);
    if (arg0->f70 & 1) {
        arg0->f70 = arg0->f70 + 1;
    } else {
        arg0->f70 = arg0->f70 - 1;
    }
    arg0->fAC = -arg0->fAC;
    func_8002ADFC(0xC3, 2000, arg0);
    return 1;
}
