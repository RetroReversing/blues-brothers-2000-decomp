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

M2C_UNK func_80015738(void *);                      /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D124();                            /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern void *gCameraTarget;
extern M2C_UNK func_800393F4;
extern M2C_UNK func_8003BC40;

void func_8003CB10(void) {
    s32 var_s0;
    void *temp_s1;
    temp_s1 = gCameraTarget;
    M2C_FIELD(temp_s1, M2C_UNK **, 0xD8) = &func_800393F4;
    actorSetAnim(temp_s1, 0x18, 0x100);
    M2C_FIELD(temp_s1, M2C_UNK **, 0x9C) = &func_8003BC40;
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0xB);
    func_8002D124();
    M2C_FIELD(temp_s1, s32 *, 0) = 0x101;
    var_s0 = 0;
    do {
        func_80015738(temp_s1);
        var_s0 += 1;
    } while (var_s0 < 0x1E);
}
