/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_BITS_F32(expr) (m2c_bits = (u32)(expr), *(f32 *)&m2c_bits)
extern u32 m2c_bits;
#define M2C_PTR_FROM_F32(type, expr) ((type)(m2c_fbits = (expr), *(u32 *)&m2c_fbits))
extern f32 m2c_fbits;
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

/* a branch below leaves the function (its target is before or after what the project filed as this function): it is drafted as a return, so check where this function really starts and ends */
s32 func_80023D58(M2C_UNK);                         /* extern */
s32 func_80023E18(s32);                             /* extern */
M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800272E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_8002D5CC(void *);                          /* extern */
extern s32 D_800B9ECC;

void func_80063C40(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x5C) + (M2C_FIELD(arg0, s32 *, 0x70) * D_800B9ECC);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
    if (temp_v0 >= 0x100) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
        if (M2C_FIELD(arg0, s32 *, 0x5C) < 0) {
            M2C_FIELD(arg0, s32 *, 0x5C) = 0;
            return;
        }
        func_8002710C(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, s32 *, 0x5C));
        temp_v0_2 = func_80023D58(0x218);
        M2C_FIELD(arg0, s32 *, 0x60) = temp_v0_2;
        func_800272E0(func_80023E18(temp_v0_2), 0, 0, 0);
        if ((func_8002D5CC(arg0) == 0) && (M2C_FIELD(arg0, s32 *, 0x5C) == 0)) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        }
    }
}
