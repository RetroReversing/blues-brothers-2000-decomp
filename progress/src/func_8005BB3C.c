s16 coss(u16);
s16 sins(u16);
void *findActor(s32, void *);
void func_8002A360(s32, s32);
void func_80034FEC(void *, s32 *);
s32 func_80043248(void *);
void debugPrintf(char *);
extern char D_800085EC[];

typedef struct ObjK {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    s16 f10;
    u16 yaw;
    u8 pad14[0x5C - 0x14];
    s32 f5C;
    u8 pad60[0x70 - 0x60];
    s32 f70;
    u8 pad74[0x7C - 0x74];
    s32 f7C;
    s32 f80;
    u8 pad84[0xA0 - 0x84];
    void (*fA0)(struct ObjK *);
    u8 padA4[0xDC - 0xA4];
    f32 fDC;
} ObjK;

extern ObjK *gCameraRig;
extern ObjK *D_800B3964;

void func_8005BB3C(ObjK *arg0) {
    s32 pos[3];
    ObjK *t;
    ObjK *cam;

    if (arg0->f7C == 0) {
        D_800B3964->f70 = 1;
        t = findActor(0x101F, NULL);
        if (t == NULL) {
            arg0->fA0(arg0);
            return;
        }
        *(s32 *)&arg0->f10 = *(s32 *)&t->f10;
        arg0->x = t->x + (f32)((sins(arg0->yaw) * 15) >> 11);
        arg0->z = t->z + (f32)((coss(arg0->yaw) * 15) >> 11);
        arg0->y = t->y;
        arg0->f7C = 1;
        cam = findActor(0x11F, NULL);
        if (cam == NULL) {
            debugPrintf(D_800085EC);
        }
        gCameraRig->x = cam->x;
        gCameraRig->y = cam->y;
        gCameraRig->z = cam->z;
        pos[0] = arg0->x;
        pos[1] = arg0->y + 225.0f;
        pos[2] = arg0->z;
        func_80034FEC(gCameraRig, pos);
    }
    t = findActor(0x101F, NULL);
    if (t != NULL) {
        *(s32 *)&arg0->f10 = *(s32 *)&t->f10;
        arg0->x = t->x + (f32)((sins(arg0->yaw) * 15) >> 11);
        arg0->z = t->z + (f32)((coss(arg0->yaw) * 15) >> 11);
        arg0->y = t->y;
    }
    func_80043248(arg0);
    if (arg0->fDC > 50.0f) {
        if (arg0->f80 == 0) {
            func_8002A360(0xC, 0x80);
            func_8002A360(8, 0x56);
            arg0->f80 = 1;
        }
        arg0->f5C -= 15;
        if (arg0->f5C < 15) {
            arg0->fA0(arg0);
        }
    }
}
