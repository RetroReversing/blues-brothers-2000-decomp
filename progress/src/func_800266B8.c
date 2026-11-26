s32 func_800263F4();
s32 func_8002642C();
s32 func_800269B8(s32);
s32 func_80026C04(s32, s32, s32);
s32 osPfsFindFile(s32 *, s32, s32, s32, s32 *, s32 *);
s32 osPfsReadWriteFile(s32 *, s32, s32, s32, s32, s32);
extern s32 D_80001110;
extern s32 D_80107210;
s32 func_800266B8(s32 arg0, s32 arg1, s32 arg2)
{
  s32 ret;
  s32 sp18;
  func_800263F4();
  if (osPfsFindFile(&D_80107210, 0x3630, 0x4E425045, func_800269B8(arg0), &D_80001110, &sp18) != 5)
  {
    func_80026C04(arg1, 0x2A, arg2);
    osPfsReadWriteFile(&D_80107210, sp18, 0, 0, arg2, arg1);
    func_8002642C();
    do
    {
      ret = arg2;
    }
    while (0);
  }
  else
  {
    func_8002642C();
    ret = 0;
  }
  return ret;
}


