/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_FIELD_PTR(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

void *findActor(M2C_UNK, M2C_UNK);              /* extern */
s32 func_8002D260(s32);                             /* extern */
void *func_8002E374(s32);                           /* extern */
M2C_UNK func_80034F50(void *);                      /* extern */
void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_8007404C(void *);                      /* extern */
M2C_UNK debugPrintf(M2C_UNK *);                   /* extern */
extern M2C_UNK D_8000915C;
extern M2C_UNK D_80009168;
extern void *gCameraRig;
extern void *D_800B3964;
extern void *gCameraTarget;
extern s32 gPadPressed;
extern s32 D_8014002C;
extern M2C_UNK func_80023078;
extern M2C_UNK func_80043248;
extern M2C_UNK func_80073A58;

void func_80073B7C(void *arg0) {
    void *boss;
    void *obj;
    void *mac;
    void *sub;
    void *t;

    if (D_8014002C != 0) {
        if (gPadPressed & ~0x2000) {
            M2C_FIELD(arg0, s32 *, 0x8C) = 1;
        }
        if ((gPadPressed & 0x2000) && (M2C_FIELD(arg0, s32 *, 0x90) != 0)) {
            t = func_8002E374(M2C_FIELD(arg0, s32 *, 0x6C));
            M2C_FIELD(t, s32 *, 0x7C) = 0;
            func_8007404C(t);
            M2C_FIELD(t, M2C_UNK (**)(void *), 0x9C) = func_8007404C;
            M2C_FIELD(t, s32 *, 0x64) = 0x12C;
            M2C_FIELD(arg0, s32 *, 0x90) -= 1;
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x8C) != 0) || (M2C_FIELD(gCameraTarget, s32 *, 0) != 3)) {
        D_8014002C = 0;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0;
        M2C_FIELD(gCameraRig, s32 *, 0xC0) = 0;
        M2C_FIELD(gCameraTarget, s32 *, 0x68) = 4;
    }
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0x10) {
        boss = findActor(0x1023, 0);
        if (boss == NULL) {
            debugPrintf(&D_8000915C);
        }
        obj = func_80042F00(0x74, 0, 0, 0);
        M2C_FIELD(obj, f32 *, 4) = M2C_FIELD(boss, f32 *, 4);
        M2C_FIELD(obj, f32 *, 8) = M2C_FIELD(boss, f32 *, 8);
        M2C_FIELD(obj, f32 *, 0xC) = M2C_FIELD(boss, f32 *, 0xC);
        actorSetAnim(obj, 0x1A3, 0x100);
        M2C_FIELD(obj, M2C_UNK **, 0x9C) = &func_80073A58;
        M2C_FIELD(boss, s32 *, 0x68) = -1;
        M2C_FIELD(boss, M2C_UNK **, 0x9C) = &func_80043248;
        mac = findActor(0x1026, 0);
        if (mac == NULL) {
            debugPrintf(&D_80009168);
        }
        M2C_FIELD(mac, M2C_UNK **, 0x9C) = &func_80023078 + 2;
        M2C_FIELD(mac, s32 *, 0x68) = -1;
        sub = M2C_FIELD(mac, void **, 0xA8);
        if (sub != NULL) {
            M2C_FIELD(sub, M2C_UNK (**)(void *), 0xA0)(sub);
            M2C_FIELD(mac, void **, 0xA8) = NULL;
        }
        M2C_FIELD(gCameraRig, M2C_UNK (**)(void *), 0x9C) = func_80034F50;
        M2C_FIELD(gCameraRig, void **, 0xA8) = obj;
        M2C_FIELD(gCameraRig, f32 *, 4) = M2C_FIELD(D_800B3964, f32 *, 4);
        M2C_FIELD(gCameraRig, f32 *, 8) = M2C_FIELD(D_800B3964, f32 *, 8);
        M2C_FIELD(gCameraRig, f32 *, 0xC) = M2C_FIELD(D_800B3964, f32 *, 0xC) - 500.0f;
        M2C_FIELD(gCameraRig, M2C_UNK (**)(void *), 0x9C)(gCameraRig);
        M2C_FIELD(obj, s32 *, 0x10) = func_8002D260(M2C_FIELD(gCameraRig, s32 *, 0x10) + 0x8000);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80023078 + 2;
    }
}
