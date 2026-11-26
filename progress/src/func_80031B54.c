/* identical to updateMenuScroll (matched), with its names changed by decompdecomp */
/* Draft from identical target func_80031B54, retargeted and judged independently. */
/* Draft from identical target func_80031B54, retargeted and judged independently. */
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

s32 tickActorTimer(void *);                          /* extern */
extern s32 gTextWaveTime;
extern s32 gPadPressed;
extern s32 D_801073B0;
extern s32 D_801073C0;

typedef struct { unsigned char pad[120]; int value; } __repair_field_78;
void func_80031B54(void *arg0, s32 arg1) {
    s32 var_v0;
    s32 temp;

    temp = (D_801073B0 >= 0) ? D_801073B0 : -D_801073B0;
    if (temp < 0x14) {
        s32 var_v0_2_a1;
        var_v0_2_a1 = D_801073C0;
        if (var_v0_2_a1 < 0) {
            var_v0_2_a1 = -var_v0_2_a1;
        }
        if (var_v0_2_a1 < 0x14) {
            (*(s32 *)((s8 *)arg0 + 0x64)) = 0;
        }
    }
    if (tickActorTimer(arg0) != 0) {
        (*(s32 *)((s8 *)arg0 + 0x64)) = 0;
        if (!(gPadPressed & 0x800)) {
            if (D_801073C0 >= 0x1F) {
                goto block_11;
            }
        } else {
block_11:
            (*(s32 *)((s8 *)arg0 + 0x64)) = 0x19;
            { (((__repair_field_78 *)arg0)->value) = (s32) ((((__repair_field_78 *)arg0)->value) - 1); }
            (*(s32 *)((s8 *)arg0 + 0x8C)) = (s32) gTextWaveTime;
        }
        if ((gPadPressed & 0x400) || (D_801073C0 < -0x1E)) {
            (*(s32 *)((s8 *)arg0 + 0x64)) = 0x19;
            { (((__repair_field_78 *)arg0)->value) = (s32) ((((__repair_field_78 *)arg0)->value) + 1); }
            (*(s32 *)((s8 *)arg0 + 0x8C)) = (s32) gTextWaveTime;
        }
        if ((((__repair_field_78 *)arg0)->value) < 0) {
            (((__repair_field_78 *)arg0)->value) = 0;
        }
        if ((((__repair_field_78 *)arg0)->value) >= arg1) {
            (((__repair_field_78 *)arg0)->value) = (s32) (arg1 - 1);
        }
    }
}

