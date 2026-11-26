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

M2C_UNK func_80023620(M2C_UNK, void *);             /* extern */
s32 func_80023D58(s32);                             /* extern */
M2C_UNK func_8002E7B8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_800880FC(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_800B9B90;
extern s32 D_8013FB20;
extern M2C_UNK D_80171988;
extern M2C_UNK D_80171A70;
extern M2C_UNK func_800877C8;

void func_800876A4(void *arg0) {
    M2C_UNK *__base_D_800B9B90;
    if (D_8013FB20 == 0xFF) {
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_800877C8;
        func_80023620(0x101, arg0);
        func_8002E7B8(0, 0);
        __base_D_800B9B90 = &D_800B9B90;
        M2C_FIELD(&D_80171988, s32 *, 0) = func_80023D58(*(M2C_FIELD(&D_80171A70, s32 *, 0) + __base_D_800B9B90));
        M2C_FIELD(&D_80171988, s32 *, 4) = func_80023D58(*(M2C_FIELD(&D_80171A70, s32 *, 4) + __base_D_800B9B90));
        func_800880FC(M2C_FIELD(&D_80171A70, s32 *, 0), 0x17B);
        func_800880FC(M2C_FIELD(&D_80171A70, s32 *, 4), 0x18B);
    }
}

