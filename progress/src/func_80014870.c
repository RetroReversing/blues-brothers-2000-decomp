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

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023C10(s32);                         /* extern */
M2C_UNK func_80023C58(s32);                         /* extern */
s32 func_80023E18(s32);                             /* extern */
s32 func_80023E3C(M2C_UNK);                         /* extern */
M2C_UNK func_80025280(s32);                         /* extern */
M2C_UNK func_8003EA18(s32);                         /* extern */
s32 func_80041418(s32);                             /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 D_800AE010;
extern M2C_UNK D_800FB038;
extern M2C_UNK func_800393F4;

void func_80014870(void *arg0) {
    M2C_UNK *__base_D_800FB038;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xE0);
    if (temp_a0 != 0) {
        func_8003EA18(temp_a0);
        func_80025280(M2C_FIELD(arg0, s32 *, 0xE0));
        M2C_FIELD(arg0, s32 *, 0xE0) = 0;
    }
    temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xC4);
    if (temp_a0_2 != 0) {
        func_80025280(temp_a0_2);
        M2C_FIELD(arg0, s32 *, 0xC4) = 0;
    }
    __base_D_800FB038 = &D_800FB038;
    func_80023C10(M2C_FIELD(__base_D_800FB038, s32 *, 4));
    M2C_FIELD(__base_D_800FB038, s32 *, 4) = 0;
    func_80023C58(0x10C);
    func_80023A74(1, 0x696);
    func_80023C58(D_800AE010);
    func_80023E18(M2C_FIELD(__base_D_800FB038, s32 *, 4));
    temp_s0 = func_80023E18(M2C_FIELD(__base_D_800FB038, s32 *, 4));
    M2C_FIELD(arg0, s32 *, 0xE4) = func_80023E3C(1);
    M2C_FIELD(arg0, s32 *, 0xE0) = func_80041418(temp_s0);
    func_800433A8(arg0, 1, 0x100);
    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800393F4;
    M2C_FIELD(arg0, s32 *, 0x68) = 3;
}
