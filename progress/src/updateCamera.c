typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    u8 pad0[4];
    Vec3f pos;
    s32 angle;
} Cam;

f32 __cosf(f32);
void updateCameraView(void *);
f32 func_8002DD60(f32);
void func_80036FB8(void *, s32);
void func_8004BDCC(f32 (*)[4], Vec3f *, Vec3f *);
void func_8004DDDC(f32 *pos, f32 *target, f32 *vel, f32 accel, f32 scale);
void func_8004DE9C(void *, f32 (*)[4]);
void func_8004E134(s32, f32, Vec3f *);
f32 func_8004E388(s32, f32, f32);
f32 sqrtf(f32);
extern Vec3f D_800B7618;
extern Vec3f D_800B7624;
extern Vec3f D_800B7630;
extern Vec3f D_800B763C;
extern s32 D_800B764C;
extern Cam *gCameraTarget;
extern s32 D_80140780;

/* Updates the follow camera: positions it behind the player along the track and eases toward the new view. */ void updateCamera(void *arg0)
{
    f32 mtx[4][4];
    Vec3f base;
    Vec3f at;
    Vec3f eye;
    Vec3f p0;
    Vec3f p1;
    Vec3f dir;
    f32 z;
    f32 t;
    f32 dirLen;
    f32 dirLenSq;
    f32 dxFromPath;

    if (gCameraTarget != NULL) {
        func_8004E134(D_80140780, 0.0f, &base);
        if (gCameraTarget->pos.z < base.z) {
            gCameraTarget->pos.z = base.z;
        }
        z = gCameraTarget->pos.z;
        if (156617.0f <= z) {
            z = 156617.0f;
        }
        t = func_8004E388(D_80140780, 0.0f, (z + 250.0) - base.z);
        func_8004E134(D_80140780, t, &p0);
        func_8004E134(D_80140780, func_8004E388(D_80140780, t, 250.0f), &p1);
        if (156617.0f <= z) {
            eye.x = gCameraTarget->pos.x;
            eye.y = gCameraTarget->pos.y + 150.0f;
            eye.z = gCameraTarget->pos.z;
            at = D_800B7618;
            D_800B7624 = eye;
            func_8004BDCC(mtx, &at, &eye);
            func_8004DE9C(arg0, mtx);
            updateCameraView(arg0);
            return;
        }
        dir.x = p1.x - p0.x;
        dir.y = p1.y - p0.y;
        dir.z = p1.z - p0.z;
        if (dir.x == 0.0 && dir.y == 0.0 && dir.z == 0.0) {
            dir.z = 1.0f;
        }
        dirLenSq = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
        dirLen = sqrtf(dirLenSq);
        dir.x /= dirLen;
        dir.y /= dirLen;
        dir.z /= dirLen;
        at.x = p0.x - dir.x * 1500.0;
        at.y = p0.y - dir.y * 1500.0;
        at.z = p0.z - dir.z * 1500.0;
        at.y += 250.0;
        eye.x = at.x + dir.x * 1500.0;
        eye.y = gCameraTarget->pos.y;
        eye.z = at.z + dir.z * 1500.0;
        if (__cosf((f32)((f32)gCameraTarget->angle * 6.283185307179586) * 1.52587890625e-05) > -0.4) {
            eye.y += 285.0;
        }
        if (eye.z == at.z) {
            eye.z = at.z + 50.0f;
        }
        dxFromPath = gCameraTarget->pos.x - p0.x;
        if (func_8002DD60(dxFromPath) > 250.0) {
            if (dxFromPath > 0.0) {
                dxFromPath -= 150.0;
            } else {
                dxFromPath += 150.0;
            }
            eye.x += dxFromPath;
            at.x += dxFromPath * 0.8;
        }
        if (D_800B764C != 0) {
            D_800B7618 = at;
            D_800B7624 = eye;
            D_800B764C = 0;
        } else {
            func_8004DDDC(&D_800B7618.x, &at.x, &D_800B7630.x, 8.0f, 0.1f);
            func_8004DDDC(&D_800B7618.y, &at.y, &D_800B7630.y, 11.0f, 0.2f);
            func_8004DDDC(&D_800B7618.z, &at.z, &D_800B7630.z, 18.0f, 0.2f);
            func_8004DDDC(&D_800B7624.x, &eye.x, &D_800B763C.x, 8.0f, 0.1f);
            if (D_800B7624.y < eye.y) {
                func_8004DDDC(&D_800B7624.y, &eye.y, &D_800B763C.y, 4.0f, 0.2f);
            } else {
                func_8004DDDC(&D_800B7624.y, &eye.y, &D_800B763C.y, 18.0f, 0.1f);
            }
            func_8004DDDC(&D_800B7624.z, &eye.z, &D_800B763C.z, 18.0f, 0.2f);
        }
        func_8004BDCC(mtx, &D_800B7618, &D_800B7624);
        func_8004DE9C(arg0, mtx);
        updateCameraView(arg0);
        func_80036FB8(arg0, 0xF);
    }
}
