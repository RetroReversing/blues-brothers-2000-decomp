s32 func_80025FF8();
s32 func_800261D4();
s32 func_800265C0();
u8 *func_80026A6C();
s32 func_80026B14();
s32 func_80027038();
s32 func_800270A8();
s32 func_8002710C();
s32 func_8002713C();
s32 func_800271D8();
s32 func_8002889C();
s32 func_80031A38();
s32 func_80031C70();
s32 func_8003CDA0();
s32 func_8003CDF4();
extern s32 D_800AE174;
extern s32 D_800AE178;
extern s32 D_800B499C;
extern s32 D_800B4A88;
extern s32 D_800B4A8C;
extern s32 D_801070A0;
extern char D_801071B0[];
extern char D_801073DE[];
extern s32 D_8013FB70;
#define SEL (*(s32 *)((char *)arg0 + 0x78))
void func_80031F0C(void *arg0)
{
  char *__base_D_801073DE;
  char *__base_D_801071B0;
  s32 *var_s2;
  s32 temp_a0;
  s32 __repair_phase_temp_a0;
  s32 var_s0;
  s32 var_s1;
  s32 row;
  char *var_s5;
  u8 *temp_v0_2;
  void *var_s3;
  void *var_s4;
  func_80027038(1);
  func_8002710C(0xFF, 0xFF, 0xFF, 0xFF);
  func_8002713C(0xA0, 0x14);
  func_8003CDA0(0x66);
  func_8002710C(0, 0xFF, 0xFF, 0xFF);
  func_8002713C(0x41, 0x22);
  func_8003CDF4(0x67);
  func_8002713C(0xC8, 0x22);
  func_8003CDF4(0x68);
  func_8002713C(0xF0, 0x22);
  func_8003CDF4(0x69);
  func_8002713C(0xA0, 0xC2);
  func_8003CDF4(0x6A);
  func_8002713C(0xF0, 0xC2);
  func_800271D8(func_80026B14() / 256);
  func_8002713C(0xA0, 0xD4);
  if (D_800B4A88 == 0) {
    if (SEL < 0x10) {
      func_8003CDA0(0x6B);
    }
    if (SEL == 0x10) {
      func_8003CDA0(0x6C);
    }
  } else {
    func_8003CDA0(0x6D);
  }
  func_800270A8(0xFF, 0xFF, 0xFF);
  D_800B499C = 0;
  if ((*((s32 *) (((char *) arg0) + 0x78))) < 0x10)
  {
    loop_9:
    loop_10:
    __repair_phase_temp_a0 = *((s32 *) (((char *) arg0) + 0x78));


    if (__repair_phase_temp_a0 < D_8013FB70)
    {
      D_8013FB70 -= 1;
      goto loop_10;
    }
    temp_a0 = D_8013FB70 + 9;
    if (__repair_phase_temp_a0 >= temp_a0)
    {
      D_8013FB70 += 1;
      goto loop_9;
    }
  }
  temp_a0 = D_8013FB70 + 9;
  var_s1 = D_8013FB70;
  row = 0;
  if (var_s1 < temp_a0) {
    do {
      var_s0 = row * 14 + 0x37;
      func_80031C70(arg0, var_s1);
      func_8002713C(0x28, var_s0);
      func_800271D8(var_s1 + 1);
      if (((s32 *)D_801071B0)[var_s1] == 0) {
        func_8002713C(0x41, var_s0);
        temp_v0_2 = func_80026A6C(D_801073DE + var_s1 * 0x20, 0x10);
        if (*temp_v0_2 == 0) {
          func_8003CDF4(0x6E);
        } else {
          func_8002889C(temp_v0_2);
        }
        func_8002713C(0xC8, var_s0);
        func_8002889C(func_80026A6C(D_801073DE + var_s1 * 0x20 - 4, 1));
        func_8002713C(0xF0, var_s0);
        func_800271D8(*(u32 *)(D_801073DE + var_s1 * 0x20 - 0xE) >> 8);
      } else {
        func_8002713C(0x41, var_s0);
        func_8003CDF4(0x6F);
      }
      row++;
      var_s1 += 1;
    } while (var_s1 < temp_a0);
  }
  func_80031C70(arg0, 0x10);
  func_8002713C(0x28, 0xC2);
  func_8003CDF4(0x70);
  func_80031A38(arg0, 0x11);
  if (D_801070A0 & 0x8000)
  {
    s32 temp_a0_a1;
    temp_a0_a1 = *((s32 *) (((char *) arg0) + 0x78));
    if (temp_a0_a1 < 0x10)
    {
      if ((*(s32 *)(D_801071B0 + temp_a0_a1 * 4)) == 0)
      {
        D_800B4A88 = 1;
        D_800B4A8C = *((s32 *) (((char *) arg0) + 0x78));
      }
    }
  }
  if (D_801070A0 & 0x4000)
  {
    if ((*((s32 *) (((char *) arg0) + 0x78))) == D_800B4A8C)
    {
      D_800AE174 = 0;
      func_800261D4(0);
      D_800AE178 = 0;
      if (func_80025FF8() == 1)
      {
        func_800265C0(*((s32 *) (((char *) arg0) + 0x78)));
      }
    }
    D_800B4A8C = -1;
    D_800B4A88 = 0;
  }
  if (((D_800B4A8C != (-1)) && ((*((s32 *) (((char *) arg0) + 0x78))) != D_800B4A8C)) && (D_800B4A88 == 1))
  {
    D_800B4A8C = -1;
    D_800B4A88 = 0;
  }
}

