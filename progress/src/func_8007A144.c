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

s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
void *findActor(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
f32 func_800385AC(void *);                          /* extern */
M2C_UNK animStepKeys();                            /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK func_8007A04C;

void func_8007A144(void *arg0) {
    s32 temp_v1;
    s32 var_s2;
    void *temp_s0;

    var_s2 = 0;
    animStepKeys();
    M2C_FIELD(arg0, f32 *, 8) = func_800385AC(arg0);
    temp_s0 = findActor(0x137, 0);
    temp_v1 = func_8001B990(0x100, 0x1E);
    if (temp_s0 != NULL) {
        var_s2 = M2C_FIELD(temp_s0, s32 *, 0xC0) == 1;
    }
    if ((temp_v1 != 0) || (var_s2 != 0)) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x6B);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8007A04C;
        actorSetAnim(arg0, 0x101, 0xC0);
    }
}
