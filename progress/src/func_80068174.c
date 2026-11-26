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

void *func_8002E374();
void *func_80042F00();
s32 func_800433A8();
s32 func_80050460();
extern char D_800F4A00[];
extern char D_800F6188[];
extern char D_8014AA5C[];
extern s32 func_80018778;
extern s32 func_80068134;

void *func_80068174(void *arg0) {
    char *__base_D_800F6188;
    char *__base_D_800F4A00;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;

    func_80050460(&func_80068134, (char *)D_8014AA5C + 3);
    temp_v0 = func_80042F00(0x38, 0, 0, 0);
    func_800433A8(temp_v0, 0x124, 0x100);
    M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_80018778;
    M2C_FIELD(temp_v0, s32 *, 0x68) = -1;
    temp_v0_2 = func_8002E374(0x6B);
    M2C_FIELD(temp_v0_2, s32 *, 0x5C) = 0x60;
    M2C_FIELD(temp_v0_2, s32 *, 0x68) = -1;
    M2C_FIELD(temp_v0, void **, 0xA8) = temp_v0_2;
    __base_D_800F4A00 = D_800F4A00;
    temp_v0_3 = (M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC) + __base_D_800F4A00;
    loop_goto_1:
    {
 M2C_FIELD(temp_v0_3, s32 *, 8) = 0x4B;
    }
    if (0)
    {
        goto loop_goto_1;
    }
    do { do { do { M2C_FIELD(temp_v0_3, s32 *, 0) = 0x4B; } while (0); } while (0); } while (0);
    M2C_FIELD(((M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC) + __base_D_800F4A00), s32 *, 4) = 0x78;
    __base_D_800F6188 = D_800F6188;
    M2C_FIELD(((M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC) + __base_D_800F6188), s32 *, 4) = 0;
    do { temp_v0_4 = (M2C_FIELD(temp_v0, s32 *, 0xB8) * 0xC) + __base_D_800F6188; } while (0);
    M2C_FIELD(temp_v0_4, s32 *, 8) = -0x4B;
    M2C_FIELD(temp_v0_4, s32 *, 0) = -0x4B;
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_v0_2, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0_2, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0_2, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    }
    return temp_v0;
}
