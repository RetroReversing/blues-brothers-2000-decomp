extern s32 *D_80106A38;
void func_800257B8(void)
{
  s32 *var_a1;
  s32 *var_a2;
  s32 var_a0;
  s32 temp;
  s32 part;
  var_a1 = NULL;
  var_a2 = D_80106A38;
  for (;;)
  {
    var_a0 = *var_a2;
    if (var_a0 > 0)
    {
      if (var_a0 & 1)
      {
        if (var_a1 != NULL)
        {
temp = *var_a1 & ~1; part = temp + 8; temp = part + (var_a0 & (~1)); var_a0 = temp;
*var_a1 = var_a0 | 1;
var_a2 = var_a1;
        }
        else
        {
          var_a1 = var_a2;
        }
      }
      else
      {
        var_a1 = NULL;
      }
      temp = (var_a0 & (~1)) + 8; var_a2 = (s32 *) ((s8 *) var_a2 + temp);
      continue;
    }
    break;
  }
}
