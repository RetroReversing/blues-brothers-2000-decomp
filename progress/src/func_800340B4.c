typedef struct {
    s32 type;
    f32 pos[3];
    s32 yaw;
    s32 unk14;
    u8 pad18[0x50 - 0x18];
    f32 unk50;
    u8 pad54[0x68 - 0x54];
    s32 unk68;
    u8 pad6C[0x90 - 0x6C];
    s32 mode;
    u8 pad94[0x9C - 0x94];
    void *callback;
} Player;

typedef struct {
    s32 unk0;
    f32 pos[3];
    s32 yaw;
    s32 pitch;
    u8 pad18[0x6C - 0x18];
    s32 preset;
    u8 pad70[0x74 - 0x70];
    s32 yawTarget;
    s32 dist;
    s32 distTarget;
    s32 pitchTarget;
    u8 pad84[0xBC - 0x84];
    s32 pad;
    s32 state;
} Camera;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 yaw;
    s32 pitch;
    s32 yawTarget;
} CamSave;

typedef struct {
    s32 dist;
    s32 pitch;
} CamPreset;

s16 coss(u16);
s16 sins(u16);
void updateCameraView(Camera *);
s32 func_80024AC4();
s32 func_80024AE8(s32, s32);
s32 func_8002D1C4(s32, s32, s32);
s32 func_8002D260(s32);
void func_80034F1C(Camera *);
void func_80035D04(Camera *);
s32 cameraAvoidWalls(Camera *);
s32 func_80036780(Camera *);
void func_800393F4(void);
extern CamPreset cameraDistTable[];
extern s32 D_800B4BFC;
extern s32 D_800B9E88;
extern s32 gFrameScale;
extern s32 gCamSpeedScale;
extern Player *gCameraTarget;
extern u32 D_80107040[];
extern u32 gPadPressed;
extern s32 D_801073B0;
extern s32 gStickY[];
extern s32 D_8013FFA0;
extern s32 D_8013FFA4;
extern s32 D_8013FFA8;
extern s32 D_8013FFCC;
extern CamSave gCameraSnapshot;
extern s32 D_80140028;
extern s32 D_8014002C;
extern s32 D_80140030;
extern s32 D_80140200;
extern s32 D_80140228;

