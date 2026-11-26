typedef struct {
    s32 pad0;
    f32 x;
    f32 y;
    f32 z;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x60];
    s32 unk78;
} Obj;

void mtxIdentity3(f32 m[3][3]);
void func_8002DB6C(f32 a[3][3], f32 b[3][3], f32 angle);
void func_8002DAE0(f32 a[3][3], f32 b[3][3], f32 angle);
void mtxTransformVec3(f32 *out, f32 m[3][3], f32 *v);
f32 __cosf(f32);
f32 sinApprox(f32);
void initBoundsToSegment(f32 *a, f32 *b, f32 *p, f32 *c);
void expandBoundsToSegment(f32 *a, f32 *b, f32 *p, f32 *c);
void collectCollisionCells(f32 *a, f32 *b, s32 n);
s32 raycastCollision(f32 *c, f32 *p, s32 n);
extern Obj *gCameraTarget;
extern f32 cameraRayDirs[][3];

s32 func_80036780(Obj *arg0) {
    f32 c[8];
    f32 pos[3];
    f32 m1[3][3];
    f32 m2[3][3];
    f32 pts[5][3];
    f32 lo[4];
    f32 hi[4];
    f32 pitch;
    f32 yaw;
    f32 r;
    f32 t;
    s32 i;
    s32 bit;
    s32 res;

    yaw = (f32)arg0->unk14;
    pitch = (f32)arg0->unk10;
    yaw = yaw * 9.587379760742188e-05;
    r = (f32)arg0->unk78;
    pos[0] = arg0->x;
    pos[1] = arg0->y;
    pos[2] = arg0->z;
    pitch = pitch * 9.587379760742188e-05;
    c[0] = gCameraTarget->x;
    c[1] = gCameraTarget->y + 200.0f;
    c[2] = gCameraTarget->z;
    mtxIdentity3(m1);
    mtxIdentity3(m2);
    func_8002DB6C(m1, m2, pitch);
    func_8002DAE0(m2, m1, -yaw);
    t = r * __cosf(yaw);
    t *= sinApprox(pitch);
    pos[0] = c[0] - t;
    pos[1] = c[1] - r * sinApprox(yaw);
    res = 0;
    r = r * __cosf(yaw);
    bit = 1;
    r *= __cosf(pitch);
    pos[2] = c[2] - r;
    for (i = 1; i < 5; i++) {
        mtxTransformVec3(pts[i], m2, cameraRayDirs[i]);
        pts[i][0] += pos[0];
        pts[i][1] += pos[1];
        pts[i][2] += pos[2];
        if (i == 1) {
            initBoundsToSegment(lo, hi, pts[1], c);
        } else {
            expandBoundsToSegment(lo, hi, pts[i], c);
        }
    }
    collectCollisionCells(lo, hi, 3);
    for (i = 1; i < 5; i++) {
        if (raycastCollision(c, pts[i], 0) != 0) {
            res |= bit;
        }
        bit <<= 1;
    }
    return res;
}
