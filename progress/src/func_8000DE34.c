s32 func_8000DCC4(void *, void *);
s32 func_8000DF10(void *);
s32 func_8003BB90(void *);
extern f32 D_800004D0;
extern void *D_800BD06C;
volatile char func_8000DE34(void *arg0)
{
  if ((func_8000DCC4(D_800BD06C, arg0) == 1) && (((*((f32 *) (((char *) D_800BD06C) + 8))) + 200.0f) < (*((f32 *) (((char *) arg0) + 8)))))
  {
    func_8000DF10(D_800BD06C);
    func_8003BB90(D_800BD06C);
  }
}


