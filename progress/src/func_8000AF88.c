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

M2C_UNK func_8000ABE8(s32, s32, u8);                /* extern */
M2C_UNK func_8000AF10(s32, u8);                     /* extern */

void func_8000AF88(s32 arg0, u8 *arg1, u32 arg2) {
    s32 temp_a0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s1;
    s32 var_v0;
    u32 var_s0;
    u8 *var_s2;
    u8 temp_a1;
    u8 temp_a1_2;
    u8 temp_a1_3;
    s32 temp_a2;
    u8 temp_v0;
    u8 temp_v1;
    void *var_s3;

    var_s1 = arg0;
    var_s2 = arg1;
    var_s0 = arg2;
    if (var_s0 != 0) {
        var_v0 = var_s1 & 3;
loop_2:
        temp_a0 = var_s1;
        if (var_v0 != 0) {
            /*__repair_loop_weight*/do { var_s1 += 1; } while (0);
            temp_a1 = *var_s2;
            do { var_s2 += 1; } while (0);
            do { do { do { var_s0 -= 1; } while (0); } while (0); } while (0);
            func_8000AF10(temp_a0, temp_a1);
            var_v0 = var_s1 & 3;
            if (var_s0 != 0) {
                goto loop_2;
            }
        }
    }
    var_a0 = var_s1; if (var_s0 >= 4U) {
        var_s3 = var_s2 + 3;
        __repair_rows: {
            do { var_s1 += 4; } while (0);
            temp_v0 = M2C_FIELD(var_s3, u8 *, -2);
            temp_v1 = M2C_FIELD(var_s3, u8 *, -1);
            temp_a2 = M2C_FIELD(var_s3, u8 *, 0);
            do { var_s3 += 4; } while (0);
            temp_a1_2 = *var_s2;
            do { var_s2 += 4; } while (0);
            do { do { do { var_s0 -= 4; } while (0); } while (0); } while (0);
            func_8000ABE8(var_a0, (temp_a1_2 << 0x18) | (temp_v0 << 0x10) | (temp_v1 << 8) | temp_a2, temp_a2);
            var_a0 = var_s1;
        }
if (var_s0 >= 4U) goto __repair_rows;
    }
    if (var_s0 != 0) {
        var_a0_2 = var_s1;
        do {
            do { var_s1 += 1; } while (0);
            temp_a1_3 = *var_s2;
            do { var_s2 += 1; } while (0);
            do { do { do { var_s0 -= 1; } while (0); } while (0); } while (0);
            func_8000AF10(var_a0_2, temp_a1_3);
            var_a0_2 = var_s1;
        } while (var_s0 != 0);
    }
}
