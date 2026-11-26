s32 coss(s32);
extern s32 gTextWaveTime;
typedef struct { int field_0; unsigned char pad_4[20]; int field_18; } __repair_record_arg0;
void func_8001E04C(void *arg0)
{
 ((__repair_record_arg0*)arg0)->field_0 = 0x10E;
  ((__repair_record_arg0*)arg0)->field_18 = (s32) ((((s32) (coss((gTextWaveTime * 0x64) & 0xFFFC) << 0x10)) >> 0x17) * 0x10);
}
