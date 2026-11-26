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
void *findActor(M2C_UNK, M2C_UNK);
M2C_UNK func_80065630();
extern s32 D_800B7FF0;
extern s32 D_8014AB34;
extern M2C_UNK func_80065260;
void func_800656B4(void *arg0) {
    s32 temp_v0_2;
    void *temp_v0;
    void *temp_v0_3;

    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        M2C_FIELD(arg0, s32 *, 0x60) = (s32) D_8014AB34;
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        func_80065630();
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0xA4);
    M2C_FIELD(arg0, f32 *, 4) = M2C_FIELD(temp_v0, f32 *, 4);
    M2C_FIELD(arg0, f32 *, 8) = M2C_FIELD(temp_v0, f32 *, 8) + 550.0f;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0xA4), s32 *, 0x9C) != &func_80065260) {
        temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x5C) - 0xC;
        M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0_2;
        if (temp_v0_2 < 0) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
            temp_v0_3 = findActor(6, 0);
            if ((temp_v0_3 != NULL) && (D_800B7FF0 == 0)) {
                M2C_FIELD(temp_v0_3, s32 *, 0x68) = 0xF;
            }
        }
    }
}
