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

M2C_UNK func_80015A90(M2C_UNK);                     /* extern */
s32 func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80023C58(M2C_UNK);                     /* extern */
s32 func_80023D58(s32);                             /* extern */
M2C_UNK func_800242A8(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_8002A360(M2C_UNK, s32);                /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80032D5C();                            /* extern */
M2C_UNK func_8004EC68(M2C_UNK);                     /* extern */
M2C_UNK func_80088ED0();                            /* extern */
M2C_UNK func_80088F40();                            /* extern */
extern s32 D_800AB408;
extern s32 D_800AB9C8;
extern void *D_800B3964;
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800B4A84;
extern s32 D_800B7B0C;
extern s32 D_800B81D0;
extern s32 D_800B81D8[];
extern s32 D_800B81E0[];
extern s32 D_800B81F4[];
extern s32 D_800B9C70;
extern s32 D_800B9EA0;
extern s32 D_800B9ECC;
extern s32 D_800BD06C;
extern s32 D_800BD100;
extern s32 D_800BD274;
extern s32 D_80107040;
extern s32 D_80140228;
extern s32 D_8014ADE0[];
extern M2C_UNK func_80070124;

void func_80070318(void *arg0) {
    s32 i;

    i = 1;
    M2C_FIELD(arg0, s32 *, 0x78) = 0;
    func_8002A360(0x1F, 0);
    func_8002A360(4, 0);
    func_8002A360(0, D_800B81D8[0] * 327);
    func_8002A360(1, D_800B81D8[1] * 327);
    func_8002A360(0xC, 0x80);
    D_800AB408 = 0;
    D_800BD274 = 0x41;
    D_800AB9C8 = 0;
    D_80140228 = 0;
    D_800B81D0 = 1;
    D_80107040 = 0;
    func_80023C58(0x10F);
    func_8002E7B8(0, 0);
    D_800B9C70 = 1;
    D_800B3978 = 0x40;
    D_800B3970 = 0;
    D_800B3974 = 0;
    D_800B7B0C = 0;
    D_800BD06C = func_800232B4(1, 0, 0, 0);
    func_8004EC68(0xABE);
    func_800242A8(0x9C, 0x458, 0);
    func_800242A8(0x87, 0xCE3, 0);
    func_800242A8(0x95, 0xDC0, 0);
    func_800242A8(0x98, 0xDDC, 0);
    func_800242A8(0x1D6, 0xDCB, 0);
    func_800242A8(0x90, 0xDA2, 0);
    func_80015A90(0x456);
    D_8014ADE0[0] = func_80023D58(0x190);
    D_8014ADE0[1] = func_80023D58(0x1C4);
    D_8014ADE0[2] = func_80023D58(0x1E3);
    D_8014ADE0[3] = func_80023D58(0x1E4);
    D_8014ADE0[4] = 0;
    D_8014ADE0[5] = 0;
    D_8014ADE0[6] = 0;
    D_8014ADE0[7] = 0;
    D_8014ADE0[8] = 0;
    if (D_800B4A84 == 2) {
        i += D_800BD100;
    }
    D_800B81F4[0] = func_80023D58(D_800B81E0[0]);
    D_800B81F4[3] = func_80023D58(D_800B81E0[i]);
    func_80032D5C();
    M2C_FIELD(D_800B3964, M2C_UNK **, 0x9C) = &func_80070124;
    M2C_FIELD(D_800B3964, s32 *, 0x7C) = 0;
    func_80088ED0();
    func_80088F40();
    D_800B9EA0 = 2;
    D_800B9ECC = 2;
    func_8002A360(3, 8);
}
