s32 func_80013654(void *);
s32 func_80013784(void *);
s32 func_800137E0(void *);
s32 func_800137F8(void *);
f32 getCameraTargetDist(void *, f32, s32);
void handleActorHit(void *, f32, s32);
s16 *func_800851D8(void);
extern void *gCameraTarget[];
extern f32 D_80008908;
extern f32 D_8000890C;

#define F(p, t, o) (*(t *)((char *)(p) + (o)))

s32 func_800609F8(void *arg0) {
    f32 r;
    f32 y;
    f32 top;
    s16 *v;
    s32 h;
    f32 d;
    s32 t;
    s32 res;
    s32 u;
    s32 x;
    s32 w;

    top = F(arg0, f32, 8);
    v = func_800851D8();
    x = v[1];
    y = top;
    top += v[0];
    if (F(gCameraTarget[0], s32, 0xD0) == 0xB) {
        x += 0x5F;
    }
    h = x;
    t = h + 0x32;
    if (F(arg0, s32, 0xC0) & 0x40) {
ret1:
        return 1;
    }
    r = t;
    F(arg0, s32, 0xC0) = 0;
    d = getCameraTargetDist(arg0, r, 0);
    if (d < D_80008908) {
        d = D_80008908;
    }
    if (!(d < r)) {
        return 0;
    }
    if (top < F(gCameraTarget[0], f32, 8)) {
        return 0;
    }
    if (F(gCameraTarget[0], f32, 8) + D_8000890C < y) {
        return 0;
    }
    if (top <= F(gCameraTarget[0], f32, 0x44) && F(gCameraTarget[0], f32, 8) < top) {
        handleActorHit(gCameraTarget[0], top, 1);
        if (F(gCameraTarget[0], s32, 0xD0) != 1) {
            F(arg0, s32, 0xC0) |= 4;
        }
        return 2;
    }
    if (d < (f32)h) {
        void *p = gCameraTarget[0];
        f32 k = (f32)h - d;
        f32 dx = F(arg0, f32, 4) - F(p, f32, 4);
        f32 dz = F(arg0, f32, 0xC) - F(p, f32, 0xC);
        F(p, f32, 4) -= dx * k / d;
        F(p, f32, 0xC) -= dz * k / d;
        u = F(arg0, s32, 0xC0);
        F(arg0, s32, 0xC0) = u | 1;
        if (F(p, s32, 0xB8) == 5) {
            F(arg0, s32, 0xC0) = u | 0x103;
        }
    }
    res = func_80013654(gCameraTarget[0]);
    if (res != 0) {
        w = F(arg0, s32, 0xC0);
        F(arg0, s32, 0xC0) = w | 2;
        if (res == 2) {
            F(arg0, s32, 0xC0) = w | 0x82;
        }
    }
    if (func_800137E0(gCameraTarget[0]) != 0) {
        F(arg0, s32, 0xC0) |= 8;
    }
    if (func_80013784(arg0) != 0) {
        handleActorHit(gCameraTarget[0], top, 1);
        F(arg0, s32, 0xC0) |= 0x20;
    }
    if (func_800137F8(gCameraTarget[0]) != 0) {
        F(arg0, s32, 0xC0) |= 0x12;
    }
    goto ret1;
}
