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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80023920();
s32 func_80025280();
s32 func_80042F00();
s32 actorSetAnim();
s32 func_8007DA10();
extern s32 D_800B8670;
extern char D_800B8674[];

s32 func_8007DA68(void) {
    s32 __index_D_800B8674;
    s32 temp_a0;
s32 __repair_phase_temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    void *var_s0;
    char *__base_D_800B8674;

    __base_D_800B8674 = 0;

    var_s0 = func_80023920(0x1000, 0x1031, NULL);
    if (var_s0 != NULL) {
        for (;;) {
            temp_v0_2 = func_8007DA10(var_s0);
                   if (temp_v0_2 != 0) {
char *__branch___base_D_800B8674;

                       temp_a0 = M2C_FIELD(var_s0, s32 *, 0xE0);
                       if (temp_a0 != 0) {
                           func_80025280(temp_a0);
                           M2C_FIELD(var_s0, s32 *, 0xE0) = 0;
                       }
                       temp_v0 = func_80042F00(M2C_FIELD(var_s0, s32 *, 0xB8), 0, 0, 0);
                       { __repair_phase_temp_a0 = (temp_v0_2 - 1) * 8;
            __branch___base_D_800B8674 = D_800B8674;
            { actorSetAnim(temp_v0, M2C_FIELD((__branch___base_D_800B8674 + __repair_phase_temp_a0), s32 *, 4), 0x100); } }
                       return temp_v0;
                   }
                   var_s0 = func_80023920(0x1000, 0x1031, var_s0);
                   if (var_s0 != NULL) {
                   continue;
               }
                   else {
                       goto block_7;
                   }
            break;
        }
}
block_7:
    D_800B8670 = -1;
    return 0;
}
