s32 initControllerPaks();
s32 refreshControllerPak();
s32 deleteSaveSlot();
u8 *decodeSaveName();
s32 getPakFreeBlocks();
s32 func_80027038();
s32 setTextColorRgb();
s32 setTextColor();
s32 setTextPos();
s32 drawInt();
s32 drawText();
s32 updateMenuScroll();
s32 setSlotTextColor();
s32 drawCenteredMessage();
s32 drawMessage();
extern s32 gPakInitWarn;
extern s32 gPakInitError;
extern s32 D_800B499C;
extern s32 gDeletePending;
extern s32 gDeleteSlot;
extern s32 gPadPressed;
extern char gSlotEmpty[];
extern char gPakFileTable[];
extern s32 gSlotScrollTop;

/* Controller pak menu state; selected is the highlighted slot (0-15, 0x10 = back). */
typedef struct PakMenu {
    u8 pad_0x00[0x78];
    s32 selected;
} PakMenu;

/* Draws the controller pak save-slot screen: header, free blocks, the slot list
 * (scrolled to keep the selection visible) and the delete prompt. */
void drawControllerPakMenu(PakMenu *menu)
{
  char *__base_D_801073DE;
  char *__base_D_801071B0;
  s32 temp_a0;
  s32 __repair_phase_temp_a0;
  s32 slot;
  s32 row;
  s32 rowY;
  u8 *name;
  func_80027038(1);
  setTextColor(0xFF, 0xFF, 0xFF, 0xFF);
  setTextPos(0xA0, 0x14);
  drawCenteredMessage(0x66);
  setTextColor(0, 0xFF, 0xFF, 0xFF);
  setTextPos(0x41, 0x22);
  drawMessage(0x67);
  setTextPos(0xC8, 0x22);
  drawMessage(0x68);
  setTextPos(0xF0, 0x22);
  drawMessage(0x69);
  setTextPos(0xA0, 0xC2);
  drawMessage(0x6A);
  setTextPos(0xF0, 0xC2);
  drawInt(getPakFreeBlocks() / 256);
  setTextPos(0xA0, 0xD4);
  if (gDeletePending == 0) {
    if (menu->selected < 0x10) {
      drawCenteredMessage(0x6B);
    }
    if (menu->selected == 0x10) {
      drawCenteredMessage(0x6C);
    }
  } else {
    drawCenteredMessage(0x6D);
  }
  setTextColorRgb(0xFF, 0xFF, 0xFF);
  D_800B499C = 0;
  if ((*((s32 *) (((char *) menu) + 0x78))) < 0x10)
  {
    loop_9:
    loop_10:
    __repair_phase_temp_a0 = *((s32 *) (((char *) menu) + 0x78));


    if (__repair_phase_temp_a0 < gSlotScrollTop)
    {
      gSlotScrollTop -= 1;
      goto loop_10;
    }
    temp_a0 = gSlotScrollTop + 9;
    if (__repair_phase_temp_a0 >= temp_a0)
    {
      gSlotScrollTop += 1;
      goto loop_9;
    }
  }
  temp_a0 = gSlotScrollTop + 9;
  slot = gSlotScrollTop;
  row = 0;
  if (slot < temp_a0) {
    do {
      rowY = row * 14 + 0x37;
      setSlotTextColor(menu, slot);
      setTextPos(0x28, rowY);
      drawInt(slot + 1);
      if (((s32 *)gSlotEmpty)[slot] == 0) {
        setTextPos(0x41, rowY);
        name = decodeSaveName(gPakFileTable + slot * 0x20, 0x10);
        if (*name == 0) {
          drawMessage(0x6E);
        } else {
          drawText(name);
        }
        setTextPos(0xC8, rowY);
        drawText(decodeSaveName(gPakFileTable + slot * 0x20 - 4, 1));
        setTextPos(0xF0, rowY);
        drawInt(*(u32 *)(gPakFileTable + slot * 0x20 - 0xE) >> 8);
      } else {
        setTextPos(0x41, rowY);
        drawMessage(0x6F);
      }
      row++;
      slot += 1;
    } while (slot < temp_a0);
  }
  setSlotTextColor(menu, 0x10);
  setTextPos(0x28, 0xC2);
  drawMessage(0x70);
  updateMenuScroll(menu, 0x11);
  if (gPadPressed & 0x8000)
  {
    s32 temp_a0_a1;
    temp_a0_a1 = *((s32 *) (((char *) menu) + 0x78));
    if (temp_a0_a1 < 0x10)
    {
      if ((*(s32 *)(gSlotEmpty + temp_a0_a1 * 4)) == 0)
      {
        gDeletePending = 1;
        gDeleteSlot = *((s32 *) (((char *) menu) + 0x78));
      }
    }
  }
  if (gPadPressed & 0x4000)
  {
    if ((*((s32 *) (((char *) menu) + 0x78))) == gDeleteSlot)
    {
      gPakInitWarn = 0;
      refreshControllerPak(0);
      gPakInitError = 0;
      if (initControllerPaks() == 1)
      {
        deleteSaveSlot(*((s32 *) (((char *) menu) + 0x78)));
      }
    }
    gDeleteSlot = -1;
    gDeletePending = 0;
  }
  if (((gDeleteSlot != (-1)) && ((*((s32 *) (((char *) menu) + 0x78))) != gDeleteSlot)) && (gDeletePending == 1))
  {
    gDeleteSlot = -1;
    gDeletePending = 0;
  }
}
