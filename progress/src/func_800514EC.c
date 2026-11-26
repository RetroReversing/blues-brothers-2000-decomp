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

s32 func_80023DBC(M2C_UNK);                         /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
f32 getCameraTargetDist(void *, f32, M2C_UNK);            /* extern */
s32 animStepKeys(void *);                          /* extern */
M2C_UNK func_80043328(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
s32 func_80052A68(s32, M2C_UNK *);                  /* extern */
M2C_UNK startStoryDialog(s32, M2C_UNK *, void *);      /* extern */
extern M2C_UNK D_80008044;
extern f32 D_80008054;
extern void *D_800B3964;
extern M2C_UNK func_80051A74;

void func_800514EC(void *arg0) {
    f32 temp_fs0;
    s32 temp_v0;
    s32 var_s1;
    M2C_UNK *__base_D_80008044;

    __base_D_80008044 = &D_80008044;

    M2C_FIELD(arg0, s32 *, 0x10) = 0x5600;
    var_s1 = M2C_FIELD(arg0, s32 *, 0x6C);
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = randomRange(1, 4);
        M2C_FIELD(arg0, s32 *, 0x80) = 0;
        var_s1 = func_80023DBC(0xE21);
        M2C_FIELD(arg0, s32 *, 0x6C) = var_s1;
    }
    temp_fs0 = 200.0f;
    if (getCameraTargetDist(arg0, temp_fs0, 0) < temp_fs0) {
        func_80052A5C(0x567);
        if (func_80052A68(var_s1, __base_D_80008044) == 0) {
            startStoryDialog(var_s1, __base_D_80008044, arg0);
        } else {
            M2C_FIELD(arg0, s32 *, 0x80) = 1;
        }
        M2C_FIELD(arg0, s32 *, 0x78) = 1;
        M2C_FIELD(arg0, s32 *, 0x8C) = 5;
        func_80043328(arg0, 0x127, 0x100);
    }
    temp_v0 = animStepKeys(arg0);
    M2C_FIELD(arg0, s32 *, 0x70) = temp_v0;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x8C) = (s32) (M2C_FIELD(arg0, s32 *, 0x8C) - 1);
    }
    if (M2C_FIELD(arg0, s32 *, 0x8C) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0xD0) == 0x129) {
            func_80043328(arg0, 0x126, 0x100);
        } else {
            func_80043328(arg0, 0x129, 0x100);
        }
        M2C_FIELD(arg0, s32 *, 0x8C) = randomRange(1, 4);
    }
    if (M2C_FIELD(D_800B3964, s32 *, 0x7C) == 0x63) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80051A74;
    }
}
