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

s16 coss();
void *func_80017344();
s32 randomRange();
s32 func_8002D1A0();
s32 approachAngle();
s32 func_8002D260();
s32 func_8002D3E4();
s32 tickActorTimer();
s32 func_8003B828();
s32 func_80043328();
s16 sins();
extern s32 gCamSpeedScale;
extern s32 gCameraTarget;

s32 func_800571F4(void *arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 var_v0;
    void *temp_v0_2;

    func_80043328(arg0, 0xC2, 0x100);
    func_8002D3E4(arg0, 0);
    if (M2C_FIELD(arg0, s32 *, 0xC0) & 1) {
        temp_v0 = approachAngle(M2C_FIELD(arg0, s32 *, 0x90), M2C_FIELD(arg0, s32 *, 0x10), gCamSpeedScale * 0x1C0);
        M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
        var_v0 = func_8002D260(M2C_FIELD(arg0, s32 *, 0x90) - temp_v0);
        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }
        if (var_v0 < 0x1388) {
            func_8003B828(gCameraTarget, 1);
            M2C_FIELD(arg0, s32 *, 0xC0) = 0;
        }
    }
    if (randomRange(0, 0x64) >= 0x51) {
        temp_s0 = func_8002D1A0();
        temp_v0_2 = func_80017344(arg0);
        temp_s0_2 = temp_s0 & 0xFFFF;
        M2C_FIELD(temp_v0_2, f32 *, 8) += 350.0f;
        M2C_FIELD(temp_v0_2, f32 *, 4) += (f32) ((s32) (sins(temp_s0_2) * 0x19) >> 0xD);
        M2C_FIELD(temp_v0_2, f32 *, 0xC) += (f32) ((s32) (coss(temp_s0_2) * 0x19) >> 0xD);
        func_8002D3E4(temp_v0_2, 0x190);
        M2C_FIELD(arg0, s32 *, 0xF0) = 0x80;
    }
    if (tickActorTimer(arg0) == 0) {
    } else {
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
        M2C_FIELD(arg0, s32 *, 0x64) = 0xC8;
        return 1;
    }
    return 0;
}

