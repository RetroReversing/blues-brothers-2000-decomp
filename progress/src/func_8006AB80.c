f32 func_8002D340(f32, f32, f32);
extern s32 D_800B9ECC;

void func_8006AB80(void *arg0) {
    *(f32 *)((s8 *)arg0 + 8) = func_8002D340(150.0f, *(f32 *)((s8 *)arg0 + 8), (f32) (D_800B9ECC * 10));
}
