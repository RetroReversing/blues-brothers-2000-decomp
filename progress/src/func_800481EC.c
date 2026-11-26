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

M2C_UNK func_80023848(void *);                      /* extern */
void *func_8004811C();                              /* extern */

void func_800481EC(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8004811C();
    M2C_FIELD(temp_v0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0x70);
    M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
    M2C_FIELD(temp_v0, s32 *, 0x78) = (s32) M2C_FIELD(arg0, s32 *, 0x78);
    M2C_FIELD(temp_v0, s32 *, 0x7C) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
    M2C_FIELD(temp_v0, s32 *, 0x80) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
    M2C_FIELD(temp_v0, s32 *, 0x84) = (s32) M2C_FIELD(arg0, s32 *, 0x84);
    func_80023848(arg0);
}
