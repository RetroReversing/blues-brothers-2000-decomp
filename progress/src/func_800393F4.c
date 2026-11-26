/* machine draft (m2c) for sn-n64-281 -G0 -mips3 -O2 -mgas -meb -mcpu=VR4300 -mhard-float -mfp64, tried by autopilot */
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

s16 coss(u16);                                      /* extern */
s32 cameraGetMode();                                /* extern */
M2C_UNK func_8000C5B4();                       /* extern */
M2C_UNK func_8000F7A0(void *);                      /* extern */
s32 func_8000FAC4(void *);                          /* extern */
void *func_80012718(void *);                        /* extern */
M2C_UNK func_80017CF0(void *);                      /* extern */
s32 func_80023E3C(M2C_UNK);                         /* extern */
s32 func_80024AC4(s32, M2C_UNK);                    /* extern */
s32 func_80024AE8(s32, M2C_UNK);                    /* extern */
s32 isqrtS32(s32);                             /* extern */
s32 atan2S16(s32, s32);                        /* extern */
M2C_UNK sendCommand(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8002ABCC();                            /* extern */
M2C_UNK func_8002ACAC();                            /* extern */
M2C_UNK func_8002ACFC();                            /* extern */
M2C_UNK func_8002AD4C();                            /* extern */
M2C_UNK func_8002D124();                            /* extern */
s32 func_8002D1C4(s32, s32, M2C_UNK);               /* extern */
M2C_UNK func_8002D3E4(void *, M2C_UNK);             /* extern */
M2C_UNK syncActorPrevPos(void *);                      /* extern */
void *func_8002E374(M2C_UNK);                       /* extern */
M2C_UNK func_80037164(void *, void *, void *);      /* extern */
M2C_UNK func_8003A9A8(void *, s32);                 /* extern */
s32 func_8003AB30(void *);                          /* extern */
M2C_UNK handleActorHit(void *, f32, M2C_UNK);  /* extern */
M2C_UNK func_8003C37C();                            /* extern */
s32 func_8003C5D8(void *);                          /* extern */
s32 func_8003CA30(void *);                          /* extern */
s32 animStepKeys(void *);                          /* extern */
M2C_UNK func_80043328(); /* extern */
M2C_UNK actorSetAnim(void *, M2C_UNK, M2C_UNK);    /* extern */
s16 sins(u16);                                      /* extern */
extern s32 D_800B3838;
extern void *gCameraRig;
extern M2C_UNK D_800B4C1C;
extern void *D_800B4CE4;
extern s32 D_800B4CE8;
extern s32 D_800B4CFC;
extern f32 D_800B4D00;
extern f32 D_800B4D04;
extern s32 gFrameScale;
extern f32 D_800B9EC4;
extern s32 gCamSpeedScale;
extern void *gCameraTarget;
extern s32 D_800BD0DC;
extern s32 D_800BD0F4;
extern s32 D_80107040[];
extern s32 gPadPressed[];
extern s32 gStickX[];
extern s32 gStickY[];
extern s32 D_80140140;
extern s32 D_801401E0;
extern f32 D_801401E4;
extern s32 D_80140200;
extern s32 D_80140204;
extern s32 D_80140208;
extern s32 D_8014020C;
extern s32 D_80140214;
extern f32 D_80140218[];
extern s32 D_80140224;
extern f32 D_8014022C;
extern s32 D_80140230;
extern f32 D_80140234;
extern s32 D_80140238;
extern s32 D_8014023C;
extern s32 D_80140240;
extern f32 D_80140248;
extern M2C_UNK func_800142A0;
extern M2C_UNK func_8003C2A0;
extern M2C_UNK func_800414D0;

typedef struct {
    s32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad_1C[0x18];
    s32 f34;
    s32 f38;
    s32 f3C;
    u8 pad_40[0xC];
    f32 f4C;
    f32 f50;
    f32 f54;
    u8 pad_58[0x10];
    s32 f68;
    u8 pad_6C[0x4];
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    u8 pad_80[0x8];
    s32 f88;
    u8 pad_8C[0x4];
    s32 f90;
    s32 f94;
    u8 pad_98[0x20];
    s32 fB8;
    s32 fBC;
    u8 pad_C0[0xC];
    s32 fCC;
    s32 fD0;
    u8 pad_D4[0x8];
    f32 fDC;
    s32 fE0;
    s32 fE4;
    u8 pad_E8[0x8];
    s32 fF0;
} Actor;
void func_800393F4(Actor *arg0) {
    s32 pad[24];
    M2C_UNK var_a1;
    M2C_UNK var_a1_2;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1_6;
    f32 var_fs0;
    f64 temp_ft0;
    f64 temp_ft0_2;
    f64 temp_fv1_10;
    f64 temp_fv1_7;
    f64 temp_fv1_8;
    f64 temp_fv1_9;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_lo;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_v1;
    void *temp_v0_6;
    void *temp_v0_9;

    var_fs0 = 7000.0f;
    if (D_800BD0F4 <= 0) {
        M2C_FIELD(gCameraTarget, s32 *, 0xC0) = 0;
        func_8003C37C();
        return;
    }
    D_80140248 = arg0->f50;
    if (arg0->f50 < D_800B4D00) {
        D_800B4D00 = arg0->f50;
    }
    temp_fv1_2 = arg0->f50;
    if (D_800B4D04 < temp_fv1_2) {
        D_800B4D04 = temp_fv1_2;
    }
    arg0->f34 = 0x100;
    arg0->f38 = 0x100;
    arg0->f3C = 0x100;
    if (arg0->fD0 != 0x2A) {
        arg0->f14 = 0;
        arg0->f18 = 0;
    }
    if (!(M2C_FIELD(gCameraRig, s32 *, 0xC0) & 1)) {
        if (arg0->fE0 == 0) {
            actorSetAnim(arg0, 1, 0x100);
        }
        temp_v1 = D_80140230 - gFrameScale;
        D_80140230 = temp_v1;
        if (temp_v1 <= 0) {
            D_80140230 = 0;
            arg0->f0 = 3;
        } else {
            arg0->f0 = 0x101;
            arg0->fF0 = (s32) (arg0->fF0 ^ 0x80);
        }
        D_80140240 = 0x708;
        temp_v1_2 = arg0->fD0;
        if ((temp_v1_2 == 0xD) || (temp_v1_2 == 0x13)) {
            if ((func_80024AE8(gStickX[0], 3) + func_80024AE8(gStickY[0], 3)) == 0) {
                arg0->f74 = 1;
            }
        } else if (!(D_80107040[0] & 0x2000) || (temp_v1_2 != 0x12)) {
            arg0->f74 = 1;
        }
        if (arg0->fD0 == 0x15) {
            arg0->f74 = 0;
        }
        D_80140204 = gStickX[0];
        D_80140208 = gStickY[0];
        D_80140234 = D_8014022C;
        syncActorPrevPos(arg0);
        if ((arg0->f90 == 0) && (D_80107040[arg0->fBC] & 0x8000)) {
            var_fs0 = 3500.0f;
        }
        temp_v1_3 = arg0->f90;
        D_800BD0DC = 0;
        if (temp_v1_3 != 0) {
            temp_v1_3 = arg0->fBC;
            if ((gPadPressed[temp_v1_3] & 0x8000) || ((arg0->fB8 == 6) && (D_80107040[temp_v1_3] & 0x8000))) {
                if (arg0->f50 <= 0.0f) {
                    var_s0_2 = 4;
                    if (arg0->fB8 == 6) {
                        var_s0_2 = 5;
                    }
                    arg0->f50 = (f32) ((var_s0_2 * D_80140240) / 4) + (D_800B9EC4 * var_fs0);
                    arg0->f8 += 1.0f;
                    actorSetAnim(arg0, 5, 0x100);
                    func_8002ACAC();
                }
            }
        }
        if (!(D_80107040[arg0->fBC] & 0x10) && (gPadPressed[arg0->fBC] & 0x20) && (arg0->f90 != 0)) {
            func_8000C5B4();
            if (arg0->fD0 != 0x1A) {
                actorSetAnim(arg0, 0x1A, 0x100);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x1E);
                func_8002D124();
            }
        }
        if (((D_8014020C < 0) || (temp_v0 = D_8014020C - gFrameScale, D_8014020C = temp_v0, (temp_v0 <= 0))) && (temp_v1_5 = arg0->fBC, ((D_80107040[temp_v1_5] & 0x2000) != 0))) {
            temp_v1_4 = arg0->fD0;
            if (temp_v1_4 == 1) {
                if (arg0->f90 != 0) {
                    if ((D_800B4CE4 == NULL) && (arg0->fB8 == temp_v1_4)) {
                        if (gPadPressed[temp_v1_5] & 0x10) {
                            actorSetAnim(arg0, 0x1C, 0x100);
                        }
                    }
                }
            }
        }
        if (!(M2C_FIELD(gCameraRig, s32 *, 0xC0) & 1)) {
            temp_v1_6 = arg0->fBC;
            temp_a0_2 = gStickX[temp_v1_6];
            temp_v0_2 = gStickY[temp_v1_6];
            temp_v0_3 = isqrtS32((temp_a0_2 * temp_a0_2) + (temp_v0_2 * temp_v0_2));
            arg0->f88 = temp_v0_3;
            if (temp_v0_3 >= 0x47) {
                arg0->f88 = 0x46;
            }
            temp_a0_3 = (arg0->f88 * 0x4B0) / 980;
            arg0->f88 = temp_a0_3;
            if (D_800BD0DC != 0) {
                arg0->f88 = (s32) (temp_a0_3 / 2);
            }
            if (arg0->fB8 == 4) {
                arg0->f88 = (s32) (arg0->f88 * 2);
            }
        } else {
            arg0->f88 = 0;
        }
        var_s0_2 = 0;
        if (arg0->f88 >= D_800B4CE8) {
            temp_v1_7 = arg0->fD0;
            if ((temp_v1_7 != 0x14) && (temp_v1_7 != 0x12) && (temp_v1_7 != 0xD) && (temp_v1_7 != 0x13) && (temp_v1_7 != 0xE) && (temp_v1_7 != 0xF) && (temp_v1_7 != 0x1A)) {
                temp_v1_8 = arg0->fBC;
                var_s0_2 = atan2S16(gStickX[temp_v1_8], gStickY[temp_v1_8]);
                D_801401E0 = M2C_FIELD(gCameraRig, s32 *, 0x10) + var_s0_2;
            }
            arg0->f10 = func_8002D1C4(D_801401E0, arg0->f10, 1);
        }
        temp_lo = arg0->f74 * arg0->f88;
        temp_s0_2 = temp_lo * gFrameScale;
        arg0->f88 = temp_lo;
        M2C_FIELD(gCameraRig, s32 *, 0x74) = (s32) (M2C_FIELD(gCameraRig, s32 *, 0x74) + ((s32) (temp_s0_2 * sins(var_s0_2 & 0xFFFF)) >> 0xF));
        temp_v0_4 = arg0->f88 - 8;
        D_80140224 = temp_v0_4;
        if (temp_v0_4 < 6) {
            D_80140224 = 0;
        }
        temp_v1_9 = arg0->fD0;
        if (((temp_v1_9 == 0xB) || (temp_v1_9 == 0x24)) && (D_80140224 >= 0x15)) {
            D_80140224 = 0x14;
        }
        var_a0 = (D_80140224 - func_80024AC4(D_80140200, 4)) * gFrameScale;
        if (arg0->fD0 == 0x12) {
            if (D_80140224 == 0) {
                var_a0 = func_80024AC4(var_a0, 4);
                goto block_82;
            }
        } else {
block_82:
            if (D_80140224 == 0) {
                if (arg0->f90 == 1) {
                    var_a0 *= 2;
                }
            }
        }
        if (D_80140200 != 0) {
            if (D_80140224 == 0) {
                if (var_a0 == 0) {
                    var_a0 = -1;
                }
            }
        }
        temp_v0_5 = D_80140200 + var_a0;
        D_80140200 = temp_v0_5;
        if (temp_v0_5 < 0) {
            D_80140200 = 0;
        }
        if (arg0->fB8 != 4) {
            if (D_80140200 >= 0x4B1) {
                D_80140200 = 0x4B0;
            }
        } else if (D_80140200 >= 0x961) {
            D_80140200 = 0x960;
        }
        temp_v1_10 = arg0->fD0;
        if ((u32) (temp_v1_10 - 0xD) >= 3U) {
            if (temp_v1_10 == 0x13) {
                goto block_102;
            }
        } else {
block_102:
            D_80140200 = 0;
        }
        if (arg0->fD0 == 0xF) {
            temp_fv1_3 = arg0->fDC;
            if ((9.0f <= temp_fv1_3) && (temp_fv1_3 <= 12.0f)) {
                D_80140200 = 0x258;
            }
        }
        if (arg0->fD0 == 0x1E) {
            temp_fv1_4 = arg0->fDC;
            if ((5.0f <= temp_fv1_4) && (temp_fv1_4 <= 14.0f)) {
                D_80140200 = 0x320;
            }
            if ((39.0f <= arg0->fDC) && (arg0->fDC <= 42.0f)) {
                D_80140200 = 0x190;
            }
            if (42.0f < arg0->fDC) {
                D_80140200 = 0;
            }
        }
        if (arg0->fD0 == 0x1A) {
            temp_fv1_5 = arg0->fDC;
            if ((7.0f < temp_fv1_5) && (temp_fv1_5 < 24.0f)) {
                D_80140200 = -0x12C;
                arg0->f74 = 0;
            }
        }
        if (arg0->fD0 == 0x1B) {
            D_80140200 = -0x258;
            arg0->f74 = 0;
        }
        if (arg0->fD0 == 0x2A) {
            D_80140200 = 0;
            temp_v1_11 = gCamSpeedScale * 0xC00;
            arg0->f14 = (s32) (arg0->f14 - temp_v1_11);
            temp_a0_4 = arg0->f70 - temp_v1_11;
            arg0->f70 = temp_a0_4;
            if (temp_a0_4 < 0) {
                arg0->f14 = 0;
                func_80043328(arg0, 0x2B, 0x100);
                D_80140238 = 0;
            }
        }
        temp_v1_12 = arg0->f94;
        if (temp_v1_12 != 0) {
            D_80140200 = temp_v1_12;
        }
        if (arg0->fD0 == 0x2A) {
            var_fs0 = 0.0f;
            arg0->f50 = 0.0f;
        }
        if (arg0->fB8 == 5) {
            func_80017CF0(arg0);
        }
        if (arg0->fB8 == 4) {
            func_80012718(arg0);
        }
        if (arg0->fB8 == 6) {
            func_80012718(arg0);
        }
        arg0->f4C = (f32) ((s32) (D_80140200 * sins((*(u16 *)((u8 *)arg0 + 0x12)))) >> 0xF);
        arg0->f54 = (f32) ((s32) (D_80140200 * coss((*(u16 *)((u8 *)arg0 + 0x12)))) >> 0xF);
        arg0->f50 = (f32) (arg0->f50 - (D_800B9EC4 * var_fs0));
        if (arg0->f90 == 0) {
            arg0->f4C = (f32) (arg0->f4C + D_80140218[0]);
            arg0->f54 = (f32) (arg0->f54 + D_80140218[2]);
            D_80140218[0] = (f32) (D_80140218[0] - (D_800B9EC4 * D_80140218[0]));
            D_80140218[2] = (f32) (D_80140218[2] - (D_800B9EC4 * D_80140218[2]));
        }
        arg0->f4C = (f32) (D_800B9EC4 * arg0->f4C);
        arg0->f50 = (f32) (D_800B9EC4 * arg0->f50);
        arg0->f54 = (f32) (D_800B9EC4 * arg0->f54);
        func_80037164(arg0, &arg0->f4, &arg0->f4C);
        arg0->f4 += arg0->f4C;
        arg0->f4C /= D_800B9EC4;
        arg0->f8 += arg0->f50;
        arg0->f50 /= D_800B9EC4;
        arg0->fC += arg0->f54;
        arg0->f54 /= D_800B9EC4;
        func_8000F7A0(arg0);
        if (arg0->fD0 == 0x2C) {
            temp_v0_6 = func_80012718(arg0);
            M2C_FIELD(temp_v0_6, f32 *, 8) = (f32) (M2C_FIELD(temp_v0_6, f32 *, 8) - 50.0f);
        }
        temp_v0_7 = cameraGetMode();
        switch (temp_v0_7) {                        /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            if (D_80140214 != 0) {
                arg0->fC = (f32) 180.0f;
            }
            if (arg0->f4 < -1897.0f) {
                arg0->f4 = (f32) -1897.0f;
            }
            if (13535.0f < arg0->f4) {
                arg0->f4 = (f32) 13535.0f;
            }
            break;
        case 33:                                    /* switch 1 */
            if (arg0->fC < -3000.0f) {
                arg0->fC = (f32) -3000.0f;
            }
            break;
        }
        D_801401E4 = arg0->fDC;
        var_s0_2 = animStepKeys(arg0);
        if ((f64) arg0->f50 < -3500.0) {
            func_80043328(arg0, 0x10, 0x100);
        }
        temp_v0_8 = arg0->fD0;
        switch (temp_v0_8) {
        case 37:
            if (var_s0_2 != 0) {
                func_80043328(arg0, 0x24, 0x100);
            }
            break;
        case 45:
            if ((var_s0_2 != 0) && (arg0->f50 <= 0.0f)) {
                func_80043328(arg0, 0x2B, 0x100);
            }
            break;
        case 32:
            if ((var_s0_2 != 0) && (arg0->f90 == 0)) {
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 44:
            if (var_s0_2 != 0) {
                func_8003A9A8(arg0, var_s0_2);
                if (D_800B3838 != 0) {
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0x19);
                    func_8002D124();
                    D_800B3838 = 0;
                } else {
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0x34);
                    func_8002D124();
                }
            }
            break;
        case 28:                                    /* switch 2 */
            if ((8.0f <= arg0->fDC) && (D_800B4CE4 == NULL) && (D_8014020C <= 0)) {
                D_8014020C = 0x64;
                arg0->fB8 = 2;
                arg0->fE4 = func_80023E3C(2);
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x7E);
                func_8002D124();
                temp_v0_9 = func_8002E374(0x7C);
                M2C_FIELD(temp_v0_9, s32 *, 0x68) = (s32) (arg0->f68 + 1);
                M2C_FIELD(temp_v0_9, s32 *, 0x14) = 0x2000;
                D_800B4CE4 = temp_v0_9;
                M2C_FIELD(temp_v0_9, s32 *, 0x10) = (s32) arg0->f10;
                func_8002D3E4(temp_v0_9, 0x5DC);
                temp_v0_9 = D_800B4CE4;
                M2C_FIELD(temp_v0_9, M2C_UNK **, 0x9C) = &func_800142A0;
                M2C_FIELD(temp_v0_9, s32 *, 0x64) = 0xC8;
                M2C_FIELD(temp_v0_9, s32 *, 0) = 0x12C;
                M2C_FIELD(temp_v0_9, f32 *, 4) = (f32) arg0->f4;
                M2C_FIELD(temp_v0_9, f32 *, 8) = (f32) (arg0->f8 + 300.0f);
                M2C_FIELD(temp_v0_9, f32 *, 0xC) = (f32) arg0->fC;
                syncActorPrevPos(temp_v0_9);
            }
            /* fallthrough */
        case 29:
            if (var_s0_2 != 0) {
                func_8003A9A8(arg0, var_s0_2);
                M2C_FIELD(arg0, M2C_UNK **, 0x98) = &func_800414D0;
            }
            break;
        case 26:                                    /* switch 2 */
        case 27:                                    /* switch 2 */
            if (var_s0_2 == 0) {
                temp_fv1_6 = arg0->fDC;
                if ((7.0f < temp_fv1_6) && (temp_fv1_6 < 24.0f)) {
                    arg0->f74 = 0;
                }
                if (var_s0_2 != 0) {
                    goto block_181;
                }
            } else {
block_181:
                if (D_800B3838 != 0) {
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0x19);
                    func_8002D124();
                    D_800B3838 = 0;
                } else {
                    sendCommand(0xC, 0x80);
                    sendCommand(8, 0x34);
                    func_8002D124();
                }
                func_8003A9A8(arg0, var_s0_2);
                arg0->f74 = 1;
            }
            break;
        case 13:
        case 19:
            if (gPadPressed[arg0->fBC] & 0x4000) {
                D_8014023C = 1;
            }
            if ((D_8014023C != 0) && (temp_ft0 = (f64) arg0->fDC, (9.0 < temp_ft0)) && (temp_ft0 <= ((f64) gCamSpeedScale + 9.0 + 1.0))) {
                func_8002AD4C();
                actorSetAnim(arg0, 0xE, 0x100);
                arg0->f88 = 0;
                arg0->f74 = 0;
                D_8014023C = 0;
                arg0->f78 ^= 1;
                break;
            }
            goto block_202;
        case 14:
            if (gPadPressed[arg0->fBC] & 0x4000) {
                D_8014023C = 1;
            }
            if (D_8014023C != 0) {
                temp_ft0_2 = (f64) arg0->fDC;
                if ((9.0 < temp_ft0_2) && (temp_ft0_2 <= ((f64) gCamSpeedScale + 1.0 + 9.0))) {
                    actorSetAnim(arg0, 0xF, 0x100);
                    arg0->f88 = 0;
                    arg0->f74 = 0;
                    D_8014023C = 0;
                    arg0->f78 ^= 1;
                    break;
                }
            }
            goto block_202;
        case 15:
            temp_fv1_7 = (f64) arg0->fDC;
            if ((4.0 < temp_fv1_7) && (temp_fv1_7 <= 6.0)) {
                func_8002AD4C();
            }
            goto block_202;
        case 21:
            arg0->f74 = 0;
        case 16:
        case 18:
        case 30:
        case 35:
        case 38:
        case 39:
