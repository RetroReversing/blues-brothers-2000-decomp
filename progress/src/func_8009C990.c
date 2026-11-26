inline static int inline_fn()
{
  return 0;
}

s32 func_8009C990(void)
{
  return (*((volatile s32 *) 0xA450000C)) < inline_fn();
}

