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

void *func_800232B4(M2C_UNK, s32, s32, s32);        /* extern */
s32 func_800253A0(M2C_UNK);                         /* extern */
M2C_UNK func_80026C04(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80048534(void *);                      /* extern */
extern M2C_UNK func_800485A4;
extern M2C_UNK func_800486C4;
void *func_80048248(void *arg0) {
    void *temp_s0;
    s32 temp_v0;
    if (arg0 != NULL) {
        temp_s0 = func_800232B4(1, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    } else {
        temp_s0 = func_800232B4(1, 0, 0, 0);
    }
    temp_v0 = func_800253A0(8);
    M2C_FIELD(temp_s0, s32 *, 0xE8) = temp_v0;
    func_80026C04(temp_v0, 0, 8);
    M2C_FIELD(temp_s0, M2C_UNK **, 0x9C) = &func_800485A4;
    M2C_FIELD(temp_s0, M2C_UNK **, 0xA0) = &func_800486C4;
    M2C_FIELD(temp_s0, s32 *, 0x70) = 0xFF;
    M2C_FIELD(temp_s0, s32 *, 0x74) = 0xFF;
    M2C_FIELD(temp_s0, s32 *, 0x78) = 0xFF;
    M2C_FIELD(temp_s0, s32 *, 0x7C) = 0x64;
    M2C_FIELD(temp_s0, s32 *, 0x80) = 0x1F4;
    M2C_FIELD(temp_s0, s32 *, 0x84) = 0;
    func_80048534(temp_s0);
    return temp_s0;
}