block_202:
            if (var_s0_2 != 0) {
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 17:
            if (var_s0_2 != 0) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x35);
                func_8002D124();
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 5:                                     /* switch 2 */
        case 12:                                    /* switch 2 */
            if (gPadPressed[arg0->fBC] & 0x2000) {
                func_80043328(arg0, 0x2A, 0x100);
                D_800B4CFC = 0;
                arg0->f7C = 9;
                arg0->f70 = 0x10000;
            }
            if ((gPadPressed[arg0->fBC] & 0x4000) && (D_80140200 >= 0x191)) {
                D_80140200 = (D_80140200 * 0x96) / 100;
                func_80043328(arg0, 0x11, 0x100);
            }
            break;
        case 1:
        case 6:
block_211:
            if ((func_8003AB30(arg0) == 0) && (func_8003CA30(arg0) == 0)) {
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 36:
            if (!(D_80107040[arg0->fBC] & 0x10)) {
                func_80043328(arg0, 0x26, 0x100);
                break;
            }
            if (D_80140200 > 0) {
                func_80043328(arg0, 0xB, 0x100);
            }
            break;
        case 11:                                    /* switch 2 */
            var_s2 = 1;
            if (!(D_80107040[arg0->fBC] & 0x10)) {
                func_80043328(arg0, 0x26, 0x100);
                var_s2 = 0;
                sendCommand(0x20, 0);
            } else if ((D_80140200 <= 0) && (var_s0_2 != 0)) {
                func_80043328(arg0, 0x24, 0x100);
                var_s2 = 0;
            }
            temp_fv1_8 = (f64) arg0->fDC;
            if (2.0 <= temp_fv1_8) {
                if (temp_fv1_8 <= ((f64) gCamSpeedScale + 2.0)) {
                    if ((var_s2 != 0) && (arg0->fCC == 0)) {
                        sendCommand(0xC, 0x80);
                        sendCommand(8, 3);
                        arg0->fCC = 1;
                    }
                } else {
                    arg0->fCC = 0;
                }
            } else {
                arg0->fCC = 0;
            }
            break;
        case 2:                                     /* switch 2 */
        case 3:                                     /* switch 2 */
            temp_fv1_9 = (f64) D_801401E4;
            if ((((temp_fv1_9 <= 1.0) || ((20.0 <= temp_fv1_9) && (var_s0_2 != 0))) && (1.0 <= (f64) arg0->fDC)) || (((f64) D_801401E4 <= 12.0) && (12.0 <= (f64) arg0->fDC))) {
                func_8002ABCC();
            }
            goto block_211;
        case 4:                                     /* switch 2 */
        case 47:                                    /* switch 2 */
            temp_fv1_10 = (f64) D_801401E4;
            if ((((temp_fv1_10 <= 1.0) || ((20.0 <= temp_fv1_10) && (var_s0_2 != 0))) && (1.0 <= (f64) arg0->fDC)) || (((f64) D_801401E4 <= 11.0) && (11.0 <= (f64) arg0->fDC))) {
                func_8002ABCC();
            }
            if (gPadPressed[arg0->fBC] & 0x2000) {
                arg0->f74 = 0;
                func_80043328(arg0, 0x12, 0x100);
                func_80012718(arg0);
                func_80012718(arg0);
                func_80012718(arg0);
                func_80012718(arg0);
                func_8002ACFC();
            } else if (func_8003AB30(arg0) == 0) {
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 10:
            if (!(D_80107040[0] & 0x4000)) {
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 20:
            if (var_s0_2 != 0) {
                arg0->f10 = (s32) (arg0->f10 + 0x8000);
                func_8003A9A8(arg0, var_s0_2);
            }
            break;
        case 22:
            if (var_s0_2 != 0) {
                func_8003A9A8(arg0, var_s0_2);
            }
        default:
            func_8003A9A8(arg0, var_s0_2);
            break;
        case 42:
        case 43:
            break;
        }
        if (func_8000FAC4(arg0) == 0) {
            var_s0_2 = func_8003C5D8(arg0);
            arg0->f90 = var_s0_2;
            if (var_s0_2 != 0) {
                handleActorHit(arg0, D_8014022C, 0);
            }
            if (((f64) D_80140140 != -1000000.0) && (arg0->f8 < (f32) (D_80140140 - 0xC8))) {
                sendCommand(0xC, 0x80);
                sendCommand(8, 0x19);
                func_8002D124();
                arg0->f8 = (f32) (D_80140140 - 0xC8);
                func_80043328(arg0, 0x17, 0x100);
                M2C_FIELD(arg0, M2C_UNK **, 0x9C) = &func_8003C2A0;
            }
        } else {
            arg0->f90 = 1;
            M2C_FIELD(&D_800B4C1C, s32 *, 0) = 0;
            M2C_FIELD(&D_800B4C1C, s32 *, 8) = 0;
            M2C_FIELD(&D_800B4C1C, f32 *, 4) = (f32) 1.0f;
        }
    }
}
