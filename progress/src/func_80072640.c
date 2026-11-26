typedef struct ObjK {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x6C - 0x10];
    s32 f6C;
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7C;
    u8 pad80[0x9C - 0x80];
    void *f9C;
} ObjK;

void initSpline(s32, s32);
void func_800789A8(ObjK *);
void func_8007591C(s32, s32);
void func_80034F1C(ObjK *);
void func_80036DB4(void);
void func_800340B4(void);
extern s32 gSplinePointCount[];
extern s32 D_800B3970;
extern s32 D_800B3974;
extern s32 D_800B3978;
extern s32 D_800BD0FC;
extern ObjK *gCameraTarget;
extern ObjK *gCameraRig;

void func_80072640(ObjK *arg0) {
    s32 i;

    if (arg0->f7C == 0) {
        arg0->f7C = 1;
        D_800B3970 = 150;
        D_800B3974 = 182;
        D_800B3978 = 198;
        arg0->f6C = 0;
        for (i = 4; i < 30; i++) {
            if (gSplinePointCount[i] != 0) {
                initSpline(i, 0);
                if (i >= 5) {
                    arg0->f70 = i;
                    func_800789A8(arg0);
                }
            }
        }
    }
    if (D_800BD0FC == 3) {
        func_8007591C(-0x1518, -0x1324);
        if (-3000.0f < gCameraTarget->y) {
            goto block;
        }
        arg0->f6C = 0;
    } else {
        func_8007591C(-0x5DC, 0x898);
        if (1000.0f < gCameraTarget->y) {
block:
            if (arg0->f6C == 0) {
                arg0->f6C = 1;
                gCameraRig->f6C = 2;
                func_80034F1C(gCameraRig);
            }
        } else {
            arg0->f6C = 0;
        }
    }
    if (gCameraRig->f9C == func_80036DB4 && -4900.0f < gCameraTarget->y) {
        gCameraRig->f9C = func_800340B4;
    }
}
