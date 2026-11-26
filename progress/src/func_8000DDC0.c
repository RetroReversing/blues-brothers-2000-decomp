extern void *gCameraTarget;
s32 func_8000DCC4(void *, void *);
s32 func_8003C140(void *);

unsigned char func_8000DDC0(void *arg0)
{
  if (func_8000DCC4(gCameraTarget, arg0) == 1) {
    if (*((f32 *) (((char *) gCameraTarget) + 8)) <= (*((f32 *) (((char *) arg0) + 8)) + 50.0f)) {
      func_8003C140(gCameraTarget);
    }
  }
}
