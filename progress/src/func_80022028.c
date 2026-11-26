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

void *func_800232B4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80023D58(M2C_UNK);                         /* extern */
extern M2C_UNK updateParticleEmitter;
extern M2C_UNK func_80021818;

void *func_80022028(void *arg0) {
    void *temp_v0;

    temp_v0 = func_800232B4(0x101, 0, 0, 0);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x98) = &func_80021818;
    M2C_FIELD(temp_v0, s32 *, 0x60) = func_80023D58(0x209);
    M2C_FIELD(temp_v0, M2C_UNK **, 0x9C) = &updateParticleEmitter;
    M2C_FIELD(temp_v0, s32 *, 0x88) = 0;
    if (arg0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x70) = (s32) M2C_FIELD(arg0, s32 *, 0);
        M2C_FIELD(temp_v0, s32 *, 0x74) = (s32) M2C_FIELD(arg0, s32 *, 4);
        M2C_FIELD(temp_v0, s32 *, 0x78) = (s32) M2C_FIELD(arg0, s32 *, 8);
        M2C_FIELD(temp_v0, s32 *, 0x7C) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
        M2C_FIELD(temp_v0, s32 *, 0x80) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_v0, s32 *, 0x84) = (s32) M2C_FIELD(arg0, s32 *, 0x14);
    } else {
        M2C_FIELD(temp_v0, s32 *, 0x70) = 0x1E;
        M2C_FIELD(temp_v0, s32 *, 0x74) = 0x1F4;
        M2C_FIELD(temp_v0, s32 *, 0x78) = 0x2BC;
        M2C_FIELD(temp_v0, s32 *, 0x7C) = 0x32;
        M2C_FIELD(temp_v0, s32 *, 0x80) = 0x3000;
        M2C_FIELD(temp_v0, s32 *, 0x84) = 0x64;
    }
    return temp_v0;
}
