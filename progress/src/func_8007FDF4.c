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

void *findActor(M2C_UNK, M2C_UNK);              /* extern */

void func_8007FDF4(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = findActor(0x127, 0);
    if (temp_v0 != NULL) {
        if (*M2C_FIELD(arg0, s32 **, 0xA4) == 0x11F) {
            M2C_FIELD(temp_v0, s32 *, 0x80) = arg1;
        } else {
            M2C_FIELD(temp_v0, s32 *, 0x84) = arg1;
        }
    }
}
