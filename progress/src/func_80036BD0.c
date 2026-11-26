/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

void func_80036BD0(void *arg0, void *arg1, const void *arg2, const void *arg3_in) {
    const void *arg3 = arg3_in;
    { f32 d = *(f32 *)((s8 *)arg0 + 0); f32 s = *(const f32 *)((s8 *)arg2 + 0);
      if (s < d) { *(f32 *)((s8 *)arg0 + 0) = s; } }
    { f32 d = *(f32 *)((s8 *)arg0 + 4); f32 s = *(const f32 *)((s8 *)arg2 + 4);
      if (s < d) { *(f32 *)((s8 *)arg0 + 4) = s; } }
    { f32 d = *(f32 *)((s8 *)arg0 + 8); f32 s = *(const f32 *)((s8 *)arg2 + 8);
      if (s < d) { *(f32 *)((s8 *)arg0 + 8) = s; } }
    { f32 d = *(f32 *)((s8 *)arg0 + 0); f32 s = *(const f32 *)((s8 *)arg3 + 0);
      if (s < d) { *(f32 *)((s8 *)arg0 + 0) = s; } }
    { f32 d = *(f32 *)((s8 *)arg0 + 4); f32 s = *(const f32 *)((s8 *)arg3 + 4);
      if (s < d) { *(f32 *)((s8 *)arg0 + 4) = s; } }
    { f32 d = *(f32 *)((s8 *)arg0 + 8); f32 s = *(const f32 *)((s8 *)arg3 + 8);
      if (s < d) { *(f32 *)((s8 *)arg0 + 8) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 0); f32 s = *(const f32 *)((s8 *)arg2 + 0);
      if (d < s) { *(f32 *)((s8 *)arg1 + 0) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 4); f32 s = *(const f32 *)((s8 *)arg2 + 4);
      if (d < s) { *(f32 *)((s8 *)arg1 + 4) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 8); f32 s = *(const f32 *)((s8 *)arg2 + 8);
      if (d < s) { *(f32 *)((s8 *)arg1 + 8) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 0); f32 s = *(const f32 *)((s8 *)arg3 + 0);
      if (d < s) { *(f32 *)((s8 *)arg1 + 0) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 4); f32 s = *(const f32 *)((s8 *)arg3 + 4);
      if (d < s) { *(f32 *)((s8 *)arg1 + 4) = s; } }
    { f32 d = *(f32 *)((s8 *)arg1 + 8); f32 s = *(const f32 *)((s8 *)arg3 + 8);
      if (d < s) { *(f32 *)((s8 *)arg1 + 8) = s; } }
}
