s32 packDrawFlags(s32, s32, s32, s32, s32, s32, s32, s32);
s32 randomRange(s32, s32);
void *func_80042F00(s32, s32, s32, s32);
s32 actorSetAnim(void *, s32, s32);
s32 func_80050460(s32 *, void *);
extern s32 D_8014AA34;
extern s32 func_80050B0C;
extern s32 func_80050B3C;
void *func_80050DB8(void *arg0)
{
  f32 temp_fv0;
  void *temp_v0;
  func_80050460(&func_80050B0C, ((char *) (&D_8014AA34)) + 2);
  temp_v0 = func_80042F00(0x15, 0, 0, 0);
  actorSetAnim(temp_v0, 0x7F, 0x100);
  *((s32 **) (((char *) temp_v0) + 0x9C)) = &func_80050B3C;
  *((s32 *) (((char *) temp_v0) + 0x58)) = packDrawFlags((double) 1, 1, 2, 3, 0, 0, 1, 0);
  *((f32 *) (((char *) temp_v0) + 0x4C)) = (f32) randomRange(0x14, 0x46);
  *((f32 *) (((char *) temp_v0) + 0x50)) = (f32) randomRange(0x14, 0x46);
  temp_fv0 = (f32) randomRange(0x14, 0x46);
 do { *((s32 *) (((char *) temp_v0) + 0x70)) = 0x5DC; *((f32 *) (((char *) temp_v0) + 0x54)) = temp_fv0; *((s32 *) (((char *) temp_v0) + 0x74)) = 0x1F4; if (arg0 != NULL) { *((f32 *) (((char *) temp_v0) + 4)) = (f32) (*((f32 *) (((char *) arg0) + 4))); *((f32 *) (((char *) temp_v0) + 8)) = (f32) (*((f32 *) (((char *) arg0) + 8))); *((f32 *) (((char *) temp_v0) + 0xC)) = (f32) (*((f32 *) (((char *) arg0) + 0xC))); } } while (0);
  return temp_v0;
}
