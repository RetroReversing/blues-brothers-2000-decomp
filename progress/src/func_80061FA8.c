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

M2C_UNK func_80012718(void *);                      /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8004303C();                            /* extern */
extern M2C_UNK func_80061EB8;
extern M2C_UNK func_800620C0;

void func_80061FA8(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;

    func_8004303C();
    temp_v1 = M2C_FIELD(arg0, s32 *, 0xC0);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + M2C_FIELD(arg0, s32 *, 0x7C));
    if (temp_v1 & ~1) {
        if (temp_v1 & 8) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800620C0;
            M2C_FIELD(arg0, s32 *, 0xF0) = 0xFF;
            return;
        }
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x34);
        if (temp_v0 > 0) {
            M2C_FIELD(arg0, s32 *, 0x34) = (s32) (temp_v0 - 0x20);
            M2C_FIELD(arg0, s32 *, 0xF0) = 0x80;
            M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) - 0x20);
            M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) - 0x20);
            goto block_6;
        }
        func_80012718(arg0);
        func_80012718(arg0);
        func_80012718(arg0);
        func_80012718(arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = (M2C_UNK *) (&func_80061EB8 + 2);
        return;
    }
block_6:
    if (M2C_FIELD(arg0, s32 *, 0x34) < 0x100) {
        temp_v0_2 = func_80024394(0, 2);
        M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + temp_v0_2);
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) + temp_v0_2);
        M2C_FIELD(arg0, s32 *, 0x3C) = (s32) (M2C_FIELD(arg0, s32 *, 0x3C) + temp_v0_2);
    }
    if (M2C_FIELD(arg0, s32 *, 0x34) < 0) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x68) = 4;
    }
}
