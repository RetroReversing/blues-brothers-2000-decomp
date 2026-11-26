/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
typedef struct { s32 a; s32 b; s32 c; } Rec12;
void func_8002A360(s32, s32);
f32 func_8002D340(f32, f32, f32);
void func_8002D620(void *);
f32 func_8002D66C(void *, f32, s32);
extern Rec12 D_800F4A00[];
extern Rec12 D_800F6188[];

void func_800166BC(void *arg0) {
    s32 go;

    func_8002D66C(arg0, 200.0f, 0);
    go = 0;
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0x129;
        D_800F4A00[M2C_FIELD(arg0, s32 *, 0xB8)].a = 100;
        D_800F6188[M2C_FIELD(arg0, s32 *, 0xB8)].a = -100;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
        func_8002D620(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0x29A) {
        if (M2C_FIELD(arg0, s32 *, 0x84) == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x45);
            M2C_FIELD(arg0, s32 *, 0x84) = 1;
        }
        go = 1;
    }
    if (go != 0) {
        M2C_FIELD(arg0, f32 *, 8) = func_8002D340(M2C_FIELD(arg0, f32 *, 0x44) + 400.0f, M2C_FIELD(arg0, f32 *, 8), 17.0f);
    }
}
