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

M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002D124();                            /* extern */
M2C_UNK func_8002D604();                            /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
f32 getCameraTargetDist(void *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK func_80014C34;

void func_80014DDC(void *arg0) {
    void *temp_a0;

    func_8002D604();
    if ((s32) getCameraTargetDist(arg0, 0x43480000, 0) < 0xC8) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0xA5);
        func_8002D124();
        temp_a0 = M2C_FIELD(arg0, void **, 0xA4);
        if (temp_a0 != NULL) {
            M2C_FIELD(temp_a0, M2C_UNK (**)(void *), 0xA0)(temp_a0);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_80014C34;
        syncActorPrevPos(arg0);
    }
}
