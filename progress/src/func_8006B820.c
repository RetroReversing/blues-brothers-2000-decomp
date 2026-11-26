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

s32 func_8002492C(f32, f32);                        /* extern */
s32 func_8004303C();                            /* extern */
s32 func_80043328(void *, s32, s32);        /* extern */
s32 func_80081990(void *, s32, f32);                /* extern */
s32 func_80081AC0(f32 *, s32, f32);             /* extern */
extern s32 func_8006BB14;

#define sp10 (*(f32 *)(sp + 0x0))
#define sp18 (*(f32 *)(sp + 0x8))
s32 func_8006B820(void *arg0) {
    u8 sp[16];
    s32 temp_s0;
    s32 temp_s0_2;
    f32 *temp;

    temp_s0 = (*(const s32 *)((s8 *)arg0 + 0x70));
    temp = (const f32 *)((s8 *)arg0 + 0xB4);
    (*(f32 *)((s8 *)arg0 + 0xB4)) = (f32) ((*temp) + (*(const f32 *)((s8 *)arg0 + 0xAC)));
    do { func_8004303C(); } while (0);
    temp_s0_2 = func_80081990(arg0 + 4, temp_s0, (*(const f32 *)((s8 *)arg0 + 0xB4)));
    func_80081AC0(&sp10, temp_s0, (*(const f32 *)((s8 *)arg0 + 0xB4)));
    (*(s32 *)((s8 *)arg0 + 0x10)) = func_8002492C(sp10, sp18);
    if (temp_s0_2 != 0) {
        (*(s32 *)((s8 *)arg0 + 0x78)) = 3;
        (*(s32 **)((s8 *)arg0 + 0xD8)) = &func_8006BB14;
        func_80043328(arg0, (*(const s32 *)((s8 *)arg0 + 0x74)) + (*(const s32 *)((s8 *)arg0 + 0x78)), 0x100);
    }
    return 0;
}

