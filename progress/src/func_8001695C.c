
s32 findActor(s32, s32);
f32 approachF32(f32, f32, f32);
extern f32 D_800008B0;
unsigned long long func_8001695C(void *arg0)
{
  if (findActor(0x101E, 0) == 0)
  {
    *((f32 *) (((char *) arg0) + 8)) = approachF32(300.0f + (*((f32 *) (((char *) arg0) + 0x44))), *((f32 *) (((char *) arg0) + 8)), 45.0f);
  }
}


