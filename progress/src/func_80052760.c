typedef struct Vec { f32 x; f32 y; f32 z; } Vec;
extern f32 func_8002DD60(f32);

s32 func_80052760(Vec *arg0, Vec *arg1, Vec *arg2, Vec *arg3) {
    f32 a;
    f32 b;

    a = func_8002DD60(((arg1->x + arg0->x) - arg2->x) - arg3->x);
    b = func_8002DD60(arg1->x - arg0->x);
    b += func_8002DD60(arg3->x - arg2->x);
    if (b < a) return 0;
    a = func_8002DD60(((arg1->z + arg0->z) - arg2->z) - arg3->z);
    b = func_8002DD60(arg1->z - arg0->z);
    b += func_8002DD60(arg3->z - arg2->z);
    if (b < a) return 0;
    a = func_8002DD60(((arg1->y + arg0->y) - arg2->y) - arg3->y);
    b = func_8002DD60(arg1->y - arg0->y);
    b += func_8002DD60(arg3->y - arg2->y);
    if (b < a) return 0;
    return 1;
}
