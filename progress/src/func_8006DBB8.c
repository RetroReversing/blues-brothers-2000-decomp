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

M2C_UNK func_800270DC(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002713C(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002E838(s32);                         /* extern */
M2C_UNK func_8003CDA0(M2C_UNK);                     /* extern */

void func_8006DBB8(void *arg0) {
    u32 temp_a0;

    temp_a0 = M2C_FIELD(arg0, u32 *, 0x70);
    func_8002E838((s32) (temp_a0 + (temp_a0 >> 0x1F)) >> 1);
    func_800270DC(0xFF, 0xFF, 0xFF, 0xFF);
    func_8002713C(0xA0, 0x28);
    func_8003CDA0(0x74);
    func_8002713C(0xA0, 0x37);
    func_8003CDA0(0x75);
    func_8002713C(0xA0, 0x5A);
    func_8003CDA0(0xD);
    func_8002713C(0xA0, 0x6E);
    func_8003CDA0(0xE);
}
