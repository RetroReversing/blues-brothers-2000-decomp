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

M2C_UNK osRecvMesg(M2C_UNK *, M2C_UNK *, M2C_UNK);  /* extern */
extern void **D_8017B290;
extern void **D_8017B294;
extern s32 D_8017B2A8;
extern M2C_UNK D_8017B2B0;

void func_80090418(void) {
    M2C_UNK sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    void **temp_a1;
    void **temp_v0_3;
    void **var_v1;
    void *temp_a0;

    if (D_8017B2A8 != 0) {
        do {
            osRecvMesg(&D_8017B2B0, &sp10, 0);
            temp_v0 = D_8017B2A8 - 1;
            D_8017B2A8 = temp_v0;
        } while (temp_v0 != 0);
    }
    var_v1 = D_8017B290;
    if (var_v1 != NULL) {
        do {
            temp_v0_2 = M2C_FIELD(var_v1, s32 *, 8) - 1;
            M2C_FIELD(var_v1, s32 *, 8) = temp_v0_2;
            if (temp_v0_2 == 0) {
                temp_a1 = M2C_FIELD(var_v1, void ***, 4);
                if (temp_a1 != NULL) {
                    *temp_a1 = M2C_FIELD(var_v1, void **, 0);
                }
                temp_a0 = M2C_FIELD(var_v1, void **, 0);
                if (temp_a0 != NULL) {
                    M2C_FIELD(temp_a0, void ***, 4) = (void **) M2C_FIELD(var_v1, void ***, 4);
                } else {
                    D_8017B290 = M2C_FIELD(var_v1, void ***, 4);
                }
                temp_v0_3 = D_8017B294;
                M2C_FIELD(var_v1, void **, 0) = NULL;
                D_8017B294 = var_v1;
                M2C_FIELD(var_v1, void ***, 4) = temp_v0_3;
                var_v1 = temp_a1;
            } else {
                var_v1 = M2C_FIELD(var_v1, void ***, 4);
            }
        } while (var_v1 != NULL);
    }
}
