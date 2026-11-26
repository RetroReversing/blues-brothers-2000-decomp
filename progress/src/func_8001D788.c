void *func_80017DEC(s32);
s32 func_8001B990(s32, s32);
void *findActor(s32, s32);
s32 func_80023D58(s32);
s32 actorSetAnim(void *, s32, s32);
s32 debugPrintf(s32 *);
extern s32 D_80000D18;
extern void *gCameraRig;
extern s32 D_800BD040;
extern void *gCameraTarget;
extern s32 func_80018610;
extern s32 func_80034F50;
extern s32 func_8003930C;
void func_8001D788(void *arg0)
{
  f32 temp_f8;
  void *temp_v0_2;
  int pad;
  if ((*((s32 *) (((s8 *) arg0) + 0xC0))) == 0)
  {
    *((s32 *) (((s8 *) (&D_800BD040)) + 0)) = func_80023D58(0x1D2);
    *((s32 *) (((s8 *) (&D_800BD040)) + 4)) = func_80023D58(0x1D2);
    *((s32 *) (((s8 *) (&D_800BD040)) + 8)) = func_80023D58(0x1D2);
    *((s32 *) (((s8 *) (&D_800BD040)) + 0xC)) = func_80023D58(0x1D2);
    *((s32 *) (((s8 *) arg0) + 0xC0)) = 1;
    temp_v0_2 = func_80017DEC(0);
    if (temp_v0_2 != NULL)
    {
      *((s32 *) (((s8 *) gCameraTarget) + 0x10)) = -0x4000;
      *((s32 **) (((s8 *) gCameraTarget) + 0x9C)) = &func_8003930C;
      *((s32 *) (((s8 *) gCameraTarget) + 0x64)) = 0xC8;
      actorSetAnim(gCameraTarget, 2, 0x100);
      *((f32 *) (((s8 *) gCameraRig) + 4)) = *((f32 *) (((s8 *) temp_v0_2) + 4));
      *((f32 *) (((s8 *) gCameraRig) + 8)) = *((f32 *) (((s8 *) temp_v0_2) + 8));
      *((f32 *) (((s8 *) gCameraRig) + 0xC)) = *((f32 *) (((s8 *) temp_v0_2) + 0xC));
      *((s32 **) (((s8 *) gCameraRig) + 0x9C)) = &func_80034F50;
      *((s32 *) (((s8 *) gCameraRig) + 0xA8)) = 0;
    }
    else
    {
      debugPrintf(&D_80000D18);
    }
  }
  if (func_8001B990(0x100, 0x1B) != 0)
  {
    temp_v0_2 = findActor(0x12D, 0);
    if (temp_v0_2 != NULL)
    {
      *((s32 **) (((s8 *) temp_v0_2) + 0x9C)) = &func_80018610;
      *((s32 *) (((s8 *) temp_v0_2) + 0x68)) = 4;
      *((s32 *) (((s8 *) temp_v0_2) + 0x5C)) = 0;
    }
  }
}


