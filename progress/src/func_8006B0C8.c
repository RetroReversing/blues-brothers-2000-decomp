/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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
void *findActor();
s32 func_8002D858();
s32 animStepKeys();
s32 debugPrintf();
extern char D_80008ECC[];
extern void *D_800B3964;
extern s32 func_8000F310;
extern s32 func_80023078;

typedef struct { unsigned char pad_0[120]; int field_78; unsigned char pad_7C[32]; void * field_9C; } __repair_record_temp_v0;
void func_8006B0C8(void *arg0) {
    void *temp_v0;

    func_8002D858(arg0, arg0 + 0x10);
    animStepKeys(arg0);
    if ((cameraGetMode() == 5) && (findActor(0x800, 0) == NULL)) {
        temp_v0 = findActor(0x13C, 0);
        if (temp_v0 != NULL) {
            ((__repair_record_temp_v0*)temp_v0)->field_9C = &func_8000F310;
            ((__repair_record_temp_v0*)temp_v0)->field_78 = 9;
            if (D_800B3964 != NULL) {
                M2C_FIELD(D_800B3964, void **, 0x9C) = (void *) ((s8 *)&func_80023078 + 8);
            }
            M2C_FIELD(arg0, s32 (**)(void *), 0x9C) = animStepKeys;
            return;
        }
        debugPrintf(D_80008ECC);
    }
}
