/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
f32 func_8002D858(void *, s32 *);                   /* extern */
M2C_UNK func_8002DA80(void *);                      /* extern */
M2C_UNK animStepKeys();                            /* extern */
void *func_800851D8(void *);                        /* extern */
s32 func_80085754(void *, s32, M2C_UNK);            /* extern */
extern f32 D_80009B00;

s32 func_80085B8C(void *arg0) {
    s32 sp10;
    f32 temp_fs0;

    animStepKeys();
    temp_fs0 = func_8002D858(arg0, &sp10);
    M2C_FIELD(arg0, s32 *, 0x10) = sp10;
    func_8002D3E4(arg0, 0x22B);
    func_8002DA80(arg0);
    if (temp_fs0 <= ((f32) M2C_FIELD(func_800851D8(arg0), s16 *, 2) + D_80009B00)) {
        return 2;
    }
    return func_80085754(arg0, M2C_FIELD(arg0, s32 *, 0xF4), 0) == 0;
}
