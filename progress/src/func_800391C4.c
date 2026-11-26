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

s32 findActor(s32, s32);                /* extern */
extern void *D_800B3964;
extern s32 func_80023078;

typedef struct { unsigned char pad[124]; int value; } __repair_field_7C;
typedef struct { unsigned char pad[104]; int value; } __repair_field_68;
void func_800391C4(void *arg0) {
    s32 *__base_func_80023078;
    if (((__repair_field_7C *)arg0)->value == 0) {
        ((__repair_field_7C *)arg0)->value = 1;
        ((__repair_field_68 *)arg0)->value = -1;
        (*(s32 *)((s8 *)arg0 + 0)) = 0x101;
    }
    if (findActor(0x101B, 0) == 0) {
        (*(s32 *)((s8 *)arg0 + 0)) = 0x10A;
        (*(void **)((s8 *)arg0 + 0x9C)) = (void *) ((s8 *)&func_80023078 + 8);
        ((__repair_field_68 *)arg0)->value = 1;
        ((__repair_field_7C *)arg0)->value = 1;
        (*(s32 *)((s8 *)D_800B3964 + 0xC0)) = 1;
    }
}
