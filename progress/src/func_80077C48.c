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

s32 heapAlloc(M2C_UNK);                         /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80047864(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_80047898();                                /* extern */
M2C_UNK func_80050460(M2C_UNK *, void *);           /* extern */
extern M2C_UNK D_8014AA74;
extern M2C_UNK func_80065D2C;
extern M2C_UNK func_800779F8;
extern M2C_UNK func_80077B9C;
extern M2C_UNK func_80077D2C;

s32 func_80077C48(void) {
    s32 temp_v0_2;
    void *temp_v0;

    func_80050460(&func_80077B9C, (char *)&D_8014AA74 + 1);
    temp_v0 = func_80042F00(0x72, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0x74) = 0x19C;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800779F8;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1023;
    actorSetAnim(temp_v0, 0x1A0, 0x100);
    temp_v0_2 = func_80047898();
    M2C_FIELD(temp_v0, s32 *, 0xE8) = temp_v0_2;
    func_80047864(temp_v0_2, 0, 0, -0x78, 0);
    func_80047864(temp_v0_2, 0, 0, -0x78, 0);
    M2C_FIELD(temp_v0, s32 *, 0x8C) = heapAlloc(0x80);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80077D2C;
    M2C_FIELD(temp_v0, M2C_UNK **, 0xA0) = &func_80065D2C;
    return (s32) temp_v0;
}
