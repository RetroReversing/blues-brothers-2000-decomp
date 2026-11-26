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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s16 coss();
void *func_80017344();
void *spawnEffectObj();
s32 func_80023E3C();
s32 sendCommand();
s32 func_8002D1A0();
s32 func_8002D3E4();
f32 getCameraTargetDist(void *, f32, s32 *);
s32 animStepKeys();
s32 func_80071708();
s16 sins();
extern s32 D_800B8360[];
extern f32 D_80009078;
extern s32 gCamSpeedScale[];
extern void *gCameraTarget[];
extern s32 func_80071300[];
extern s32 func_80071440[];

typedef struct { unsigned char pad[16]; int value; } __repair_field_10;
void func_8007148C(void *arg0) {
    f32 dist;
    s32 i;
    u16 ang;
    s32 t;
    void *q;
    void *p;
    void *o;

    dist = getCameraTargetDist(arg0, 500.0f, 0);
    M2C_FIELD(arg0, s32 *, 0xF8) |= 1;
    if (M2C_FIELD(arg0, s32 *, 0x90) == 1) {
        func_80071708(arg0);
    } else {
        animStepKeys(arg0);
    }
    M2C_FIELD(arg0, s32 *, 0x10) += gCamSpeedScale[0] << 8;
    if (dist < 500.0f) {
        i = 0;
        do {
            i++;
            ang = func_8002D1A0();
            p = func_80017344(arg0);
            M2C_FIELD(p, f32 *, 8) += D_80009078;
            M2C_FIELD(p, f32 *, 4) += (sins(ang) * 25) >> 13;
            M2C_FIELD(p, f32 *, 0xC) += (coss(ang) * 25) >> 13;
            func_8002D3E4(p, 400);
            q = gCameraTarget[0];
            M2C_FIELD(q, s32 *, 0xF0) = 0xFF;
            t = D_800B8360[M2C_FIELD(arg0, s32 *, 0x90)];
            M2C_FIELD(q, s32 *, 0xB8) = t;
            M2C_FIELD(gCameraTarget[0], s32 *, 0xE4) = func_80023E3C(t);
        } while (i < 8);
        p = spawnEffectObj(0x101, 0, 0, 0);
        M2C_FIELD(p, s32 **, 0x9C) = func_80071300;
        M2C_FIELD(p, s32 *, 0x64) = 3000;
        M2C_FIELD(arg0, s32 *, 0x64) = 3000;
        q = M2C_FIELD(arg0, void **, 0xA8);
        M2C_FIELD(arg0, s32 **, 0x9C) = func_80071440;
        M2C_FIELD(arg0, s32 *, 0x68) = -1;
        if (q != NULL) {
            M2C_FIELD(q, s32 *, 0x78) = 0;
        }
        switch (M2C_FIELD(arg0, s32 *, 0x90)) {
        case 1:
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x81);
            break;
        case 2:
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x87);
            break;
        case 3:
            sendCommand(0xC, 0x80);
            sendCommand(8, 0x85);
            break;
        }
    }
}
