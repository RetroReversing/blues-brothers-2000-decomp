/* identical to ai_dma_start in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
/* adapted from similar verified C in ai_dma_start in V-RALLY-PAL (matched), with its names changed by decompdecomp */
/* Audio DMA registers (AI) and the "buffer flip" flag shared with the audio code. */
#define AI_DRAM_ADDR (*(vs32 *)0xA4500000)
#define AI_LEN       (*(vs32 *)0xA4500004)

extern u8 D_800BB540;
extern s32 osVirtualToPhysical(s32);
extern s32 func_8009C990(void);

/* Starts an audio DMA from virtual address vaddr for len bytes. Alternates between two
 * halves of the buffer (0x2000 apart) so the DMA does not overlap the previous one.
 * Returns 0 if the transfer started, -1 if the AI FIFO is full. */
s32 ai_dma_start(s32 vaddr, s32 len)
{
  s32 addr = vaddr;
  s32 ret;
  if (D_800BB540 != 0)
  {
    addr -= 0x2000;
  }
  if (((vaddr + len) & 0x1FFF) == 0)
  {
    D_800BB540 = 1; }
  else
  {
    D_800BB540 = 0;
  }
  if (func_8009C990() == 0)
  {
    ret = osVirtualToPhysical(addr);
    AI_DRAM_ADDR = ret;
    ret = 0;
    AI_LEN = len;
    return ret;
  }
  return -1;
}
