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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 initControllerPaks();
s32 osContInit();
s32 osCreateMesgQueue();
s32 osCreateThread();
s32 osPfsIsPlug();
s32 osSetEventMesg();
s32 osStartThread();
extern s32 gPakInitError;
extern char D_80106A54[];
extern char D_80106A60[];
extern char D_80107010[];
extern char D_80106C10[];
extern char D_80107050[];
extern char D_80107058[];
extern char D_801071F0[];
extern char D_801075DC[];
extern char D_801075E0[];
extern s32 func_80025BC8;

void func_80025F20(void) {
    osCreateMesgQueue(D_80107058, D_801075DC, 1);
    osSetEventMesg(5, D_80107058, 1);
    osCreateMesgQueue(D_801075E0, D_80106A54, 1);
    osCreateThread(D_80106A60, 8, &func_80025BC8, 0, D_80106C10 + 0x400, 0xF);
    { osStartThread(D_80106A60); }
    osContInit(D_80107058, D_801071F0, D_80107010);
    osPfsIsPlug(D_80107058, D_80107050);
    gPakInitError = 0;
    initControllerPaks();
}

