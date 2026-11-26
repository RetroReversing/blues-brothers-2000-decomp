s32 func_8000C5B4();
s32 func_80023874(s32, s32);
s32 func_8002A360(s32, s32);
s32 func_8002D124();
extern s32 D_800B4D2C;
extern s32 D_800B5DD4;
extern void *D_800BD06C;
extern s32 D_800BD0E0;
extern s32 func_8003C37C;
typedef struct 
{
  int field_0;
  unsigned char pad_4[48];
  int field_34;
  int field_38;
  int field_3C;
  unsigned char pad_40[128];
  int field_C0;
} __repair_record_D_800BD06C;
s32 func_8003C140(void)
{
  s32 temp_v1;
  if (((*((s32 **) (((char *) D_800BD06C) + 0x9C))) == (&func_8003C37C)) || (func_80023874(0x13F, 0) != 0))
  {
    return 1;
  }
  func_8000C5B4();
{ s32 *p = &D_800BD0E0; s32 t; D_800B4D2C = 1; p[5]--; t = D_800BD0E0 - 1; p[5] = 0; D_800BD0E0 = t; if (t < 0) D_800BD0E0 = 0; }
  D_800B5DD4 = 0;
  ((__repair_record_D_800BD06C *) D_800BD06C)->field_34 = 0x100;
  ((__repair_record_D_800BD06C *) D_800BD06C)->field_38 = 0x100;
  ((__repair_record_D_800BD06C *) D_800BD06C)->field_3C = 0x100;
  ((__repair_record_D_800BD06C *) D_800BD06C)->field_0 = 0x101;
  ((__repair_record_D_800BD06C *) D_800BD06C)->field_C0 = 2;
  *((s32 **) (((char *) D_800BD06C) + 0x9C)) = &func_8003C37C;
  func_8002A360(0xC, 0x80);
  func_8002A360(8, 0x7D);
  func_8002D124();
  return 0;
}

