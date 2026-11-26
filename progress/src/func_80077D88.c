typedef struct {
    f32 x, y, z, w;
} Pos77D88;

typedef struct {
    u8 pad_0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad_10[0x80];
    s32 f90;
} Obj77D88;

f32 getCameraTargetDist(Obj77D88 *, f32, s32);
extern Obj77D88 *gCameraTarget;

s32 func_80077D88(Obj77D88 *arg0) {
    f32 d;
    f32 k;
    Obj77D88 *cam;

    d = getCameraTargetDist(arg0, 650.0f, 0);
    arg0->f90 = d;
    if (d == 0.0f) {
        return 0;
    }
    if (480.0f <= d) {
        return 0;
    }
    if (d < 470.0f) {
        cam = gCameraTarget;
        k = 470.0f - d;
        {
            f32 dx = arg0->x - cam->x;
            f32 dz = arg0->z - cam->z;
            cam->x -= dx * k / d;
            cam->z -= dz * k / d;
        }
    }
    return 0;
}
