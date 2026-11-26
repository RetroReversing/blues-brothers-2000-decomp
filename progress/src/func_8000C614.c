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

M2C_UNK func_8002710C(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80027158(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002889C(M2C_UNK *);                   /* extern */
M2C_UNK func_8002D5CC();                            /* extern */
M2C_UNK func_8003CDA0(M2C_UNK);                     /* extern */
M2C_UNK func_8003CDF4(M2C_UNK);                     /* extern */
M2C_UNK sprintf(M2C_UNK *, M2C_UNK *, s32);         /* extern */
extern M2C_UNK D_80000478;
extern M2C_UNK D_8000047C;
extern s32 D_800AB9B4;
extern void *D_800BD06C;
extern void *D_80177E18;
extern M2C_UNK func_800393F4;

void func_8000C614(void *arg0) {
    u8 sp10[0x8];
    s32 temp_v0;
    void *temp_a0;
    void *temp_c;

    if ((M2C_FIELD(D_800BD06C, s32 *, 0x9C) == &func_800393F4) && (D_800AB9B4 == 0)) {
        func_8002D5CC();
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x64);
        if (temp_v0 <= 0) {
            do { M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0); } while (0);
            return;
        }
        M2C_FIELD(arg0, s32 *, 0x5C) = (temp_v0 * 2);
        if ((temp_v0 * 2) >= 0x100) {
            do { do { do { M2C_FIELD(arg0, s32 *, 0x5C) = 0xFF; } while (0); } while (0); } while (0);
        }
        do { do { do { func_8002710C(0xFF, 0xFF, 0xFF, M2C_FIELD(arg0, s32 *, 0x5C)); } while (0); } while (0); } while (0);
        func_80027158(0x28, 0x64);
        if (M2C_FIELD(arg0, s32 *, 0x70) == 1) {
            func_80027158(0xA0, 0x64);
            func_8003CDA0(0x32);
        } else {
            func_80027158(0x14, 0x64);
            sprintf(sp10, &D_80000478, M2C_FIELD(arg0, s32 *, 0x70) - M2C_FIELD(arg0, s32 *, 0x74));
            func_8002889C(sp10);
            func_8003CDF4(0x33);
            sprintf(sp10, &D_8000047C, M2C_FIELD(arg0, s32 *, 0x70));
            func_8002889C(sp10);
            func_8003CDF4(0x34);
        }
        temp_c = D_80177E18; temp_a0 = temp_c; temp_c = (s8 *) temp_c + 8; D_80177E18 = temp_c;
        M2C_FIELD(temp_a0, s32 *, 0) = 0xE7000000;
        M2C_FIELD(temp_a0, s32 *, 4) = 0;
    }
}


