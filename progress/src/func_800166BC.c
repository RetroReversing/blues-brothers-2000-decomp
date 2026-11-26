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
typedef struct { s32 a; s32 b; s32 c; } Rec12;
void func_8002A360(s32, s32);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(void *);
f32 getCameraTargetDist(void *, f32, s32);
extern Rec12 gPlatformMaxOffsets[];
extern Rec12 gPlatformMinOffsets[];

void func_800166BC(void *arg0) {
    s32 go;

    getCameraTargetDist(arg0, 200.0f, 0);
    go = 0;
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0x129;
        gPlatformMaxOffsets[M2C_FIELD(arg0, s32 *, 0xB8)].a = 100;
        gPlatformMinOffsets[M2C_FIELD(arg0, s32 *, 0xB8)].a = -100;
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x84) = 0;
        syncActorPrevPos(arg0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xC0) == 0x29A) {
        if (M2C_FIELD(arg0, s32 *, 0x84) == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x45);
            M2C_FIELD(arg0, s32 *, 0x84) = 1;
        }
        go = 1;
    }
    if (go != 0) {
        M2C_FIELD(arg0, f32 *, 8) = approachF32(M2C_FIELD(arg0, f32 *, 0x44) + 400.0f, M2C_FIELD(arg0, f32 *, 8), 17.0f);
    }
}
