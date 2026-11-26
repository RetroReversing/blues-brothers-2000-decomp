typedef struct { f32 m[4][4]; } Mat4;
void func_8004BA40(Mat4 *, f32, f32, f32);
void func_8004D148(Mat4 *, Mat4 *, Mat4 *);

void func_8004DF94(Mat4 *m, f32 x, f32 y, f32 z) {
    Mat4 a;
    Mat4 b;

    func_8004BA40(&a, x, y, z);
    func_8004D148(&a, m, &b);
    *m = b;
}
