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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);
void *func_800232B4(M2C_UNK, s32, s32, s32);
s32 randomRange(M2C_UNK, M2C_UNK);
s32 func_8002D1A0();
M2C_UNK func_8002D3E4(void *, M2C_UNK);
M2C_UNK syncActorPrevPos(void *);
extern s32 D_800BD170;
extern M2C_UNK func_800172B8;
extern M2C_UNK func_8002F8D0;

s32 func_80017344(void *arg0) {
    void *temp_v0;

    temp_v0 = func_800232B4(1, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0xC8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8002F8D0;
    M2C_FIELD(temp_v0, s32 *, 0x60) = (s32) D_800BD170;
    M2C_FIELD(temp_v0, s32 *, 0x70) = randomRange(0x32, 0x96);
    M2C_FIELD(temp_v0, s32 *, 0x74) = 0;
    M2C_FIELD(temp_v0, s32 *, 0x78) = 0xFFFFFF;
    M2C_FIELD(temp_v0, s32 *, 0x7C) = 1;
    M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0);
    M2C_FIELD(temp_v0, s32 *, 0x68) = 0xE;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = 0xFF;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0xC8;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_800172B8;
    M2C_FIELD(temp_v0, s32 *, 0x10) = func_8002D1A0();
    M2C_FIELD(temp_v0, s32 *, 0x14) = randomRange(0x2000, 0x2BB8);
    func_8002D3E4(temp_v0, 0x12C);
    syncActorPrevPos(temp_v0);
    M2C_FIELD(temp_v0, s32 *, 0x80) = 0;
    return (s32) temp_v0;
}
