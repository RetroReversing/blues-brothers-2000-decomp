s16 coss(u16);
s16 sins(u16);
s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void func_8002ADFC(s32, s32, void *);
void func_8002D604(void *);
f32 func_8002DD60(f32);
f32 sqrtf(f32);

typedef struct Obj {
    char pad0[4];
    f32 x4;
    f32 x8;
    f32 xC;
    char pad10[0x34 - 0x10];
    s32 x34;
    s32 x38;
    s32 x3C;
    char pad40[0x4C - 0x40];
    f32 x4C;
    f32 x50;
    f32 x54;
    s32 x58;
    char pad5C[0x7C - 0x5C];
    s32 x7C;
    char pad80[0xA0 - 0x80];
    void (*fnA0)(struct Obj *);
} Obj;

extern f32 D_80000770;
extern f32 D_80000774;
extern f32 D_80000778;
extern f32 D_8000077C;
extern f32 D_80000780;
extern u8 gTextWaveTime[];
extern s32 gCamSpeedScale[];
extern u8 gCameraTarget[];
#define BD (*(Obj **)gCameraTarget)

void func_80011D30(Obj *arg0) {
    char buf[0x70];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 lim;
    f32 vx;
    f32 vz;
    f32 sp;

    arg0->x58 = packDrawFlags(1, 1, 0, 2, 0, 1, 1, 0);
    dx = arg0->x4 - BD->x4;
    dz = arg0->xC - BD->xC;
    dy = arg0->x8 - BD->x8;
    func_8002D604(arg0);
    func_8002D604(arg0);
    arg0->x38 = (coss((*(s32 *)gTextWaveTime) * 1500 & 0xFFFC) >> 11) + 0x100;
    arg0->x3C = (sins((*(s32 *)gTextWaveTime) * 1500 & 0xFFFC) >> 11) + 0x100;
    arg0->x34 = (sins((*(s32 *)gTextWaveTime) * 1500 & 0xFFFC) >> 11) + 0x100;
    if (arg0->x7C < 10) {
        arg0->x50 = D_80000770;
    }
    if (arg0->x7C >= 61) {
        lim = D_80000774;
        arg0->x7C = 61;
        if (func_8002DD60(dx) < lim && func_8002DD60(dy) < D_80000778 && func_8002DD60(dz) < lim) {
            vx = BD->x4C;
            vz = BD->x54;
            sp = sqrtf(vx * vx + vz * vz);
            if (D_8000077C < sp) {
                arg0->x8 += D_80000780;
                return;
            }
            func_8002ADFC(1, 1000, arg0);
            arg0->fnA0(arg0);
            return;
        }
    }
    arg0->x7C += gCamSpeedScale[0];
}
