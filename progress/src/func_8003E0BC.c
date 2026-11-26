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

s16 coss(s32);                                      /* extern */
M2C_UNK func_80027038(M2C_UNK);                     /* extern */
M2C_UNK func_80027060(s32, s32, s32, u32);          /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, u32); /* extern */
M2C_UNK setTextPos(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80027158(M2C_UNK, s32);                /* extern */
M2C_UNK func_8002E838(s32);                         /* extern */
M2C_UNK drawCenteredMessage(M2C_UNK);                     /* extern */
extern s32 D_800B5DD8;
extern s32 gTextWaveTime;

void func_8003E0BC(void *arg0) {
  u32 guard_value;
    M2C_UNK var_a0;
    M2C_UNK var_a0_2;
    s32 temp_a0_2;
    s32 var_s0;
    s32 var_s1;
    u32 temp_a0;

    func_80027038(0);
    temp_a0 = M2C_FIELD(arg0, u32 *, 0x70);
    func_8002E838((s32) (temp_a0 + (temp_a0 >> 0x1F)) >> 1);
    setTextColor(0xCE, 0x10, 0x25, M2C_FIELD(arg0, u32 *, 0x70));
    setTextPos(0xA0, 0x14);
    drawCenteredMessage(0x9A);
    func_80027158(0xA0, 0x28);
    temp_a0_2 = 0xFF - ((s32) (((s32) (coss((gTextWaveTime * 0x190) & 0xFFF0) * 0x7F) >> 0xF) + 0x80) / 2);
    do { func_80027060(temp_a0_2, temp_a0_2, temp_a0_2, M2C_FIELD(arg0, u32 *, 0x70)); } while (0);
    for (var_s0 = 0; var_s0 < D_800B5DD8; var_s0++) {
        func_80027158(0xA0, var_s0 * 10 + 0x50);
        var_a0 = 0x77;
        if (var_s0 == M2C_FIELD(arg0, s32 *, 0x88)) {
            var_a0 = 0xFF;
        }
        setTextColor(var_a0, var_a0, var_a0, M2C_FIELD(arg0, u32 *, 0x70));
        switch (var_s0) {
        case 0: drawCenteredMessage(0xA4); break;
        case 1: drawCenteredMessage(0xA6); break;
        case 2: drawCenteredMessage(0xA7); break;
        }
    }
    setTextPos(0x96, 0xCD);
    setTextColor(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, u32 *, 0x70));
    drawCenteredMessage(0xA2);
}

