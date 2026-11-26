typedef struct { s32 m[4][4]; } MtxW;
typedef struct { u8 data[0x20]; } LookAtW;
typedef struct { u8 data[0x10]; } HiliteW;
typedef struct { u32 w0, w1; } GfxW;

typedef struct {
    MtxW proj[2];
    MtxW view[2];
    u8 pad100[0x1C0 - 0x100];
    LookAtW lookAt[2];
    HiliteW hilite[2];
    LookAtW reflLookAt[2];
    MtxW refl[2];
} DynW;

typedef struct {
    u8 pad0[8];
    s8 x;
    s8 y;
    s8 z;
    u8 padB[5];
} LightDirW;

extern f32 D_800B9C80;
extern s32 D_800B9EC0;
extern DynW *D_80178238;
extern u16 D_801771C4;
extern LightDirW D_800B9F00[];
extern s32 D_800B9E88;
extern s32 D_80179A30;
extern s32 gTextWaveTime;
extern f32 D_800B9EAC;
extern f32 D_800B9EB0;
extern f32 D_800B9EB4;
extern GfxW *D_80177E18;

void guPerspective(MtxW *m, u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
void guLookAtHilite(MtxW *m, LookAtW *l, HiliteW *h, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt,
                    f32 xUp, f32 yUp, f32 zUp, f32 xl1, f32 yl1, f32 zl1, f32 xl2, f32 yl2, f32 zl2, s32 twidth,
                    s32 theight);
void guLookAtReflectMtx(MtxW *m, LookAtW *l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp,
                        f32 yUp, f32 zUp);
f32 __cosf(f32);
f32 sinApprox(f32);

/* Builds the projection, view and reflection matrices for the current view, then queues the matching display-list commands. */
void setupCameraViewMatrices(void) {
    s32 lightX;
    s32 lightY;
    s32 lightZ;
    f32 waveAngle;
    u8 unused[0x58];

    lightX = D_800B9F00[D_800B9EC0].x;
    lightY = D_800B9F00[D_800B9EC0].y;
    lightZ = D_800B9F00[D_800B9EC0].z;
    guPerspective(&D_80178238->proj[D_800B9EC0], &D_801771C4, D_800B9C80, -1.3333334f, D_800B9E88, 25000.0f, 1.0f);
    guLookAtHilite(&D_80178238->view[D_800B9EC0], &D_80178238->lookAt[D_800B9EC0], &D_80178238->hilite[D_800B9EC0],
                   0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 100.0f, 0.0f, 1.0f, 0.0f, lightX, lightY, lightZ, 100.0f, 0.0f, 0.0f, 32, 32);
    waveAngle = 0.0061359182f;
    if (D_80179A30 != 0) {
        D_800B9EB4 = 0.0f;
        D_800B9EB0 = __cosf(gTextWaveTime * waveAngle);
        D_800B9EAC = sinApprox(gTextWaveTime * waveAngle);
    }
    guLookAtReflectMtx(&D_80178238->refl[D_800B9EC0], &D_80178238->reflLookAt[D_800B9EC0], 0.0f, 0.0f, 0.0f, 0.0f,
                       0.0f, 100.0f, D_800B9EAC, D_800B9EB0, D_800B9EB4);
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xDC08000A;
        g->w1 = (u32)&D_80178238->reflLookAt[D_800B9EC0];
    }
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xDC08030A;
        g->w1 = (u32)&D_80178238->reflLookAt[D_800B9EC0] + 0x10;
    }
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xDB0E0000;
        g->w1 = D_801771C4;
    }
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xDA380007;
        g->w1 = (u32)&D_80178238->proj[D_800B9EC0] - 0x80000000;
    }
    {
        GfxW *g = D_80177E18++;
        g->w0 = 0xDA380005;
        g->w1 = (u32)&D_80178238->view[D_800B9EC0] - 0x80000000;
    }
}
