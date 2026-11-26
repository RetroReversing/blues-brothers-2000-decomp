/* identical to osSetThreadPri in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSetThreadPri in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in osSetThreadPri in V-RALLY-PAL (matched), with its names changed by decompdecomp */
s32 func_80096DBC();
s32 __osEnqueueThread();
s32 func_800970B0();
s32 func_800970D0();
s32 __osDequeueThread();
extern void *D_800BB238;
extern void *D_800BB240;
static inline s32 *inline_fn(int arg0)
{
  return (s32 *) (((char *) D_800BB238) + arg0);
}

void osSetThreadPri(void *arg0, s32 arg1)
{
  int new_var;
  s32 temp_s2;
  arg0 = arg0;
  temp_s2 = func_800970B0();
  if (arg0 == NULL)
  {
    arg0 = D_800BB240;
  }
  if ((*((s32 *) (((char *) arg0) + 4))) != arg1)
  {
    new_var = arg0 != D_800BB240;
    *((s32 *) (((char *) arg0) + 4)) = arg1;
    if (new_var && ((*((u16 *) (((char *) arg0) + 0x10))) != 1))
    {
      __osDequeueThread(*((s32 *) (((char *) arg0) + 8)), arg0);
      __osEnqueueThread(*((s32 *) (((char *) arg0) + 8)), arg0);
    }
    if ((*((s32 *) (((char *) D_800BB240) + 4))) < (*inline_fn(4)))
    {
      *((s16 *) (((char *) D_800BB240) + 0x10)) = 2;
      func_80096DBC(&D_800BB238);
    }
  }
  func_800970D0(temp_s2);
}
