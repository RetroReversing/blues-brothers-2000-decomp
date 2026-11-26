
s32 func_8003AB30();
s32 func_80043328();
s32 func_80043418();
extern s32 D_800B4CE8;
extern s32 D_800B4CF4;
extern s32 D_80140200[];
extern s32 D_80140224;
extern unsigned int D_80140228;
inline static s32 inline_fn(int arg0)
{
  return (s32) arg0;
}

void func_8003A9A8(void *arg0)
{
  s32 var_a1;
  s32 temp_s0;
  s32 temp_v0;
  s32 temp;
  void *temp_v1;
  temp_s0 = D_80140200[0];
  D_80140228 = 0;
  if (func_8003AB30() == 0)
  {
    if (D_80140224 >= 6)
    {
      temp_v1 = &D_800B4CE8;
      if ((*((s32 *) (((s8 *) temp_v1) + 0xC))) < temp_s0)
      {
        if ((*((s32 *) (((s8 *) arg0) + 0x8C))) == 0)
        {
          if ((*((s32 *) (((s8 *) arg0) + 0xB8))) == 4)
          {
            do
            {
              func_80043418(arg0, 0x2F, 0x100);
            }
            while (0);
          }
          else
          {
            func_80043418(arg0, 4, 0x100);
          }
        }
        temp_s0 = ((D_80140200[0] - D_800B4CF4) / 5) + 0x100;
        temp_v0 = temp_s0; temp_s0 = 0;
        *((s32 *) (((s8 *) arg0) + 0xD4)) = temp_v0;
        if (temp_v0 >= 0x140)
        {
          *((s32 *) (((s8 *) arg0) + 0xD4)) = 0x140;
        }
      }
      else
      {
        if ((*((s32 *) (((s8 *) temp_v1) + 8))) < temp_s0)
        {
          if ((*((s32 *) (((s8 *) arg0) + 0x8C))) == 0)
          {
            func_80043418(arg0, 3, 0x100);
          }
          *((s32 *) (((s8 *) arg0) + 0xD4)) = inline_fn(D_80140200[0] - 0x1A9);
          return;
        }
        if ((*((s32 *) (((s8 *) temp_v1) + 4))) < temp_s0)
        {
          if ((*((s32 *) (((s8 *) arg0) + 0x8C))) == 0)
          {
            func_80043328(arg0, 2, 0x100);
          }
          *((s32 *) (((s8 *) arg0) + 0xD4)) = inline_fn((D_80140200[0] << 8) / 300);
          return;
        }
        goto block_17;
      }
    }
    else
    {
      block_17:
      func_80043328(arg0, 1, 0x100);

    }
  }
}


