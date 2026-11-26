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

s32 func_80023AE8(s32);                             /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_8004303C(void *);                          /* extern */
M2C_UNK func_800433A8(void *, s32, M2C_UNK);        /* extern */
extern void *D_800BD06C;
extern void *D_801705F0;
extern s16 D_801705F6;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; int field_10; unsigned char pad_14[120]; int field_8C; int field_90; } __repair_record_var_s0;
s32 func_8007D6DC(void) {
    s32 temp_v0;
    void *var_s0;

    if (D_801705F0 == NULL) {
        var_s0 = func_80042F00(1, 0, 0, 0);
        ((__repair_record_var_s0*)var_s0)->field_4 = (f32) M2C_FIELD(D_800BD06C, f32 *, 4);
        ((__repair_record_var_s0*)var_s0)->field_8 = (f32) M2C_FIELD(D_800BD06C, f32 *, 8);
        ((__repair_record_var_s0*)var_s0)->field_C = (f32) M2C_FIELD(D_800BD06C, f32 *, 0xC);
        ((__repair_record_var_s0*)var_s0)->field_10 = (s32) M2C_FIELD(D_800BD06C, s32 *, 0x10);
        D_801705F0 = var_s0;
        func_800433A8(var_s0, 1, 0x100);
        ((__repair_record_var_s0*)var_s0)->field_8C = func_80024394(1, 3);
        ((__repair_record_var_s0*)var_s0)->field_90 = 1;
    } else {
        var_s0 = D_801705F0;
    }
    if (D_801705F6 != 0) {
        func_800433A8(var_s0, 1, 0x100);
        ((__repair_record_var_s0*)var_s0)->field_90 = 1;
        ((__repair_record_var_s0*)var_s0)->field_8C = func_80024394(1, 3);
        ((__repair_record_var_s0*)var_s0)->field_4 = (f32) M2C_FIELD(D_800BD06C, f32 *, 4);
        ((__repair_record_var_s0*)var_s0)->field_8 = (f32) M2C_FIELD(D_800BD06C, f32 *, 8);
        ((__repair_record_var_s0*)var_s0)->field_C = (f32) M2C_FIELD(D_800BD06C, f32 *, 0xC);
    }
    if (func_8004303C(var_s0) != 0) {
        ((__repair_record_var_s0*)var_s0)->field_8C = (s32) (((__repair_record_var_s0*)var_s0)->field_8C - 1);
    }
    if (((__repair_record_var_s0*)var_s0)->field_8C <= 0) {
        __repair_rows: {
            temp_v0 = ((__repair_record_var_s0*)var_s0)->field_90 + 1;
            ((__repair_record_var_s0*)var_s0)->field_90 = temp_v0;
            if (temp_v0 >= 0x30) {
                ((__repair_record_var_s0*)var_s0)->field_90 = 1;
            }
        }
if (func_80023AE8(((__repair_record_var_s0*)var_s0)->field_90) == 0) goto __repair_rows;
        ((__repair_record_var_s0*)var_s0)->field_8C = func_80024394(1, 4);
        func_800433A8(var_s0, ((__repair_record_var_s0*)var_s0)->field_90, 0x100);
    }
    func_8002D604(var_s0);
    M2C_FIELD(var_s0, M2C_UNK (**)(void *), 0x98)(var_s0);
    return 0;
}


