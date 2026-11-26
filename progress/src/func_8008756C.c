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

M2C_UNK func_8000C458();                            /* extern */
M2C_UNK func_80023620(M2C_UNK);                     /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK tickActorTimer(void *);                      /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
extern s32 D_800B5DD4;
extern s32 gPadPressed;
extern M2C_UNK gBrotherActorTypes;
extern M2C_UNK gIntroSprites;
extern void *gIntroActors;
extern M2C_UNK func_8003D558;
extern M2C_UNK func_800876A4;

void func_8008756C(void *arg0) {
    s32 var_a0;
    s32 var_s0;
    void **var_v1;

    var_s0 = 0;
    if (gPadPressed & 0x4000) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003D558;
        func_8002E7B8(1, 0);
        D_800B5DD4 = 1;
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x9D);
        return;
    }
    var_a0 = 0;
    var_v1 = &gIntroActors;
    do {
        if (M2C_FIELD(*var_v1, s32 *, 0xC0) != 0) {
            var_s0 += 1;
        }
        var_a0 += 1;
        var_v1 += 1;
    } while (var_a0 < 4);
    if (var_s0 == 2) {
        tickActorTimer(arg0);
    } else {
        M2C_FIELD(arg0, s32 *, 0x64) = 0x96;
    }
    if ((var_s0 == 2) && (M2C_FIELD(arg0, s32 *, 0x64) < 0)) {
        func_8000C458();
        func_80023620(0x101);
        func_8002E7B8(1, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800876A4;
        M2C_FIELD(&gBrotherActorTypes, s32 *, 0) = (s32) M2C_FIELD(M2C_FIELD(&gIntroSprites, void **, 0), s32 *, 0x84);
        M2C_FIELD(&gBrotherActorTypes, s32 *, 4) = (s32) M2C_FIELD(M2C_FIELD(&gIntroSprites, void **, 4), s32 *, 0x84);
    }
}
