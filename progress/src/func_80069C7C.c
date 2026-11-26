#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
s32 func_80024394(s32, s32);
void func_8002A360(s32, s32);
void func_8002D124(void);
f32 func_8002D340(f32, f32, f32);
void func_8002D3E4(void *, s32);
s32 func_8002D5CC(void *);
f32 func_8002D66C(void *, f32, s32);
void func_8002DA80(void *);
void func_8003BF98(void *);
void func_8004303C(void *);
void func_800433A8(void *, s32, s32);
void *func_80085650(void *);
extern f32 D_80008E58;
extern f32 D_80008E5C;
extern f32 D_80008E60;
extern void *D_800B3964[];
extern void *D_800BD06C[];
extern s32 D_8014AB38[];

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    s32 x10;
    char pad14[0x5C - 0x14];
    s32 x5C;
    s32 x60;
    s32 x64;
    char pad68[0x8C - 0x68];
    s32 x8C;
    char pad90[0xA0 - 0x90];
    void (*fnA0)(struct Obj *);
} Obj;

void func_80069C7C(Obj *arg0) {
    f32 lim;
    f32 d;
    Obj *e;

    if (M2C_FIELD(D_800B3964[0], s32 *, 0x84) != 0 && M2C_FIELD(D_800B3964[0], s32 *, 0x88) != 0) {
        arg0->fnA0(arg0);
        return;
    }
    func_8004303C(arg0);
    arg0->x10 = arg0->x8C;
    func_8002D3E4(arg0, arg0->x64 * 12);
    func_8002DA80(arg0);
    arg0->x8 = func_8002D340(M2C_FIELD(D_800BD06C[0], f32 *, 8) + D_80008E58, arg0->x8, 20.0f);
    lim = D_80008E5C;
    d = func_8002D66C(arg0, lim, 0);
    arg0->x10 = 0x4000;
    e = func_80085650(arg0);
    e->x60 = D_8014AB38[0];
    e->x5C = func_80024394(0xC0, 0xFF);
    e = func_80085650(arg0);
    e->x60 = D_8014AB38[0];
    e->x5C = func_80024394(0xC0, 0xFF);
    e->x4 += func_80024394(-10, 10);
    e->x8 += func_80024394(-10, 10);
    e->xC += func_80024394(-10, 10);
    if (d < lim && M2C_FIELD(D_800BD06C[0], f32 *, 8) <= arg0->x8 + D_80008E60) {
        func_8003BF98(D_800BD06C[0]);
        func_800433A8(D_800BD06C[0], 0x1F, 0x100);
        M2C_FIELD(D_800B3964[0], s32 *, 0x6C) = 1;
        arg0->fnA0(arg0);
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x4E);
        func_8002D124();
    }
    if (func_8002D5CC(arg0) != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0x4E);
        arg0->fnA0(arg0);
    }
}
