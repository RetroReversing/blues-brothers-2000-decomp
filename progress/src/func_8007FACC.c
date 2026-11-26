typedef struct {
    s32 m[4][4];
} Mtx;
typedef struct Obj Obj;
struct Obj {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x54];
    s32 unk64;
    u8 pad68[4];
    s32 unk6C;
    s32 unk70;
    u8 pad74[8];
    s32 unk7C;
    u8 pad80[0x1C];
    void (*unk9C)(Obj *);
    u8 padA0[0x60];
    f32 unk100;
};
typedef struct {
    u8 pad0[0x90];
    s32 unk90;
} Ctl;
typedef struct {
    u8 pad0[0xA8];
    s32 unkA8;
} Cam;

s32 func_8002492C(f32, f32);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260(s32);
f32 approachF32(f32, f32, f32);
f32 func_8002DD60(f32);
void func_80034F50(Obj *);
void func_8004C020(Mtx *, s32, s32, s32, s32, s32, s32, f32 *, f32 *, f32 *);
void func_8004DF94(Mtx *, s32, f32, f32);
void func_8004E008(Mtx *, f32);
void func_8007F990(Obj *);
extern Cam *gCameraRig;
extern Ctl *D_800B3964;
extern Mtx D_800B76E0;
extern f32 D_800B8708[];
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;
extern s32 gPadPressed;
extern s32 D_80140028;

void func_8007FACC(Obj *arg0) {
    Mtx m;
    f32 pos[3];
    s32 angle;
    s32 t;
    f32 rot;

    if (func_8002DD60(gCameraTarget->x) < 500.0 && func_8002DD60(gCameraTarget->z) < 500.0) {
        arg0->unk70 = 1;
    }
    angle = func_8002492C(gCameraTarget->x, gCameraTarget->z) + 0x2000;
    if (arg0->unk70 != 0) {
        t = approachAngle(angle, arg0->unk6C, gCamSpeedScale << 8);
        arg0->unk6C = t;
        if (t == angle) {
            arg0->unk70 = 0;
        }
    } else {
        arg0->unk6C = func_8002D260(angle);
    }
    if (arg0->unk6C >= -0x8FB && arg0->unk6C < 0x3E8) {
        arg0->unk7C = 1;
    } else {
        arg0->unk7C = 0;
    }
    arg0->unk100 = approachF32(D_800B8708[arg0->unk7C], arg0->unk100, gCamSpeedScale * 16);
    rot = (f32)arg0->unk6C * 6.283185307179586;
    rot = rot * 1.52587890625e-05;
    m = D_800B76E0;
    func_8004E008(&m, rot);
    func_8004DF94(&m, 0, 850.0f, arg0->unk100);
    func_8004C020(&m, 0, 0, 0, 0, 0, 0, &pos[0], &pos[1], &pos[2]);
    arg0->x = pos[0];
    arg0->y = pos[1];
    arg0->z = pos[2];
    func_80034F50(arg0);
    gCameraRig->unkA8 = 0;
    if (D_800B3964->unk90 != 0) {
        if (gPadPressed & 8) {
            arg0->unk9C = func_8007F990;
            arg0->unk64 = 120;
            arg0->unk7C = 100;
        }
    } else {
        D_80140028 = 4;
    }
}
