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

void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80050460(M2C_UNK *, void *);           /* extern */
M2C_UNK func_80074BAC();                            /* extern */
M2C_UNK func_80081588(M2C_UNK, M2C_UNK);            /* extern */
extern s32 D_800B3974;
extern s32 D_800B3970;
extern s32 D_800B3978;
extern M2C_UNK D_8014AA7A;
extern M2C_UNK func_80074DDC;
extern M2C_UNK func_80075E4C;
extern M2C_UNK func_8007BC24;

void func_80074C9C(void *arg0) {
    void *temp_v0;
    
    
    

    D_800B3970 = 150;
    D_800B3974 = 182;
    D_800B3978 = 0xC6;
    func_80081588(1, 0);
    func_80081588(6, 0);
    func_80074BAC();
    func_80050460(&func_80075E4C, (char *)&D_8014AA7A + 1);
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    temp_v0 = func_800232B4(1, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007BC24;
    M2C_FIELD(temp_v0, s32 *, 0x70) = 7;
    M2C_FIELD(temp_v0, s32 *, 0x74) = 1;
    temp_v0 = func_800232B4(1, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007BC24;
    M2C_FIELD(temp_v0, s32 *, 0x70) = 8;
    M2C_FIELD(temp_v0, s32 *, 0x74) = 1;
    temp_v0 = func_800232B4(1, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007BC24;
    M2C_FIELD(temp_v0, s32 *, 0x70) = 4;
    temp_v0 = func_800232B4(1, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0x70) = 5;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8007BC24;
    M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80074DDC;
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    M2C_FIELD(arg0, s32 *, 0x64) = 0;
}
