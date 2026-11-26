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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s16 coss();
s32 findActor();
s32 func_8002A360();
s32 func_80043328();
s32 actorSetAnim();
s16 sins();
extern void *gCameraTarget;
extern s32 func_80066764;
extern s32 func_800672A0;

typedef struct { unsigned char pad_0[18]; unsigned short field_12; unsigned char pad_14[92]; int field_70; int field_74; unsigned char pad_78[4]; int field_7C; unsigned char pad_80[64]; int field_C0; unsigned char pad_C4[20]; void * field_D8; } __repair_record_arg0;
void func_80066FDC(void *arg0) {
char *__repair_addr;

    void **__base_D_800BD06C;
    if (((__repair_record_arg0*)arg0)->field_7C == 0) {
        func_80043328(arg0, 0xFD, 0x100);
        ((__repair_record_arg0*)arg0)->field_74 = 1;
        ((__repair_record_arg0*)arg0)->field_7C = 1;
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xD3);
    }
    if (findActor(0x800, 0) != 0) {
        ((__repair_record_arg0*)arg0)->field_74 = 0;
        return;
    }
    if (((__repair_record_arg0*)arg0)->field_74 == 0) {
        ((__repair_record_arg0*)arg0)->field_70 = 1;
    }
    if (((__repair_record_arg0*)arg0)->field_C0 & 0x18) {
        ((__repair_record_arg0*)arg0)->field_D8 = &func_800672A0;
        ((__repair_record_arg0*)arg0)->field_7C = 0;
        __base_D_800BD06C = &gCameraTarget;
        actorSetAnim((*__base_D_800BD06C), 0x1A, 0x100);
        M2C_FIELD((*__base_D_800BD06C), f32 *, 4) = (f32) (M2C_FIELD((*__base_D_800BD06C), f32 *, 4) - (f32) ((s32) (sins(((__repair_record_arg0*)arg0)->field_12) * 0x4B) >> 0xE));
        M2C_FIELD((*__base_D_800BD06C), f32 *, 0xC) = (f32) (M2C_FIELD((*__base_D_800BD06C), f32 *, 0xC) - (f32) ((s32) (coss(((__repair_record_arg0*)arg0)->field_12) * 0x4B) >> 0xE));
        return;
    }
    if (((__repair_record_arg0*)arg0)->field_70 != 0) {
        func_8002A360(0xC, 0x80);
        func_8002A360(8, 0xD2);
        ((__repair_record_arg0*)arg0)->field_D8 = &func_80066764;
        ((__repair_record_arg0*)arg0)->field_7C = 0;
    }
}
