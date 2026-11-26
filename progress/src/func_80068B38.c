s32 func_8002A360(s32, s32);
s32 func_80043248(void *);
s32 func_80069F00();
extern f32 D_80008DAC;
extern void *D_800B3964;
s32 func_80068B38(void *arg0)
{
  if ((((*((const s32 *) (((char *) arg0) + 0x88))) == 0) && ((*((const s32 *) (((char *) D_800B3964) + 0x74))) == 0)) && ((*((const f32 *) (((char *) arg0) + 0xDC))) > 26.0f))
  {
    *((s32 *) (((char *) arg0) + 0x88)) = 1;
    func_80069F00();
    func_8002A360(0xC, 0x80);
    func_8002A360(8, 0x50);
  }
  if (func_80043248(arg0) != 0)
  {
    *((s32 *) (((char *) arg0) + 0x88)) = (s32) ((*((const s32 *) (((char *) arg0) + 0x88))) + 1);
  }
  if ((*((const s32 *) (((char *) D_800B3964) + 0x6C))) == 1)
  {
    *((s32 *) (((char *) D_800B3964) + 0x6C)) = 0;
    return 2;
  }
  return (*((const s32 *) (((char *) arg0) + 0x88))) >= 5;
}


