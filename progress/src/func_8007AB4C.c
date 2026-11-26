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

void *func_80023874(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
extern void *D_800B3960;
extern M2C_UNK func_80023078;
extern M2C_UNK func_80064024;

void func_8007AB4C(void *arg0) {
    void *temp_s0;
    void *temp_v0;

    temp_s0 = D_800B3960;
    M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_80064024;
    temp_v0 = func_80023874(0x11E, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_s0, f32 *, 4) = (f32) M2C_FIELD(temp_v0, f32 *, 4);
        M2C_FIELD(temp_s0, f32 *, 8) = (f32) M2C_FIELD(temp_v0, f32 *, 8);
        M2C_FIELD(temp_s0, f32 *, 0xC) = (f32) M2C_FIELD(temp_v0, f32 *, 0xC);
        func_8002D620(temp_s0);
        M2C_FIELD(arg0, void **, 0x9C) = (void *) (&func_80023078 + 2);
    }
}
