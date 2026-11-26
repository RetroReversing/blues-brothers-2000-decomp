s16 coss();
s32 tickActorTimer();
s32 func_8002DA80();
f32 func_800385AC();
s32 animStepKeys();
s32 func_80043328();
s16 sins();
extern s32 func_800393F4;
inline static s32 inline_fn(s16 arg0, int arg1)
{
  return (s32) (arg0 * arg1);
}

void func_8003930C(void *arg0)
{
  u16 *temp;
  func_80043328(arg0, 2, 0x100);
  animStepKeys(arg0);
  temp = (const u16 *) (((char *) arg0) + 0x12);
  *((f32 *) (((char *) arg0) + 0x4C)) = (f32) (inline_fn(sins(*temp), 0x190) >> 0xF);
  *((f32 *) (((char *) arg0) + 0x54)) = (f32) (inline_fn(coss(*((const u16 *) (((char *) arg0) + 0x12))), 0x190) >> 0xF);
  func_8002DA80(arg0);
  *((f32 *) (((char *) arg0) + 8)) = func_800385AC(arg0);
  if (tickActorTimer(arg0) != 0)
  {
    *((s32 **) (((char *) arg0) + 0x9C)) = &func_800393F4;
  }
}

