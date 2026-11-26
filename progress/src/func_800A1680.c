/* identical to func_8003C8E0 in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
extern s32 D_800BC320[];
extern u8 D_8017DC50[];
extern u8 D_8017DC10[];
extern u8 D_8017DC00;
extern u8 D_8017DD50[];
void osRecvMesg(s32, s32, s32);
u8 func_8009EAC8(void *);
void func_8009DBF4(void);
void func_8009DC60(void);
void func_8009DB00(s32, void *);
void *memcpy(void *, const void *, u32);

u32 func_800A1680(s32 *a)
{
  u8 sp10[0x28];
  u8 *p = D_8017DC10;
  s32 i;
  u32 r;

  if (D_800BC320[a[2]] == 0)
    return 5;
  func_8009DBF4();
  D_8017DC00 = 3;
  func_8009DB00(1, D_8017DC50 + (a[2] << 6));
  osRecvMesg(a[1], 0, 1);
  func_8009DB00(0, p);
  osRecvMesg(a[1], 0, 1);
  if (a[2] != 0)
  {
    for (i = 0; i < a[2]; i++)
      p++;
  }
  memcpy(sp10, p, 0x28);
  r = (sp10[2] & 0xC0) >> 4;
  if (r == 0 && func_8009EAC8(D_8017DD50) != sp10[0x26])
    r = 4;
  func_8009DC60();
  return r;
}
