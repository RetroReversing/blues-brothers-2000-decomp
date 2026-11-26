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

s16 coss(u16);                                      /* extern */
s32 packDrawFlags(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
s32 randomRange(M2C_UNK, M2C_UNK);                /* extern */
s32 func_8002D260(s32);                             /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
M2C_UNK func_80034FEC(void *, s32 *);               /* extern */
s16 sins(u16);                                      /* extern */
extern void *D_800B3964;
extern M2C_UNK func_80020F50;

void func_8006DEC0(void *arg0) {
    s32 sp20[3];
    void *temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        temp_v0 = func_8002E374(0x9C);
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
        M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) M2C_FIELD(arg0, s32 *, 0x18);
        M2C_FIELD(temp_v0, s32 *, 0x58) = packDrawFlags(0, 1, 1, 1, 0, 0, 1, 0);
        M2C_FIELD(temp_v0, s32 *, 0x68) = 8;
        M2C_FIELD(temp_v0, s32 *, 0x5C) = 0x20;
        M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80020F50;
        M2C_FIELD(arg0, s32 *, 0x8C) = 0x1F4;
        M2C_FIELD(arg0, void **, 0xA8) = temp_v0;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        M2C_FIELD(arg0, s32 *, 0x88) = -0x15E;
        M2C_FIELD(arg0, s32 *, 0x84) = randomRange(0, 0xFFFF);
        M2C_FIELD(arg0, s32 *, 0x80) = randomRange(0x300, 0x400);
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
    }
    if (M2C_FIELD(D_800B3964, s32 *, 0xBC) == 1) {
        sp20[0] = M2C_FIELD(arg0, s32 *, 0x90) + ((s32) (sins(M2C_FIELD(arg0, u16 *, 0x86)) * 0x7D) >> 0xD);
        sp20[1] = M2C_FIELD(arg0, s32 *, 0x8C);
        sp20[2] = M2C_FIELD(arg0, s32 *, 0x88) + ((s32) (coss(M2C_FIELD(arg0, u16 *, 0x86)) * 0x7D) >> 0xD);
        M2C_FIELD(arg0, s32 *, 0x84) = func_8002D260(M2C_FIELD(arg0, s32 *, 0x84) + M2C_FIELD(arg0, s32 *, 0x80));
        func_80034FEC(arg0, sp20);
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), s32 *, 0x10) = func_8002D260(M2C_FIELD(arg0, s32 *, 0x10));
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xA8), s32 *, 0x14) = func_8002D260(-0x4000 - M2C_FIELD(arg0, s32 *, 0x14));
        M2C_FIELD(arg0, s32 *, 0x14) = func_8002D260(-M2C_FIELD(arg0, s32 *, 0x14));
    }
}
