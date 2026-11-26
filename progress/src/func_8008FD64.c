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

s32 alHeapDBAlloc();
s32 func_8008FEBC();
s32 func_800901B0();
s32 func_800901F4();
s32 func_8009A8C0();
extern s32 D_8017B270;
extern s32 D_8017B274;
extern s32 D_8017B278;
extern s32 D_8017B27C;
extern s32 D_8017B280;
extern s32 D_8017B284;
extern s32 alFxParamHdl;
extern s32 alFxPull;
extern s32 func_8009B074;

void func_8008FD64(void *arg0, void *arg1, s32 arg2) {
    func_8009A8C0(arg0, 0, &func_8009B074, 5);
    M2C_FIELD(arg0, s32 **, 4) = &alFxPull;
    M2C_FIELD(arg0, s32 **, 0x28) = &alFxParamHdl;
    D_8017B270 = alHeapDBAlloc(0, 0, arg2, func_800901B0(), 0x28);
    D_8017B274 = alHeapDBAlloc(0, 0, arg2, func_800901F4(), 2);
    D_8017B278 = alHeapDBAlloc(0, 0, arg2, 1, 0x34);
    D_8017B27C = alHeapDBAlloc(0, 0, arg2, 1, 0x20);
    D_8017B280 = alHeapDBAlloc(0, 0, arg2, 1, 0x30);
    D_8017B284 = alHeapDBAlloc(0, 0, arg2, 1, 8);
    func_8008FEBC(M2C_FIELD(arg1, s32 *, 0x20));
}
