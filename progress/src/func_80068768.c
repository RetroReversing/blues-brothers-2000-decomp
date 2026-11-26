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

s32 findActor();
s32 func_80023DBC();
s32 func_80052A30();
s32 func_80052A5C();
s32 func_80052B24();
extern s32 D_80008D80;
extern s32 D_80008D8C;
extern s32 D_80008D98;
extern void *D_800B3960;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 func_800393F4;
extern s32 func_80064808;
extern s32 func_80068894;

void func_80068768(void *arg0) {
    s32 *var_a1;
    s32 temp_s0;
    s32 temp_v1;

    if (findActor(0x800, 0) == 0) {
        D_800B5DD4 = 0;
        func_80052A30();
        do { do { temp_s0 = func_80023DBC(0xE0F); } while (0); } while (0);
        temp_v1 = (*(s32 *)((s8 *)arg0 + 0x7C));
        switch (temp_v1) {                          /* irregular */
        case 0:
            func_80052A5C(0x55F);
            var_a1 = &D_80008D80;

            { { { func_80052B24(temp_s0, var_a1, arg0); } } }
            (*(s32 *)((s8 *)arg0 + 0x7C)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x7C)) + 1);
            return;
        case 1:
            (*(s32 **)((s8 *)D_800B3960 + 0x9C)) = &func_80064808;
            (*(s32 *)((s8 *)D_800B3960 + 0xA8)) = 0;
            func_80052A5C(0x564);
            var_a1 = &D_80008D8C;
            {
{ { { func_80052B24(temp_s0, var_a1, arg0); } } }
(*(s32 *)((s8 *)arg0 + 0x7C)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x7C)) + 1);
return;
}
        case 2:
            func_80052A5C(0x55F);
            var_a1 = &D_80008D98;
            {
func_80052B24(temp_s0, var_a1, arg0);
(*(s32 *)((s8 *)arg0 + 0x7C)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x7C)) + 1);
return;
}
        case 3:
            (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_80068894;
            D_800B5DD4 = 1;
            (*(s32 **)((s8 *)gCameraTarget + 0x9C)) = &func_800393F4;
            break;
        }
    }
}
