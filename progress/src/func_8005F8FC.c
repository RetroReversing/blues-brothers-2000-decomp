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

void *func_80042F00(M2C_UNK, s32, s32, s32);        /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK D_8014AA58;
extern M2C_UNK updateChaserEnemy;
extern M2C_UNK func_8005F8AC;

void *func_8005F8FC(void *arg0) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    void *temp_v0;

    if (arg0 != NULL) {
        var_s2 = (s32) M2C_FIELD(arg0, f32 *, 4);
        var_s0 = (s32) M2C_FIELD(arg0, f32 *, 8);
        var_s1 = (s32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    func_80050460(&func_8005F8AC, &D_8014AA58);
    temp_v0 = func_80042F00(0x2E, var_s2, var_s0, var_s1);
    func_80043328(temp_v0, 0x74, 0x100);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &updateChaserEnemy;
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1016;
    return temp_v0;
}

