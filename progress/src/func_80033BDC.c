s16 coss(s32);
s16 sins(s32);
s32 cameraGetMode(void);
void func_80034F1C(void *);
extern void *gCameraRig;
extern s32 cameraDistTable[];
extern void *gCameraTarget;
extern s32 gCameraOffsetZ;
extern s32 gCameraOffsetX;
extern s32 D_8014002C;
extern s32 D_80140030;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

void func_80033BDC(s32 arg0) {
    void *p;
    f32 t;
    s32 a1, a2;
    void *q;

    D_80140030 = 0;
    p = gCameraRig;
    D_8014002C = 0;
    F(p, s32, 0x6C) = arg0;
    F(p, s32, 0xC0) = 0;
    if (cameraGetMode() == 0x36 || cameraGetMode() == 0x23) {
        cameraDistTable[0] = 800;
        cameraDistTable[2] = 1000;
        cameraDistTable[4] = 1200;
        cameraDistTable[6] = 1000;
        cameraDistTable[8] = 800;
    } else {
        cameraDistTable[0] = 800;
        cameraDistTable[2] = 1200;
        cameraDistTable[4] = 1600;
        cameraDistTable[6] = 1200;
        cameraDistTable[8] = 800;
    }
    func_80034F1C(p);
    a1 = F(p, s32, 0x10);
    a2 = F(p, s32, 0x80);
    q = gCameraTarget;
    F(p, s32, 0x78) = F(p, s32, 0x7C);
    F(p, s32, 0x74) = a1;
    F(p, s32, 0x14) = a2;
    F(p, f32, 0x40) = F(q, f32, 4);
    F(p, f32, 0x44) = F(q, f32, 8);
    F(p, f32, 0x48) = F(q, f32, 0xC);
    F(p, f32, 4) = F(p, f32, 0x40) + (f32)((((-F(p, s32, 0x78) * sins(F(p, u16, 0x12))) >> 15) * coss(F(p, u16, 0x16))) >> 15);
    F(p, f32, 0xC) = F(p, f32, 0x48) + (f32)((((-F(p, s32, 0x78) * coss(F(p, u16, 0x12))) >> 15) * coss(F(p, u16, 0x16))) >> 15);
    t = F(p, f32, 0x44) + (f32)((-F(p, s32, 0x78) * sins(F(p, u16, 0x16))) >> 15) + 200.0f;
    gCameraOffsetX = 0;
    F(p, f32, 8) = t;
    gCameraOffsetZ = 0;
}
