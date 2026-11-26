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

s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8002D620(void *);
void *func_80042F00(s32, s32, s32, s32);
s32 func_800433A8(void *, s32, s32);
s32 func_80050460(void *, s32 *);
s32 func_80081588(s32, s32);
s32 func_800852CC(void *, s32);
extern u8 D_8014AA3C[];
extern s32 func_80058E1C;
extern s32 func_80059100;

void *func_80058E90(s32 arg0) {
    void *temp_v0;

    func_80050460((char *) &func_80058E1C + 4, (s32 *) D_8014AA3C);
    temp_v0 = func_80042F00(0x11, 0, 0, 0);
    func_800433A8(temp_v0, 0x40, 0x180);
    func_800852CC(temp_v0, arg0);
    M2C_FIELD(temp_v0, s32 *, 0x34) = 0x180;
    M2C_FIELD(temp_v0, s32 *, 0x38) = 0x180;
    M2C_FIELD(temp_v0, s32 *, 0x3C) = 0x180;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0x80;
    M2C_FIELD(temp_v0, s32 *, 0x58) = func_800221C0(1, 1, 0, 3, 0, 0, 1, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x100F;
    if (M2C_FIELD(temp_v0, s32 *, 0x70) != 0) {
        func_80081588(M2C_FIELD(temp_v0, s32 *, 0x70), 1);
        M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_80059100;
    }
    func_8002D620(temp_v0);
    return temp_v0;
}
