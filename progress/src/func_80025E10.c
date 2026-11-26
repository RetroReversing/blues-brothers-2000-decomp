s32 func_80025B64();
s32 func_80025BA0();
s32 osContGetReadData(s32 *);
s32 osContStartReadData(s32 *);
s32 osRecvMesg(s32 *, s32, s32);
extern s32 D_80107030;
extern s32 D_80107058;
extern s32 D_80107070;
extern s32 D_80107080;
extern u8 D_801071F0;
extern s32 D_80107600;
extern s32 D_80107610;
extern s32 D_80107630;
inline static char *inline_fn(int arg0)
{
  return (char *) ((s32 *) (((u8 *) (&D_80107630)) + arg0));
}

u8 func_80025E10(s32 arg0)
{
  char *__repair_addr;
  s32 temp_v1;
  s32 var_t0;
  u16 temp_a0;
  if (arg0 < 0)
  {
    return 0U;
  }
  func_80025B64();
  osContStartReadData(&D_80107058);
  osRecvMesg(&D_80107058, 0, 1);
  func_80025BA0();
  osContGetReadData(&D_80107630);
  do
  {
    
      var_t0 = 0;
    
  }
  while (0);
  do
  {
    {
      if ((((s32) D_801071F0) >> var_t0) & 1)
      {
        *((&D_80107080) + var_t0) |= *((u16 *) (inline_fn(var_t0 * 6) + 0));
        temp_a0 = *((u16 *) (inline_fn(var_t0 * 6) + 0));
 loop_goto_1:
 {
 temp_v1 = temp_a0 ^ (*((&D_80107070) + var_t0));
 }
 if (0)
 {
     { goto loop_goto_1; }
 }
        *((&D_80107070) + var_t0) = (s32) temp_a0;
        *((&D_80107030) + var_t0) |= temp_v1 & temp_a0;
        __repair_addr = inline_fn(var_t0 * 6);
        *((&D_80107600) + var_t0) = (s32) (*((s8 *) (((char *) __repair_addr) + 2)));
        *((&D_80107610) + var_t0) = (s32) (*((s8 *) (inline_fn(var_t0 * 6) + 3)));
      }
    }
    var_t0 += 1;
  }
  while (var_t0 < 4);
  return D_801071F0;
}
