s32 func_8002444C();
inline static int inline_fn(s32 arg0)
{
  return arg0 - 1;
}

s32 randomRange(s32 arg0, s32 arg1)
{
  if (!(arg0 >= arg1))
  {
    return (func_8002444C() % ((s32) (arg1 - inline_fn(arg0)))) + arg0;
  }
  else
  {
    s32 temp;
    return (func_8002444C() % ((s32) (arg0 - (temp = inline_fn(arg1))))) + arg1;
  }
}

