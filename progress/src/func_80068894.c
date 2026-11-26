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

s32 func_8002D5CC(void *);                          /* extern */
f32 func_8002DD60(f32);                             /* extern */
s32 func_80069050(void *);                          /* extern */
s32 func_80069520(s32);                     /* extern */
extern void *D_800BD06C;

void func_80068894(void *arg0) {
    void *temp_a0;
    void *temp_a0_gc;
    void *temp_s0;

    if (func_8002DD60(*(f32 *)((s8 *)D_800BD06C + 4)) < 730.0f) {
        if (550.0f < *(f32 *)((s8 *)D_800BD06C + 0xC)) {
            *(f32 *)((s8 *)D_800BD06C + 0xC) = 550.0f;
        }
    }
    if (func_8002D5CC(arg0) != 0) {
        (*(s32 *)((s8 *)arg0 + 0x90)) = func_80069050(D_800BD06C);
        (*(s32 *)((s8 *)arg0 + 0x64)) = 0;
        temp_a0 = (*(void **)((s8 *)arg0 + 0x84));
        if (temp_a0 != NULL) {
            temp_a0_gc = temp_a0;
            temp_a0 = NULL;
            temp_s0 = (*(void **)((s8 *)arg0 + 0x88));
            if (temp_s0 != NULL) {
                (*(s32 *)((s8 *)temp_a0_gc + 0x8C)) = 0;
                (*(s32 *)((s8 *)temp_s0 + 0x8C)) = 0;
                if (((*(s32 *)((s8 *)temp_a0_gc + 0x74)) == (*(s32 *)((s8 *)temp_s0 + 0x74))) && ((*(s32 *)((s8 *)temp_a0_gc + 0x70)) == (*(s32 *)((s8 *)temp_s0 + 0x70)))) {
                    (*(s32 (**)(void *))((s8 *)temp_a0_gc + 0xA0))(temp_a0_gc);
                    (*(s32 (**)(void *))((s8 *)temp_s0 + 0xA0))(temp_s0);
                    func_80069520(1);
                }
                (*(s32 *)((s8 *)arg0 + 0x90)) = -1;
                (*(void **)((s8 *)arg0 + 0x88)) = NULL;
                (*(void **)((s8 *)arg0 + 0x84)) = NULL;
                (*(s32 *)((s8 *)arg0 + 0x64)) = 0x64;
            }
        } else if ((*(void **)((s8 *)arg0 + 0x88)) == NULL) {
            func_80069520(0);
        }
    }
}
