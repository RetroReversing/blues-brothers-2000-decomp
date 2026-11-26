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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
f32 func_8002D858(void *, void *);                  /* extern */
f32 func_800385AC();                                /* extern */
M2C_UNK func_8004303C(void *);                      /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
M2C_UNK func_8007A8A0(void *);                      /* extern */
M2C_UNK func_8007A934(void *);                      /* extern */
extern f32 D_80009498;

void func_8007A98C(void *arg0) {
    s32 temp_v0;
    s32 var_v0;

    M2C_FIELD(arg0, f32 *, 8) = func_800385AC();
    temp_v0 = func_8001B990(0x100, 0x1E);
    do { do { var_v0 = 3; } while (0); } while (0);
    if (temp_v0 == 0) {
        do { do { do { do { var_v0 = -1; } while (0); } while (0); } while (0); } while (0);
    }
    do { M2C_FIELD(arg0, s32 *, 0x68) = var_v0; } while (0);
    if (func_8002D858(arg0, arg0 + 0x10) < D_80009498) {
        func_80043328(arg0, 0x6A, 0x100);
        func_80052A5C(0x55D);
        if (temp_v0 != 0) {
            func_8007A934(arg0);
        } else {
            func_8007A8A0(arg0);
        }
    } else {
        func_80043328(arg0, 0x69, 0x100);
        M2C_FIELD(arg0, s32 *, 0x88) = 0;
    }
    func_8004303C(arg0);
}
