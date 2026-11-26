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

M2C_UNK func_80023C10(s32);                         /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern void *D_800B3960;
extern void *D_800B3964;
extern M2C_UNK D_800B81F4;
extern M2C_UNK D_8014ADE0;

void func_8006F644(void *arg0) {
    M2C_UNK *__base_D_8014ADE0;
    if (M2C_FIELD(arg0, s32 *, 0x68) == -1) {
        if (M2C_FIELD(arg0, s32 *, 0x6C) != 0) {
            if (M2C_FIELD(&D_800B81F4, s32 *, 0) != 0) {
                func_80023C10(M2C_FIELD(&D_800B81F4, s32 *, 0));
                M2C_FIELD(&D_800B81F4, s32 *, 0) = 0;
                M2C_FIELD((__base_D_8014ADE0 = &D_8014ADE0), s32 *, 0x10) = func_80023D58(0x2BF);
                M2C_FIELD(__base_D_8014ADE0, s32 *, 0x14) = func_80023D58(0x2BE);
                M2C_FIELD(__base_D_8014ADE0, s32 *, 0x18) = func_80023D58(0);
                M2C_FIELD(__base_D_8014ADE0, s32 *, 0x1C) = func_80023D58(0xDA7);
                M2C_FIELD(__base_D_8014ADE0, s32 *, 0x20) = func_80023D58(0xDA8);
            }
            func_80023C10(M2C_FIELD(&D_800B81F4, s32 *, 0xC));
            M2C_FIELD(&D_800B81F4, s32 *, 0xC) = 0;
        }
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        return;
    }
    if (M2C_FIELD(D_800B3964, s32 *, 0xBC) != M2C_FIELD(arg0, s32 *, 0xBC)) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    }
    if (M2C_FIELD(D_800B3960, s32 *, 0x74) != M2C_FIELD(arg0, s32 *, 0x74)) {
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
    }
}
