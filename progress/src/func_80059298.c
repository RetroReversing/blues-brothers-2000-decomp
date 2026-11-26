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

s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void *func_800232B4(M2C_UNK, s32, s32, s32);        /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
M2C_UNK func_8003BF98(s32);                         /* extern */
extern s32 gCameraTarget;
extern s32 D_8014AAD0;
extern M2C_UNK func_8002F8D0;
extern M2C_UNK func_8005923C;

typedef struct { unsigned char pad_0[16]; int field_10; unsigned char pad_14[4]; int field_18; unsigned char pad_1C[60]; int field_58; int field_5C; int field_60; int field_64; int field_68; unsigned char pad_6C[4]; int field_70; int field_74; int field_78; int field_7C; } __repair_record_temp_v0;
void *func_80059298(void *arg0) {
    void *temp_v0;

    temp_v0 = func_800232B4(1, (s32) M2C_FIELD(arg0, f32 *, 4), (s32) M2C_FIELD(arg0, f32 *, 8), (s32) M2C_FIELD(arg0, f32 *, 0xC));
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8002F8D0;
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8005923C;
    ((__repair_record_temp_v0*)temp_v0)->field_70 = 0x32;
    ((__repair_record_temp_v0*)temp_v0)->field_78 = 0xFFFFFF;
    ((__repair_record_temp_v0*)temp_v0)->field_64 = 0xC8;
    ((__repair_record_temp_v0*)temp_v0)->field_74 = 0;
    ((__repair_record_temp_v0*)temp_v0)->field_7C = 1;
    ((__repair_record_temp_v0*)temp_v0)->field_60 = (s32) D_8014AAD0;
    { ((__repair_record_temp_v0*)temp_v0)->field_58 = packDrawFlags(0, 1, 1, 3, 0, 0, 1, 0); }
    ((__repair_record_temp_v0*)temp_v0)->field_68 = 0xE;
    ((__repair_record_temp_v0*)temp_v0)->field_5C = 0xFF;
    ((__repair_record_temp_v0*)temp_v0)->field_18 = 0xC000;
    ((__repair_record_temp_v0*)temp_v0)->field_64 = 0xC8;
    { { { ((__repair_record_temp_v0*)temp_v0)->field_10 = (s32) (M2C_FIELD(arg0, s32 *, 0x10) + 0x8000);
    func_8002D3E4(temp_v0, 0x1E); } } }
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0x15);
    func_8003BF98(gCameraTarget);
    return temp_v0;
}
