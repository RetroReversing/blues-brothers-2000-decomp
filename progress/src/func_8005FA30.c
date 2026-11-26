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

s32 func_8000C43C();                                /* extern */
M2C_UNK func_80013F24(void *);                      /* extern */
s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_80024394(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800433A8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(void *, void *);              /* extern */
M2C_UNK func_800852CC(void *, void *);              /* extern */
M2C_UNK func_800899DC(M2C_UNK *);                   /* extern */
extern M2C_UNK D_800088C0;
extern M2C_UNK D_800088D0;
extern s32 D_800B7B0C;
extern M2C_UNK D_8014AA3E;
extern M2C_UNK func_8005F9AC;
extern M2C_UNK func_800602FC;
extern M2C_UNK func_80060418;
extern M2C_UNK func_80060574;
extern M2C_UNK func_80060610;
extern M2C_UNK func_800607B0;

void *func_8005FA30(void *arg0) {
    M2C_UNK *var_v0;
    s32 temp_v0;
    s32 var_s1;
    void *temp_s0;

    var_s1 = 0;
    if (arg0 != NULL) {
        var_s1 = M2C_FIELD(arg0, s32 *, 0x70);
    }
    func_80050460((char *)&func_8005F9AC + 4, (char *)&D_8014AA3E + 1);
    temp_s0 = func_80042F00(0x10, 0, 0, 0);
    M2C_FIELD(temp_s0, s32 *, 0x58) = func_800221C0(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(temp_s0, s32 *, 0) = 0x1018;
    func_800433A8(temp_s0, 0x55, 0x100);
    func_800852CC(temp_s0, arg0);
    if (func_8000C43C() != 0x20) {
        switch (var_s1) {                           /* irregular */
        case 0:
            var_v0 = &func_80060418;
            goto block_18;
        case 1:
            M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_800602FC;
            func_80013F24(temp_s0);
            break;
        case 2:
            var_v0 = &func_80060610;
            goto block_18;
        case 3:
            M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_80060574;
            func_800899DC(&D_800088C0);
            break;
        default:
            M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_80060418;
            func_800899DC(&D_800088D0);
            break;
        }
    } else {
        var_v0 = &func_800607B0;
block_18:
        M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = var_v0;
    }
    func_8002D620(temp_s0);
    temp_v0 = func_80024394(0, 8) << 0xD;
    M2C_FIELD(temp_s0, s32 *, 0x10) = temp_v0;
    M2C_FIELD(temp_s0, s32 *, 0x88) = temp_v0;
    func_8002D3E4(temp_s0, 0x96);
    return temp_s0;
}
