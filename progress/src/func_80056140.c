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

s32 func_800113D8(s32);                         /* extern */
s32 findActor(s32, s32);                /* extern */
s32 func_80023DBC(s32);                         /* extern */
f32 func_8002D858(void *, void *);                  /* extern */
s32 func_8002E7B8(s32, s32);            /* extern */
s32 animStepKeys(void *);                      /* extern */
s32 func_80052A5C(s32);                     /* extern */
s32 startStoryDialog(s32, s32 *, void *);          /* extern */
s32 updateDistanceCull();                                /* extern */
extern s32 D_8000837C;
extern s32 D_80008384;
extern s32 D_8000838C;
extern f32 D_80008394;
extern s32 func_8003D558;

void func_80056140(void *arg0) {
    f32 temp_fs0;
    s32 temp_s0;
    s32 temp_v1;

    if (updateDistanceCull() == 0) {
        animStepKeys(arg0);
        temp_fs0 = func_8002D858(arg0, arg0 + 0x10);
        temp_s0 = func_80023DBC(0xE75);
        temp_v1 = (*(s32 *)((s8 *)arg0 + 0x7C));
        switch (temp_v1) {                          /* irregular */
        case 0:
            if (temp_fs0 < D_80008394) {
                func_80052A5C(0x561);
                if (startStoryDialog(temp_s0, &D_8000837C, arg0) != 0) {
                    (*(s32 *)((s8 *)arg0 + 0x7C)) = 1;
                    return;
                }
                return;
            }
            break;
        case 1:
            if (findActor(0x801, 0) == 0) {
                if (func_800113D8(1) != 0) {
                    do { do { startStoryDialog(temp_s0, &D_80008384, arg0); } while (0); } while (0);
                    (*(s32 *)((s8 *)arg0 + 0x7C)) = 2;
                    return;
                }
                do { do { startStoryDialog(temp_s0, &D_8000838C, arg0); } while (0); } while (0);
                (*(s32 *)((s8 *)arg0 + 0x7C)) = 3;
                return;
            }
            break;
        case 2:
            if (findActor(0x801, 0) == 0) {
                (*(s32 *)((s8 *)arg0 + 0x7C)) = 4;
                return;
            }
            break;
        case 3:
            if (findActor(0x801, 0) == 0) {
                (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_8003D558;
                func_8002E7B8(1, 0);
                (*(s32 *)((s8 *)arg0 + 0x70)) = 2;
            }
            break;
        }
    }
}
