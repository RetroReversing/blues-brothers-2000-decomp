/* machine draft */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
s32 func_800899DC();
extern char D_80007BE4[];
extern s32 D_800B7690;
extern char D_801407C8[];
void func_80048374(s32 arg0) {
    void *temp_v1;
    s32 n;

    if (D_800B7690 >= 0x100) {
        func_800899DC(D_80007BE4);
    }
    { u8 *bp = D_801407C8; temp_v1 = bp + D_800B7690 * 8; }
    M2C_FIELD(temp_v1, s8 *, 4) = 0;
    n = D_800B7690 + 1;
    M2C_FIELD(temp_v1, s32 *, 0) = arg0;
    D_800B7690 = n;
}
