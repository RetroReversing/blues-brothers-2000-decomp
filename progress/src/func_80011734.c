void func_8000C5B4(void);
void func_8002ADFC(s32, s32, void *);
f32 func_8002DD60(f32);
extern s32 D_800A9540;
extern void *gCameraTarget;
typedef struct { u8 pad[0x14]; s32 value; } Counter14;
extern Counter14 D_800BD0E0;
void func_80011734(void *arg0)
{
  f32 dx;
  f32 dy;
  f32 dz;
  void *sub;
  f32 pos[3];

  dx = *(f32 *)((s8 *)arg0 + 4) - *(f32 *)((s8 *)gCameraTarget + 4);
  dz = *(f32 *)((s8 *)arg0 + 0xC) - *(f32 *)((s8 *)gCameraTarget + 0xC);
  if (18000.0f < func_8002DD60(dx)) return;
  if (18000.0f < func_8002DD60(dz)) return;
  dy = *(f32 *)((s8 *)arg0 + 8) - *(f32 *)((s8 *)gCameraTarget + 8);
  if (func_8002DD60(dx) < 250.0f && func_8002DD60(dy) < 500.0f && func_8002DD60(dz) < 250.0f) {
    *(s32 *)((s8 *)gCameraTarget + 0xF0) = 0xFF;
    *(s32 *)((s8 *)gCameraTarget + 0xF8) |= 2;
    func_8000C5B4();
    D_800BD0E0.value++;
    if (D_800A9540 < D_800BD0E0.value) {
      D_800BD0E0.value = D_800A9540;
    }
    func_8002ADFC(1, 0x3E8, arg0);
    sub = *(void **)((s8 *)arg0 + 0xA8);
    if (sub != NULL) {
      (*(void (**)(void *))((s8 *)sub + 0xA0))(sub);
    }
    (*(void (**)(void *))((s8 *)arg0 + 0xA0))(arg0);
  }
}
