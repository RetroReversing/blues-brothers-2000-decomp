typedef struct { s32 x, y, z; } Vec3i;
typedef struct Obj {
    f32 x00;
    f32 x;      /* 0x04 */
    f32 y;      /* 0x08 */
    f32 z;      /* 0x0C */
    s32 yaw;    /* 0x10 */
    s32 pitch;  /* 0x14 */
} Obj;

f32 func_800247D0(f32, f32);
s32 func_8002D260(s32);

void func_80034FEC(Obj *arg0, Vec3i *arg1) {
    f32 dx;
    f32 dz;
    f32 dy;
    f32 dist;
    f32 yaw;
    f32 pitch;

    dx = arg1->x - arg0->x;
    dz = arg1->z - arg0->z;
    dy = arg1->y - arg0->y;
    dist = sqrtf(dx * dx + dz * dz);
    yaw = func_800247D0(dx, dz);
    pitch = func_800247D0(dy, dist);
    yaw = yaw * 32768.0f / 3.141459;
    pitch = pitch * 32768.0f / 3.141459;
    arg0->yaw = func_8002D260(yaw);
    arg0->pitch = func_8002D260(pitch);
}
