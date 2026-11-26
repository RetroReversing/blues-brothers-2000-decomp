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

s32 func_80013654();
s32 spawnSparkle();
s32 func_80017F78();
s32 func_8001B990();
s32 packDrawFlags();
s32 func_8002ADFC();
f32 getCameraTargetDist();
void *func_800510F4();
extern s32 func_8000DA34;
extern s32 func_80013610;

void func_8001D168(void *arg0) {
    s32 var_s0;
    void *temp_v0;

    if (((s32) getCameraTargetDist(arg0, 0x43480000, 0) < 0xC8) && (func_80013654(arg0) != 0)) {
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_8000DA34;
        M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF;
        M2C_FIELD(arg0, s32 *, 0x58) = packDrawFlags(1, 1, 1, 3, 0, 0, 1, 0);
        var_s0 = 0;
        M2C_FIELD(arg0, s32 *, 0x68) = 0xE;
        do {
            spawnSparkle(arg0);
            var_s0 += 1;
        } while (var_s0 < 4);
        temp_v0 = func_800510F4(arg0);
        M2C_FIELD(temp_v0, s32 *, 0x10) = 0x8000;
        M2C_FIELD(temp_v0, s32 **, 0x9C) = &func_80013610;
        M2C_FIELD(temp_v0, s32 *, 0x5C) = 0xFF;
        M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(1, 1, 1, 3, 0, 0, 1, 0);
        M2C_FIELD(temp_v0, s32 *, 0x68) = 0xE;
        func_8002ADFC(0xA, 0x3E8, arg0);
        if (func_8001B990(0x100, M2C_FIELD(arg0, s32 *, 0x70)) == 0) {
            func_8001B990(0x200, M2C_FIELD(arg0, s32 *, 0x70));
            func_80017F78(0xB);
        }
        M2C_FIELD(arg0, s32 (**)(void *), 0xA0)(arg0);
    }
}
