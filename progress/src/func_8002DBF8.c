/* adapted from similar verified C in func_8002DAE0 in BLUES BROTHERS 2000 (matched), with its names changed by decompdecomp */
f32 __cosf(f32);
f32 sinApprox(f32);
void func_8002DE20(s32, s32, f32 (*)[3]);

void func_8002DBF8(s32 arg0, s32 arg1, f32 angle) {
    f32 m[3][3];
    f32 c;
    f32 s;

    c = __cosf(angle);
    s = sinApprox(angle);
    m[0][0] = c;
    m[0][1] = -s;
    m[0][2] = 0.0f;
    m[1][0] = s;
    m[1][1] = c;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = 1.0f;
    func_8002DE20(arg0, arg1, m);
}

