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

s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D1A0();                                /* extern */
M2C_UNK func_8002D4E0(void *, s32);                 /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
f32 func_8002D858(void *, M2C_UNK);                 /* extern */
void *func_8002E374(s32);                           /* extern */
extern f32 D_80000D5C;
extern M2C_UNK func_8001E314;
extern M2C_UNK func_80023848;

void *func_8001E394(void *arg0) {
    void *temp_s1;

    temp_s1 = func_8002E374(M2C_FIELD(arg0, s32 *, 0xB8));
    M2C_FIELD(temp_s1, s32 *, 0x10) = func_8002D1A0();
    M2C_FIELD(temp_s1, s32 *, 0x14) = randomRange(0x2000, 0x3E80);
    func_8002D4E0(temp_s1, randomRange(0x5DC, 0x7D0));
    M2C_FIELD(temp_s1, s32 *, 0) = 0x101;
    M2C_FIELD(temp_s1, M2C_UNK **, 0x9C) = &func_8001E314;
    M2C_FIELD(temp_s1, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
    M2C_FIELD(temp_s1, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
    M2C_FIELD(temp_s1, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
    syncActorPrevPos(temp_s1);
    if (func_8002D858(temp_s1, 0) < 200.0f) {
        M2C_FIELD(temp_s1, M2C_UNK **, 0x9C) = &func_80023848;
        M2C_FIELD(temp_s1, s32 *, 0) = 0x101;
    }
    return temp_s1;
}

