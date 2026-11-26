f32 getCameraTargetDist(void *, f32, s32);
extern void *gCameraTarget;
typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x80];
    s32 unk90;
    u8 pad94[0x2C];
    s32 unkC0;
} Obj;
typedef struct {
    u8 pad0[4];
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0xC0];
    s32 unkD0;
} Player;

s32 func_8005F308(Obj *arg0)
{
  s32 state;
  f32 lim;
  f32 dy;
  f32 d;
  f32 k;
  f32 vx;
  f32 vz;

  if ((u32)(arg0->unk90 - 3) < 2) {
    return 0;
  }
  state = ((Player *)gCameraTarget)->unkD0;
  if (state == 5 || state == 0x10) {
    return 0;
  }
  dy = ((Player *)gCameraTarget)->y - arg0->y;
  lim = 0.0f;
  if (state == 0xB) {
    lim = 95.0f;
  }
  lim += 110.0f;
  if (!(dy < 180.0f)) {
    return 0;
  }
  arg0->unkC0 = 0;
  d = getCameraTargetDist(arg0, 250.0f, 0);
  if (d < 200.0f) {
    if (d < lim) {
      k = lim - d;
      vx = (arg0->x - ((Player *)gCameraTarget)->x) * k / d;
      vz = (arg0->z - ((Player *)gCameraTarget)->z) * k / d;
      ((Player *)gCameraTarget)->x -= vx;
      ((Player *)gCameraTarget)->z -= vz;
      arg0->unkC0 |= 1;
      arg0->x += vx * 0.0f;
      arg0->z += vz * 0.0f;
    }
    return 1;
  }
  return 0;
}
