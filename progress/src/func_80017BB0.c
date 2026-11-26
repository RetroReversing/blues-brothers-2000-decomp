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

void *func_80015600(void *);                        /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_8002D4E0(void *, M2C_UNK);             /* extern */
s32 tickActorTimer();                                /* extern */
extern s16 D_800BD080;
extern M2C_UNK func_80017B14;

typedef struct { unsigned char pad_0[16]; int field_10; int field_14; int field_18; unsigned char pad_1C[68]; int field_60; unsigned char pad_64[32]; int field_84; } __repair_record_temp_v0;
void func_80017BB0(void *arg0) {
    void *temp_v0;

    if (tickActorTimer() != 0) {
        M2C_FIELD(arg0, s32 *, 0x64) = 5;
        temp_v0 = func_80015600(arg0);
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80017B14;
        ((__repair_record_temp_v0*)temp_v0)->field_14 = (s32) (randomRange(-0x1F4, 0x1F4) + 0x2000);
        ((__repair_record_temp_v0*)temp_v0)->field_10 = randomRange(-0xFA0, 0xFA0);
        func_8002D4E0(temp_v0, 0x5DC);
        *((int *)((char *)temp_v0 + 24)) = 0x4000;
        ((__repair_record_temp_v0*)temp_v0)->field_84 = 2;
        ((__repair_record_temp_v0*)temp_v0)->field_60 = (s32) (*(s32 *)&D_800BD080);
    }
    M2C_FIELD(arg0, s32 *, 0x68) = -1;
}
