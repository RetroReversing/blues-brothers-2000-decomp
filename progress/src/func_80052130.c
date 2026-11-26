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

void *func_80023874();
s32 func_800433A8();
extern s32 func_800521D8;

void func_80052130(s32 arg0, s32 arg1) {
    s32 var_a1;
    void *temp_v0;

    temp_v0 = func_80023874(arg0, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0xC0) = arg1;
        switch (arg1) {                             /* irregular */
        case 2:
            var_a1 = 0x1BE;

            func_800433A8(temp_v0, var_a1, 0x100);
            M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_800521D8;
            return;
        case 3:
            var_a1 = 0x1BF;
            {
func_800433A8(temp_v0, var_a1, 0x100);
M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_800521D8;
return;
}
        case 4:
            M2C_FIELD(temp_v0, s32 (**)(void *), 0xA0)(temp_v0);
            break;
        }
    }
}
