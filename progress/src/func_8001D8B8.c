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

s32 func_80013784(void *);                          /* extern */
M2C_UNK func_80015C30(void *);                      /* extern */
s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
f32 func_8002D66C(void *, f32, s32);                    /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern f32 D_80000D2C;

void func_8001D8B8(void *arg0) {
    f32 temp_fs0;
    s32 var_s0;

    temp_fs0 = 200.0f;
    if ((func_8002D66C(arg0, temp_fs0, 0) < temp_fs0) && (func_80013784(arg0) != 0)) {
        if (M2C_FIELD(arg0, s32 *, 0x70) == 1) {
            func_8001B990(0x200, 0x17);
        }
        if ((M2C_FIELD(arg0, s32 *, 0x70) == 2) && (func_8001B990(0x100, 0x17) != 0)) {
            func_8001B990(0x200, 0x18);
        }
        if ((M2C_FIELD(arg0, s32 *, 0x70) == 3) && (func_8001B990(0x100, 0x18) != 0)) {
            func_8001B990(0x200, 0x19);
        }
        if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 9);
            var_s0 = 0;
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
            do {
                func_80015C30(arg0);
                var_s0 += 1;
            } while (var_s0 < 4);
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x70) != 1) || (func_8001B990(0x100, 0x17) != 0)) {
        if (M2C_FIELD(arg0, s32 *, 0x70) == 2) {
            if (func_8001B990(0x100, 0x18) != 0) {
                goto block_18;
            }
        } else {
block_18:
            if ((M2C_FIELD(arg0, s32 *, 0x70) != 3) || (func_8001B990(0x100, 0x19) != 0)) {
                if (M2C_FIELD(arg0, s32 *, 0x7C) == 1) {
                    func_800433A8(arg0, 0x135, 0x100);
                    M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
                }
                if (M2C_FIELD(arg0, s32 *, 0x7C) != 0) {
                    func_8004303C(arg0);
                }
            }
        }
    }
}

