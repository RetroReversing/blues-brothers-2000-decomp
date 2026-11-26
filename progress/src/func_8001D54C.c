typedef struct ObjE ObjE;
struct ObjE {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x40 - 0x10];
    f32 f40;
    f32 f44;
    f32 f48;
    u8 pad4C[0x70 - 0x4C];
    s32 f70;
    s32 f74;
    u8 pad78[0x7C - 0x78];
    s32 f7C;
    u8 pad80[0x90 - 0x80];
    s32 f90;
    u8 pad94[0x9C - 0x94];
    void *f9C;
    void (*fA0)(ObjE *);
    void *fA4;
    u8 padA8[0xC0 - 0xA8];
    s32 fC0;
};

s32 cameraGetMode(void);
s32 func_8001B990(s32, s32);
void updateCameraView(ObjE *);
void sendCommand(s32, s32);
f32 approachF32(f32, f32, f32);
void syncActorPrevPos(ObjE *);
extern ObjE *gCameraRig;
extern s32 gCamSpeedScale;

void func_8001D54C(ObjE *arg0) {
    s32 go;
    f32 *cur;
    f32 *tgt;

    if (arg0->f7C == 0) {
        if (cameraGetMode() == 7) {
            arg0->f90 = 1;
        } else {
            arg0->f90 = 0;
        }
        arg0->f7C = 1;
    }
    go = 1;
    if (arg0->f90 != 0) {
        cur = &arg0->z;
        tgt = &arg0->f48;
        if (func_8001B990(0x100, arg0->f70) != 0) {
            arg0->fC0 = 1;
        } else {
            arg0->fC0 = 0;
        }
    } else {
        go = arg0->f74;
        cur = &arg0->x;
        tgt = &arg0->f40;
    }
    if (go != 0) {
    if (arg0->fC0 == 1) {
        if (arg0->f90 != 0) {
            *cur = approachF32(*tgt - 750.0f, *cur, gCamSpeedScale * 7);
            if (*cur == *tgt - 750.0f) {
                arg0->fC0 = 0;
                if (arg0->f90 != 0) {
                    arg0->fA0(arg0);
                    return;
                }
            }
        } else {
            *cur = approachF32(*tgt - 500.0f, *cur, gCamSpeedScale * 20);
            if (*cur == *tgt - 500.0f) {
                sendCommand(12, 0x80);
                sendCommand(8, 0x72);
                arg0->fC0 = 0;
            }
        }
    }
    if (arg0->fC0 == 2) {
        *cur = approachF32(*tgt, *cur, gCamSpeedScale * 20);
        if (*cur == *tgt) {
            arg0->fC0 = 0;
            arg0->f74 = 0;
            if (arg0->f90 != 0) {
                arg0->fA0(arg0);
                gCameraRig->fC0 = 0;
                gCameraRig->f9C = gCameraRig->fA4;
                updateCameraView(gCameraRig);
            }
        }
    }
    } else {
        syncActorPrevPos(arg0);
    }
}
