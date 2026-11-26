f32 func_8002DD60(f32);
f32 sqrtf(f32);

void func_8002E100(f32 *out, f32 *in) {
    f32 len;

    len = sqrtf(in[0] * in[0] + in[1] * in[1] + in[2] * in[2]);
    if (func_8002DD60(len) > 1e-05) {
        out[0] = in[0] / len;
        out[1] = in[1] / len;
        out[2] = in[2] / len;
    } else {
        out[0] = 0.0f;
        out[2] = 0.0f;
        out[1] = 1.0f;
    }
}
