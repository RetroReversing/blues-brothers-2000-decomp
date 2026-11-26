/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (((struct { __typeof__(*(type_ptr)0) v; } *)((s8 *)(expr) + (offset)))->v)
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8006DAA0(s32);                             /* extern */
void *func_8006F828();                        /* extern */
void *func_8006F88C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern void *D_800B3960;
extern void *D_800B3964;
extern M2C_UNK func_80032E40;
extern M2C_UNK func_8006EF70;
extern M2C_UNK func_8006F0C0;
extern M2C_UNK func_8006F284;
extern M2C_UNK func_8006F300;
extern M2C_UNK func_8006F73C;

void func_8006F944(void) {
    s32 var_a0;
    void *temp_v0;
    void *temp_v0_2;
    
    

    if (M2C_FIELD(D_800B3964, s32 *, 0xBC) == 0) {
        if (M2C_FIELD(D_800B3960, s32 *, 0x74) != 0) {
            M2C_FIELD(func_8006F828(), M2C_UNK **, 0x98) = &func_8006F300;
            if (func_8006DAA0(M2C_FIELD(D_800B3964, s32 *, 0xBC)) != 0) {
                M2C_FIELD(func_8006F88C(0x87, 0, -0x78, 0x19C, 0x20), M2C_UNK **, 0x98) = &func_8006EF70;
            }
        } else {
            temp_v0 = func_8006F828();
            M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_8006F0C0;
            M2C_FIELD(temp_v0, s32 *, 0x6C) = 1;
            temp_v0_2 = func_8006F828(temp_v0);
            M2C_FIELD(temp_v0_2, M2C_UNK **, 0x98) = &func_8006F284;
            M2C_FIELD(temp_v0_2, s32 *, 0x64) = 0x96;
            var_a0 = M2C_FIELD(D_800B3964, s32 *, 0xBC);
            goto block_8;
        }
    } else {
        if (M2C_FIELD(D_800B3960, s32 *, 0x74) != 0) {
            temp_v0 = func_8006F828();
            M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006F73C;
            M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80032E40;
            return;
        }
        temp_v0_2 = func_8006F828();
        M2C_FIELD(temp_v0_2, M2C_UNK **, 0x98) = &func_8006F0C0;
        M2C_FIELD(temp_v0_2, s32 *, 0x6C) = 1;
        M2C_FIELD(func_8006F828(temp_v0_2), M2C_UNK **, 0x98) = &func_8006F300;
        var_a0 = M2C_FIELD(D_800B3964, s32 *, 0xBC);
block_8:
        if (func_8006DAA0(var_a0) != 0) {
            func_8006F88C(0x87, 0, -0x78, 0x19C, 0x20);
        }
    }
}
