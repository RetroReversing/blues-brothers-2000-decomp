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
/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */

void *func_80023874();
s32 func_80023DBC();
void *func_800511B4();
s32 func_80052B24();
extern char D_80008C90[];
extern s32 D_800AB408;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800BD06C;
extern s32 D_80140214;
extern s32 D_8014AB40;
extern s32 D_801700D8;
extern s32 func_80065A28;

void func_800658FC(void *arg0) {
    void *temp_v0;
    void *var_a1;

    var_a1 = (void *)1;
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0) {
        D_80140214 = 1;
        D_8014AB40 = 0;
        D_800B3970 = 0x80;
        D_800B3974 = 0x80;
        D_800B3978 = 0x80;
        D_801700D8 = 0x7D0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, s32 *, 0xC0) = 1;
        D_800AB408 = 1;
        M2C_FIELD(arg0, s32 *, 0xA8) = 0;
        var_a1 = func_800511B4(arg0);
        M2C_FIELD(var_a1, s32 (**)(void *), 0xA0)(var_a1);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        var_a1 = func_80023874(0x121, NULL);
        if (var_a1 != NULL) {
            M2C_FIELD(arg0, s32 *, 0x7C) += 1;
            do {
                M2C_FIELD(var_a1, s32 **, 0x9C) = &func_80065A28;
                var_a1 = func_80023874(0x121, var_a1);
            } while (var_a1 != NULL);
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x7C) == 1) && (func_80052B24(func_80023DBC(0xE15, var_a1), D_80008C90, D_800BD06C) != 0)) {
        M2C_FIELD(arg0, s32 *, 0x7C) += 1;
    }
}

