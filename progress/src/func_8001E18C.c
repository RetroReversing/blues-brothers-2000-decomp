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

s32 func_80013654(void *);                          /* extern */
s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
f32 func_8002DD60(f32);                             /* extern */
extern f32 D_80000D48;
extern f32 D_80000D4C;
extern f32 D_80000D50;
extern u8 gCameraTarget[];
extern M2C_UNK func_8001E0E0;

void func_8001E18C(void *arg0) {
    f32 temp_fs0;
    f32 temp_fs1;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        if (func_8001B990(0x100, 0x12) != 0) {
            M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        goto block_4;
    }
block_4:
    temp_fs0 = D_80000D48;
    temp_fs1 = M2C_FIELD(arg0, f32 *, 0xC) - M2C_FIELD(*(void **) gCameraTarget, f32 *, 0xC);
    if ((func_8002DD60(M2C_FIELD(arg0, f32 *, 4) - M2C_FIELD(*(void **) gCameraTarget, f32 *, 4)) < temp_fs0) && (func_8002DD60(temp_fs1) < temp_fs0) && (func_80013654(arg0) != 0)) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x28);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8001E0E0;
        func_8001B990(0x200, 0x12);
        if (temp_fs1 > 0.0f) {
            M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_80000D4C;
            return;
        }
        M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_80000D50;
    }
}
