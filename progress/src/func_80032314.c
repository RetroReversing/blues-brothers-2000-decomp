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

s32 getImageAsset();
s32 func_80027038();
s32 setTextColor();
s32 setTextPos();
s32 func_80028710();
s32 func_800294D0();
s32 setSlotTextColor();
extern s32 D_800B4A90;

void func_80032314(void *arg0) {
    char *var_s1;
    s32 temp_a0;
    s32 var_s0;
    s32 var_s2;

    func_80027038(1);
    var_s0 = 0;
    var_s2 = 0x46;
    func_800294D0(getImageAsset(M2C_FIELD(arg0, s32 *, 0x84)));
    setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
    var_s1 = &D_800B4A90;
    do {
        setSlotTextColor(arg0, var_s0);
        setTextPos(0xA0, var_s2);
        temp_a0 = *(s32 *)var_s1;
        var_s1 += 4;
        var_s2 += 0xF;
        var_s0 += 1;
        func_80028710(temp_a0);
    } while (var_s0 < 6);
}
