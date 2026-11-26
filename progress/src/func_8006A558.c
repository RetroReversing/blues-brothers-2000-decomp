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

M2C_UNK func_8000C5B4();                            /* extern */
M2C_UNK func_8000C5E4();                            /* extern */
s32 func_8001B990();       /* extern */
s32 findActor(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80023DBC(M2C_UNK);                         /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_8003C140(void *);                      /* extern */
M2C_UNK func_80052A5C(M2C_UNK);                     /* extern */
s32 startStoryDialog(s32, M2C_UNK *, void *);          /* extern */
void *func_8006B760(void *);                        /* extern */
extern M2C_UNK D_80008E84;
extern f32 D_80008E90;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B5DD4;
extern s32 D_800B9B18;
extern void *gCameraTarget;
extern s32 D_800BD0E0;
extern M2C_UNK func_8006A978;

void func_8006A558(void *arg0) {
    s32 temp_s0;
    s32 temp_v1;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x7C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        D_800B3978 = 0;
        D_800B3974 = 0;
        D_800B3970 = 0;
        if (func_8001B990(0x100, 0x27) != 0) {
            M2C_FIELD(arg0, s32 *, 0x7C) = 8;
        } else {
            D_800B5DD4 = 0;
            func_8000C5E4();
            temp_v0 = func_8006B760(NULL);
            M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0xA0)(temp_v0);
            M2C_FIELD(arg0, s32 *, 0x7C) = 6;
        }
        break;
    case 6:
        temp_s0 = func_80023DBC(0xE5D);
        func_80052A5C(0);
        if (startStoryDialog(temp_s0, "hubstart", arg0) != 0) {
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
        } else {
            M2C_FIELD(gCameraTarget, s32 *, 0x90) = 1;
            M2C_FIELD(gCameraTarget, s32 *, 0) = 3;
            M2C_FIELD(gCameraTarget, s32 *, 0x50) = 0;
        }
        break;
    case 7:
        if (findActor(0x801, 0) == 0) {
            D_800B5DD4 = 1;
            M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) + 1);
            func_8001B990(0x200, 0x27);
            func_8000C5B4();
        }
        break;
    }
    if ((tickActorTimer(arg0) != 0) && (M2C_FIELD(arg0, s32 *, 0x7C) >= 8)) {
        M2C_FIELD(arg0, s32 *, 0x64) = 0xBB8;
        if (findActor(0x100E, 0) == 0) {
            M2C_FIELD(arg0, s32 *, 0x70) = 1;
            M2C_FIELD(arg0, s32 *, 0x74) = 3;
            M2C_FIELD(arg0, s32 *, 0x78) = 3;
            D_800B9B18 = 1;
            temp_v0 = func_8006B760(arg0);
            M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006A978;
            D_800B9B18 = 0;
        }
    }
    if ((M2C_FIELD(gCameraTarget, f32 *, 8) < -500.0f) && (M2C_FIELD(gCameraTarget, s32 *, 0) == 3)) {
        D_800BD0E0 += 1;
        func_8003C140(gCameraTarget);
    }
}


