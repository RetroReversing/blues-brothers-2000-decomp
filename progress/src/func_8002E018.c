s32 func_8002E018(f32 *arg0, f32 *arg1, f32 *arg2) {
    arg0[0] = (arg1[1] * arg2[2]) - (arg2[1] * arg1[2]);
    arg0[1] = (arg1[2] * arg2[0]) - (arg2[2] * arg1[0]);
    arg0[2] = (arg1[0] * arg2[1]) - (arg2[0] * arg1[1]);
    return (s32) arg0;
}
