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

s32 __osRdbSend(M2C_UNK *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_800A34C4();                            /* extern */
M2C_UNK func_800A3530();                            /* extern */
M2C_UNK osCreateMesgQueue(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK osRecvMesg(M2C_UNK *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK osSetEventMesg(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8017F5F0;
extern M2C_UNK D_8017F608;
extern M2C_UNK D_8017F610;
extern M2C_UNK D_8017F628;

void ramromMain(void) {
    M2C_UNK sp10;
    s32 var_s0;

    osCreateMesgQueue(&D_8017F5F0, &D_8017F608, 1);
    osCreateMesgQueue(&D_8017F610, &D_8017F628, 1);
    osSetEventMesg(0x12, &D_8017F5F0, 0);
    osSetEventMesg(0x13, &D_8017F610, 0);
loop_1:
    osRecvMesg(&D_8017F5F0, 0, 1);
    var_s0 = 0;
    func_800A34C4();
    do {
        var_s0 += __osRdbSend(&sp10, 1, 9);
    } while (var_s0 == 0);
    osRecvMesg(&D_8017F610, 0, 1);
    func_800A3530();
    goto loop_1;
}
