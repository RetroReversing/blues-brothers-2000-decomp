s32 func_800261A0(s32);
s32 func_80030C40(void *, s32);
extern s32 gPakInitWarn;
extern s32 gFontScale;
extern s32 gPadPressed;
extern s32 func_80023078;
extern s32 drawControllerPakMenu;
s32 func_80030EFC(void *arg0)
{
  if ((*((s32 *) (((s8 *) arg0) + 0x7C))) != 0)
  {
    if (func_800261A0(0) == 0)
    {
      if (gPakInitWarn == 0)
      {
        func_80030C40(arg0, 1);
        return;
      }
      *((s32 *) (((s8 *) arg0) + 0x7C)) = 0;

    gFontScale = 2;
    goto block_6;
    }
    
    *((s32 *) (((s8 *) arg0) + 0x7C)) = 0;

    gFontScale = 2;
    goto block_6;
  }
  block_6:
  *((s32 **) (((s8 *) arg0) + 0x98)) = &drawControllerPakMenu;

  if (gPadPressed & 0x9000)
  {
    switch (*((s32 *) (((s8 *) arg0) + 0x78)))
    {
    case 0x10:
      *((s32 **) (((s8 *) arg0) + 0x98)) = (s32 *) ((s8 *)&func_80023078 + 8);
      func_80030C40(arg0, -7);
      gFontScale = 1;
      break;
    }
  }
}


