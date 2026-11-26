/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s16 coss(u16);                                      /* extern */
s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_800232B4(M2C_UNK, s32, s32, s32);        /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
s16 sins(u16);                                      /* extern */
extern s32 *D_800BD06C;
extern s32 D_8014AB3C;
extern s32 D_8014AB44;
extern M2C_UNK func_8002F8D0;
extern M2C_UNK func_800677F8;
typedef struct Obj {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    s32 f14;
    s32 f18;
    char pad1C[0x30];
    f32 f4C;
    s32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 pad6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 pad88;
    struct Obj *f8C;
    s32 f90;
    s32 pad94;
    void *f98;
    void *f9C;
} Obj;
#define ANG (*(u16 *)((char *)arg0 + 0x12))
typedef struct Src {
    char pad0[0x30];
    f32 x;
    f32 y;
    f32 z;
} Src;

void *func_8006788C(Obj *arg0, s32 arg1) {
    s32 sp20[3];
    s32 sp30[3];
    Obj *o;
    Src *p;

    o = func_800232B4(1, (s32) arg0->x, (s32) (arg0->y + 250.0f), (s32) arg0->z);
    o->f64 = 0x3E8;
    o->f98 = &func_8002F8D0;
    p = (Src *) arg0->f8C;
    sp20[0] = (s32) p->x;
    sp20[1] = (s32) p->y;
    sp20[2] = (s32) (p->z + 150.0f);
    sp30[0] = ((sp20[0] * coss(ANG)) >> 15) + ((sp20[2] * sins(ANG)) >> 15);
    sp30[2] = -((sp20[0] * sins(ANG)) >> 15) + ((sp20[2] * coss(ANG)) >> 15);
    sp30[1] = sp20[1];
    o->x = arg0->x + (f32) sp30[0];
    o->y = arg0->y + (f32) sp30[1];
    o->z = arg0->z + (f32) sp30[2];
    o->f9C = &func_800677F8;
    o->f70 = 0x64;
    o->f74 = 0;
    o->f78 = 0xFFFFFF;
    o->f7C = 1;
    o->f58 = func_800221C0(0, 1, 1, 3, 0, 0, 2, 0);
    o->f68 = 0xA;
    o->f5C = 0xFF;
    o->f18 = 0xC000;
    o->f64 = 0xC8;
    o->f10 = arg0->f10 + 0x8000;
    o->f84 = 3;
    o->f80 = -func_80024394(0, 3);
    o->f4C = arg0->f4C;
    o->f54 = arg0->f54;
    if (arg1 != 0) {
        o->id = 0x11F;
        o->f90 = 1;
        o->f60 = D_8014AB44;
        o->f70 = o->f70 + 0x2D;
        *D_800BD06C = 3;
    } else {
        o->f90 = 0;
        o->f70 = 0x4B;
        o->f60 = D_8014AB3C;
    }
    func_8002ADFC(0xD5, 0x3E8, o);
    return o;
}
