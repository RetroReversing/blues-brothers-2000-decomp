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

s32 func_80018048(void *);                          /* extern */
s32 func_800181AC(void *);                          /* extern */
s32 func_80018208(void *);                          /* extern */
s32 func_80018244(void *);                          /* extern */
s32 func_800182CC(void *);                          /* extern */
s32 func_8001835C();                            /* extern */

void func_800183F0(void *arg0) {

    s32 var_s0;
    u32 temp_v1;

    var_s0 = 0;
    func_8001835C();
    temp_v1 = (*(u32 *)((s8 *)arg0 + 0xC0));
    switch (temp_v1) {
    case 0:
        var_s0 = func_80018048(arg0);
        (*(s32 *)((s8 *)arg0 + 0x80)) = 0;
        break;
    case 1:
        var_s0 = func_800181AC(arg0);
        break;
    case 2:
        var_s0 = func_80018208(arg0);
        break;
    case 3:
        var_s0 = func_80018244(arg0);
        break;
    case 4:
        var_s0 = func_800182CC(arg0);
        break;

    default:
        (*(u32 *)((s8 *)arg0 + 0xC0)) = 3U;
        break;
    }
    if (var_s0 != 0) {
        (*(u32 *)((s8 *)arg0 + 0xC0)) = (u32) ((*(u32 *)((s8 *)arg0 + 0xC0)) + 1);
    }
}


