s32 animStepKeys(s32);
s32 func_80068CBC();
extern s32 func_80068894;
extern void *D_800B3964;
s32 func_80068AE8(s32 arg0)
{
  func_80068CBC();
  if (!((animStepKeys(arg0) == 0) || (((*((s32 *) (((char *) D_800B3964) + 0x9C))) != (&func_80068894))))) {
  return (1);
} else { return 0; }}
