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

s32 *heapAlloc(s32 size);
s32 debugPrintf(s32 *);
extern char D_80007E98[];

void func_8004E538(void *arg0, s32 arg1, s32 *arg2, s32 arg3) {
    s32 *temp_a1;
    s32 *temp_a3;
    s32 *p;
    s32 *src;
    s32 i;
    s32 bound;
    s32 m1;
    s32 temp_v0_2;

    if (arg1 < 4) {
        debugPrintf((s32 *) D_80007E98);
    }
    M2C_FIELD(arg0, s32 *, 0x70) = arg1;
    temp_a1 = heapAlloc(arg1 * 0xC);
    i = 0;
    if (M2C_FIELD(arg0, s32 *, 0x70) > 0) {
        do {
            temp_a1[i * 3] = arg2[i * 3];
            temp_a1[i * 3 + 1] = arg2[i * 3 + 1];
            temp_a1[i * 3 + 2] = arg2[i * 3 + 2];
            i++;
        } while (i < M2C_FIELD(arg0, s32 *, 0x70));
    }
    M2C_FIELD(arg0, s32 **, 0x74) = temp_a1;
    temp_a3 = heapAlloc((arg1 + 4) * 4);
    temp_v0_2 = arg1 + 3;
    i = 0;
    if (temp_v0_2 >= 0) {
        m1 = arg1 - 1;
        bound = temp_v0_2;
        p = temp_a3;
        do {
            if (i < 3) {
                *p = 0;
            } else if (arg1 >= i) {
                *p = i - 4;
            } else {
                *p = m1;
            }
            i++;
            p++;
        } while (bound >= i);
    }
    M2C_FIELD(arg0, s32 **, 0x78) = temp_a3;
    M2C_FIELD(arg0, s32 *, 0x7C) = arg3;
}
