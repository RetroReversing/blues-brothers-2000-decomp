#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
s32 func_80024A3C();
s32 func_80024B58();
s32 func_80024BE0();
s32 func_80024FE8();
s32 func_8002DAE0(s32 *, s32 *, f32);
s32 func_8002DB6C(s32 *, s32 *, f32);
s32 func_8002DBF8(s32 *, s32 *, f32);
s32 func_8002DC84();
s32 func_80089C18(f64, f64, f64);
extern f64 D_80000E70;
extern s32 D_800CD120;
extern s32 D_800CD148;
extern s32 D_80177E28;
void func_8001FF64(void *arg0)
{
  char sp18[0x28];
  char sp40[0x28];
  char sp68[0x28];
  char sp90[0x28];
  f32 fs0;
  f32 fs1;
  f32 fs2;
  *((s32 *) (((char *) arg0) + 0x10)) = (s32) (*((u16 *) (((char *) arg0) + 0x12)));
  *((s32 *) (((char *) arg0) + 0x14)) = (s32) (*((u16 *) (((char *) arg0) + 0x16)));
  func_80024FE8(sp18);
  func_80024BE0(sp40, sp18, *((s32 *) (((char *) arg0) + 0x18)));
  func_80024A3C(sp18, sp40, *((s32 *) (((char *) arg0) + 0x14)));
  func_80024B58(&D_80177E28, sp18, -(*((s32 *) (((char *) arg0) + 0x10))));
  fs2 = (f32) (*((s32 *) (((char *) arg0) + 0x10)));
  fs2 = (f32) (((f64) fs2) * D_80000E70);
  fs1 = (f32) (*((s32 *) (((char *) arg0) + 0x14)));
  fs1 = (f32) (((f64) fs1) * D_80000E70);
  fs0 = (f32) (*((s32 *) (((char *) arg0) + 0x18)));
  fs0 = (f32) (((f64) fs0) * D_80000E70);
  func_8002DC84(sp68);
  func_8002DBF8(sp90, sp68, fs0);
  func_8002DAE0(sp68, sp90, fs1);
  func_8002DB6C(&D_800CD148, sp68, -fs2);
  func_8002DC84(sp68);
  func_8002DBF8(sp90, sp68, -fs0);
  func_8002DAE0(sp68, sp90, -fs1);
  func_8002DB6C(&D_800CD120, sp68, fs2);
  func_80089C18((f64) (*((f32 *) (((char *) arg0) + 4))), (f64) (*((f32 *) (((char *) arg0) + 8))), (f64) (*((f32 *) (((char *) arg0) + 0xC))));
}
