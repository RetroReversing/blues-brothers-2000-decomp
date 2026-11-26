typedef struct {
    s32 unk0;
} Unk800BD06C;

typedef struct {
    u8 pad0[0xA8];
    s32 unkA8;
} Unk8007B94C_A4;

typedef struct Unk8007B94C {
    u8 pad0[4];
    f32 unk4;
    f32 unk8;
    u8 padC[4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0x44 - 0x1C];
    f32 unk44;
    u8 pad48[0x50 - 0x48];
    f32 unk50;
    u8 pad54[0x64 - 0x54];
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    u8 pad74[0x7C - 0x74];
    s32 unk7C;
    u8 pad80[0xA0 - 0x80];
    void (*unkA0)(struct Unk8007B94C *);
    Unk8007B94C_A4 *unkA4;
    u8 padA8[4];
    f32 unkAC;
    u8 padB0[4];
    f32 unkB4;
    u8 padB8[0xF8 - 0xB8];
    s32 unkF8;
} Unk8007B94C;

extern s32 D_800BD100;
extern Unk800BD06C *gCameraTarget;
extern f32 D_800B9EC4;
extern s32 gCamSpeedScale;
extern s32 gSplinePointCount[];

s32 func_80081990(f32 *out, s32 i, f32 t);
void syncActorPrevPos(void *arg0);
s32 tickActorTimer(void *arg0);
s32 func_80081AC0(f32 *out, s32 i, f32 t);
s32 func_8002492C(f32, f32);
f32 func_8002D8F4(void *arg0, s32 *arg1);
void *func_8003B980(void *o);
s32 func_8003BF98(void *o);

/* Per-frame update for a camera that rides a spline path: runs the ease-in, the constant-speed run along the path, and the hand-off to the camera target when it arrives. */
void updateCamPathFollow(Unk8007B94C *cam) {
    s32 idx;
    s32 flag;
    f32 t;
    f32 sum;
    f32 vec[3];
    f32 dist;
    s32 mode;

    idx = cam->unk70;
    flag = 0;
    if (cam->unk7C == 0) {
        cam->unk7C = D_800BD100;
    }
    cam->unkF8 |= 1;
    switch (cam->unk6C) {
    case 0:
        func_80081990(&cam->unk4, idx, cam->unkB4);
        syncActorPrevPos(cam);
        cam->unk68 = -1;
        cam->unk64 = 200;
        cam->unk6C++;
        cam->unk8 += 2000.0f;
        break;
    case 1:
        if (tickActorTimer(cam) != 0) {
            cam->unk68 = 4;
            cam->unk6C++;
        }
        break;
    case 2:
        t = D_800B9EC4;
        cam->unk50 += t * -2700.0f;
        cam->unk8 += cam->unk50 * t;
        if (cam->unk8 <= cam->unk44) {
            cam->unk8 = cam->unk44;
            cam->unk6C++;
        }
        break;
    default:
        sum = cam->unkB4 + cam->unkAC;
        cam->unkB4 = sum;
        t = (f32)gSplinePointCount[idx] - 1.1f;
        if (t <= sum) {
            cam->unkA4->unkA8 = 0;
            cam->unkA0(cam);
            break;
        }
        func_80081990(&cam->unk4, idx, sum);
        if (cam->unk7C == 4) {
            func_80081AC0(vec, idx, cam->unkB4);
            cam->unk10 = func_8002492C(vec[0], vec[2]);
            cam->unk14 += gCamSpeedScale << 10;
        } else if (cam->unk70 < 7) {
            cam->unk18 += gCamSpeedScale << 10;
        } else {
            cam->unk14 -= gCamSpeedScale << 10;
        }
        dist = func_8002D8F4(cam, NULL);
        do { do { mode = D_800BD100; } while (0); } while (0);
        if (mode == 1) {
            if (dist < 500.0) {
                if (gCameraTarget->unk0 == 3) {
                    func_8003B980(gCameraTarget);
                }
            }
        } else if (dist < 425.0f) {
            if (flag && gCameraTarget->unk0 == 3) {
                func_8003B980(gCameraTarget);
            } else {
                func_8003BF98(gCameraTarget);
            }
        }
        break;
    }
}