void func_800340B4(Camera *arg0) {
    f32 pad[20];
    f32 eye[3];
    f32 at[3];
    f32 pad2[36];
    f32 speed;
    u32 buttons;
    s32 step;

    if (gCameraTarget == NULL) {
        updateCameraView(arg0);
        return;
    }
    {
        gCameraSnapshot.x = arg0->pos[0];
        gCameraSnapshot.y = arg0->pos[1];
        gCameraSnapshot.z = arg0->pos[2];
        gCameraSnapshot.yaw = arg0->yaw;
        gCameraSnapshot.pitch = arg0->pitch;
        gCameraSnapshot.yawTarget = arg0->yawTarget;
        if (D_8013FFA8 == 0 && D_80140200 > 0) {
            arg0->distTarget += func_80024AC4(cameraDistTable[arg0->preset].dist - arg0->distTarget, arg0->distTarget, 3);
        }
        if (arg0->state != 2) {
            if (gPadPressed != 0 && arg0->state == 1 && D_8014002C == 0) {
                arg0->state = 0;
                gCameraTarget->unk14 = 0;
                if (gCameraTarget->callback == func_800393F4) {
                    gCameraTarget->unk68 = 3;
                }
                arg0->yaw = D_8013FFCC;
                arg0->pitch = D_8013FFA0;
            } else if ((gPadPressed & 8) && arg0->state == 0 && gCameraTarget->type == 3 &&
                       gCameraTarget->unk50 <= 0.0f && gCameraTarget->mode == 1) {
                D_8013FFCC = arg0->yaw;
                D_8013FFA0 = arg0->pitch;
                arg0->yaw = gCameraTarget->yaw;
                arg0->pitch = 0;
                D_800B9E88 = 50;
                arg0->pos[0] = gCameraTarget->pos[0];
                arg0->pos[1] = gCameraTarget->pos[1] + 300.0f;
                arg0->pos[2] = gCameraTarget->pos[2];
                arg0->state = 1;
                gCameraTarget->unk68 = -1;
            }
            if (arg0->state == 1) {
                arg0->yaw += func_80024AE8(D_801073B0, 3) * 80;
                arg0->pitch -= func_80024AE8(gStickY[0], 3) * 80;
                arg0->pitch = func_8002D260(arg0->pitch);
                if (arg0->pitch < -7000) {
                    arg0->pitch = -7000;
                }
                if (arg0->pitch > 9000) {
                    arg0->pitch = 9000;
                }
                arg0->pos[0] = gCameraTarget->pos[0];
                arg0->pos[1] = gCameraTarget->pos[1] + 300.0f;
                arg0->pos[2] = gCameraTarget->pos[2];
                updateCameraView(arg0);
                D_80140228 = 0;
                D_800B9E88 = 50;
                gCameraTarget->yaw = arg0->yaw;
                return;
            }
            D_800B9E88 = 100;
            if (!(D_80107040[0] & 0x2000) && (gPadPressed & 4)) {
                arg0->preset++;
                if (arg0->preset >= 4) {
                    arg0->preset = 0;
                }
                func_80034F1C(arg0);
            }
            arg0->dist += func_80024AC4(arg0->distTarget - arg0->dist, 3);
            D_80140030 = func_80024AE8(D_80140030, 1);
        }
        arg0->yaw = func_8002D1C4(arg0->yawTarget, arg0->yaw, 3);
        arg0->yaw = arg0->yawTarget;
        arg0->pitch = func_8002D1C4(arg0->pitchTarget, arg0->pitch, 2);
        arg0->pos[0] = gCameraTarget->pos[0] + (((-arg0->dist * sins(arg0->yaw)) >> 15) * coss(arg0->pitch) >> 15);
        arg0->pos[2] = gCameraTarget->pos[2] + (((-arg0->dist * coss(arg0->yaw)) >> 15) * coss(arg0->pitch) >> 15);
        arg0->pos[1] = gCameraTarget->pos[1] + ((-arg0->dist * sins(arg0->pitch)) >> 15) + 200.0f;
        eye[0] = arg0->pos[0];
        eye[1] = arg0->pos[1];
        eye[2] = arg0->pos[2];
        at[0] = gCameraTarget->pos[0];
        at[1] = gCameraTarget->pos[1] + 200.0f;
        at[2] = gCameraTarget->pos[2];
        func_80035D04(arg0);
        arg0->yaw += D_8013FFA4;
        arg0->yawTarget += D_8013FFA4;
        if (D_8013FFA8 == 0) {
            arg0->pitch = func_8002D260(arg0->pitch);
            if (arg0->pitch < cameraDistTable[arg0->preset].pitch) {
                D_8013FFA8 = 0x200;
            }
            if (cameraDistTable[arg0->preset].pitch + 0x400 < arg0->pitch) {
                D_8013FFA8 = -0x200;
            }
            arg0->pitch += D_8013FFA8;
            arg0->pitchTarget += D_8013FFA8;
            if (func_80036780(arg0) != 0) {
                arg0->pitch -= D_8013FFA8;
                arg0->pitchTarget -= D_8013FFA8;
            }
            D_8013FFA8 = 0;
        }
        arg0->pitch += D_8013FFA8;
        arg0->pitchTarget += D_8013FFA8;
        arg0->pitch = func_8002D260(arg0->pitch);
        if (arg0->pitch < -0x4000) {
            arg0->pitch = -0x4000;
        }
        if (arg0->pitch > 0x4000) {
            arg0->pitch = 0x4000;
        }
        if (gCameraTarget->callback == func_800393F4) {
            if (D_80107040[0] & 2) {
                arg0->yaw += gCamSpeedScale << 8;
                if (cameraAvoidWalls(arg0) == 0) {
                    arg0->yawTarget = arg0->yaw;
                } else {
                    D_80140028 = 8;
                    arg0->yaw -= gCamSpeedScale << 8;
                }
            }
            if (D_80107040[0] & 1) {
                arg0->yaw -= gCamSpeedScale << 8;
                if (cameraAvoidWalls(arg0) == 0) {
                    arg0->yawTarget = arg0->yaw;
                } else {
                    D_80140028 = 8;
                    arg0->yaw += gCamSpeedScale << 8;
                }
            }
        }
        speed = 0.0f;
        if (D_80107040[0] & 0x400) {
            speed = 1.0f;
        }
        buttons = D_80107040[arg0->pad];
        if (buttons & 0x2000) {
            if (buttons & 4) {
                speed = 1.0f;
            }
        }
        if (D_800B4BFC > 100000) {
            speed = 1.0f;
        }
        if (speed != 0.0f) {
            step = func_80024AE8(func_8002D260(gCameraTarget->yaw - arg0->yaw), 2);
            arg0->yaw += step;
            if (cameraAvoidWalls(arg0) == 0) {
                D_800B4BFC = 0;
                arg0->yawTarget = arg0->yaw;
            } else {
                D_80140028 = 8;
                arg0->yaw -= step;
            }
        }
        arg0->pos[0] = gCameraTarget->pos[0] + (((-arg0->dist * sins(arg0->yaw)) >> 15) * coss(arg0->pitch) >> 15);
        arg0->pos[2] = gCameraTarget->pos[2] + (((-arg0->dist * coss(arg0->yaw)) >> 15) * coss(arg0->pitch) >> 15);
        arg0->pos[1] = gCameraTarget->pos[1] + ((-arg0->dist * sins(arg0->pitch)) >> 15) + 200.0f;
        if (D_80107040[0] != 0) {
            D_800B4BFC = 0;
        }
        if (func_80024AE8(D_801073B0, 3) != 0) {
            D_800B4BFC = 0;
        }
        if (func_80024AE8(gStickY[0], 3) != 0) {
            D_800B4BFC = 0;
        }
        D_800B4BFC += gFrameScale;
    }
    updateCameraView(arg0);
}
