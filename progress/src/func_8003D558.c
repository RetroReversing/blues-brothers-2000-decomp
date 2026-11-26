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

M2C_UNK initLevel(void);                       /* extern */
M2C_UNK func_8002A360(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80088F40();                            /* extern */
extern s32 D_800AB9B4;
extern s32 D_800B3838;
extern void *D_800B3960;
extern s32 D_800B4A84;
extern s32 D_800B5DD0;
extern s32 D_800BD0FC;
extern s32 D_8013FB20;
extern void *D_8013FB74;
extern M2C_UNK updateCameraView;
extern M2C_UNK func_80023078;
extern M2C_UNK func_8003D3C8;

void func_8003D558(void *arg0) {
    s32 temp_a0;

    if (D_8013FB20 == 0xFF) {
        func_8002E7B8(0, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003D3C8;
        D_800AB9B4 = 0;
        M2C_FIELD(arg0, void **, 0x98) = (void *) (&func_80023078 + 2);
        func_8002A360(4, 0);
        func_8002A360(0x1F, 0);
        func_8002A360(2, 0);
        D_800B3838 = 0;
        if (D_800B5DD0 != 0) {
            D_800B5DD0 = 0;
            initLevel();
            func_80088F40();
            return;
        }
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x70);
        if (temp_a0 == 2) {
            D_800B4A84 = temp_a0;
        } else {
            D_800B4A84 = 1;
        }
        M2C_FIELD(D_8013FB74, s32 *, 0x90) = 2;
        M2C_FIELD(D_800B3960, M2C_UNK **, 0x9C) = &updateCameraView;
        D_800BD0FC = 0;
    }
}
