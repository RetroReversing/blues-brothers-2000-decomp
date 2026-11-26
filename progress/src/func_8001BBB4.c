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

M2C_UNK func_8001B990(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002ADFC(M2C_UNK, M2C_UNK, void *);    /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK func_8000F0DC;

void func_8001BBB4(void *arg0) {
    func_8001B990(0x300, 0x22);
    if (M2C_FIELD(arg0, s32 *, 0xC0) & 2) {
        func_8001B990(0x200, 0x22);
        func_8002ADFC(5, 0x3E8, arg0);
        actorSetAnim(arg0, 0x8A, 0x100);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8000F0DC;
        M2C_FIELD(arg0, s32 *, 0x64) = 0xBB8;
    }
}
