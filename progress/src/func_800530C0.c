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

M2C_UNK func_80027038(s32);                     /* extern */
M2C_UNK setTextColor(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800271A8(M2C_UNK, s32);                /* extern */
M2C_UNK func_80028FF4(s32, void *);                 /* extern */
s32 func_800291AC(s32);                             /* extern */
M2C_UNK debugPrintf(M2C_UNK *);                   /* extern */
extern M2C_UNK D_80008160;
extern u32 D_800B4988;
extern s32 D_80107684;
extern s32 D_8014AA88;
extern s32 D_8014AA8C;
typedef struct { s32 w0; s32 w1; } CursorRec8;
extern CursorRec8 *D_80177E18;

typedef struct { unsigned char pad_0[104]; int field_68; unsigned char pad_6C[24]; int field_84; int field_88; } __repair_record_arg0;
void func_800530C0(void *arg0) {
    M2C_UNK var_a0;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 var_v1;
    CursorRec8 *temp_a0;
    int temp;

    temp_s2 = ((__repair_record_arg0*)arg0)->field_88;
    ((__repair_record_arg0*)arg0)->field_68 = 0xB;
    temp_s1 = (u32) D_800B4988 > 0U;
    temp_s0 = ((__repair_record_arg0*)arg0)->field_84 == 0;
    D_8014AA88 = temp_s2;
    func_80027038(0);
    setTextColor(0x20, 0x20, 0x20, 0xFF);
    D_80107684 = 1;
    D_8014AA8C = temp_s0;
    if (temp_s0 != 0) {
        var_a0 = 0x3E;
        func_800271A8(var_a0, temp_s1 + 1);
    } else {
        func_800271A8(0x22, 0xB - temp_s1);
        var_v1 = func_800291AC(D_8014AA88);
        var_v1 = var_v1 / 15;
        var_v1 -= 4;
        if (var_v1 < 0) {
            var_v1 = 0;
        }
        var_a0 = 0x22;
        temp = 0xB - var_v1;
        func_800271A8(var_a0, temp - temp_s1);
    }
    if (temp_s2 != 0) {
        func_80028FF4(temp_s2, arg0);
    } else {
        debugPrintf(&D_80008160);
    }
    temp_a0 = D_80177E18++;
    temp_a0->w0 = 0xE7000000;
    temp_a0->w1 = 0;
}

