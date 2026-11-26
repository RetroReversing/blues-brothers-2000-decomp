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

s16 coss(u16);                                      /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
s32 tickActorTimer(void *);                 /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
s16 sins(u16);                                      /* extern */
extern void *gCameraTarget;
extern M2C_UNK wardenChase;
extern M2C_UNK func_800672A0;

void func_80067150(void *arg0) {
    void **__base_D_800BD06C;
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x21);
        M2C_FIELD(arg0, s32 *, 0x64) = 0x190;
        func_80043328(arg0, 0xF6, 0x100);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) & 0x18) {
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &func_800672A0;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        __base_D_800BD06C = &gCameraTarget;
        actorSetAnim((*__base_D_800BD06C), 0x1A, 0x100);
        M2C_FIELD((*__base_D_800BD06C), f32 *, 4) = (f32) (M2C_FIELD((*__base_D_800BD06C), f32 *, 4) - (f32) ((s32) (sins(M2C_FIELD(arg0, u16 *, 0x12)) * 0x4B) >> 0xE));
        M2C_FIELD((*__base_D_800BD06C), f32 *, 0xC) = (f32) (M2C_FIELD((*__base_D_800BD06C), f32 *, 0xC) - (f32) ((s32) (coss(M2C_FIELD(arg0, u16 *, 0x12)) * 0x4B) >> 0xE));
        return;
    }
    if (tickActorTimer(arg0) != 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xD2);
        M2C_FIELD(arg0, s32 *, 0x7C) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0xD8) = &wardenChase;
    }
}
