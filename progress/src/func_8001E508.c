s32 func_80013550(void *);
s32 func_80024394(s32, s32);
s32 func_8002D620(void *);
s16 sins(s32);
extern unsigned int D_800B9EA4;
inline static int inline_fn(s32 arg0, s32 arg1)
{
  return arg1 * arg0;
}

void func_8001E508(void *arg0)
{
  if ((*((s32 *) (((char *) arg0) + 0x7C))) == 0)
  {
    *((s32 *) (((char *) arg0) + 0)) = 0x10E;
    *((s32 *) (((char *) arg0) + 0x8C)) = func_80024394(0, 0xFFFF);
    *((s32 *) (((char *) arg0) + 0x7C)) = 1;
    *((f32 *) (((char *) arg0) + 0x100)) = (f32) (*((f32 *) (((char *) arg0) + 8)));
  }
  func_8002D620(arg0);
  *((f32 *) (((char *) arg0) + 8)) = (f32) (((f32) (((s32) inline_fn(sins(((*((u16 *) (((char *) arg0) + 0x8E))) + (D_800B9EA4 * 0x64)) & 0xFFFF) * 0x32, *((s32 *) (((char *) arg0) + 0x70)))) >> 0xF)) + (*((f32 *) (((char *) arg0) + 0x100))));
  func_80013550(arg0);
}


