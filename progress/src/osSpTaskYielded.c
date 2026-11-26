/* identical to func_80051640 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskYielded in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskYielded in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskYielded in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osSpTaskYielded in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
u32 func_8009CD50();

/* Reads the SP status register. If the task yielded (bit 0x80), copies the signal bit (bit 8)
 * into bit 0 of the task's flags at +4 and clears bit 1. Returns the signal bit. */
s32 osSpTaskYielded(void *task)
{
  s32 signal;
  u32 status;
  status = func_8009CD50();
  signal = status >> 8;
  signal = signal & 1;
  if (status & 0x80)
  {
    *((s32 *) (((s8 *) task) + 4)) = (s32) (((*((s32 *) (((s8 *) task) + 4))) | signal) & (~2));
  }
  return signal;
}
