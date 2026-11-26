f32 func_8002D2FC(f32);
f32 func_8002DD60(f32);
f32 func_8002D340(f32 arg0, f32 arg1, f32 arg2)
{
  f32 t; f32 r;
  t = arg0 - arg1;
  r = func_8002D2FC(t);
  t = func_8002DD60(t);
  if (arg2 < t) { t = arg2; }
  return arg1 + r * t;
}
