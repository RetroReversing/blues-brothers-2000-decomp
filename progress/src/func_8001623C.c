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

void *func_80012718(void *);                        /* extern */
s32 tickActorTimer();                                /* extern */
extern f32 D_80000878;
extern s32 func_80016168;
extern s32 func_80023078;

typedef struct { unsigned char pad[100]; int value; } __repair_field_64;
void func_8001623C(void *arg0) {
    f32 temp_fs0;
    s32 var_s0;
    void *temp_v0;

    loop_goto_1:
    {
 (*(void **)((s8 *)arg0 + 0x98)) = (void *) ((&func_80023078) + 0x2);
    }
    if (0)
    {
        goto loop_goto_1;
    }
    (*(s32 *)((s8 *)arg0 + 0)) = 0x101;
    if (tickActorTimer() != 0) {
        var_s0 = 0;
        temp_fs0 = 400.0f;
        (((__repair_field_64 *)arg0)->value) = (s32) (*(s32 *)((s8 *)arg0 + 0x70));
        do {
            { temp_v0 = func_80012718(arg0); }
            { var_s0 += 1; }
            (*(f32 *)((s8 *)temp_v0 + 0x50)) = temp_fs0;
            { { { (((__repair_field_64 *)temp_v0)->value) = 0x32; } } }
            { { { (*(s32 **)((s8 *)temp_v0 + 0x9C)) = &func_80016168; } } }
            { { { (*(s32 *)((s8 *)temp_v0 + 0x70)) = 0xC8; } } }
        } while (var_s0 <= 0);
    }
}
