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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 heapAlloc(M2C_UNK);                         /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800477F0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80047824(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80047864(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80047898();                                /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_800852CC(void *, s32);                 /* extern */
extern s32 D_800B7B0C;
extern M2C_UNK D_800B86C0;
extern M2C_UNK D_800B86CC;
extern M2C_UNK D_8014AA40;
extern M2C_UNK func_80065D2C;
extern M2C_UNK func_8007DEA0;
extern M2C_UNK func_8007ECB0;
extern M2C_UNK func_8007EF74;
extern M2C_UNK func_8007EFD0;

void *func_8007F01C(s32 arg0) {
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v1;
    void *temp_v0;
    void *temp_v0_3;

    func_80050460(&func_8007DEA0, &D_8014AA40);
    temp_v0 = func_80042F00(0x2A, 0, 0, 0);
    actorSetAnim(temp_v0, 0x1A7, 0x100);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 *, 0x74) = 0x1A7;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x102D;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007ECB0;
    temp_v0_2 = func_80047898();
    M2C_FIELD(temp_v0, s32 *, 0xE8) = temp_v0_2;
    func_80047864(temp_v0_2, 0, 0, -0x78, 0);
    func_80047864(temp_v0_2, 0, 0, -0x78, 0);
    func_80047824(temp_v0_2, 0, 8, 0x28, 0x24);
    func_80047824(temp_v0_2, 0, 8, 0x28, 0x24);
    func_800477F0(temp_v0_2, 0x4B, 0x4B, 0x52);
    func_800477F0(temp_v0_2, 0x4B, 0x4B, 0x52);
    M2C_FIELD(&D_800B86C0, s32 *, 0) = 0x2C;
    M2C_FIELD(&D_800B86C0, s32 *, 4) = 0xD1;
    M2C_FIELD(&D_800B86C0, s32 *, 8) = 0xBD;
    M2C_FIELD(&D_800B86CC, s32 *, 0) = 4;
    M2C_FIELD(&D_800B86CC, s32 *, 4) = 0x14;
    M2C_FIELD(&D_800B86CC, s32 *, 8) = 0x12;
    M2C_FIELD(temp_v0, s32 *, 0x8C) = heapAlloc(0x80);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8007EF74;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xA0) = &func_80065D2C;
    M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(temp_v0, s32 *, 0xFC) = 5;
    M2C_FIELD(temp_v0, s32 *, 0x34) = (M2C_FIELD(temp_v0, s32 *, 0x34) * 2) / 3;
    M2C_FIELD(temp_v0, s32 *, 0x38) = M2C_FIELD(temp_v0, s32 *, 0x34);
    M2C_FIELD(temp_v0, s32 *, 0x3C) = M2C_FIELD(temp_v0, s32 *, 0x34);
    temp_v0_3 = func_80042F00(0x77, 0, 0, 0);
    M2C_FIELD(temp_v0_3, s32 *, 0) = 0x102E;
    M2C_FIELD(temp_v0, void **, 0xA8) = temp_v0_3;
    M2C_FIELD(temp_v0_3, void **, 0xA4) = temp_v0;
    actorSetAnim(temp_v0_3, 0x1AE, 0x100);
    func_800852CC(temp_v0_3, arg0);
    M2C_FIELD(temp_v0_3, s32 *, 0x58) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(temp_v0_3, s32 *, 0x34) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
    M2C_FIELD(temp_v0_3, s32 *, 0x38) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
    M2C_FIELD(temp_v0_3, s32 *, 0x3C) = (s32) M2C_FIELD(temp_v0, s32 *, 0x34);
    temp_v0_2 = func_80047898();
    M2C_FIELD(temp_v0_3, s32 *, 0xE8) = temp_v0_2;
    func_80047864(temp_v0_2, 0, 0x14, 0, -0x78);
    func_80047864(temp_v0_2, 0, 0x14, 0, -0x78);
    func_80047824(temp_v0_2, 0, 0x23, 0x23, 0x23);
    func_80047824(temp_v0_2, 0, 0x23, 0x23, 0x23);
    func_800477F0(temp_v0_2, 0x30, 0x30, 0x30);
    func_800477F0(temp_v0_2, 0x30, 0x30, 0x30);
    M2C_FIELD(temp_v0_3, M2C_UNK **, 0x9C) = &func_8007EFD0;
    M2C_FIELD(temp_v0_3, s32 *, 0x74) = 0x1AE;
    return temp_v0;
}

