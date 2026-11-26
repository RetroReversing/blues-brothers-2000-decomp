/* identical to func_80049450 in BATTLEZONE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osVirtualToPhysical in BASSMASTERS2000 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osVirtualToPhysical in Asteroids Hyper 64 (local match library) (matched), with its names changed by decompdecomp */
/* identical to osVirtualToPhysical in Army Men Sarge (local match library) (matched), with its names changed by decompdecomp */
/* identical to osVirtualToPhysical in TWINE (local match library) (matched), with its names changed by decompdecomp */
/* identical to osVirtualToPhysical in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_80098390(s32);

/* Converts a virtual address to physical. KSEG0 and KSEG1 (0x80000000-0xBFFFFFFF) are
 * unmapped and just lose their top bits; anything else goes through the TLB lookup. */
s32 osVirtualToPhysical(s32 vaddr)
{
  if ((u32) (vaddr - 0x80000000) > 0x1FFFFFFFU)
  {
    if ((u32) (vaddr + 0x60000000) > 0x1FFFFFFFU)
    {
      return func_80098390(vaddr);
    }
    return vaddr & 0x1FFFFFFF;
  }
  return vaddr & 0x1FFFFFFF;
}
