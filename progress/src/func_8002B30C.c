s32 func_8002B240(s32, s32, s32, s32, s32, s32);
inline static s32 *inline_fn(void *arg0)
{
  return (s32 *) (((char *) arg0) + 0x78);
}

void func_8002B30C(void *arg0)
{
  func_8002B240((s32) (*((f32 *) (((char *) arg0) + 4))), (s32) (*((f32 *) (((char *) arg0) + 8))), (s32) (*((f32 *) (((char *) arg0) + 0xC))), *((s32 *) (((char *) arg0) + 0x74)), (*inline_fn(arg0)) * 0x64, *((s32 *) (((char *) arg0) + 0x70)));
}

