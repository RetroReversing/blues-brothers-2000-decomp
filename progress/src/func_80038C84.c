/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 traceBounceMove();
extern s32 D_8014014C;

#define sp18 (*(s32 *)(sp + 0x0))
#define sp1C (*(s32 *)(sp + 0x4))
#define sp20 (*(s32 *)(sp + 0x8))
#define sp28 (*(s32 *)(sp + 0x10))
#define sp2C (*(s32 *)(sp + 0x14))
#define sp30 (*(s32 *)(sp + 0x18))
typedef struct { int field_0; int field_4; int field_8; } __repair_record_arg2;
typedef struct { unsigned char pad[8]; int value; } __repair_field_8;
void func_80038C84(s32 arg0, void *arg1, void *arg2) {
    u8 sp[32];
    D_8014014C = 0;
    { traceBounceMove(arg0, arg1, arg2, &sp18, &sp28); }
    *(__repair_record_arg2 *)arg1 = *(__repair_record_arg2 *)&sp18;
    *(__repair_record_arg2 *)arg2 = *(__repair_record_arg2 *)&sp28;
}
