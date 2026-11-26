s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
void *func_80042F00(s32, s32, s32, s32);
s32 actorSetAnim(void *, s32, s32);
s32 func_80050460(void *, s32 *);
s32 func_80085244(void *, s32);
s32 func_800852CC(void *, s32);
extern s32 D_800B7B0C;
extern s32 D_800B81D0;
extern s32 D_8014AA48;
extern s32 func_80058C64;
extern s32 func_8006E0A0;
void *func_80058D28(s32 arg0)
{
  void *p;
  func_80050460(((char *) (&func_80058C64)) + 0xC, &D_8014AA48);
  p = func_80042F00(0xC, 0, 0, 0);
  actorSetAnim(p, 0x4F, 0x100);
  *((s32 *) p) = 0x100C;
  *((s32 *) ((char *) p + 0x58)) = packDrawFlags(1, 1, 2, 3, D_800B7B0C, 0, 1, 0);
  func_800852CC(p, arg0);
  if (D_800B81D0 != 0)
  {
    void *r;
    r = p;
    *((s32 **) ((char *) r + 0x9C)) = &func_8006E0A0;
    *((s32 *) ((char *) r + 0xBC)) = 4;
    return r;
  }
  else
  {
    void *r;
    func_80085244(p, arg0);
    r = p;
    *((s32 *) ((char *) r + 0x74)) = 0x4E;
    *((s32 *) ((char *) r + 0x88)) = 0x1E0;
    return r;
  }
}
