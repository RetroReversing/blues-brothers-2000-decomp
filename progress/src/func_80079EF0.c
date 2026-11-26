void *findActor(s32, s32);
s32 randomRange(s32, s32);
void func_8002ADFC(s32, s32, void *);
s32 animStepKeys(void *);
void *func_80079E3C(void *);
extern void *gCameraRig;
extern s32 D_800B5DD4;
extern void *gCameraTarget;
extern s32 func_800393F4;
void func_80079EF0(void *arg0)
{
  s32 ok;
  f32 f;
  void *obj;

  ok = animStepKeys(arg0);
  f = *(f32 *)((s8 *)arg0 + 0xDC);
  if (66.0f <= f && f <= 80.0f) {
    if (f <= 68.0f) {
      func_8002ADFC(0x6C, 0x7D0, arg0);
    }
    obj = findActor(0x137, 0);
    if (obj != NULL) {
      obj = func_80079E3C(obj);
      *(f32 *)((s8 *)obj + 4) += (f32)randomRange(-0x14, 0x14);
      *(f32 *)((s8 *)obj + 0xC) += (f32)randomRange(-0x14, 0x14);
    }
  }
  if (*(s32 *)((s8 *)gCameraRig + 0xA8) != 0 && ok != 0) {
    func_8002ADFC(0x6C, 0x7D0, arg0);
    *(s32 *)((s8 *)gCameraRig + 0xA8) = 0;
    *(s32 *)((s8 *)gCameraRig + 0x9C) = *(s32 *)((s8 *)gCameraRig + 0xD8);
    *(s32 **)((s8 *)gCameraTarget + 0x9C) = &func_800393F4;
    *(s32 *)((s8 *)findActor(6, 0) + 0x68) = 0xF;
    D_800B5DD4 = 1;
  }
}
