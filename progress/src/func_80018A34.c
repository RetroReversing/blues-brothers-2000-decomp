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

s32 findActor(M2C_UNK, M2C_UNK);                /* extern */
void syncActorPrevPos(void *);                         /* extern */
extern M2C_UNK func_80018954;

void func_80018A34(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        syncActorPrevPos(arg0);
    } else {
        if (findActor(0x1025, 0) == 0) {
            M2C_FIELD(arg0, s32 *, 0) = 0x10E;
            M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80018954;
        }
    }
}
