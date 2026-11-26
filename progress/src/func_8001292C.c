typedef struct ObjW {
    s32 f0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x40 - 0x10];
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    u8 pad58[0x84 - 0x58];
    s32 f84;
    s32 f88;
    s32 f8C;
} ObjW;

f32 func_8002DD60(f32);
f32 func_8002D280(f32, s32);

void func_8001292C(ObjW *arg0) {
    arg0->f84 += arg0->f4C;
    arg0->f88 += arg0->f50;
    arg0->f8C += arg0->f54;
    if (arg0->f84 < arg0->f40 - 500.0f) {
        arg0->f4C = func_8002DD60(arg0->f4C);
    }
    if (arg0->f40 + 500.0f < arg0->f84) {
        arg0->f4C = -func_8002DD60(arg0->f4C);
    }
    if (arg0->f88 < arg0->f44 - 500.0f) {
        arg0->f50 = func_8002DD60(arg0->f50);
    }
    if (arg0->f44 + 500.0f < arg0->f88) {
        arg0->f50 = -func_8002DD60(arg0->f50);
    }
    if (arg0->f8C < arg0->f48 - 500.0f) {
        arg0->f54 = func_8002DD60(arg0->f54);
    }
    if (arg0->f48 + 500.0f < arg0->f8C) {
        arg0->f54 = -func_8002DD60(arg0->f54);
    }
    arg0->x += func_8002D280(arg0->f84 - arg0->x, 3);
    arg0->y += func_8002D280(arg0->f88 - arg0->y, 3);
    arg0->z += func_8002D280(arg0->f8C - arg0->z, 3);
}
