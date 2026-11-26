typedef struct Hdr { u8 p0[0xBC]; s32 fBC; } Hdr;
typedef struct Obj {
    u8 p0[4]; f32 f4; f32 f8; f32 fC; s32 f10; s32 f14; s32 f18; u8 p1[0x54]; s32 f70; s32 f74; u8 p2[4]; s32 f7C;
} Obj;
extern Obj *func_80017DEC(s32);
extern f32 approachF32(f32, f32, f32);
extern void syncActorPrevPos(Obj *);
extern void func_8006F944();
extern void updateCameraView(Obj *);
extern Hdr *D_800B3964;
extern s32 D_800B8200;
extern s32 gCamSpeedScale;
extern s32 D_80107040;

void func_8006FD58(Obj *arg0) {
    f32 var_fs0;
    s32 temp_a0;
    s32 var_s2;
    Obj *temp_s0;

    temp_a0 = D_800B3964->fBC;
    var_s2 = 0;
    if (temp_a0 != 0) {
        temp_s0 = func_80017DEC(temp_a0);
        if (arg0->f70 != 0) {
            if (temp_s0 != NULL) {
                arg0->f4 = temp_s0->f4;
                arg0->f8 = temp_s0->f8;
                arg0->fC = temp_s0->fC;
                var_s2 = 1;
                if (D_800B3964->fBC > 0) {
                    arg0->f70 = 0;
                }
            }
        } else {
            var_fs0 = 50.0f;
            if (D_80107040 & 0x2030) {
                var_fs0 = 187.5f;
            }
            var_fs0 = var_fs0 * (f32) gCamSpeedScale;
            if ((temp_s0 != NULL) && (D_800B8200 == 0)) {
                arg0->f4 = approachF32(temp_s0->f4, arg0->f4, var_fs0);
                arg0->fC = approachF32(temp_s0->fC, arg0->fC, var_fs0);
            }
        }
        if ((arg0->f7C == 0) && (temp_s0 != NULL) && (arg0->f4 == temp_s0->f4) && (arg0->fC == temp_s0->fC)) {
            arg0->f7C = 1;
            var_s2 = 1;
            func_8006F944();
        }
        if (var_s2 != 0) {
            arg0->f10 = temp_s0->f10;
            arg0->f14 = temp_s0->f14;
            arg0->f18 = temp_s0->f18;
            syncActorPrevPos(arg0);
            arg0->f74 = 0;
        }
        updateCameraView(arg0);
    }
}
