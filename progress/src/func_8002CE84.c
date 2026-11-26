/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s32 osSendMesg();
extern char D_8013FAA0[];
extern s32 D_8013FAC0;
extern char D_8013FB08[];

void func_8002CE84(s32 arg0, s32 arg1) {
    s32 temp_v0_2;
    void *temp_v0;

    { u8 *bp = D_8013FAA0; temp_v0 = bp + D_8013FAC0 * 8; }
    M2C_FIELD(temp_v0, s32 *, 0) = arg0;
    M2C_FIELD(temp_v0, s32 *, 4) = arg1;
    osSendMesg(D_8013FB08, temp_v0, 1);
    temp_v0_2 = D_8013FAC0 + 1;
    D_8013FAC0 = temp_v0_2;
    if (temp_v0_2 == 4) {
        D_8013FAC0 = 0;
    }
}
