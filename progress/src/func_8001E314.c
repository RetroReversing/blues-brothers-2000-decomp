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

M2C_UNK func_80015EAC();                            /* extern */
M2C_UNK func_8002D9B0(void *);                      /* extern */
M2C_UNK func_8002D9F8(void *);                      /* extern */
extern f32 D_80000D58;

void func_8001E314(void *arg0) {
    func_80015EAC();
    M2C_FIELD_PTR(arg0, s32 *, 0x14) = 0x2BC;
    M2C_FIELD(arg0, s32 *, 0xAC) = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    loop_goto_1:
    {
 M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 0x200);
    }
    if (0)
    {
        goto loop_goto_1;
    }
    M2C_FIELD(arg0, f32 *, 0xB0) = (f32) D_80000D58;
    func_8002D9F8(arg0);
    func_8002D9B0(arg0);
    if (M2C_FIELD(arg0, f32 *, 8) < M2C_FIELD(arg0, f32 *, 0x44)) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
    }
}
