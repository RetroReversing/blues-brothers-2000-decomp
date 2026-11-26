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

void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern M2C_UNK func_8001B6D0;
extern M2C_UNK func_8001B7C4;

void * func_8001B91C(void) {
    void *temp_s0;

    temp_s0 = func_800232B4(0x101, 0, 0, 0);
    M2C_FIELD(temp_s0, s32 *, 0x60) = func_80023D58(0xD84);
    M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_8001B6D0;
    M2C_FIELD(temp_s0, M2C_UNK **, 0x98) = &func_8001B7C4;
    M2C_FIELD(temp_s0, s32 *, 0x5C) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x68) = 0xD;
    return temp_s0;
}
