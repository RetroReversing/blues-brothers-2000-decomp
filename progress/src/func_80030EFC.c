s32 func_800261A0(s32);
s32 func_80030C40(void *, s32);
extern s32 D_800AE174;
extern s32 D_800B28C0;
extern s32 D_801070A0;
extern s32 func_80023078;
extern s32 func_80031F0C;
s32 func_80030EFC(void *arg0)
{
  if ((*((s32 *) (((s8 *) arg0) + 0x7C))) != 0)
  {
    if (func_800261A0(0) == 0)
    {
      if (D_800AE174 == 0)
      {
        func_80030C40(arg0, 1);
        return;
      }
      *((s32 *) (((s8 *) arg0) + 0x7C)) = 0;

    D_800B28C0 = 2;
    goto block_6;
    }
    
    *((s32 *) (((s8 *) arg0) + 0x7C)) = 0;

    D_800B28C0 = 2;
    goto block_6;
  }
  block_6:
  *((s32 **) (((s8 *) arg0) + 0x98)) = &func_80031F0C;

  if (D_801070A0 & 0x9000)
  {
    switch (*((s32 *) (((s8 *) arg0) + 0x78)))
    {
    case 0x10:
      *((s32 **) (((s8 *) arg0) + 0x98)) = (s32 *) ((s8 *)&func_80023078 + 8);
      func_80030C40(arg0, -7);
      D_800B28C0 = 1;
      break;
    }
  }
}


