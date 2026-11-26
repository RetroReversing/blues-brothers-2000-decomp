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

s16 coss(s32);                                      /* extern */
s32 func_8001B990(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_80024394(M2C_UNK, M2C_UNK);            /* extern */
f32 func_8002D340(f32, f32, f32);               /* extern */
extern f32 D_80000C78;
extern s32 D_800B9EA4;
extern M2C_UNK func_80013594;

void func_8001BE38(void *arg0) {
    f32 temp_fv0;

    func_80024394(0, 0x32);
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((s32) (coss(((D_800B9EA4 + M2C_FIELD(arg0, s32 *, 0x8C)) * 0x64) & 0xFFFC) * 0x7D) >> 0xC);
    if (func_8001B990(0x100, 2) != 0) {
      f32 temp_fs0;
        do { temp_fs0 = D_80000C78; } while (0);
        temp_fv0 = func_8002D340(temp_fs0, M2C_FIELD(arg0, f32 *, 8), 20.0f);
        M2C_FIELD(arg0, f32 *, 8) = temp_fv0;
        if (temp_fv0 == temp_fs0) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80013594;
            M2C_FIELD(arg0, s32 *, 0) = 0x10E;
        }
    }
}
