s32 func_800493A0();
extern f64 D_80007CD8;
void func_80048C8C(void *arg0, s32 arg1)
{
  f32 sp10[3];
  sp10[0] = *((f32 *) (((char *) arg0) + 0));
  sp10[1] = (f32) (((f64) (*((f32 *) (((char *) arg0) + 4)))) - D_80007CD8);
 do { sp10[2] = *((f32 *) (((char *) arg0) - -8)); func_800493A0(arg0, sp10, arg1); } while (0);
}
