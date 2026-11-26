void syncActorPrevPos(void *);
s32 tickActorTimer(void *);
void func_80023078(void);
void func_80033DC4(void *);
void func_800340B4(void *);
void func_80036DB4(void);
void func_80036F44(void);
u8 *func_80055D10(s32);
void func_80074F74(void);
void func_8007ABE0(void);
void updateCameraSplineTrigger(void);
f32 func_800812B4(s32, void *, void *, s32);
s32 func_80081990(void *, s32, f32);
extern f32 D_800094B4;
extern f32 D_800094B8;
extern f64 D_800094C0;
extern u8 *gCameraRig[];
extern u8 *gCameraTarget[];
extern s32 D_800B9560[];

void func_8007ACD4(u8 *arg0) {
    u8 *g;
    u8 *src;
    u8 *obj;
    f32 d;
    f32 t;

    if (*(f32 *)(arg0 + 0x104) == D_800094B4) {
        g = gCameraRig[0];
        *(void **)(g + 0x9C) = func_800340B4;
        syncActorPrevPos(g);
        *(void **)(arg0 + 0x9C) = updateCameraSplineTrigger;
        *(void **)(arg0 + 0x98) = (u8 *)func_80023078 + 8;
    }
    if (*(u8 **)(arg0 + 0xA8) == NULL) {
        g = gCameraRig[0];
        *(s32 *)(arg0 + 0xC0) = 0;
        *(f32 *)(arg0 + 0xDC) = 0.0f;
        *(s32 *)(arg0 + 0xB0) = 0;
        *(s32 *)(g + 0xC0) = 0;
        if (*(void **)(g + 0x9C) != func_80036DB4) {
            *(void **)(g + 0x9C) = func_80036F44;
        }
        if (tickActorTimer(arg0) != 0) {
            src = *(u8 **)(arg0 + 0x6C);
            obj = func_80055D10(0);
            *(void **)(obj + 0x9C) = func_8007ABE0;
            *(f32 *)(obj + 4) = *(f32 *)(src + 4);
            *(f32 *)(obj + 8) = *(f32 *)(src + 8);
            *(f32 *)(obj + 0xC) = *(f32 *)(src + 0xC);
            *(s32 **)(obj + 0xC8) = D_800B9560;
            *(u8 **)(arg0 + 0xA8) = obj;
            *(s32 *)(arg0 + 0xC0) = 0;
        }
    } else {
        *(s32 *)(arg0 + 0x64) = 200;
    }
    g = gCameraRig[0];
    if (*(void **)(g + 0x9C) != func_80036DB4) {
        *(void **)(g + 0x9C) = func_80036DB4;
    }
    d = func_800812B4(1, gCameraTarget[0] + 4, arg0 + 0x104, 0);
    t = d + D_800094B8;
    *(f32 *)(arg0 + 0x100) = d;
    *(f32 *)(arg0 + 0xDC) = t;
    if (t < 0.0) {
        *(f32 *)(arg0 + 0xDC) = 0.0f;
    }
    if (*(f32 *)(arg0 + 0xDC) > D_800094C0) {
        *(s32 *)(arg0 + 0xC0) = 1;
    }
    if (func_80081990(gCameraRig[0] + 4, 1, *(f32 *)(arg0 + 0xDC)) != 0) {
        g = gCameraRig[0];
        *(void **)(g + 0x9C) = func_800340B4;
        syncActorPrevPos(g);
        func_80033DC4(gCameraRig[0]);
        func_800340B4(gCameraRig[0]);
        *(void **)(arg0 + 0x9C) = func_80074F74;
    }
}
