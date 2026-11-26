s32 func_80013654(void *);
s32 func_80015C30(void *);
s32 func_8001B990(s32, s32);
s32 func_8002A360(s32, s32);
f32 getCameraTargetDist(void *, f32, s32);
void *func_80051384(void *);
extern void *gCameraTarget;
extern s32 D_800BD100;
extern s32 func_8000EA34;
extern s32 func_8000EC24;
extern s32 func_800721A8;
inline static f32 inline_fn(void *arg0)
{
  return *((f32 *) (((char *) arg0) + 8));
}

void func_8001BA54(void *arg0)
{
  f32 temp_fs0;
  s32 var_s0;
  void *temp_v0;
  if (D_800BD100 != 0)
  {
    *((s32 **) (((char *) arg0) + 0x9C)) = &func_800721A8;
    return;
  }
  temp_fs0 = 300.0f;
  if (getCameraTargetDist(arg0, temp_fs0, 0) < temp_fs0)
  {
    if (func_8001B990(0x100, 0x1D) == 0)
    {
      func_8001B990(0x200, 0x1D);
      return;
    }
    if ((((*((f32 *) (((char *) gCameraTarget) + 8))) - inline_fn(arg0)) < 20.0f) && (func_80013654(arg0) != 0))
    {
      *((s32 *) (((char *) arg0) + 0xC0)) = 2;
    }
    goto block_8;
  }
  block_8:
  if ((*((s32 *) (((char *) arg0) + 0xC0))) & 2)
  {
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0xA);
    temp_v0 = func_80051384(arg0);
    var_s0 = 0;
    *((f32 *) (((char *) temp_v0) + 4)) = *((f32 *) (((char *) arg0) + 4));
    *((f32 *) (((char *) temp_v0) + 8)) = *((f32 *) (((char *) arg0) + 8));
    *((f32 *) (((char *) temp_v0) + 0xC)) = *((f32 *) (((char *) arg0) + 0xC));
    *((s32 **) (((char *) temp_v0) + 0x9C)) = &func_8000EA34;
    *((s32 *) (((char *) temp_v0) + 0)) = 0x101;
    do
    {
      func_80015C30(arg0);
      var_s0 += 1;
    }
    while (var_s0 < 4);
    *((s32 **) (((char *) arg0) + 0x9C)) = &func_8000EC24;
    *((s32 *) (((char *) arg0) + 0x68)) = -1;
  }

}

