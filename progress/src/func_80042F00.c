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

s32 func_800221C0();
void *func_800232B4();
void *func_80023E18();
s32 func_80023E3C();
s32 func_8002D620();
s32 func_80041418();
s32 func_800899DC();
extern char D_800078C4[];
extern s32 D_800B7B0C;
extern char D_800FB038[];
extern s32 D_801407C0;
extern s32 func_800414D0;
extern s32 func_80042EA4;

void *func_80042F00(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 *temp_s0_2;
    void *temp_s0;
    void *temp_s1;
    void *temp_s5;
    s32 temp;
    char *__base_D_800FB038;

    __base_D_800FB038 = D_800FB038;

    temp = arg0 * 4;
    { temp_s0_2 = temp + __base_D_800FB038; }
    temp_s5 = func_80023E18(*temp_s0_2);
    temp_s1 = func_80023E18(*temp_s0_2);
    temp_s0 = func_800232B4(1, arg1, arg2, arg3);
    M2C_FIELD(temp_s0, s32 *, 0x58) = func_800221C0(1, 1, 0, 3, D_800B7B0C, 0, 1, 0);
    M2C_FIELD(temp_s0, s32 *, 0xD0) = -1;
    M2C_FIELD(temp_s0, s32 **, 0xA0) = &func_80042EA4;
    M2C_FIELD(temp_s0, s32 *, 0xB8) = arg0;
    M2C_FIELD(temp_s0, s32 **, 0x98) = &func_800414D0;
    M2C_FIELD(temp_s0, s32 *, 0xE4) = func_80023E3C(arg0);
    if (temp_s5 == NULL) {
        func_800899DC(D_800078C4, M2C_FIELD(temp_s0, const s32 *, 0xB8));
    }
    M2C_FIELD(temp_s0, s32 *, 0xE0) = func_80041418(temp_s5);
    if (M2C_FIELD(temp_s1, const u16 *, 2) & 2) {
        M2C_FIELD(temp_s0, s32 *, 0xE8) = (s32) D_801407C0;
    }
    func_8002D620(temp_s0);
    return temp_s0;
}
