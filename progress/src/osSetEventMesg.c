/* identical to osSetEventMesg in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 func_800970B0();
void func_800970D0(s32);
extern char D_80175186[];

/* Stores the two message words for event arg0 (8-byte entries at D_80175186+0x75FA), with interrupts disabled. */
void osSetEventMesg(s32 event, s32 msg0, s32 msg1)
{
  s32 saved;
  void *entry;
  saved = func_800970B0();
  entry = (event * 8) + (D_80175186 + 0x75FA);
  *((s32 *) (((char *) entry) + 0)) = msg0;
  *((s32 *) (((char *) entry) + 4)) = msg1;
  func_800970D0(saved);
}
