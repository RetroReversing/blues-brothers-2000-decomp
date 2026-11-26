/* identical to func_800457DC in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to alEnvmixerNew in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to alEnvmixerNew in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
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

s32 func_8009A8C0();
s32 func_8009BA60();
extern s32 func_80099C10;
extern s32 func_8009A110;

void alEnvmixerNew(void *arg0, s32 arg1) {
    func_8009A8C0(arg0, &func_80099C10, &func_8009A110, 4);
    M2C_FIELD(arg0, s32 *, 0x14) = func_8009BA60(0, 0, arg1, 1, 0x50);
    M2C_FIELD(arg0, s32 *, 0x38) = 1;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = 1;
    M2C_FIELD(arg0, s16 *, 0x28) = 1;
    M2C_FIELD(arg0, s16 *, 0x2E) = 1;
    M2C_FIELD(arg0, s16 *, 0x1C) = 1;
    M2C_FIELD(arg0, s16 *, 0x1E) = 1;
    M2C_FIELD(arg0, s16 *, 0x20) = 0;
    M2C_FIELD(arg0, s16 *, 0x22) = 0;
    M2C_FIELD(arg0, s16 *, 0x26) = 1;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s16 *, 0x26) = 1;
    M2C_FIELD(arg0, s16 *, 0x24) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s16 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x3C) = 0;
    M2C_FIELD(arg0, s32 *, 0x40) = 0;
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
}
