typedef struct {
    s32 pad0;
    f32 x;
    s32 pad8;
    f32 z;
    s32 unk10;
    u8 pad14[0x2C];
    f32 unk40;
    s32 pad44;
    f32 unk48;
    u8 pad4C[0x20];
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    u8 pad7C[0x14];
    s32 unk90;
    u8 pad94[0x6C];
    f32 unk100;
    f32 unk104;
} Obj;

s32 approachAngle(s32, s32, s32);
void func_8002D3E4(Obj *, s32);
void func_8002DA80(Obj *);
void animStepKeys(Obj *);
void func_80043328(Obj *, s32, s32);
void startStoryDialog(s32, char *, Obj *);
extern s32 gCamSpeedScale;
extern Obj *gCameraTarget;

s32 func_800516F0(Obj *arg0) {
    f32 range;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 f;
    char *msg = "cellpad_outofrange";

    range = arg0->unk104 - 2.0f;
    arg0->unk10 = approachAngle(arg0->unk90, arg0->unk10, gCamSpeedScale << 9);
    dx = gCameraTarget->x - arg0->unk40;
    dz = gCameraTarget->z - arg0->unk48;
    dist = sqrtf(dx * dx + dz * dz);
    f = arg0->unk100;
    if (f < 300.0f) {
        return 2;
    }
    if (dist < range) {
        if (f < 600.0f) {
            arg0->unk78 = 1;
            func_8002D3E4(arg0, 150);
        } else {
            arg0->unk78 = 2;
            func_8002D3E4(arg0, 750);
        }
        if (arg0->unk70 == 0) {
            arg0->unk70 = 1;
        }
    } else {
        arg0->unk78 = 0;
        func_8002D3E4(arg0, 0);
        if (arg0->unk70 == 1) {
            startStoryDialog(arg0->unk6C, msg, arg0);
            arg0->unk70++;
        }
    }
    func_80043328(arg0, arg0->unk74 + arg0->unk78, 0x100);
    animStepKeys(arg0);
    func_8002DA80(arg0);
    dx = arg0->x - arg0->unk40;
    dz = arg0->z - arg0->unk48;
    dist = sqrtf(dx * dx + dz * dz);
    if (range < dist) {
        arg0->unk78 = 0;
        arg0->x = arg0->unk40 + dx * range / dist;
        arg0->z = arg0->unk48 + dz * range / dist;
        func_8002D3E4(arg0, 0);
        if (arg0->unk70 == 1) {
            startStoryDialog(arg0->unk6C, msg, arg0);
            arg0->unk70++;
        }
        return 1;
    }
    return 0;
}
