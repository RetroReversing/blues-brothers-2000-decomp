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

s32 func_8002A360();
s32 func_8002D5CC();
s32 func_80043328();
extern f32 D_80008D00;
extern f32 D_80008D04;
extern f32 D_80008D08;
extern s32 D_80140228;
extern s32 func_800673FC;
extern s32 func_80067474;
extern s32 func_800674E4;

typedef struct { unsigned char pad_0[100]; int field_64; unsigned char pad_68[8]; int field_70; int field_74; int field_78; int field_7C; int field_80; unsigned char pad_84[60]; int field_C0; unsigned char pad_C4[20]; void * field_D8; float field_DC; unsigned char pad_E0[16]; int field_F0; } __repair_record_arg0;
s32 func_800672A0(void *arg0) {
    f32 temp_fv1;
    s32 temp_v0;

    if (((__repair_record_arg0*)arg0)->field_7C == 0) {
        func_80043328(arg0, 0xF7, 0x100);
        ((__repair_record_arg0*)arg0)->field_74 = 1;
        ((__repair_record_arg0*)arg0)->field_7C = 1;
        ((__repair_record_arg0*)arg0)->field_70 = 0;
        ((__repair_record_arg0*)arg0)->field_64 = 0x3E8;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xD6);
        return;
    }
    if (((__repair_record_arg0*)arg0)->field_70 != 0) {
        D_80140228 = 0;
    } else {
        if (32.0f < ((__repair_record_arg0*)arg0)->field_DC) {
            D_80140228 = 1;
            if (((__repair_record_arg0*)arg0)->field_DC < 34.0f) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0xD6);
            }
        }
    }
    if (((__repair_record_arg0*)arg0)->field_C0 & ~1) {
        temp_v0 = ((__repair_record_arg0*)arg0)->field_78 - 1;
        ((__repair_record_arg0*)arg0)->field_78 = temp_v0;
        if (temp_v0 == 0) {
            ((__repair_record_arg0*)arg0)->field_7C = 0;
            ((__repair_record_arg0*)arg0)->field_D8 = &func_800674E4;
        } else {
            ((__repair_record_arg0*)arg0)->field_D8 = &func_800673FC;
            ((__repair_record_arg0*)arg0)->field_7C = 0;
            ((__repair_record_arg0*)arg0)->field_F0 = 0xFF;
            ((__repair_record_arg0*)arg0)->field_80 = (s32) ((f32) ((__repair_record_arg0*)arg0)->field_80 + 8.0f);
        }
    }
    if (func_8002D5CC(arg0) != 0) {
        ((__repair_record_arg0*)arg0)->field_7C = 0;
        ((__repair_record_arg0*)arg0)->field_D8 = &func_80067474;
    }
}

