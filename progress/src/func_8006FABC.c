typedef struct {
    f32 m[4][4];
} Mtx3;
typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x30];
    f32 px;
    f32 py;
    f32 pz;
    u8 pad4C[0x20];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 pad78;
    s32 unk7C;
    u8 pad80[8];
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x70];
    f32 unk100;
    f32 unk104;
} Obj3;

void updateCameraView(Obj3 *);
s32 approachS32(s32, s32, s32);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(void);
void func_80034FEC(Obj3 *, s32 *);
void func_8004C020(Mtx3 *, s32, s32, s32, s32, s32, s32, f32 *, f32 *, f32 *);
void func_8004DF94(Mtx3 *, f32, f32, f32);
void func_8004E008(Mtx3 *, f32);
void func_8006F944(void);
extern f32 D_80009024;
extern f32 D_80009028;
extern f32 D_8000902C;
extern f64 D_80009030;
extern f64 D_80009038;
extern f64 D_80009040;
extern Mtx3 D_800B76E0;
extern f32 D_800B8320[2];
extern f32 D_800B8328[2];
extern s32 gCamSpeedScale;

void func_8006FABC(Obj3 *arg0) {
    s32 pos[3];
    f32 out[3];
    Mtx3 m;
    s32 done;

    done = 0;
    if (arg0->unk6C != 0) {
done = 1;
arg0->unk6C = 0;
        arg0->x = 15.0f;
        arg0->y = 2755.0f;
        arg0->z = 1924.0f;
arg0->unk100 = D_800B8320[0];
arg0->unk104 = D_800B8320[1];
arg0->unk88 = -0x78;
arg0->unk8C = 0;
        syncActorPrevPos();
    }
    arg0->unk70 = 1;
    if (arg0->unk6C == 0) {
        arg0->unk100 = approachF32(D_800B8328[0], arg0->unk100, gCamSpeedScale * 35.0);
        arg0->unk104 = approachF32(D_800B8328[1], arg0->unk104, gCamSpeedScale * 35.0);
        if (arg0->unk100 == D_800B8328[0]) {
            done = 1;
        }
    }
    m = D_800B76E0;
    func_8004DF94(&m, arg0->px, arg0->py, arg0->pz);
    func_8004E008(&m, (f32)((f32)arg0->unk8C * 6.283185307179586) * 1.52587890625e-05);
    func_8004DF94(&m, 0.0f, arg0->unk104, arg0->unk100);
    func_8004C020(&m, 0, 0, 0, 0, 0, 0, &out[0], &out[1], &out[2]);
    arg0->x = out[0];
    arg0->y = out[1];
    arg0->z = out[2];
    if (arg0->unk74 != 0) {
        arg0->unk88 = approachS32(0x50, arg0->unk88, 0x19);
    }
    pos[0] = arg0->px;
    pos[1] = arg0->py + arg0->unk88;
    pos[2] = arg0->pz;
    func_80034FEC(arg0, pos);
    if (arg0->unk7C == 0 && done != 0) {
        arg0->unk7C = 1;
        func_8006F944();
    }
    updateCameraView(arg0);
}
