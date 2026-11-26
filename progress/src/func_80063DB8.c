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

M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8002DA40();                            /* extern */
f32 func_8002DD60(f32);                             /* extern */
extern f64 D_80008B30;
extern M2C_UNK func_80063D8C;

void func_80063DB8(void *arg0) {
    func_8002DA40();
    if ((tickActorTimer(arg0) != 0) || (M2C_FIELD(arg0, f32 *, 8) < M2C_FIELD(arg0, f32 *, 0x44))) {
        M2C_FIELD(arg0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 0x44);
        M2C_FIELD(arg0, f32 *, 0x50) = (f32) ((f64) func_8002DD60(M2C_FIELD(arg0, f32 *, 0x50)) * D_80008B30);
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xA7);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80063D8C;
    }
}
