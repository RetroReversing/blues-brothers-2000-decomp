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

s32 func_8002D3E4();
s32 func_8002D8F4();
s32 func_8002DA80();
f32 func_800385AC();
s32 func_8004303C();
s32 func_800433A8();
s32 func_800853E8();
extern f32 D_80008B4C;
extern s32 func_80063D70;

void func_80063F98(void *arg0) {
    f32 temp;
    func_8002D8F4(arg0, 0);
    (*(f32 *)((s8 *)arg0 + 8)) = func_800385AC(arg0);
    func_8004303C(arg0);
    func_8002D3E4(arg0, 0xA0);
    func_8002DA80(arg0);
    func_800853E8(arg0);
    temp = *(f32 *)((s8 *)arg0 + 0xC);
    if (D_80008B4C < temp) {
        func_800433A8(arg0, 0xDE, 0x100);
        (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_80063D70;
    }
}
