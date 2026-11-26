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

s32 func_8002D5CC(void *);                          /* extern */
M2C_UNK func_8002D620(void *);                      /* extern */
M2C_UNK func_80033DC4(void *);                      /* extern */
M2C_UNK func_800340B4(void *);                      /* extern */
M2C_UNK func_80036DB4(void *);                      /* extern */
s32 func_80075338(M2C_UNK);                         /* extern */
f32 func_800812B4(M2C_UNK, s32, void *, M2C_UNK);   /* extern */
s32 func_80081990(void *, M2C_UNK, f32);            /* extern */
extern void *D_800B3960;
extern s32 D_800BD06C;
extern s32 D_80107040;
extern s32 D_801070A0;
extern M2C_UNK func_80023078;
extern M2C_UNK func_80074F74;

typedef struct { unsigned char pad_0[100]; int field_64; unsigned char pad_68[20]; int field_7C; unsigned char pad_80[12]; int field_8C; unsigned char pad_90[8]; void * field_98; unsigned char pad_9C[12]; int field_A8; float field_AC; int field_B0; unsigned char pad_B4[12]; int field_C0; unsigned char pad_C4[24]; float field_DC; unsigned char pad_E0[32]; float field_100; } __repair_record_arg0;
void func_80074DDC(void *arg0) {
    volatile u64 scratch[2];
    f32 temp_fv0;
    s32 temp_v0;

    if (((__repair_record_arg0*)arg0)->field_A8 == 0) {
        ((__repair_record_arg0*)arg0)->field_C0 = 0;
        ((__repair_record_arg0*)arg0)->field_DC = 0.0f;
        ((__repair_record_arg0*)arg0)->field_AC = (f32) 0.05f;
        ((__repair_record_arg0*)arg0)->field_B0 = 0;
        if (M2C_FIELD(D_800B3960, M2C_UNK (**)(void *), 0x9C) != func_80036DB4) {
            M2C_FIELD(D_800B3960, M2C_UNK (**)(void *), 0x9C) = func_80036DB4;
        }
        if (func_8002D5CC(arg0) != 0) {
            temp_v0 = func_80075338(0);
            if (temp_v0 != 0) {
                ((__repair_record_arg0*)arg0)->field_A8 = temp_v0;
                ((__repair_record_arg0*)arg0)->field_7C = (s32) (((__repair_record_arg0*)arg0)->field_7C + 1);
            }
        }
    } else {
        ((__repair_record_arg0*)arg0)->field_64 = 0xC8;
    }
    D_80107040 &= ~8;
    D_801070A0 &= ~8;
    temp_fv0 = func_800812B4(1, D_800BD06C + 4, arg0 + 0x104, 0);
    ((__repair_record_arg0*)arg0)->field_100 = temp_fv0;
    ((__repair_record_arg0*)arg0)->field_DC = (f32) (temp_fv0 + 0.8f);
    if (0.21 < (f64) ((__repair_record_arg0*)arg0)->field_100) {
        ((__repair_record_arg0*)arg0)->field_C0 = 1;
    }
    if (((__repair_record_arg0*)arg0)->field_DC < 0.0f) {
        ((__repair_record_arg0*)arg0)->field_DC = 0.0f;
    }
    if (func_80081990(D_800B3960 + 4, 1, ((__repair_record_arg0*)arg0)->field_DC) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80074F74;
        M2C_FIELD(D_800B3960, M2C_UNK (**)(void *), 0x9C) = func_800340B4;
        func_8002D620(D_800B3960);
        func_80033DC4(D_800B3960);
        func_800340B4(D_800B3960);
        ((__repair_record_arg0*)arg0)->field_8C = 0;
        ((__repair_record_arg0*)arg0)->field_98 = (void *) (&func_80023078 + 2);
    }
}

