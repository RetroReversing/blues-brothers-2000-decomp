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

s32 func_8000AB80();                                /* extern */
M2C_UNK func_8000ABB8(s32);                         /* extern */
M2C_UNK func_8000AF88(M2C_UNK, s32, u32);           /* extern */
s32 func_8000B5FC(M2C_UNK, s32, u32, M2C_UNK);      /* extern */

s32 func_8000B988(s32 arg0, s32 arg1, u32 arg2) {
    s32 temp_s5;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s3;
    u32 var_s0;
    u32 var_s1;

    var_s3 = arg1;
    var_s1 = arg2;
    
    temp_s5 = func_8000AB80(); var_s2 = 0;
    if (var_s1 != 0) {
        for (;;) {
            var_s0 = var_s1;
            if (var_s1 > 0x8000U) {
                do { var_s0 = 0x8000; } while (0);
            }
            func_8000AF88(0xB1FF0000, var_s3, var_s0);
            do { do { temp_v0 = func_8000B5FC(0x606, arg0, var_s0, 0); } while (0); } while (0);
            if (temp_v0 == 0) {
                break;
            }
            loop_goto_1:
            {
 var_s3 += temp_v0;
            }
            if (0)
            {
                goto loop_goto_1;
            }
            do { var_s1 -= temp_v0; } while (0);
            do { var_s2 += temp_v0; } while (0);
            if (var_s1 == 0) {
                goto block_6;
            }
        }
    } else {
block_6:
        func_8000ABB8(temp_s5);
    }
    return var_s2;
}
