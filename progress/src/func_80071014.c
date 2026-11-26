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

M2C_UNK func_8009CCE0();                            /* extern */
M2C_UNK osRecvMesg(void *, void **, M2C_UNK);       /* extern */
M2C_UNK osSendMesg(void *, void **, M2C_UNK);       /* extern */
M2C_UNK osSpTaskStartGo(void *);                    /* extern */
s32 osSpTaskYielded(s32);                           /* extern */
M2C_UNK osWritebackDCacheAll();                     /* extern */
M2C_UNK rspStartTask(void *);                       /* extern */

void func_80071014(void *arg0) {
    void *sp10;
    void *sp14;
    s32 temp_s1;
    s32 var_s0;
    void *temp_s0;
    void *temp_s4;

    temp_s4 = arg0 + 0xAC;
    sp14 = NULL;
    sp10 = NULL;
    for (;;) {
        osRecvMesg(arg0 + 4, &sp10, 1);
        var_s0 = 0;
        osWritebackDCacheAll();
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x66C);
        do { do { do { do { if (temp_s1 != 0) {
            var_s0 = 2;
            func_8009CCE0();
            osRecvMesg(arg0 + 0xAC, &sp14, 1);
            if (osSpTaskYielded(temp_s1 + 0x10) != 0) {
                var_s0 = 1;
            }
        } } while (0); } while (0); } while (0); } while (0);
        M2C_FIELD(arg0, void **, 0x670) = sp10;
        rspStartTask(sp10 + 0x10);
        osSpTaskStartGo(sp10 + 0x10);
        osRecvMesg(temp_s4, &sp14, 1);
        M2C_FIELD(arg0, void **, 0x670) = NULL;
        if (M2C_FIELD(arg0, s32 *, 0x674) != 0) {
            osSendMesg(arg0 + 0x11C, &sp14, 1);
        }
        if (var_s0 == 1) {
            temp_s0 = temp_s1 + 0x10;
            rspStartTask(temp_s0);
            osSpTaskStartGo(temp_s0);
        } else if (var_s0 == 2) {
            osSendMesg(temp_s4, &sp14, 1);
        }
        osSendMesg(M2C_FIELD(sp10, void **, 0x50), M2C_FIELD(sp10, void ***, 0x54), 1);
        continue;
        break;
    }
}

