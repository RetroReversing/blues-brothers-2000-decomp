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

s32 cameraGetMode();                                /* extern */
M2C_UNK func_80025280(s32);                         /* extern */
f32 func_8002D858(void *, M2C_UNK *);               /* extern */
f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_8003EA18(s32);                         /* extern */
extern f32 D_80009240;
extern f64 D_80009248;
extern s32 D_800B83B4;
extern void *gCameraTarget;
extern f32 D_801700D0;
extern M2C_UNK D_801700D4;
extern s32 D_801700D8;

s32 func_80076080(void *arg0) {
    f32 limit;
    f32 dist;
    s32 near;
    s32 temp_a0;
    s32 temp_a0_2;

    near = 0;
    if (cameraGetMode() == 1) {
        D_801700D8 = 0x7D0;
        near = 1;
    } else {
        D_801700D8 = 0x1F40;
    }
    limit = (f32) D_801700D8;
    dist = func_8002D858(arg0, &D_801700D4);
    D_801700D0 = dist;
    if (dist < limit) {
        if (M2C_FIELD(arg0, s32 *, 0x68) < 0) {
            M2C_FIELD(arg0, s32 *, 0x68) = 4;
        }
        return 0;
    }
    if (near != 0) {
        dist = func_8002DD60(M2C_FIELD(arg0, f32 *, 8) - M2C_FIELD(gCameraTarget, f32 *, 8));
        limit = limit / 3.0f;
        M2C_FIELD(arg0, s32 *, 0x68) = 4;
    } else {
        limit = (f32) ((f64) limit * 2.5);
    }
    if (limit < dist) {
        if (M2C_FIELD(arg0, s32 *, 0x68) == -1) {
            temp_a0 = M2C_FIELD(arg0, s32 *, 0xE0);
            if (temp_a0 != 0) {
                func_8003EA18(temp_a0);
                func_80025280(M2C_FIELD(arg0, s32 *, 0xE0));
                M2C_FIELD(arg0, s32 *, 0xE0) = 0;
            }
            goto block_16;
        }
    } else if (M2C_FIELD(arg0, s32 *, 0x68) == -1) {
block_16:
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0xC4);
        if (temp_a0_2 != 0) {
            func_80025280(temp_a0_2);
            M2C_FIELD(arg0, s32 *, 0xC4) = 0;
        }
        D_800B83B4 += 1;
    }
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
    return 1;
}
