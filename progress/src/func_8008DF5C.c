inline static int __repair_inline(s32 a, s32 b)
{
  return a > b;
}

s32 alSynStopVoice();
s32 func_8008C380();
s32 func_8008DDAC();
s32 playSeqChannelNote();
s32 func_8008E644();
s32 func_8008E6D4();
s32 func_8008E834(s32 *, s32, f32);
s32 func_8008E9AC();
s32 func_8008EBA8();
f32 func_8008EC60();
f32 func_8008ECB8();
s32 func_8008ED20();
s32 func_8008EDE4();
extern s32 D_8017B204;
extern s32 D_8017B208;
extern s32 *D_8017B20C;
extern s32 D_8017B218;
extern char D_8017B4A0[];
s32 func_8008DF5C(void)
{
  u32 guard_value;
  f32 var_fs0;
  char *var_s1;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v1;
  s32 var_s2;
  s32 var_s3;
  void *var_s0;
  s32 temp;
  {
    var_s2 = -4;
  }
  func_8008DDAC();
  {
    temp_v0 = D_8017B204 - 4;
  }
  var_s1 = D_8017B20C;
  guard_value = __repair_inline(temp_v0, -4);
  if (guard_value)
  {
    do
    {
      if (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA6)))) != 0) && (!((*((s32 *) var_s1)) & 1)))
      {
        if ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA2)))) != 0)
        {
          func_8008E644(var_s1, var_s2);
        }
        temp_v1 = (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E)))) + (*((u16 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xE))));
        *((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E))) = temp_v1;
        if ((*((u16 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x10)))) != 0x7FFF)
        {
          if (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x6E)))) - temp_v1) < 0)
          {
            loop_8:
            if ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA6)))) != 0)
            {
              playSeqChannelNote(var_s1, var_s2);
              if (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x6E)))) - (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E))))) >= 0)
              {
                goto block_10;
              }
              goto loop_8;
            }

          }
          else
          {
            block_10:
            if ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA6)))) != 0)
            {
              goto block_11;
            }

          }
        }
        else
        {
          block_11:
          if (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x72)))) != 0) && (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x96)))) - (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E))))) < 0))
          {
            func_8008ED20(var_s1);
          }

          if (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x76)))) != 0) && (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x92)))) - (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E))))) < 0))
          {
            func_8008EDE4(var_s1);
          }
          temp_v0 = *((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9A)));
          temp_v0_2 = temp_v0 - 1;
          if ((temp_v0 != (-1)) && ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9A))) = temp_v0 - 1, (temp_v0 - 1) == (-1))))
          {
            *((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA6))) = func_8008C380(var_s1, 0);
            if ((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x1F))) != 0)
            {
              *((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x1F)) = 0U;
 { alSynStopVoice(D_8017B4A0, D_8017B208 + var_s2 * 0x1C); goto block_21; }
            }
          }
          else
          {
            block_21:
            if ((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x1F))) != 0)
            {
              if ((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x19))) != 0)
              {
                func_8008E9AC(var_s1);
              }
              if (((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x2A))) != 0) && (((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x16)))) - (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E))))) < 0))
              {
                func_8008EBA8(var_s1);
              }
              __repair_rows:
              {
                {
                  var_fs0 = *((f32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x7A)));
                }
              }

              if (0)
              {
                goto __repair_rows;
              }
              if ((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x2B))) != 0)
              {
                {
                  var_fs0 += func_8008ECB8(var_s1);
                }
              }
              if ((*((u8 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0x24))) != 0)
              {
                {
                  var_fs0 += func_8008EC60(var_s1);
                }
              }
              if ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0xA2)))) == 0)
              {
                func_8008E834(var_s1, var_s2, var_fs0);
                func_8008E6D4(var_s1, var_s2);
              }
            }

          }
          {
            {
              {
                *((s16 *) (((char *) ((void *) (var_s1 + 0xAA))) + 0)) = (s16) (((u32) ((*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x9E)))) - (*((s32 *) (((char *) ((void *) (var_s1 + 0xAA))) + (-0x6A)))))) >> 8);
              }
            }
          }
        }
      }
      {
        {
          var_s2 += 1;
        }
      }
      {
      }
      {
        var_s1 += 0x13C;
      }
    }
    while (var_s2 < (D_8017B204 - 4));
  }
  return D_8017B218;
}

