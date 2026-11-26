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

void *func_80042F00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80050460(M2C_UNK *, M2C_UNK *);        /* extern */
extern u8 D_800B7B10[];
extern s32 D_800B81D0;
extern M2C_UNK D_8014AA57;
extern M2C_UNK func_80059D80;
extern M2C_UNK func_8005A838;
extern M2C_UNK func_8006DC44;

void *func_8005A648(void *arg0) {
    u8 *__base_D_800B7B10;
char *__repair_addr;

    void *temp_v0;

    func_80050460(&func_8005A838, &D_8014AA57);
    temp_v0 = func_80042F00(0x2D, 0, 0, 0);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x1011;
    if (D_800B81D0 != 0) {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_8006DC44;
        actorSetAnim(temp_v0, 0x6C, 0x80);
        M2C_FIELD(temp_v0, s32 *, 0xBC) = 1;
    } else {
        M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &func_80059D80;
        actorSetAnim(temp_v0, 0x6D, 0x100);
    }
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 4);
        M2C_FIELD(temp_v0, f32 *, 8) = (f32) M2C_FIELD(arg0, f32 *, 8);
        M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
        M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
    }
__base_D_800B7B10 = D_800B7B10;
    __repair_addr = (char *)((((M2C_FIELD(temp_v0, s32 *, 0xB8) - 0xA) * 8) + __base_D_800B7B10));

    M2C_FIELD(temp_v0, s32 *, 0xFC) = (s32) M2C_FIELD(__repair_addr, s16 *, 4);
    return temp_v0;
}
