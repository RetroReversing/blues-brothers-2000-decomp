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
extern s32 D_800B9ECC;
extern s32 func_80023078;

void func_8001B6D0(void *arg0) {
    s32 temp_v0;
    s32 temp_v1_2;
    u32 temp_v1;

    temp_v1 = (*(u32 *)((s8 *)arg0 + 0xC0));
    switch (temp_v1) {
    case 0:
        (*(s32 *)((s8 *)arg0 + 0x5C)) = 0;

        (*(u32 *)((s8 *)arg0 + 0xC0)) = (u32) ((*(u32 *)((s8 *)arg0 + 0xC0)) + 1);
        return;
    case 1:
        temp_v0 = (*(s32 *)((s8 *)arg0 + 0x5C)) + (D_800B9ECC * 2);
        (*(s32 *)((s8 *)arg0 + 0x5C)) = temp_v0;
        if (temp_v0 >= 0xFF) {
            (*(s32 *)((s8 *)arg0 + 0x5C)) = 0xFF;
            (*(s32 *)((s8 *)arg0 + 0x64)) = 0xC8;
            {
(*(u32 *)((s8 *)arg0 + 0xC0)) = (u32) ((*(u32 *)((s8 *)arg0 + 0xC0)) + 1);
return;
}
        }
    default:
        return;
    case 2:
        if (func_8002D5CC(arg0) != 0) {
            {
(*(u32 *)((s8 *)arg0 + 0xC0)) = (u32) ((*(u32 *)((s8 *)arg0 + 0xC0)) + 1);
return;
}
        }
        break;
    case 3:
        temp_v1_2 = (*(s32 *)((s8 *)arg0 + 0x5C)) - (D_800B9ECC * 2);
        (*(s32 *)((s8 *)arg0 + 0x5C)) = temp_v1_2;
        if (temp_v1_2 <= 0) {
            (*(s32 *)((s8 *)arg0 + 0x5C)) = 0;
            (*(void **)((s8 *)arg0 + 0x98)) = (void *)((s8 *)&func_80023078 + 8);
            loop_goto_1:
            {
 (*(u32 *)((s8 *)arg0 + 0xC0)) = (u32) ((*(u32 *)((s8 *)arg0 + 0xC0)) + 1);
            }
            if (0)
            {
                goto loop_goto_1;
            }
            return;
        }
        break;
    case 4:
        (*(s32 (**)(void *))((s8 *)arg0 + 0xA0))(arg0);
        break;
    }
}
