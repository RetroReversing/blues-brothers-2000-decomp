typedef struct O6FEEC {
    f32 f0;
    f32 f4;
    f32 f8;
    u8 padC[0x44 - 0xC];
    f32 f44;
    u8 pad48[0x74 - 0x48];
    s32 f74;
    s32 f78;
    s32 f7C;
    u8 pad80[0x9C - 0x80];
    void (*f9C)(void);
    u8 padA0[0xBC - 0xA0];
    s32 fBC;
} O6FEEC;
void updateCameraView(O6FEEC *);
f32 approachF32(f32, f32, f32);
void func_8006F944(void);
extern O6FEEC *D_800B3964;
extern f32 D_800B82B0[];
extern s32 gCamSpeedScale;
extern s32 D_80107040;
void func_8006FD58(void);

void func_8006FEEC(O6FEEC *arg0) {
    f32 speed;
    f32 t;
    f32 r;

    speed = 40.0f;
    if (D_80107040 & 0x2030) {
        speed = 150.0f;
    }
    speed *= gCamSpeedScale;
    switch (arg0->f74) {
    case 0:
        arg0->f74 = 1;
    case 1:
        t = D_800B82B0[D_800B3964->fBC - 1];
        r = approachF32(t, arg0->f8, speed);
        arg0->f8 = r;
        if (r == t) {
            arg0->f74++;
            func_8006F944();
        }
        break;
    case 3:
        r = approachF32(arg0->f44, arg0->f8, speed);
        arg0->f8 = r;
        if (r == arg0->f44) {
            arg0->f74 = 0;
            arg0->f7C = 0;
            arg0->f9C = func_8006FD58;
        }
        break;
    }
    updateCameraView(arg0);
}
