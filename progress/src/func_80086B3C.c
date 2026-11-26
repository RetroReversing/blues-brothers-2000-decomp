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

s32 findActor(M2C_UNK, M2C_UNK);                /* extern */
f32 approachF32(f32, f32, f32);               /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80082400(void);                      /* extern */
extern f32 D_80009B84;
extern f64 D_80009B88;
extern f64 D_80009B90;
extern f64 D_80009B98;
extern f64 D_80009BA0;
extern s32 gComboBeat;
extern void *gComboActorA;
extern void *gComboActorB;
extern void *D_80171A30;
extern M2C_UNK func_800869E8;

void func_80086B3C(void *arg0) {
    f64 temp_fv1;

    M2C_FIELD(D_80171A30, f32 *, 4) = approachF32(20.0f, M2C_FIELD(D_80171A30, f32 *, 4), 4.0f);
    if (findActor(0x800, 0) == 0) {
        actorSetAnim(gComboActorA, 1, 0x100);
        M2C_FIELD(gComboActorA, s32 *, 0x10) = -0x4000;
        actorSetAnim(gComboActorB, 0x18C, 0x100);
        M2C_FIELD(gComboActorB, s32 *, 0x10) = 0x8000;
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800869E8;
        M2C_FIELD(arg0, s32 *, 0x74) = (s32) gComboBeat;
        M2C_FIELD(D_80171A30, s32 *, 0x68) = 0xE;
    }
    if ((M2C_FIELD(gComboActorB, s32 *, 0xD0) == 0x18B) && (((temp_fv1 = (f64) M2C_FIELD(gComboActorB, f32 *, 0xDC), (D_80009B88 <= temp_fv1)) && (temp_fv1 < D_80009B90)) || ((D_80009B98 <= temp_fv1) && (temp_fv1 < D_80009BA0)))) {
        func_80082400();
    }
}

