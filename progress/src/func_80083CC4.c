s32 randomRange(s32, s32);
s32 approachAngle(s32, s32, s32);
s32 func_8002D260(s32);
s32 func_8002D3E4(void *, s32);
f32 getCameraTargetDist(void *, f32, s32);
s32 func_8002DA80(void *);
s32 func_8003BF98(void *);
s32 func_80043248(void *);
void *func_800851D8(void *);
s32 func_800854C4(void *);
s32 func_80085754(void *, s32, s32);
extern f32 D_80009998;
extern f64 D_800099A0;
extern s32 D_800B3968;
extern s32 gCamSpeedScale;
extern void *gCameraTarget;
extern s32 D_801700D4;
inline static s32 *inline_fn(char *arg0, int arg1)
{
  return (s32 *) (arg0 + arg1);
}

s32 func_80083CC4(void *arg0)
{
  s32 *__base_D_801700D4;
  s32 ret;
  f32 temp_fs0;
  f32 temp_fs1;
  s32 temp_s2;
  s32 var_v0;
  void *temp_v0;
  __base_D_801700D4 = &D_801700D4;
  *inline_fn((char *) arg0, 0x10) = approachAngle(*__base_D_801700D4, *inline_fn((char *) arg0, 0x10), gCamSpeedScale * 0x1C0);
  temp_v0 = func_800851D8(arg0);
  loop_goto_1:
  {
    __repair_rows: { temp_fs1 = (((f32) (*((s16 *) (((char *) temp_v0) + 2))))) + (50.0f); }
if (0) goto __repair_rows;
  }

  if (0)
  {
    goto loop_goto_1;
  }
  temp_s2 = *((s16 *) (((char *) temp_v0) + 6));
  temp_fs0 = getCameraTargetDist(arg0, (f32) (((f64) temp_fs1) + D_800099A0), 0);
  var_v0 = func_8002D260((*__base_D_801700D4) - (*inline_fn((char *) arg0, 0x10)));
  if ((((*inline_fn((char *) arg0, 0x8C)) == 0) && (temp_fs0 <= temp_fs1)) && (((f32) temp_s2) <= (*((f32 *) (((char *) arg0) + 0xDC)))))
  {
    if (var_v0 < 0)
    {
      var_v0 = -var_v0;
    }
    if (var_v0 < 0xAF0)
    {
      if (D_800B3968 != 2)
      {
        func_8003BF98(arg0);
      }
      else
      {
        *inline_fn((char *) gCameraTarget, 0xF0) = 0x80;
      }
      func_800854C4(arg0);
      *inline_fn((char *) arg0, 0x8C) = 1;
    }
  }
  if ((*inline_fn((char *) arg0, 0x70)) == 0)
  {
    func_8002D3E4(arg0, *inline_fn((char *) arg0, 0x88));
  }
  else
    if (func_80085754(arg0, *inline_fn((char *) arg0, 0xF4), 0) != 0)
  {
    func_8002D3E4(arg0, *inline_fn((char *) arg0, 0x88));
  }
  else
  {
    func_8002D3E4(arg0, 0);
  }
  func_8002DA80(arg0);
  if (func_80043248(arg0) == 0)
  {
    ret = 0;
  }
  else
  {
    *inline_fn((char *) arg0, 0x64) = (s32) (randomRange(0x19, 0x1E) * 0x64);
    ret = 1;
  }
  return ret;
}

