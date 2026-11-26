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

void *func_80017CF0(void *);                        /* extern */
s32 func_80023DBC(M2C_UNK);                         /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
f32 func_8002D858(void *, M2C_UNK);                 /* extern */
f32 func_8002DD60(f32);                             /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
s32 func_80052B24(s32, M2C_UNK *, void *);          /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32);         /* extern */
extern M2C_UNK D_80008244;
extern s32 D_800AB9C8;
extern void *D_800B3960;
extern void *D_800BD06C;

typedef struct { unsigned char pad_0[4]; float field_4; float field_8; float field_C; int field_10; } __repair_record_D_800BD06C;
void func_80053FB0(void *arg0) {
    char sp10[0x18];
    f32 temp_fs0;
    f32 temp_fv1;
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0x817;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
        M2C_FIELD(arg0, s32 *, 0xBC) = func_80023DBC(0xE57);
    }
    temp_fs0 = ((__repair_record_D_800BD06C*)D_800BD06C)->field_8 - M2C_FIELD(arg0, f32 *, 8);
    temp_fv1 = func_8002D858(arg0, 0);
    if (M2C_FIELD(arg0, s32 *, 0x84) == 0) {
        if ((temp_fv1 < 75.0f) && (func_8002DD60(temp_fs0) < 50.0f)) {
            func_80052A5C(0);
            sprintf(sp10, &D_80008244, M2C_FIELD(arg0, s32 *, 0x70));
            temp_v0 = func_80052B24(M2C_FIELD(arg0, s32 *, 0xBC), sp10, arg0);
            M2C_FIELD(arg0, s32 *, 0x84) = temp_v0;
            if (temp_v0 != 0) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x22);
                ((__repair_record_D_800BD06C*)D_800BD06C)->field_4 = (f32) M2C_FIELD(arg0, f32 *, 4);
                ((__repair_record_D_800BD06C*)D_800BD06C)->field_8 = (f32) M2C_FIELD(arg0, f32 *, 8);
                ((__repair_record_D_800BD06C*)D_800BD06C)->field_C = (f32) M2C_FIELD(arg0, f32 *, 0xC);
                ((__repair_record_D_800BD06C*)D_800BD06C)->field_10 = (s32) (M2C_FIELD(D_800B3960, s32 *, 0x10) + 0x8000);
            }
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
        }
    } else {
        if (200.0f < temp_fv1) {
            (*(&D_800AB9C8)) = 0;
            M2C_FIELD(arg0, s32 *, 0x84) = 0;
            return;
        }
        M2C_FIELD(func_80017CF0(arg0), s32 *, 0x68) = 0xC;
        (*(&D_800AB9C8)) = 0x1000;
    }
}
