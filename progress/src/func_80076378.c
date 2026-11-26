/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;



#define M2C_CARRY 0

#endif

M2C_UNK func_80023A74(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_80023A98(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_800242A8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_800B83B0;
extern M2C_UNK D_800F7910;

void func_80076378(void *arg0) {
    s8 *temp;
    func_80023A74(0x47, 0x446);
    func_80023A98(0x14A, 0x447, 1);
    func_800242A8(D_800B83B0 + 0x1D6, 0x448, 0x10);
    (*(s32 *)((s8 *)(arg0) + (0xBC))) = (s32) D_800B83B0;
    D_800B83B0 += 1;
    temp = (s8 *)(&D_800F7910);
    (*(s32 *)(temp + (0x11C))) = (s32) ((*(s32 *)(temp + (0x11C))) + 0x64);
}
