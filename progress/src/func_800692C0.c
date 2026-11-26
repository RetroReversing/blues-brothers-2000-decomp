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

void *func_800693B0(void *);                        /* extern */
void *func_800693CC(void *);                        /* extern */
void *func_800693E8(void *);                        /* extern */
void *func_80069404(void *);                        /* extern */

extern M2C_UNK func_800694A0;

void func_800692C0(void *arg0) {
    s32 temp_v1;
    void *var_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x74);
    var_a0 = NULL;
    switch (temp_v1) {                              /* irregular */
    case 1:
        var_a0 = func_800693B0(arg0);
        break;
    case 2:
        var_a0 = func_800693CC(arg0);
        break;
    case 3:
        var_a0 = func_800693E8(arg0);
        break;
    case 4:
        var_a0 = func_80069404(arg0);
        break;
    }
    if (var_a0 != NULL) {
        M2C_FIELD(var_a0, M2C_UNK **, 0x9C) = &func_800694A0;
        M2C_FIELD(var_a0, s32 *, 0x5C) = 0x90;
        M2C_FIELD(var_a0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(var_a0, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + 200.0f);
        M2C_FIELD(var_a0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(var_a0, s32 *, 0x90) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
        M2C_FIELD(arg0, s32 *, 0x68) = 0xE;
    }
}

