void debugPrintf();
extern char D_80000F00[];
extern u32 D_800AB9B0;
extern s32 D_800AB9B8;
extern u32 D_800AB9BC;
extern u32 D_800AB9C0;
extern u32 D_800AB9C4;
u32 func_80023124(void)
{
  u32 temp_v0;
  u32 var_s0;
  u32 temp;
  u32 temp2;
  var_s0 = D_800AB9BC;
  if (((u32) D_800AB9C0) >= var_s0)
  {
    for (;;)
    {
      if ((*((s32 *) var_s0)) != 0)
      {
        var_s0 += 0x108;
        if (((u32) D_800AB9C0) < var_s0)
        {
        }
        else
        {
          continue;
        }
      }
      break;
    }

  }
  if (var_s0 >= ((u32) D_800AB9C0))
  {
    temp_v0 = var_s0 + 0x108;
    D_800AB9C0 = temp_v0;
    if (((u32) D_800AB9C4) < temp_v0)
    {
      D_800AB9C0 = D_800AB9C4;
      D_800AB9B8 -= 1;
    }
    *((s32 *) D_800AB9C0) = 0;
  }
  temp2 = (u32) D_800AB9C0;
  temp = (u32) D_800AB9B0;
  if (temp2 >= temp)
  {
    debugPrintf(D_80000F00, 0x190);
  }
  D_800AB9B8 += 1;
  return var_s0;
}

