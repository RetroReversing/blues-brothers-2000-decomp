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

s32 func_80023AE8();
s32 func_80043328();
s32 actorSetAnim();
s32 enemyTakeHit();
extern s32 func_80043248;
extern s32 func_8007631C;

void func_80083A28(void *arg0) {
    s32 temp_v0;

    temp_v0 = enemyTakeHit(arg0, M2C_FIELD(arg0, s32 *, 0x78) == 6);
    switch (temp_v0) {                              /* irregular */
    case 1:
        if (func_80023AE8(M2C_FIELD(arg0, s32 *, 0x74) + 6) == temp_v0) {
            M2C_FIELD(arg0, s32 *, 0xF0) = 0xFF;
            M2C_FIELD(arg0, s32 *, 0x78) = 6;
            M2C_FIELD(arg0, s32 **, 0xD8) = &func_80043248;
            func_80043328(arg0, M2C_FIELD(arg0, s32 *, 0x74) + M2C_FIELD(arg0, s32 *, 0x78), 0xE0);
            return;
        }
        return;
    case 2:
        M2C_FIELD(arg0, s32 *, 0xF0) = 0x80;
        M2C_FIELD(arg0, s32 *, 0x78) = 5;
        actorSetAnim(arg0, M2C_FIELD(arg0, s32 *, 0x74) + 5, 0x100);
        M2C_FIELD(arg0, s32 **, 0x9C) = &func_8007631C;
        M2C_FIELD(arg0, s32 **, 0xD8) = NULL;
        M2C_FIELD(arg0, s32 *, 0) = 0x101;
        break;
    }
}
