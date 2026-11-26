/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
s32 func_8000C43C();                                /* extern */
extern s32 D_800B74E8;

void func_8004145C(void) {
    s32 temp_v0;

    temp_v0 = func_8000C43C();
    switch (temp_v0)
    {
    case 0x16:
      D_800B74E8 = 0x1388;
      break;
    case 0x25:
      D_800B74E8 = 0x3E80;
      break;
    case 0x30:
      D_800B74E8 = 0x2710;
      break;
    default:
      D_800B74E8 = 0x1F40;
      break;
    }
}
