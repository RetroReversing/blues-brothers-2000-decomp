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

s32 cameraGetMode();
extern s32 D_800BD100;
s32 func_8000F294(void *arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;

    temp_s0 = (D_800BD100 * 0x10) | M2C_FIELD(arg0, s32 *, 0x78);
    temp_v0 = cameraGetMode();
    switch (temp_v0) {
    case 0x12:
        var_v0 = 19;
        goto block_4;
    default:
        return 0;
    case 0x20:
        var_v0 = 33;
block_4:
        if (temp_s0 == var_v0) {
        case 0x6:
        case 0x8:
        case 0x19:
        case 0x1C:
        case 0x27:
        case 0x38:
        case 0x3C:
            return 1;
        }
        return 0;
    }
}
