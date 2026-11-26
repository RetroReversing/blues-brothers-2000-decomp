/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 approachAngle();
f32 func_8002D858();
s32 animStepKeys();
s32 func_80043248();
s32 func_80043328();
s32 func_800660CC();
s32 func_80066628();
s32 func_8006788C();
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern s32 *gCameraTarget;
extern s32 D_800BD0F4;

typedef struct { unsigned char pad_0[16]; int field_10; unsigned char pad_14[92]; int field_70; int field_74; int field_78; int field_7C; unsigned char pad_80[8]; int field_88; unsigned char pad_8C[4]; int field_90; } __repair_record_arg0;
void func_80065F84(void *arg0) {
    s32 (*temp_v0)(void *);
    s32 temp_s1;
    s32 temp_v1;

    temp_s1 = ((__repair_record_arg0*)arg0)->field_10;
    ((__repair_record_arg0*)arg0)->field_90 = (s32) func_8002D858(arg0, arg0 + 0x10);
    if (((__repair_record_arg0*)arg0)->field_74 != 0) {
        ((__repair_record_arg0*)arg0)->field_70 = func_80043248(arg0);
        ((__repair_record_arg0*)arg0)->field_10 = temp_s1;
    } else {
        ((__repair_record_arg0*)arg0)->field_70 = animStepKeys(arg0);
        ((__repair_record_arg0*)arg0)->field_10 = approachAngle(((__repair_record_arg0*)arg0)->field_10, temp_s1, gCamSpeedScale << 9);
    }
    temp_v1 = ((__repair_record_arg0*)arg0)->field_88 - gFrameScale;
    ((__repair_record_arg0*)arg0)->field_88 = temp_v1;
    if ((temp_v1 <= 0) && (((__repair_record_arg0*)arg0)->field_78 != 0)) {
        if (D_800BD0F4 <= 0) {
            if (M2C_FIELD(arg0, s32 (**)(void *), 0xD8) != func_80066628) {
                func_80043328(arg0, 0xF4, 0x100);
                M2C_FIELD(arg0, s32 (**)(void *), 0xD8) = func_80066628;
                ((__repair_record_arg0*)arg0)->field_7C = 0;
                ((__repair_record_arg0*)arg0)->field_74 = 0;
                *gCameraTarget = 3;
                func_8006788C(arg0, 1);
            }
        } else {
            func_8006788C(arg0, 1);
            ((__repair_record_arg0*)arg0)->field_88 = (s32) (((__repair_record_arg0*)arg0)->field_78 * 0x32);
            goto block_9;
        }
    } else {
block_9:
        temp_v0 = M2C_FIELD(arg0, s32 (**)(void *), 0xD8);
        if (temp_v0 != NULL) {
            temp_v0(arg0);
        }
        func_800660CC(arg0, 0x190, 1);
    }
}
