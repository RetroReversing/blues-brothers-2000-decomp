#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_BITS_F32(expr) (m2c_bits = (u32)(expr), *(f32 *)&m2c_bits)
extern u32 m2c_bits;
#define M2C_PTR_FROM_F32(type, expr) ((type)(m2c_fbits = (expr), *(u32 *)&m2c_fbits))
extern f32 m2c_fbits;
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
s32 func_80023D58(s32);
s32 getImageAsset(s32);
void setTextColor(s32, s32, s32, s32);
void drawImage(s32, s32, s32, s32);
s32 tickActorTimer(void *);
extern s32 gCamSpeedScale;

void func_80063C40(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x5C) + (M2C_FIELD(arg0, s32 *, 0x70) * gCamSpeedScale);
    M2C_FIELD(arg0, s32 *, 0x5C) = temp_v0;
    if (temp_v0 >= 0x100) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
    }
    if (M2C_FIELD(arg0, s32 *, 0x5C) < 0) {
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    }
    setTextColor(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, s32 *, 0x5C));
    temp_v0_2 = func_80023D58(0x218);
    M2C_FIELD(arg0, s32 *, 0x60) = temp_v0_2;
    drawImage(getImageAsset(temp_v0_2), 0, 0, 0);
    if ((tickActorTimer(arg0) != 0) || (M2C_FIELD(arg0, s32 *, 0x5C) == 0)) {
        M2C_FIELD(arg0, void (**)(void *), 0xA0)(arg0);
    }
}
