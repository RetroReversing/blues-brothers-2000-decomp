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

extern f32 D_80009A94;
extern f64 D_80009A98;
extern M2C_UNK func_80084000;
extern M2C_UNK func_80085C28;

void func_80085244(void *arg0, void *arg1) {
    s32 temp_v1;
    s32 temp_v1_2;

    if (arg1 != NULL) {
        temp_v1 = M2C_FIELD(arg1, s32 *, 0x74);
        if (temp_v1 >= 2) {
            M2C_FIELD(arg0, f32 *, 0x104) = (f32) ((f32) temp_v1 * 50.0f);
        }
        temp_v1_2 = M2C_FIELD(arg1, s32 *, 0x78);
        if (temp_v1_2 >= 2) {
            M2C_FIELD(arg0, f32 *, 0xAC) = (f32) ((f64) temp_v1_2 * D_80009A98);
        }
        if (M2C_FIELD(arg1, s32 *, 0x70) != 0) {
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80085C28;
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80084000;
    }
}
