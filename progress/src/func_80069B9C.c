/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
M2C_UNK func_80065630(void *);                      /* extern */
extern s32 D_8014AB70;
extern M2C_UNK func_80069AA0;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; unsigned char pad_10[80]; int field_60; int field_64; unsigned char pad_68[8]; int field_70; unsigned char pad_74[24]; int field_8C; } __repair_record_temp_v0;
void *func_80069B9C(void *arg0) {
    M2C_UNK *__base_func_80069AA0;
    void *temp_v0;
    s32 dv;

    temp_v0 = func_800232B4(1, 0, 0, 0);
    do { func_80065630(temp_v0); } while (0);
    ((__repair_record_temp_v0*)temp_v0)->field_70 = 0x28;
    *(s32 *)((char *)temp_v0 + 0x8C) = 0;
    dv = (s32) D_8014AB70;
    __base_func_80069AA0 = &func_80069AA0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = __base_func_80069AA0;
    ((__repair_record_temp_v0*)temp_v0)->field_60 = dv;
    if (arg0 != NULL) {
        ((__repair_record_temp_v0*)temp_v0)->field_4 = (f32) M2C_FIELD(arg0, f32 *, 4);
        ((__repair_record_temp_v0*)temp_v0)->field_8 = (f32) M2C_FIELD(arg0, f32 *, 8);
        ((__repair_record_temp_v0*)temp_v0)->field_C = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    /*__repair_pointer_balance*/if ((unsigned long)temp_v0 & 0x100) {
func_8002D620(temp_v0);
} else {
func_8002D620(temp_v0);
}
    ((__repair_record_temp_v0*)temp_v0)->field_64 = 0x55;
    return temp_v0;
}
