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
M2C_UNK func_8002D3B0(void *);                      /* extern */
M2C_UNK func_8002D4E0(void *, M2C_UNK);             /* extern */
s32 tickActorTimer(void *);                          /* extern */
M2C_UNK func_80034FEC(void *, s32 *);               /* extern */
M2C_UNK collectCollisionCells(f32 *, f32 *, M2C_UNK);       /* extern */
s32 func_80048CD8(f32, f32, f32, f32, f32, f32, s32); /* extern */
extern void *gCameraRig[];
extern s32 gCamSpeedScale;
extern void *gCameraTarget;

extern f32 D_80009174;
extern f32 D_80009178;
extern f32 D_8000917C;
extern f32 D_80009180;
extern f32 D_80009184;

s32 func_80073DC8(void *arg0, s32 arg1) {
    s32 pos[3];
    s32 t;
    void *src;
    s32 u;
    s32 one;
    f32 lo[3];
    f32 hi[3];

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        M2C_FIELD(arg0, s32 *, 0x7C) = 1;
        M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg0, s32 *, 0x34) * 3;
        M2C_FIELD(arg0, s32 *, 0x38) = M2C_FIELD(arg0, s32 *, 0x34);
        M2C_FIELD(arg0, s32 *, 0x64) = 350;
        M2C_FIELD(arg0, s32 *, 0x3C) = M2C_FIELD(arg0, s32 *, 0x34);
        if (arg1 != 0) {
            pos[0] = M2C_FIELD(gCameraTarget, f32 *, 4);
            pos[1] = M2C_FIELD(gCameraTarget, f32 *, 8) + D_80009174;
            pos[2] = M2C_FIELD(gCameraTarget, f32 *, 0xC);
            func_80034FEC(arg0, pos);
        } else {
            src = gCameraRig[0];
            M2C_FIELD(arg0, f32 *, 4) = M2C_FIELD(src, f32 *, 4);
            M2C_FIELD(arg0, f32 *, 8) = M2C_FIELD(src, f32 *, 8);
            M2C_FIELD(arg0, f32 *, 0xC) = M2C_FIELD(src, f32 *, 0xC);
            M2C_FIELD(arg0, s32 *, 0x14) = M2C_FIELD(src, s32 *, 0x14);
            M2C_FIELD(arg0, s32 *, 0x10) = M2C_FIELD(src, s32 *, 0x10);
        }
        func_8002D4E0(arg0, 200);
    }
    lo[0] = D_80009178;
    lo[1] = D_8000917C;
    lo[2] = D_80009178;
    hi[0] = D_80009180;
    hi[1] = D_80009184;
    hi[2] = D_80009180;
    lo[0] = M2C_FIELD(arg0, f32 *, 4) + D_80009178;
    hi[0] = M2C_FIELD(arg0, f32 *, 4) + D_80009180;
    lo[1] = M2C_FIELD(arg0, f32 *, 8) + D_8000917C;
    hi[1] = M2C_FIELD(arg0, f32 *, 8) + D_80009184;
    lo[2] = M2C_FIELD(arg0, f32 *, 0xC) + D_80009178;
    hi[2] = M2C_FIELD(arg0, f32 *, 0xC) + D_80009180;
    collectCollisionCells(lo, hi, 0);
    if (func_80048CD8(lo[0], hi[0], lo[1], hi[1], lo[2], hi[2], 0) != 0) {
        sendCommand(0xC, 0x80);
        sendCommand(8, 0x9B);
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        return 1;
    }
    func_8002D3B0(arg0);
    M2C_FIELD(arg0, s32 *, 0x14) += gCamSpeedScale << 11;
    if (tickActorTimer(arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(void *), 0xA0)(arg0);
        return 1;
    }
    return 0;
}
