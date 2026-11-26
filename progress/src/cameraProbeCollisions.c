typedef struct Obj {
    char pad0[4];
    f32 x;
    f32 y;
    f32 z;
    s32 f10;
    s32 f14;
} Obj;
s32 func_8002DAE0(s32 *, s32 *, f32);
s32 func_8002DB6C(s32 *, s32 *, f32);
s32 mtxIdentity3();
s32 mtxTransformVec3();
s32 raycastCollision();
s32 expandBoundsToSegment();
s32 initBoundsToSegment();
s32 collectCollisionCells();
extern f32 D_800B4B48[][3];
extern f32 cameraRayDirs[][3];
extern f32 D_800B4BC0[][3];

/* Casts four probe rays from the object's rotated direction set (mode picks the table) and returns a bitmask of the rays that hit collision. */
s32 cameraProbeCollisions(Obj *obj, s32 mode) {
    f32 spare[4];
    f32 pos[4];
    f32 m1[10];
    f32 m2[10];
    f32 w[5][3];
    u8 bb0[0x10];
    u8 bb1[0x30];
    f32 a, b;
    s32 res;
    s32 bit;
    s32 i;
    f32 *p;

    res = 0;
    a = (f32) obj->f14;
    b = (f32) obj->f10;
    a = a * 0.00009587379760742188;
    b = b * 0.00009587379760742188;
    pos[0] = obj->x;
    pos[1] = obj->y;
    pos[2] = obj->z;
    mtxIdentity3(m1);
    mtxIdentity3(m2);
    func_8002DB6C(m1, m2, b);
    func_8002DAE0(m2, m1, -a);
    bit = 1;
    for (i = 1; i < 5; i++) {
        if (mode == 2) {
            mtxTransformVec3(w[i], m2, D_800B4BC0[i]);
        } else if (mode == 1) {
            mtxTransformVec3(w[i], m2, D_800B4B48[i]);
        } else {
            mtxTransformVec3(w[i], m2, cameraRayDirs[i]);
        }
        w[i][0] += pos[0];
        w[i][1] += pos[1];
        w[i][2] += pos[2];
        if (i == 1) {
            initBoundsToSegment(bb0, bb1, w[i], pos);
        } else {
            expandBoundsToSegment(bb0, bb1, w[i], pos);
        }
    }
    collectCollisionCells(bb0, bb1, 3);
    for (i = 1; i < 5; i++) {
        if (mode == 2) {
            mtxTransformVec3(w[i], m2, D_800B4BC0[i]);
        } else if (mode == 1) {
            mtxTransformVec3(w[i], m2, D_800B4B48[i]);
        } else {
            mtxTransformVec3(w[i], m2, cameraRayDirs[i]);
        }
        w[i][0] += pos[0];
        w[i][1] += pos[1];
        w[i][2] += pos[2];
        if (raycastCollision(pos, w[i], 0)) {
            res |= bit;
        }
        bit <<= 1;
    }
    return res;
}
