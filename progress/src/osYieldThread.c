/* identical to osYieldThread in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* identical to osYieldThread in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80095C90 in V-RALLY (matched), with its names changed by decompdecomp */

s32 func_80096DBC();
s32 func_800970B0();
s32 func_800970D0();
extern char D_800BB238[];
extern void *D_800BB240;
static inline char *inline_fn()
{
  return ((char *) D_800BB240) + 0x10;
}

void osYieldThread(void)
{
  int new_var;
  s32 temp_s0;
  temp_s0 = func_800970B0();
  new_var = 2;
  *((s16 *) inline_fn()) = new_var;
  func_80096DBC(&D_800BB238, 2);
  func_800970D0(temp_s0);
}
