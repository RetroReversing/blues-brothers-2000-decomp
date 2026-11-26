s32 func_8002D260(s32);
s32 func_8002D464(void *, s32);
f32 func_8002D858(void *, s32);
s32 func_8002DA80(void *);
f32 func_8002DD60(f32);
s32 animStepKeys(void *);
s32 func_80043328(void *, s32, s32);
s32 actorSetAnim(void *, s32, s32);
s32 func_800853E8(void *);
extern void *gCameraTarget;
extern s32 func_80079A08;
void func_80079BBC(void *arg0)
{
  f32 temp_fs0;
  f32 temp_fs0_2;
  s32 temp_a0;
  temp_fs0 = func_8002DD60((*((f32 *) (((char *) arg0) + 8))) - (*((f32 *) (((char *) gCameraTarget) + 8))));
  if ((*((s32 *) (((char *) arg0) + 0x7C))) == 0)
  {
    actorSetAnim(arg0, 0xDA, 0x100);
    func_8002D464(arg0, 0xFA);
    *((s32 *) (((char *) arg0) + 0x7C)) = 1;
  }
  if (1250.0f < temp_fs0)
  {
    *((s32 *) (((char *) arg0) + 0x68)) = -1;
    return;
  }
  *((s32 *) (((char *) arg0) + 0x68)) = 4;
  func_800853E8(arg0);
  temp_fs0_2 = 800.0f;
  if (temp_fs0_2 < func_8002DD60((*((f32 *) (((char *) arg0) + 4))) - (*((f32 *) (((char *) arg0) + 0x40)))))
  {
    *((f32 *) (((char *) arg0) + 4)) = (f32) (*((f32 *) (((char *) arg0) + 0x40)));
  }
  if (temp_fs0_2 < func_8002DD60((*((f32 *) (((char *) arg0) + 0xC))) - (*((f32 *) (((char *) arg0) + 0x48)))))
  {
    *((f32 *) (((char *) arg0) + 0xC)) = (f32) (*((f32 *) (((char *) arg0) + 0x48)));
  }
  if (func_8002D858(arg0, 0) < 200.0f)
  {
    *((s32 **) (((char *) arg0) + 0x9C)) = &func_80079A08;
    *((s32 *) (((char *) arg0) + 0x7C)) = 0;
    *((s32 *) (((char *) arg0) + 0x78)) = 0;
    return;
  }
  if (animStepKeys(arg0) != 0)
  {
    if ((*((s32 *) (((char *) arg0) + 0xD0))) == 0xDC)
    {
      temp_a0 = (*((s32 *) (((char *) arg0) + 0x10))) + 0x8000;
      *((s32 *) (((char *) arg0) + 0x10)) = temp_a0;
      func_8002D260(temp_a0);
      func_80043328(arg0, 0xDA, 0x100);
      func_8002D464(arg0, 0xFA);
    }
    else
    {
      f32 __repair_fzero = 0.0f;
      func_80043328(arg0, 0xDC, 0x100);
      *((f32 *) (((char *) arg0) + 0x54)) = __repair_fzero;
      *((f32 *) (((char *) arg0) + 0x4C)) = (unsigned short) __repair_fzero;
    }
  }
  func_8002DA80(arg0);
}


