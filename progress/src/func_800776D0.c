f32 func_8002D858();
s32 func_8003BF98();
s32 animStepKeys();
extern f32 D_800092BC;
extern f32 D_800092C0;
extern f32 D_800092C4;
s32 func_800776D0(void *arg0)
{
  f32 temp_fs0;
  s32 var_v0;
  temp_fs0 = func_8002D858(arg0, arg0 + 0x10);
  if (animStepKeys(arg0) != 0)
  {
    var_v0 = 1;
    if (!(D_800092BC < temp_fs0))
    {
      *((s32 *) (((char *) arg0) + 0x88)) = 0;
      goto block_3;
    }
  }
  else
  {
    block_3:
    if ((((*((s32 *) (((char *) arg0) + 0x88))) == 0) && ((*((f32 *) (((char *) arg0) + 0xDC))) > D_800092C0)) && (temp_fs0 < D_800092C4))
    {
      func_8003BF98(arg0);
      *((s32 *) (((char *) arg0) + 0x88)) += 1;
    }

    var_v0 = 0;
  }
  return var_v0;
}

