f32 func_8002D66C();
s32 func_8003CAD4();
extern void *D_800BD06C;
void func_8001E5D4(void *arg0)
{
  *((s32 *) (((char *) arg0) + 0x68)) = -1;
 do { *((s32 *) (((char *) arg0) + 0)) = 0x101; if (((s32) func_8002D66C(arg0, 0x43E10000, 0)) < 0x1C2) { func_8003CAD4(arg0, *((s32 *) (((char *) D_800BD06C) + 0x10))); } } while (0);
}
