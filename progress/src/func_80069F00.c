s32 func_800221C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8002A360(s32, s32);
s32 func_8002D620(void *);
void *func_80042F00(s32, s32, s32, s32);
s32 func_800433A8(void *, s32, s32);
s32 func_80050460(s32 *, s32 *);

extern s32 D_800B7B0C;
extern s32 D_8014AA60;
extern s32 func_80023848;
extern s32 func_80069C7C;
extern s32 func_80069ED0;
void *func_80069F00(void *arg0)
{
  s32 temp_v0_2;
  void *temp_v0;
  func_80050460(&func_80069ED0, &D_8014AA60);
  temp_v0 = func_80042F00(0x6C, 0, 0, 0);
  func_800433A8(temp_v0, 0x125, 0x180);
  *((s32 *) (((char *) temp_v0) + 0x58)) = func_800221C0(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
  *((s32 **) (((char *) temp_v0) + 0x9C)) = &func_80069C7C;
  func_8002A360(0xC, 0x80);
  func_8002A360(8, 0x16);
  *((s32 *) (((char *) temp_v0) + 0x64)) = 0x104;
  if (arg0 != NULL)
  {
    *((f32 *) (((char *) temp_v0) + 4)) = (f32) (*((f32 *) (((char *) arg0) + 4)));
    *((f32 *) (((char *) temp_v0) + 8)) = (f32) (450.0f + (*((f32 *) (((char *) arg0) + 8))));
    *((f32 *) (((char *) temp_v0) + 0xC)) = (f32) (*((f32 *) (((char *) arg0) + 0xC)));
    temp_v0_2 = *((s32 *) (((char *) arg0) + 0x10));
    *((void **) (((char *) temp_v0) + 0xA4)) = arg0;
    *((s32 *) (((char *) temp_v0) + 0x10)) = temp_v0_2;
    *((s32 *) (((char *) temp_v0) + 0x8C)) = temp_v0_2;
  }
  else
  {
    *((s32 **) (((char *) temp_v0) + 0x9C)) = &func_80023848;
    *((s32 *) (((char *) temp_v0) + 0x68)) = -1;
    *((s32 *) (((char *) temp_v0) + 0x64)) = 0;
  }
  func_8002D620(temp_v0);
  return temp_v0;
}


