typedef struct Pos { u8 p0[4]; f32 x; f32 y; f32 z; } Pos;
typedef struct Obj {
    u8 p0[0x18]; s32 f18; u8 p1[0x30]; f32 f4C; f32 f50; f32 f54; s32 f58; s32 f5C; s32 f60; s32 f64; s32 f68;
    u8 p3[4]; s32 f70; s32 f74; s32 f78; s32 f7C; u8 p4[0x18]; void *f98; void *f9C;
} Obj;
extern s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
extern Obj *func_800232B4(s32, s32, s32, s32);
extern s32 func_80024394(s32, s32);
extern void func_8002D620(Obj *);
extern s32 D_800BCFAC;
extern void func_8001292C(void);
extern void func_8002F8D0(void);

Obj *func_80012B3C(Pos *arg0) {
    Obj *o;

    o = func_800232B4(1, (s32) arg0->x, (s32) arg0->y, (s32) arg0->z);
    o->f64 = 0xC8;
    o->f98 = func_8002F8D0;
    o->f9C = func_8001292C;
    o->f78 = 0xFFFFFF;
    o->f60 = D_800BCFAC;
    o->f74 = 0;
    o->f70 = 0x28;
    o->f7C = 1;
    o->f58 = func_800221C0(0, 1, 1, 3, 0, 0, 1, 0);
    o->f68 = 0xD;
    o->f5C = 0xFF;
    o->f18 = 0xC000;
    o->f4C = (f32) func_80024394(0x14, 0x46);
    o->f50 = (f32) func_80024394(0x14, 0x46);
    o->f54 = (f32) func_80024394(0x14, 0x46);
    func_8002D620(o);
    return o;
}
