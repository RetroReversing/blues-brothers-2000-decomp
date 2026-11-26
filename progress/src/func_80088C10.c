/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;



#define M2C_CARRY 0

#endif

extern M2C_UNK D_800BB5E0;
extern s32 D_8017825C;
extern s32 D_80178260;
extern s32 D_80178264;
extern s32 D_80178268;

void func_80088C10(void) {
    s8 *temp;
    temp = (s8 *)(&D_800BB5E0);
    (*(s32 *)(temp + (0x490))) = (s32) D_8017825C;
    (*(s32 *)((s8 *)(&D_800BB5E0) + (0x4A4))) = (s32) D_80178260;
    (*(s32 *)((s8 *)(&D_800BB5E0) + (0x48C))) = (s32) D_80178264;
    (*(s32 *)((s8 *)(&D_800BB5E0) + (0x4A0))) = (s32) D_80178268;
}
