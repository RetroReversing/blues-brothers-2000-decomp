s32 tickActorTimer(void *);
s32 func_8002DA80(void *);
s32 animStepKeys();
extern f32 D_800B9EC4;
extern s32 func_8000EB34;
typedef struct {
  unsigned char pad_0[12];
  float field_C;
  int field_10;
  unsigned char pad_14[60];
  float field_50;
  unsigned char pad_54[16];
  int field_64;
  unsigned char pad_68[52];
  void *field_9C;
  unsigned char pad_A0[16];
  float field_B0;
} R;
void func_8000EB94(R *arg0) {
  f32 k = -1600.0f;
  animStepKeys();
  arg0->field_10 = 0;
  arg0->field_50 += D_800B9EC4 * k;
  arg0->field_B0 = k;
  func_8002DA80(arg0);
  if ((tickActorTimer(arg0) != 0) || (arg0->field_C > 3226.0f)) {
    arg0->field_9C = &func_8000EB34;
    arg0->field_64 = 0x64;
  }
}
