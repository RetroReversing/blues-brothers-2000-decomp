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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 initLevel();
s32 func_8002E7B8();
s32 func_80088ED0();
s32 func_80088F40();
extern s32 D_800BD0E0;
extern void *D_8013FB74;

void func_8000F178(void *arg0) {
    s32 *temp_v0;
    s32 temp_v1;

    if ((*(s32 *)((s8 *)arg0 + 0x78)) == -1) {
        (*(s32 *)((s8 *)D_8013FB74 + 0x90)) = 1;
        func_80088ED0();
        func_8002E7B8(0, 0);
        do { (*(s32 (**)(void *))((s8 *)arg0 + 0xA0))(arg0); } while (0);
        return;
    }
    temp_v0 = (s32 *)((char *)&D_800BD0E0);
    temp_v1 = *(s32 *)((char *)temp_v0 + 0x1C);
    *(s32 *)((char *)temp_v0 + 0x24) = temp_v1;
    temp_v1 = *(s32 *)((char *)arg0 + 0x78);
    *(s32 *)((char *)temp_v0 + 0x1C) = temp_v1;
    initLevel();
    func_80088F40();
}
