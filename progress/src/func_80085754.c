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

extern void *D_8014AAB0;

#define sp0 (*(s16 *)(sp + 0x0))
#define sp2 (*(s16 *)(sp + 0x2))
#define sp4 (*(f32 * *)(sp + 0x4))
#define sp8 (*(f32 *)(sp + 0x8))
#define spC (*(f32 *)(sp + 0xC))
#define sp10 (*(f32 *)(sp + 0x10))
#define sp14 (*(f32 *)(sp + 0x14))
typedef struct { unsigned char pad_0[108]; int field_6C; int field_70; unsigned char pad_74[4]; int field_78; int field_7C; unsigned char pad_80[20]; int field_94; unsigned char pad_98[104]; float field_100; float field_104; } __repair_record_D_8014AAB0;
s32 func_80085754(void *arg0, void *arg1, f32 arg2) {
    u8 sp[24];
    f32 temp_fv1;
    f32 temp_fv1_2;
    s32 var_a2;
    s32 var_v0;
    void *temp_v1;
    void *var_a1;

    
    var_a1 = arg1;
    if ((arg1) == NULL) {
        sp0 = 1;
        sp2 = 0;
        sp4 = &sp8;
        sp8 = (*(f32 *)((s8 *)arg0 + 0x40));
        spC = (*(f32 *)((s8 *)arg0 + 0x40));
        sp10 = (*(f32 *)((s8 *)arg0 + 0x48));
        var_a1 = sp;
        sp14 = (*(f32 *)((s8 *)arg0 + 0x48));
    }
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_100) = (f32) (*(f32 *)((s8 *)arg0 + 4));
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_104) = (f32) (*(f32 *)((s8 *)arg0 + 0xC));
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_6C) = (s32) (*(f32 *)((s8 *)(*(void **)((s8 *)var_a1 + 4)) + 0));
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_70) = (s32) (*(f32 *)((s8 *)(*(void **)((s8 *)var_a1 + 4)) + 4));
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_78) = (s32) (*(f32 *)((s8 *)(*(void **)((s8 *)var_a1 + 4)) + 8));
    (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_7C) = (s32) (*(f32 *)((s8 *)(*(void **)((s8 *)var_a1 + 4)) + 0xC));
    var_a2 = 0;
    if ((*(u16 *)((s8 *)var_a1 + 0)) != 0) {
        for (;;) {
            temp_v1 = (void *)((char *)((void *)((var_a2 * 0x10))) + (s32)((*(void **)((s8 *)var_a1 + 4))));
            temp_fv1 = (*(f32 *)((s8 *)arg0 + 4));
            var_v0 = 0;
            if (((*(f32 *)((s8 *)temp_v1 + 0)) - arg2) <= temp_fv1) {
                var_v0 = 1;
            }
            if (temp_fv1 <= ((*(f32 *)((s8 *)temp_v1 + 4)) + arg2)) {
                var_v0 |= 2;
            }
            temp_fv1_2 = (*(f32 *)((s8 *)arg0 + 0xC));
            if (((*(f32 *)((s8 *)temp_v1 + 8)) - arg2) <= temp_fv1_2) {
                var_v0 |= 4;
            }
            if (temp_fv1_2 <= ((*(f32 *)((s8 *)temp_v1 + 0xC)) + arg2)) {
                var_v0 |= 8;
            }
            (((__repair_record_D_8014AAB0*)D_8014AAB0)->field_94) = var_v0;
            if (var_v0 == 0xF) {
                return var_a2 + 1;
            }
            var_a2 += 1;
            if (var_a2 >= (s32) (*(u16 *)((s8 *)var_a1 + 0))) {
                goto block_15;
            }
            continue;
            break;
        }
    }
block_15:
    return 0;
}
