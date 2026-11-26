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

s32 func_8002D1A0();                                /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
extern M2C_UNK func_80014E70;

void *func_800153B4(void *arg0) {
    void *temp_v0;

    temp_v0 = func_8002E374(0x99);
    M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    M2C_FIELD(temp_v0, s32 *, 0x10) = func_8002D1A0();
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80014E70;
    M2C_FIELD(temp_v0, s32 *, 0x64) = 0x3E8;
    syncActorPrevPos(temp_v0);
    return temp_v0;
}
