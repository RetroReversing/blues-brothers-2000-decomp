/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
s32 func_8004303C();                          /* extern */
s32 func_8007DDB8(void *, M2C_UNK *, M2C_UNK *);    /* extern */
extern void *D_800B3964;
extern M2C_UNK D_800B86C0;
extern M2C_UNK D_800B86CC;
extern M2C_UNK D_800B86D8;
extern M2C_UNK D_800B86E4;
extern M2C_UNK D_800B86F0;
extern M2C_UNK D_800B86FC;
extern s32 D_80140228;

typedef struct { unsigned char pad_0[136]; int field_88; unsigned char pad_8C[28]; void * field_A8; unsigned char pad_AC[80]; int field_FC; } __repair_record_arg0;
s32 func_8007E4B8(void *arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    void *temp_s2;

    temp_s2 = ((__repair_record_arg0*)arg0)->field_A8;
    temp_s0 = func_8004303C();
    { func_8004303C(temp_s2); }
    temp_v0 = ((__repair_record_arg0*)arg0)->field_88;
    if (temp_v0 == 0) {
        D_80140228 = 1;
        temp_s0 = func_8007DDB8(arg0, &D_800B86D8, &D_800B86CC);
        temp_v0_2 = func_8007DDB8(temp_s2, &D_800B86FC, &D_800B86E4);
        if ((temp_s0 != 0) && (temp_v0_2 != 0)) {
            ((__repair_record_arg0*)arg0)->field_88 = 1;
            D_80140228 = 0;
            M2C_FIELD(D_800B3964, s32 *, 0x8C) = 1;
        }
        goto block_12;
    }
    if (temp_s0 != 0) {
        ((__repair_record_arg0*)arg0)->field_88 = (s32) (temp_v0 + 1);
    }
    if (M2C_FIELD(D_800B3964, s32 *, 0x88) != 0) {
        func_8002ADFC(0xC8, 0x1770, arg0);
        M2C_FIELD(D_800B3964, s32 *, 0x88) = 0;
        ((__repair_record_arg0*)arg0)->field_FC = (s32) (((__repair_record_arg0*)arg0)->field_FC - 1);
        M2C_FIELD(&D_800B86C0, s32 *, 0) = (s32) (M2C_FIELD(&D_800B86C0, s32 *, 0) - (M2C_FIELD(&D_800B86CC, s32 *, 0) * 2));
        M2C_FIELD(&D_800B86C0, s32 *, 4) = (s32) (M2C_FIELD(&D_800B86C0, s32 *, 4) - (M2C_FIELD(&D_800B86CC, s32 *, 4) * 2));
        M2C_FIELD(&D_800B86C0, s32 *, 8) = (s32) (M2C_FIELD(&D_800B86C0, s32 *, 8) - (M2C_FIELD(&D_800B86CC, s32 *, 8) * 2));
        return 2;
    }
    if (((__repair_record_arg0*)arg0)->field_88 >= 3) {
        temp_s0 = func_8007DDB8(arg0, &D_800B86D8, &D_800B86C0);
        temp_v0_3 = func_8007DDB8(temp_s2, &D_800B86FC, &D_800B86F0);
        if ((temp_s0 != 0) && (temp_v0_3 != 0)) {
            M2C_FIELD(D_800B3964, s32 *, 0x8C) = 0;
            return 1;
        }
block_12:
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
