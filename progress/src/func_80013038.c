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

s32 func_800221C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 func_80023E3C(M2C_UNK);                         /* extern */
M2C_UNK func_8002D604(void *);                      /* extern */
void *func_8004EB60(void *);                        /* extern */
extern s32 D_800BD23C;
extern M2C_UNK func_80012FB8;
extern M2C_UNK func_8001F26C;

void func_80013038(void *arg0) {
    void *temp_v0;

    M2C_FIELD(arg0, s32 *, 0xB8) = 0x90;
    M2C_FIELD(arg0, s32 *, 0xE4) = func_80023E3C(0x90);
    M2C_FIELD(arg0, s32 *, 0x58) = func_800221C0(1, 1, 0, 2, 0, 1, 1, 0);
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
    M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_8001F26C;
    M2C_FIELD(arg0, s32 *, 0x94) = 0x1B58;
    func_8002D604(arg0);
    func_8002D604(arg0);
    if (D_800BD23C != 0) {
        temp_v0 = func_8004EB60(arg0);
        M2C_FIELD(arg0, void **, 0xA8) = temp_v0;
        if (temp_v0 != NULL) {
            M2C_FIELD(arg0, s32 *, 0x68) = -1;
            M2C_FIELD(arg0, s32 *, 0x64) = 0xBB8;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80012FB8;
            M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_80012FB8;
            M2C_FIELD(temp_v0, void **, 0xA4) = arg0;
            M2C_FIELD(temp_v0, s32 *, 0x64) = 0xBB8;
        }
    }
}
