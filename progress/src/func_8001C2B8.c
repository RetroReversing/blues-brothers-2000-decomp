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

s32 cameraGetMode();                                /* extern */
s32 func_8001B990(s32, s32);                    /* extern */
s32 func_8002A360(s32, s32);            /* extern */
extern s32 func_8007F7DC;

void func_8001C2B8(void *arg0) {
    s32 var_v0;

    if ((*(s32 *)((s8 *)arg0 + 0x7C)) == 0) {
        if (cameraGetMode() == 0x25) {
            (*(s32 **)((s8 *)arg0 + 0x9C)) = &func_8007F7DC;
            return;
        }
        (*(s32 *)((s8 *)arg0 + 0x7C)) = (s32) ((*(s32 *)((s8 *)arg0 + 0x7C)) + 1);
        goto block_4;
    }
block_4:
    var_v0 = -0x1F4;
    if (func_8001B990(0x100, (*(s32 *)((s8 *)arg0 + 0x70))) != 0) {
        if ((*(s32 *)((s8 *)arg0 + 0x74)) != 0) {
            s32 var_v0_a1;
            if ((*(s32 *)((s8 *)arg0 + 0x78)) == 0) {
                func_8002A360(0xC, 0x80);
                func_8002A360(8, 0x11);
            }
            (*(s32 *)((s8 *)arg0 + 0x78)) = 1;
            var_v0_a1 = (*(s32 *)((s8 *)arg0 + 0x74)) + 0xA;
            (*(s32 *)((s8 *)arg0 + 0x74)) = var_v0_a1; goto block_9;
        }
    } else {
(*(s32 *)((s8 *)arg0 + 0x74)) = (-0x1F4);
block_9: ;
    }
    (*(f32 *)((s8 *)arg0 + 0xC)) = (f32) ((*(f32 *)((s8 *)arg0 + 0x48)) + (f32) (*(s32 *)((s8 *)arg0 + 0x74)));
}
