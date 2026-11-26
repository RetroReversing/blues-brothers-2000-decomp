s32 func_8000DCC4(void *, void *);
s32 spawnPuffEffect(void *);
s32 func_8003BB90(void *);
extern f32 D_800004D0;
extern void *gCameraTarget;
volatile char func_8000DE34(void *arg0)
{
  if ((func_8000DCC4(gCameraTarget, arg0) == 1) && (((*((f32 *) (((char *) gCameraTarget) + 8))) + 200.0f) < (*((f32 *) (((char *) arg0) + 8)))))
  {
    spawnPuffEffect(gCameraTarget);
    func_8003BB90(gCameraTarget);
  }
}


