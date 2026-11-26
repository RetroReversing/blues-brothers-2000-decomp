s32 func_8001F230();
s32 func_80022728(void *, s32 *, s32);
s32 func_80024A3C(s32 *, s32 *, s32);
s32 func_80024B58(s32 *, s32 *, s32);
s32 func_80024BE0(s32 *, s32 *, s32);
s32 func_80024FE8(s32 *);
s32 func_80029F8C(s32, s32 *);
s32 func_800479B0(s32);
typedef struct { s32 w0; s32 w1; } CursorRec8;
extern CursorRec8 *D_80177E18;
typedef struct { s32 v; } Field_s32;
s32 func_8001FE50(void *arg0)
{
  int __repair_constant = 8;
  volatile unsigned char pad[9];
  char sp20[0x28];
  char sp48[0x28];
  CursorRec8 *temp_a1;
  CursorRec8 *temp_v1;
  s32 temp_a0;
  func_8001F230();
  do
  {
    func_80024FE8(sp20);
  }
  while (0);
  do
  {
    func_80024B58(sp48, sp20, (((Field_s32 *) (((char *) arg0) + 0x10))->v));
  }
  while (0);
  func_80024A3C(sp20, sp48, (((Field_s32 *) (((char *) arg0) + 0x14))->v));
  do
  {
    do
    {
      func_80024BE0(sp48, sp20, (((Field_s32 *) (((char *) arg0) + 0x18))->v));
    }
    while (0);
  }
  while (0);
  do
  {
    func_80022728(arg0, sp48, 0);
  }
  while (0);
  if (((((Field_s32 *) (((char *) arg0) + 0x58))->v)) & 1)
  {
    temp_a0 = (((Field_s32 *) (((char *) arg0) + 0xE8))->v);
    if (temp_a0 != 0)
    {
      func_800479B0(temp_a0);
    }
  }
  if ((((s32) ((((Field_s32 *) (((char *) arg0) + 0x58))->v))) >> 2) & 1)
  {
    temp_v1 = D_80177E18++;
    (temp_v1->w0) = 0xE200001C;
    (temp_v1->w1) = 0x552048;
  }
  temp_a1 = D_80177E18++;
  (temp_a1->w0) = 0xDE000000;
  (temp_a1->w1) = (s32) ((((Field_s32 *) (((char *) arg0) + 0xE4))->v));
  func_80029F8C(-1, temp_a1);
  return 1;
}


