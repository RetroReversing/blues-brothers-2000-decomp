extern s32 gCamSpeedScale;
extern char D_801719E0[];
inline static s16 inline_fn(void *arg0)
{
  return *((s16 *) (((char *) arg0) + 0x18));
}

void func_8008203C(s32 arg0, s32 arg1)
{
  int __repair_constant = 0x80;
  s16 temp_v0;
  s16 temp_v0_2;
  s16 temp_v0_3;
  void *temp_a1;
  s32 temp;
  char *__base_D_801719E0;
  __base_D_801719E0 = D_801719E0;
  {
    temp = (arg1 * 2) + (arg0 * 0x28);
    temp_a1 = temp + __base_D_801719E0;
    temp_v0 = (s16) (*((s16 *) (((char *) temp_a1) + 0x18)));
  }
  if (temp_v0 != 0x80)
  {
    if (temp_v0 >= 0x81)
    {
      temp_v0_2 = ((u16) (s16) (*((s16 *) (((char *) temp_a1) + 0x18)))) - (gCamSpeedScale * 3);
      *((s16 *) (((char *) temp_a1) + 0x18)) = temp_v0_2;
      if (temp_v0_2 < 0x80)
      {
        *((s16 *) (((char *) temp_a1) + 0x18)) = 0x80;
        goto block_4;
      }
    }
    else
    {
      block_4:
      if ((s16) (*((s16 *) (((char *) temp_a1) + 0x18))) < 0x80)
      {
        temp_v0_3 = ((u16) (s16) (*((s16 *) (((char *) temp_a1) + 0x18)))) + (gCamSpeedScale * 3);
        *((s16 *) (((char *) temp_a1) + 0x18)) = temp_v0_3;
        if (temp_v0_3 >= 0x81)
        {
          *((s16 *) (((char *) temp_a1) + 0x18)) = 0x80;
        }
      }

    }
  }
}

