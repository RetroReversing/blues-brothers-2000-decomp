extern s32 D_800DA840;
extern char D_800DA848[];
void func_8002338C(s32 arg0)
{
  s32 n; s32 *bp;
  bp = (s32 *)D_800DA848;
  n = D_800DA840;
  bp[n] = arg0;
  D_800DA840 = n + 1;
  if (n + 1 >= 0xC8) D_800DA840 = 0xC7;
}
