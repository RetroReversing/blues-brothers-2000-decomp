void *func_80023874(s32, s32);
s32 func_80024394(s32, s32);
void func_8002ADFC(s32, s32, void *);
s32 func_8004303C(void *);
void *func_80079E3C(void *);
extern void *D_800B3960;
extern s32 D_800B5DD4;
extern void *D_800BD06C;
extern s32 func_800393F4;
void func_80079EF0(void *arg0)
{
  s32 ok;
  f32 f;
  void *obj;

  ok = func_8004303C(arg0);
  f = *(f32 *)((s8 *)arg0 + 0xDC);
  if (66.0f <= f && f <= 80.0f) {
    if (f <= 68.0f) {
      func_8002ADFC(0x6C, 0x7D0, arg0);
    }
    obj = func_80023874(0x137, 0);
    if (obj != NULL) {
      obj = func_80079E3C(obj);
      *(f32 *)((s8 *)obj + 4) += (f32)func_80024394(-0x14, 0x14);
      *(f32 *)((s8 *)obj + 0xC) += (f32)func_80024394(-0x14, 0x14);
    }
  }
  if (*(s32 *)((s8 *)D_800B3960 + 0xA8) != 0 && ok != 0) {
    func_8002ADFC(0x6C, 0x7D0, arg0);
    *(s32 *)((s8 *)D_800B3960 + 0xA8) = 0;
    *(s32 *)((s8 *)D_800B3960 + 0x9C) = *(s32 *)((s8 *)D_800B3960 + 0xD8);
    *(s32 **)((s8 *)D_800BD06C + 0x9C) = &func_800393F4;
    *(s32 *)((s8 *)func_80023874(6, 0) + 0x68) = 0xF;
    D_800B5DD4 = 1;
  }
}
