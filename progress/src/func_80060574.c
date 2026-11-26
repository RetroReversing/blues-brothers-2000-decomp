s32 randomRange(s32, s32);
s32 func_8002D3E4(void *, s32, s32);
f32 getCameraTargetDist(void *, s32, s32 *);
s32 func_8002DA80(void *);
s32 func_8005FE74(void *);
s32 func_80060214(void *);
s32 func_80076080();
inline static int inline_fn(int arg0, int arg1)
{
  return randomRange(arg0, 0xFA0) + arg1;
}

void func_80060574(void *arg0)
{
  s32 sp10;
  s32 temp_a2;
  if (func_80076080() == 0)
  {
    func_80060214(arg0);
    if ((*((s32 *) (((char *) arg0) + 0x80))) == 0)
    {
      func_8002DA80(arg0);
      if (((s32) getCameraTargetDist(arg0, 0x447A0000, &sp10)) >= 0x2EE)
      {
        temp_a2 = (*((s32 *) (((char *) arg0) + 0x10))) + inline_fn(-0xFA0, 0x8000);
        *((s32 *) (((char *) arg0) + 0x10)) = temp_a2;
        func_8002D3E4(arg0, 0x96, temp_a2);
      }
      func_8005FE74(arg0);
    }
  }
}

