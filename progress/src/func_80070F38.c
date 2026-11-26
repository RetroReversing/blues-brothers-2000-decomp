s32 func_80096100(s32);
void func_80070F38(void *arg0, s32 arg1)
{
  s32 *var_s0;
  s32 *var_s1;
  s32 temp_a0;
  var_s1 = NULL;
  var_s0 = *((s32 **) (((char *) arg0) + 0x668));
  temp_a0 = func_80096100(1);
  if (var_s0 != NULL)
  {
    loop_1:
    if (var_s0 == arg1)
    {
 loop_goto_1:
 {
 if (var_s1 != NULL) { *var_s1 = *var_s0; } else { *((s32 **) (((char *) arg0) + 0x668)) = (s32 *) (*var_s0); }
 }
 if (0)
 {
     goto loop_goto_1;
 }
    }
    else
    {
      var_s1 = var_s0;
      var_s0 = *var_s0;
      if (var_s0 != NULL)
      {
        goto loop_1;
      }
    }

  }
  func_80096100(temp_a0);
}
