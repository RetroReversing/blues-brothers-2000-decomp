s32 func_800263F4();
s32 func_8002642C();
s32 func_80026848(s32);
s32 func_800269B8(s32);
s32 func_800899DC(s32 *);
s32 osPfsAllocateFile(s32 *, s32, s32, s32, s32 *, s32, s32 *);
s32 osPfsFindFile(s32 *, s32, s32, s32, s32 *, s32 *);
s32 osPfsReadWriteFile(s32 *, s32, s32, s32, s32, s32);
extern s32 D_80001110;
extern s32 D_80001114;
extern s32 D_80107210;
s32 func_80026464(s32 arg0, s32 arg1, s32 arg2)
{
  s32 sp20;
  s32 found;
  u16 temp;
  func_800263F4();
  temp = (arg2 + 0xFF) & 0xFF00;
  arg2 = temp;
  func_80026848(1);
  found = osPfsFindFile(&D_80107210, 0x3630, 0x4E425045, func_800269B8(arg0), &D_80001110, &sp20);
  if (found == 5)
  {
    if (osPfsAllocateFile(&D_80107210, 0x3630, 0x4E425045, func_800269B8(arg0), &D_80001110, arg2, &sp20) == 9)
    {
      func_800899DC(&D_80001114);
    }
    found = osPfsFindFile(&D_80107210, 0x3630, 0x4E425045, func_800269B8(arg0), &D_80001110, &sp20);
    if (found == 5)
    {
      func_8002642C();
      return 0;
    }
  }
  osPfsReadWriteFile(&D_80107210, sp20, 1, 0, arg2, arg1);
  func_8002642C();
  return arg2;
}
