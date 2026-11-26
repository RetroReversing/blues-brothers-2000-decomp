s32 func_8002854C(s32, s32);
typedef struct { s32 w0; s32 w1; } CursorRec8;
extern CursorRec8 *D_80177E18;
void func_8002889C(u8 *arg0)
{
  s32 var_a1;
  unsigned char temp_a0;
  u8 *var_s0;
  CursorRec8 *temp_a0_2;
  var_s0 = arg0;
  var_a1 = 1;
  loop_1:
  temp_a0 = (*var_s0) & 0xFF;

  var_s0 += 1;
  if (temp_a0 != 0)
  {
    func_8002854C(temp_a0, var_a1);
    var_a1 = 0;
    goto loop_1;
  }
  temp_a0_2 = D_80177E18++;
  temp_a0_2->w0 = 0xE7000000;
  temp_a0_2->w1 = 0;
}


